#include <iostream>
#include "gl_framework.cpp"

void renderGL(void) {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	
	//	glRotatef(40,-0.5,0.0,0.1);

	model1.drawModel();
	glPopMatrix();
}

int main(int argc, char *argv[]){
	GLFWwindow* window;

	// Setting up GLFW Error callback
	glfwSetErrorCallback(csX75::error_callback);

	if(!glfwInit()) {
		return -1;
	}

	int win_width=512;
	int win_height=512;

	//! Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(win_width, win_height, "Bumblebee is here", NULL, NULL);
	if (!window) {
		//! Free allocated resources and sets library to unintialised state 
		glfwTerminate();
		return -1;
	}

	//! Make the window's context current 
	glfwMakeContextCurrent(window);

	//Keyboard Callback
	glfwSetKeyCallback(window, csX75::key_callback);

	//Framebuffer resize callback
	// If you wish to be notified when the framebuffer of a window is resized
	glfwSetFramebufferSizeCallback(window, csX75::framebuffer_size_callback);

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// For directly retrieving the current size of the framebuffer of a window.
	glfwGetFramebufferSize(window, &win_width, &win_height);
csX75::initGL();
	csX75::framebuffer_size_callback(window, win_width, win_height);
	//Initialize GL state
	
	model1.groundTex = csX75::loadBMP("./ground.bmp");
	model1.skyTex= csX75::loadBMP("./sky.bmp");
	model1.logoTex=csX75::loadBMP("./decept.bmp");
	model1.faceTex=csX75::loadBMP("./face.bmp");
	// Loop until the user closes the window
	// Run the state is set to close window by clicking in close or through keyboard like Alt+F4 
	while (glfwWindowShouldClose(window) == 0)
	{
		// Render here
		renderGL();

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}





