build:
	meson build
	ninja -C build
	ninja -C build test
install:
	ninja -C build install
clean:
	rm -rf build