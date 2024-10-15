#ifndef GDH3_H
#define GDH3_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class GDH3 : public Sprite2D {
	GDCLASS(GDH3, Sprite2D)

private:
	double time_passed;

protected:
	static void _bind_methods();

public:
	GDH3();
	~GDH3();

	void _process(double delta) override;
};

}

#endif // GDH3_H