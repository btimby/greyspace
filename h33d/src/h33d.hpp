#ifndef H33D_HPP
#define H33D_HPP

#include "globals.hpp"
#include "h33dIndex.hpp"
#include <godot_cpp/classes/node.hpp>

extern "C" {
#include "../h3/build/src/h3lib/include/h3api.h"
}

namespace godot {

class H33D : public Node {
	GDCLASS(H33D, Node)

private:

protected:
	static void _bind_methods();

public:
	H33D();
	~H33D();

	int resolution;
	float radius;

	void set_resolution(int);
	int get_resolution();
	void set_radius(float);
	float get_radius();

	H33DIndex *latLngToCell(float, float, int);
	Variant getRes0Cells();
	Variant getPentagons();
};

}

#endif // H33D_HPP