SRC=src/*


demo/bin/libgdh33d.linux.template_debug.x86_64.so: ${SRC} godot-cpp/SConstruct h3/build/src/h3lib/include/h3api.h
	scons platform=linux


h3/CMakeLists.txt:
	git submodule update --init h3
	patch -d h3 < h3-CMakeLists.txt.patch


h3/build/src/h3lib/include/h3api.h:
	mkdir -p h3/build
	cd h3/build && cmake -DCMAKE_BUILD_TYPE=Release .. && make


godot-cpp/SConstruct:
	git submodule update --init godot-cpp


.PHONY: clean
clean:
	rm -rf demo/bin/libgdh33d.linux.template_debug.x86_64.so
