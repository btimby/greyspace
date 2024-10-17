#include "h33d.hpp"
#include "h33dIndex.hpp"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void H33D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("latLngToCell"), &H33D::latLngToCell);
}

H33D::H33D() {
	// Initialize any variables here.
	// time_passed = 0.0;
}

H33D::~H33D() {
	// Add your cleanup here.
}

H33DIndex *H33D::latLngToCell(float lat, float lng, int res) {
	LatLng location;
	location.lat = degsToRads(lat);
	location.lng = degsToRads(lng);
	H33DIndex *index = new H33DIndex();

	::latLngToCell(&location, res, &(index->index));

	return index;
}
