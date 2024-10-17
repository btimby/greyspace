#include "h33dIndex.hpp"
#include <godot_cpp/core/class_db.hpp>

extern "C" {
#include "../h3/build/src/h3lib/include/h3api.h"
}

using namespace godot;

void H33DIndex::_bind_methods() {
	ClassDB::bind_method(D_METHOD("cellToLatLng"), &H33DIndex::cellToLatLng);
	ClassDB::bind_method(D_METHOD("cellToBoundary"), &H33DIndex::cellToBoundary);

	ClassDB::bind_method(D_METHOD("get_index"), &H33DIndex::get_index);
	ClassDB::bind_method(D_METHOD("set_index"), &H33DIndex::set_index);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "index"), "set_index", "get_index");

	ClassDB::bind_method(D_METHOD("get_radius"), &H33DIndex::get_radius);
	ClassDB::bind_method(D_METHOD("set_radius"), &H33DIndex::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "resolution"), "set_radius", "get_radius");

	ClassDB::bind_method(D_METHOD("getResolution"), &H33DIndex::getResolution);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "index"), "", "getResolution");
}

H33DIndex::H33DIndex() {
	// Initialize any variables here.
	this->radius = H33D_DEFAULT_RADIUS;
	this->index = 0;
}

H33DIndex::~H33DIndex() {
	// Add your cleanup here.
}

H33DIndex *H33DIndex::create() {
	H33DIndex *instance = new H33DIndex();
	return instance;
}

H33DIndex *H33DIndex::create(String index) {
	H33DIndex *instance = H33DIndex::create();
	instance->set_index(index);
	return instance;
}

String H33DIndex::get_index() {
	char s[17];

	::h3ToString(this->index, s, sizeof(s));
	return String(s);
}

void H33DIndex::set_index(String value) {
	const char *s = value.utf8().get_data();

	this->index = ::stringToH3(s, &(this->index));
}

float H33DIndex::get_radius() {
	return this->radius;
}

void H33DIndex::set_radius(float value) {
	this->radius = value;
}

Variant H33DIndex::getResolution() {
	return ::getResolution(this->index);
}

H33DLatLng *H33DIndex::cellToLatLng() {
	H33DLatLng *latlng = new H33DLatLng();
	latlng->radius = this->radius;

	::cellToLatLng(this->index, &(latlng->location));

	return latlng;
}

Variant H33DIndex::cellToBoundary() {
	Array *vertices = new Array();

	if (this->index == 0) {
		return vertices;
	}

	CellBoundary boundary;
	::cellToBoundary(this->index, &boundary);

	for (int i = 0; i < boundary.numVerts; i++) {
		H33DLatLng vll = H33DLatLng(boundary.verts[i]);
		vll.radius = this->radius;
		vertices->append((Variant)&vll);
	}

	return vertices;
}
