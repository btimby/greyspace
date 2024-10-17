#include "h33dLatLng.hpp"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

extern "C" {
#include "../h3/build/src/h3lib/include/h3api.h"
}

using namespace godot;

void H33DLatLng::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_lat"), &H33DLatLng::get_lat);
	ClassDB::bind_method(D_METHOD("set_lat"), &H33DLatLng::set_lat);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "lat"), "set_lat", "get_lat");

	ClassDB::bind_method(D_METHOD("get_lng"), &H33DLatLng::get_lng);
	ClassDB::bind_method(D_METHOD("set_lng"), &H33DLatLng::set_lng);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "lng"), "set_lng", "get_lng");

	ClassDB::bind_method(D_METHOD("get_radius"), &H33DLatLng::get_radius);
	ClassDB::bind_method(D_METHOD("set_radius"), &H33DLatLng::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "resolution"), "set_radius", "get_radius");
}

H33DLatLng::H33DLatLng() {
    this->radius = H33D_DEFAULT_RADIUS;
}

H33DLatLng::H33DLatLng(LatLng loc) {
    this->radius = H33D_DEFAULT_RADIUS;
	this->location = loc;
}

H33DLatLng::~H33DLatLng() {
	// Add your cleanup here.
}

float H33DLatLng::get_lat() {
    return radsToDegs(this->location.lat);
}

void H33DLatLng::set_lat(float value) {
    this->location.lat = degsToRads(value);
}

float H33DLatLng::get_lng() {
    return radsToDegs(this->location.lng);
}

void H33DLatLng::set_lng(float value) {
    this->location.lng = degsToRads(value);
}

float H33DLatLng::get_radius() {
	return this->radius;
}

void H33DLatLng::set_radius(float value) {
	this->radius = value;
}

H33DLatLng *H33DLatLng::create() {
    H33DLatLng *instance = new H33DLatLng();
    return instance;
}

H33DLatLng *H33DLatLng::create(float lat, float lng) {
    H33DLatLng *instance = H33DLatLng::create();
    instance->set_lat(lat);
    instance->set_lng(lng);
    return instance;
}
