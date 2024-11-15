#include <flgl.h>
#include <flgl/tools.h>
#include <flgl/logger.h>
LOG_MODULE(main);


static Mesh<Vertex_3f> get_pyr() {

	Vertex_3f verts[5] = {
		{0.f, 0.5f, 0.f},
		{-.5f, -.5f, -.5f},
		{.5f, -.5f, -.5f},
		{-.5f, -.5f, .5f},
		{.5f, -.5f, .5f}
	};

	uint32_t elements[12] = {
		0, 1, 2,
		0, 1, 3,
		0, 3, 4,
		0, 2, 4
	};

	return Mesh<Vertex_3f>::from_arrays(5, verts, 12, elements);
}


int main() {
	gl.init();
	window.create("hello window", 1280, 720);

	auto pyramid = get_pyr();

	Shader shad = Shader::from_source("passvec3_vert", "color");
	
	while (!window.should_close()) {
		if (window.keyboard[GLFW_KEY_ESCAPE].pressed) window.close();
		gl.clear();

		shad.bind();
		pyramid.bind();
		gl.draw_mesh(pyramid);

		window.update();
	}

	gl.destroy();
	
	return 0;
}
