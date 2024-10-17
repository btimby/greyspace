#ifndef H33DINDEX_HPP
#define H33DINDEX_HPP

#include "globals.hpp"
#include "h33dLatLng.hpp"

#include <godot_cpp/classes/node.hpp>

extern "C" {
#include "../h3/build/src/h3lib/include/h3api.h"
}

namespace godot {

class H33DIndex : public Node {
	GDCLASS(H33DIndex, Node)

private:

protected:
	static void _bind_methods();

public:
	H33DIndex();
	~H33DIndex();

	float radius;

	H3Index index;
	static H33DIndex *create();
	static H33DIndex *create(String);

	void set_radius(float);
	float get_radius();

	H33DLatLng *cellToLatLng();
	Variant cellToBoundary();
	Variant getResolution();
	Variant cellToParent();
	Variant cellToChildren();
	Variant cellToCenterChild();
	Variant isPentagon();

	void set_index(String);
	String get_index();
};

}

#endif // H33DINDEX_HPP