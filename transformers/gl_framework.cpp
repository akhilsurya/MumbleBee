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

#include "gl_framework.hpp"


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
    leftShoulderAngle=0;
    leftElbowAngle=0;
    rightShoulderAngle=0;
    rightElbowAngle =0;

    leftThighAngle = 0;
    rightThighAngle = 0;

    leftLegAngle = 0;
    rightLegAngle = 0;
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

    glMatrixMode( GL_MODELVIEW);
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
  }
  
  //!GLFW keyboard callback

  void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
  {
    //!Close the window if the ESC key was pressed
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GL_TRUE);
    if (key == GLFW_KEY_A && action == GLFW_PRESS && leftShoulderAngle <= 70) {
      leftShoulderAngle+=10; 
    }
      
    if (key == GLFW_KEY_S && action == GLFW_PRESS && leftElbowAngle >= -120) {
      leftElbowAngle-=10;
    }
      
    if (key == GLFW_KEY_D && action == GLFW_PRESS && rightShoulderAngle <= 70) {
      rightShoulderAngle+=10;
    }
      
    if (key == GLFW_KEY_F && action == GLFW_PRESS && rightElbowAngle >= -120) {
      rightElbowAngle-=10;
    }

    if (key == GLFW_KEY_G && action == GLFW_PRESS && leftThighAngle >= -20) {
      leftThighAngle-=4; 
    }
      
    if (key == GLFW_KEY_J && action == GLFW_PRESS && rightThighAngle >= -20) {
      rightThighAngle-=4;
    } 

    if (key == GLFW_KEY_H && action == GLFW_PRESS && leftLegAngle <= 20) {
      leftLegAngle+=4; 
    }

    if (key == GLFW_KEY_K && action == GLFW_PRESS && rightLegAngle <= 20) {
      rightLegAngle+=4; 
    }


  }
};  
  


