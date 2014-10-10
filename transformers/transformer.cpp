#include <iostream>
#include "gl_framework.cpp"
#include "model.hpp"


void renderGL(void) {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(10,+0.5,-1.0,0.0);
	//glTranslatef(0,1,0);
	/* The torso */
	glPushMatrix();
	{
		glScalef(2,2,2);
		glCallList(3);
	}
	glPopMatrix();

	/* The right arm */
	glPushMatrix();
	{
		glScalef(0.5,0.5,0.5);

		glTranslatef(0.8,0.65,0.0);
		glRotatef(-csX75::rightShoulderAngle,0,0,1.0);

		glPushMatrix(); 
		{
			glCallList(1);
		}
		glPopMatrix();

		glTranslatef(0.9,0,0);
		glRotatef(-csX75::rightElbowAngle,0, 0.0,1.0);
		glCallList(2);
	}
	glPopMatrix();

	/* The left arm */
	glPushMatrix();
	{
		glScalef(0.5,0.5,0.5);

		glTranslatef(-0.8,0.65,0.0);
		glRotatef(-180,0,0,1);
		glRotatef(csX75::leftShoulderAngle,0,0,1.0);

		glPushMatrix(); 
		{
			glCallList(1);
		}
		glPopMatrix();

		glTranslatef(0.9,0,0);
		glRotatef(csX75::leftElbowAngle,0, 0.0,1.0);
		glCallList(2);
	}
	glPopMatrix();
	
	/* Left Leg */
	glPushMatrix();
	{
		glScalef(0.5,0.5,0.5);

		glTranslatef(-0.4,-0.65,0.0);
		glRotatef(90,0,0,1);
		glRotatef(csX75::leftThighAngle,0.0,1.0,0.0);

		glPushMatrix(); 
		{
			glCallList(4);
		}
		glPopMatrix();

		glTranslatef(-1,0,0);
		glRotatef(csX75::leftLegAngle,0, 1.0,0.0);
		glCallList(5);
	}
	glPopMatrix();
	
	/* Right Leg */

	glPushMatrix();
	{
		glScalef(0.5,0.5,0.5);

		glTranslatef(+0.4,-0.65,0.0);
		glRotatef(90,0,0,1);
		glRotatef(csX75::rightThighAngle,0.0,1.0,0.0);

		glPushMatrix(); 
		{
			glCallList(4);
		}
		glPopMatrix();

		glTranslatef(-1,0,0);
		glRotatef(csX75::rightLegAngle,0.0,1.0,0.0);
		glCallList(5);
	}
	glPopMatrix();
	
	/* Neck and head */
	
	glPushMatrix();
	{
		glTranslatef(0.0, 0.4, 0.0);
		
		glRotatef(csX75::neckAngle, 1.0, 0.0, 0.0);
		
		glPushMatrix();
		{
			glCallList(6);
		}
		glPopMatrix();
		glTranslatef(0.0, 0.2, 0.0);
		
		glRotatef(csX75::headAngle, 0.0, 1.0, 0.0);
		
		glCallList(7);
		
	}
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

	csX75::framebuffer_size_callback(window, win_width, win_height);
	//Initialize GL state
	csX75::initGL();

	model::makeModel();
 
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




	
