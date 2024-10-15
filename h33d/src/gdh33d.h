#ifndef GDH33D_H
#define GDH33D_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class GDH33D : public Sprite2D {
	GDCLASS(GDH33D, Sprite2D)

private:
	double time_passed;

protected:
	static void _bind_methods();

public:
	GDH33D();
	~GDH33D();

	void _process(double delta) override;
};

}

#endif // GDH33D_H