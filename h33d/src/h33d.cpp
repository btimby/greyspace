#include "h33d.hpp"
#include "h33dIndex.hpp"
#include "h33dLatLng.hpp"
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

H33DIndex *H33D::latLngToCell(H33DLatLng *loc, int res) {
	H33DIndex *index = new H33DIndex();

	//latLngToCell(&loc.location, res, index);

	return index;
}
