.PHONY: build
build:
	clear
	cmake -B ./build
	make -C ./build

clean:
	rm -r ./build
	rm -r ./run

run: build
	rm -rf ./run
	mkdir -p ./run
	cp ./build/opengl ./run/opengl
	
	mkdir -p ./run/shaders/
	mkdir -p ./run/textures/
	cp -r ./src/shaders/* ./run/shaders/
	cp -r ./src/textures/* ./run/textures/
	
	./run/opengl
