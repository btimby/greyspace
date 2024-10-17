#include "h33d.hpp"
#include "h33dIndex.hpp"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void H33D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("latLngToCell"), &H33D::latLngToCell);

	ClassDB::bind_method(D_METHOD("get_resolution"), &H33D::get_resolution);
	ClassDB::bind_method(D_METHOD("set_resolution"), &H33D::set_resolution);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "resolution"), "set_resolution", "get_resolution");

	ClassDB::bind_method(D_METHOD("get_radius"), &H33D::get_radius);
	ClassDB::bind_method(D_METHOD("set_radius"), &H33D::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "resolution"), "set_radius", "get_radius");
}

H33D::H33D() {
	this->resolution = 0;
	this->radius = H33D_DEFAULT_RADIUS;
}

H33D::~H33D() {
	// Add your cleanup here.
}

int H33D::get_resolution() {
	return this->resolution;
}

void H33D::set_resolution(int value) {
	this->resolution = value;
}

float H33D::get_radius() {
	return this->radius;
}

void H33D::set_radius(float value) {
	this->radius = value;
}

H33DIndex *H33D::latLngToCell(float lat, float lng, int res) {
	LatLng location;
	location.lat = degsToRads(lat);
	location.lng = degsToRads(lng);
	H33DIndex *index = new H33DIndex();
	index->radius = this->radius;

	::latLngToCell(&location, res, &(index->index));

	return index;
}
