#ifndef H33DINDEX_HPP
#define H33DINDEX_HPP

#include <godot_cpp/classes/node.hpp>

namespace godot {

class H33DIndex : public Node {
	GDCLASS(H33DIndex, Node)

private:

protected:
	static void _bind_methods();

public:
	H33DIndex();
	~H33DIndex();
};

}

#endif // H33DINDEX_HPP