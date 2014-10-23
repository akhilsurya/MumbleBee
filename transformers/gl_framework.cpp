/*
 * CS475/CS675 - Computer Graphics
 *  ToyLOGO Assignment Base Code
 *
 * Copyright 2009-2014, Parag Chaudhuri, Department of CSE, IIT Bombay
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <unistd.h>
#include "gl_framework.hpp"
#include "model.hpp"
model model1;

void renderGL(void);

namespace csX75
{
	int win_width;
	int win_height;


	//! Initialize GL State
	void initGL(void)
	{
		//Set framebuffer clear color
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		//Set depth buffer furthest depth
		glClearDepth(1.0);
	}

	//!GLFW Error Callback
	void error_callback(int error, const char* description)
	{
		std::cerr<<description<<std::endl;
	}

	//!GLFW framebuffer resize callback
	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		if  ( height == 0 ) height = 1;

		glMatrixMode( GL_PROJECTION);
		glLoadIdentity();
		glEnable(GL_DEPTH_TEST);
		//Draw to the whole window
		glViewport( 0, 0, width, height );

		//Keep the aspect ratio fixed
		// Changes to draw 3D

		double aspect;
		if (width > height) {
			aspect = (double)width/(double)height;
			glFrustum(-aspect, aspect, -1.0, 1.0, -1.0, 1.0); 
		}
		else {
			aspect = (double)height/(double)width;
			glFrustum(-1.0, 1.0, -aspect, aspect, -1.0, 1.0);
		}

		win_width = width;
		win_height = height;
		  glMatrixMode(GL_MODELVIEW);
	}

	//!GLFW keyboard callback


	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		//!Close the window if the ESC key was pressed
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);

		if (key == GLFW_KEY_A && action == GLFW_PRESS|GLFW_REPEAT ) {
			if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)==GLFW_PRESS) model1.headAngleZ-=3; 
			if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS) model1.headAngleX-=3;
			if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)==GLFW_PRESS) model1.headAngleY-=3;
		}

		if (key == GLFW_KEY_S && action == GLFW_PRESS ) {
			if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)==GLFW_PRESS) model1.neckAngleZ-=3; 
			if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS) model1.neckAngleX-=3;
			if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)==GLFW_PRESS) model1.neckAngleY-=3;
		}

		if (key == GLFW_KEY_C && action == GLFW_PRESS ) {
			if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)==GLFW_PRESS) model1.rightShoulderAngleZ-=3; 
			if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS) model1.rightShoulderAngleX-=3;
			if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)==GLFW_PRESS) model1.rightShoulderAngleY-=3;
		}

		if (key == GLFW_KEY_E && action == GLFW_PRESS ) {
			if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)==GLFW_PRESS) model1.leftShoulderAngleZ-=3; 
			if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS) model1.leftShoulderAngleX-=3;
			if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)==GLFW_PRESS) model1.leftShoulderAngleY-=3;
		}

		if (key == GLFW_KEY_V && action == GLFW_PRESS ) {
			if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)==GLFW_PRESS) model1.rightElbowAngleZ-=3; 
			if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS) model1.rightElbowAngleX-=3;
			if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)==GLFW_PRESS) model1.rightElbowAngleY-=3;
		}

		if (key == GLFW_KEY_R && action == GLFW_PRESS ) {
			if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)==GLFW_PRESS) model1.leftElbowAngleZ-=3; 
			if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS) model1.leftElbowAngleX-=3;
			if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)==GLFW_PRESS) model1.leftElbowAngleY-=3;
		} 

		if (key == GLFW_KEY_T && action == GLFW_PRESS ) {
			if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)==GLFW_PRESS) model1.leftWristAngleZ-=3; 
			if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS) model1.leftWristAngleX-=3;
			if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)==GLFW_PRESS) model1.leftWristAngleY-=3;
		}

		if (key == GLFW_KEY_B && action == GLFW_PRESS ) {
			if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)==GLFW_PRESS) model1.rightWristAngleZ-=3; 
			if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS) model1.rightWristAngleX-=3;
			if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)==GLFW_PRESS) model1.rightWristAngleY-=3;
		}

		if (key == GLFW_KEY_N && action == GLFW_PRESS ) {
			if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)==GLFW_PRESS) model1.rightThighAngleZ-=3; 
			if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS) model1.rightThighAngleX-=3;
			if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)==GLFW_PRESS) model1.rightThighAngleY-=3;
		}

		if (key == GLFW_KEY_Y && action == GLFW_PRESS ) {
			if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)==GLFW_PRESS) model1.leftThighAngleZ-=3; 
			if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS) model1.leftThighAngleX-=3;
			if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)==GLFW_PRESS) model1.leftThighAngleY-=3; 
		}

		if (key == GLFW_KEY_U && action == GLFW_PRESS ) {
			if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)==GLFW_PRESS) model1.leftLegAngleZ-=3; 
			if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS) model1.leftLegAngleX-=3;
			if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)==GLFW_PRESS) model1.leftLegAngleY-=3; 
		}

		if (key == GLFW_KEY_M && action == GLFW_PRESS ) {
			if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)==GLFW_PRESS) model1.rightLegAngleZ-=3; 
			if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS) model1.rightLegAngleX-=3;
			if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)==GLFW_PRESS) model1.rightLegAngleY-=3;  
		}



		if (key == GLFW_KEY_I && action == GLFW_PRESS) {
			if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)==GLFW_PRESS) model1.leftFootAngleZ-=3; 
			if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS) model1.leftFootAngleX-=3;
			if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)==GLFW_PRESS) model1.leftFootAngleY-=3; 
		}

		if (key == GLFW_KEY_COMMA && action == GLFW_PRESS) {
			if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)==GLFW_PRESS) model1.rightFootAngleZ-=3; 
			if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS) model1.rightFootAngleX-=3;
			if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)==GLFW_PRESS) model1.rightFootAngleY-=3;
		}

		if(key==GLFW_KEY_Q && action== GLFW_PRESS|GLFW_REPEAT){
			if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)==GLFW_PRESS) model1.bodyAngleZ-=3; 
			if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS) model1.bodyAngleX-=3;
			if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)==GLFW_PRESS) model1.bodyAngleY-=3;

		}

		if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
			if(model1.mode==0){
				while(model1.mode==0){
					model1.toCar();
					renderGL();
					glfwSwapBuffers(window);
					usleep(20000);
				}
			}
			else{
				while(model1.mode==1){
					model1.toHumanoid();
					renderGL();
					glfwSwapBuffers(window);
					usleep(20000);
				}
			}
		}
	}
};  



