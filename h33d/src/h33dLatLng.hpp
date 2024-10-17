#ifndef H33DLATLNG_HPP
#define H33DLATLNG_HPP

#include "globals.hpp"
#include <godot_cpp/classes/node.hpp>

extern "C" {
#include "../h3/build/src/h3lib/include/h3api.h"
}

namespace godot {

class H33DLatLng : public Node {
	GDCLASS(H33DLatLng, Node)

private:

protected:
	static void _bind_methods();

public:
	H33DLatLng();
	H33DLatLng(LatLng);
	~H33DLatLng();

    float radius;
    LatLng location;

    float get_lat();
    void set_lat(float);

    float get_lng();
    void set_lng(float);

	void set_radius(float);
	float get_radius();

    static H33DLatLng *create();
    static H33DLatLng *create(float, float);
};

}

#endif // H33DLATLNG_HPP