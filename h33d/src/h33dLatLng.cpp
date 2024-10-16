#include "h33dLatLng.hpp"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

extern "C" {
#include "../h3/build/src/h3lib/include/h3api.h"
}

using namespace godot;

void H33DLatLng::_bind_methods() {
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "lat"), "set_lat", "get_lat");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "lng"), "set_lng", "get_lng");
}

H33DLatLng::H33DLatLng() {
	// Initialize any variables here.
	// time_passed = 0.0;
}

H33DLatLng::~H33DLatLng() {
	// Add your cleanup here.
}

float H33DLatLng::get_lat() {
    return this->location.lat;
}

void H33DLatLng::set_lat(float value) {
    this->location.lat = value;
}

float H33DLatLng::get_lng() {
    return this->location.lng;
}

void H33DLatLng::set_lng(float value) {
    this->location.lng = value;
}

H33DLatLng *H33DLatLng::create() {
    H33DLatLng *instance = new H33DLatLng();
    return instance;
}

H33DLatLng *H33DLatLng::create(float lat, float lng) {
    H33DLatLng *instance = new H33DLatLng();
    instance->location.lat = degsToRads(lat);
    instance->location.lng = degsToRads(lng);
    return instance;
}
