#ifndef H33DINDEX_HPP
#define H33DINDEX_HPP

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

	H3Index index;

};

}

#endif // H33DINDEX_HPP