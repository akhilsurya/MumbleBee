#include "model.hpp"
#include <math.h>
model::model(){
	leftShoulderAngleX=0;
	leftShoulderAngleY=0;
	leftShoulderAngleZ=90;
	
    	leftElbowAngleX=0;
    	leftElbowAngleY=0;
    	leftElbowAngleZ=0;
    
    	rightShoulderAngleX=0;
    	rightShoulderAngleY=0;
    	rightShoulderAngleZ=90;
    
    	rightElbowAngleX =0;
    	rightElbowAngleY =0;
    	rightElbowAngleZ =0;

    	leftThighAngleX = 0;
   	leftThighAngleY = 0;
    	leftThighAngleZ = 0;
    
    	rightThighAngleX = 0;
    	rightThighAngleY = 0;
    	rightThighAngleZ = 0;

    	leftLegAngleZ = 0;
    	leftLegAngleY = 0;
    	leftLegAngleX = 0;
    
    	rightLegAngleX = 0;
    	rightLegAngleY = 0;
   	rightLegAngleZ = 0;        
    	neckAngleX = 0;
    	neckAngleY = 0;
    	neckAngleZ = 0;

    	headAngleX = 0;
    	headAngleY = 0;
    	headAngleZ = 0;
 	bodyAngleX=0;
	bodyAngleY=0;
	bodyAngleZ=0;
	
	leftWristAngleZ = 0;
    	leftWristAngleY = 0;
    	leftWristAngleX = 0;
	
	rightWristAngleX = 0;
    	rightWristAngleY = 0;
   	rightWristAngleZ = 0;

	leftFootAngleZ = 0;
    	leftFootAngleY = 0;
    	leftFootAngleX = 0;
	
	rightFootAngleX = 0;
    	rightFootAngleY = 0;
   	rightFootAngleZ = 0;

	rightWingAngleX = 0;
    	rightWingAngleY = 0;
   	rightWingAngleZ = 0;
	
	leftWingAngleZ = 0;
    	leftWingAngleY = 0;
    	leftWingAngleX = 0;


		makeModel();
}



void model::makeModel() {
	makeCube();
	makeUpperArm();
	makeLowerArm();
	makeTorso();
	makeThigh();
	makeLeg();
	makeNeck();
	makeHead();
	makeHand();
	makeFoot();


	makeLeftWing();
	makeRightWing();
	makeWheel();
}


void model::drawModel() {
	/* The torso */
	glRotatef(bodyAngleX, 1.0,0,0);
	glRotatef(bodyAngleY, 0.0,1.0,0.0);
	glRotatef(bodyAngleZ, 0.0,0.0,1.0);
	glPushMatrix();
	{
		glScalef(1.5,1.5,1.5);
		glCallList(3);
	}
	glPopMatrix();

	/* The right arm */
	glPushMatrix();
	{
		glTranslatef(0.35,0.3,0.0);
		glScalef(0.5,0.5,0.5);

		
		glRotatef(-rightShoulderAngleX,1.0,0,0.0);
		glRotatef(-rightShoulderAngleY,0,1.0,0.0);
		glRotatef(-rightShoulderAngleZ,0,0,1.0);

		glPushMatrix(); 
		{
			glCallList(1);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glTranslatef(0.3,0,-0.25);
			glRotatef(90,1,0,0);	
			glCallList(14);
		}
		glPopMatrix();
		glTranslatef(1,0,0);
		glRotatef(-rightElbowAngleX,1.0, 0.0,0.0);
		glRotatef(-rightElbowAngleY,0.0, 1.0,0.0);
		glRotatef(-rightElbowAngleZ,0, 0.0,1.0);
		glPushMatrix();
		{
			glCallList(2);
		}
		glPopMatrix();
		glTranslatef(1,0,0);
		glScalef(2,2,2);
		glRotatef(-rightWristAngleX,1.0, 0.0,0.0);
		glRotatef(-rightWristAngleY,0.0, 1.0,0.0);
		glRotatef(-rightWristAngleZ,0, 0.0,1.0);
		glCallList(10);
	}
	glPopMatrix();

	/* The left arm */
	glPushMatrix();
	{
		glTranslatef(-0.35,0.3,0.0);
		glScalef(0.5,0.5,0.5);

		glRotatef(-180,0,0,1);
		glRotatef(leftShoulderAngleX,1.0,0,0.0);
		glRotatef(leftShoulderAngleY,0,1.0,0.0);
		glRotatef(leftShoulderAngleZ,0,0,1.0);

		glPushMatrix(); 
		{
			glCallList(1);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glTranslatef(0.3,0,-0.25);
			glRotatef(90,1,0,0);	
			glCallList(14);
		}
		glPopMatrix();
		glTranslatef(1,0,0);
		glRotatef(leftElbowAngleX,1, 0.0,0.0);
		glRotatef(leftElbowAngleY,0, 1.0,0.0);
		glRotatef(leftElbowAngleZ,0, 0.0,1.0);
		glPushMatrix(); 
		{
			glCallList(2);
		}
		glPopMatrix();
		glTranslatef(1,0.0,0.0);
		glScalef(2,2,2);
		glRotatef(leftWristAngleX,1, 0.0,0.0);
		glRotatef(leftWristAngleY,0, 1.0,0.0);
		glRotatef(leftWristAngleZ,0, 0.0,1.0);
		glCallList(10);
	}
	glPopMatrix();

	/* Left Leg */
	glPushMatrix();
	{
		glTranslatef(-0.17,-0.3,0.0);
		glScalef(0.5,0.5,0.5);

		glRotatef(leftThighAngleX,1.0,0.0,0.0);
		glRotatef(leftThighAngleY,0.0,1.0,0.0);
		glRotatef(leftThighAngleZ,0.0,0.0,1.0);

		glPushMatrix(); 
		{	
			glCallList(4);
		}
		glPopMatrix();

		glTranslatef(0,-1,0);
		glRotatef(leftLegAngleX,1.0,0.0,0.0);
		glRotatef(leftLegAngleY,0.0,1.0,0.0);
		glRotatef(leftLegAngleZ,0.0,0.0,1.0);
		glPushMatrix();
		{
			glCallList(5);
		}
		glPopMatrix();
		
		glPushMatrix();
		{
			glTranslatef(-0.3,-0.5,-0.25);
			glRotatef(90,0,1,0);	
			glCallList(14);
		}
		glPopMatrix();
		glTranslatef(0,-1,0);
		glRotatef(leftFootAngleX,1.0,0.0,0.0);
		glRotatef(leftFootAngleY,0, 1.0,0.0);
		glRotatef(leftFootAngleZ,0, 0.0,1.0);

		glCallList(11);
	}
	glPopMatrix();
	
	/* Right Leg */

	glPushMatrix();
	{
		glTranslatef(0.17,-0.3,0.0);
		glScalef(0.5,0.5,0.5);

		glRotatef(rightThighAngleX,1.0,0.0,0.0);
		glRotatef(rightThighAngleY,0.0,1.0,0.0);
		glRotatef(rightThighAngleZ,0.0,0.0,1.0);

		glPushMatrix(); 
		{
			glCallList(4);
		}
		glPopMatrix();

		glTranslatef(0,-1,0);
		glRotatef(rightLegAngleX,1.0,0.0,0.0);
		glRotatef(rightLegAngleY,0.0,1.0,0.0);
		glRotatef(rightLegAngleZ,0.0,0.0,1.0);
		glPushMatrix();
		{
			glCallList(5);
		}
		glPopMatrix();
		
		glPushMatrix();
		{
			glTranslatef(0.3,-0.5,-0.25);
			glRotatef(90,0,1,0);	
			glCallList(14);
		}
		glPopMatrix();

		glTranslatef(0,-1,0);
		glRotatef(rightFootAngleX,1.0,0.0,0.0);
		glRotatef(rightFootAngleY,0, 1.0,0.0);
		glRotatef(rightFootAngleZ,0, 0.0,1.0);
		glCallList(11);
	}
	glPopMatrix();
	
	/* Neck and head */
	
	glPushMatrix();
	{
		glTranslatef(0.0, 0.4, 0.0);
		
		glRotatef(neckAngleY, 0.0, 1.0, 0.0);
		glRotatef(neckAngleZ, 0.0, 0.0, 1.0);
		glRotatef(neckAngleX, 1.0, 0.0, 0.0);
		
		glPushMatrix();
		{
			glCallList(6);
		}
		glPopMatrix();
		glTranslatef(0.0, 0.2, 0.0);
		
		glRotatef(headAngleZ, 0.0, 0.0, 1.0);
		glRotatef(headAngleX, 1.0, 0.0, 0.0);
		glRotatef(headAngleY, 0.0, 1.0, 0.0);
		
		glCallList(7);
		
	}
	glPopMatrix();

	glTranslatef(0.0, 0.45, 0.0);
	glPushMatrix(); 
	{
		glRotatef(rightWingAngleZ, 0.0, 0.0, 1.0);
		glRotatef(rightWingAngleX, 1.0, 0.0, 0.0);
		glRotatef(rightWingAngleY, 0.0, 1.0, 0.0);

		glCallList(12);
	}
	glPopMatrix();

	glPushMatrix(); 
	{
		glRotatef(leftWingAngleZ, 0.0, 0.0, 1.0);
		glRotatef(leftWingAngleX, 1.0, 0.0, 0.0);
		glRotatef(leftWingAngleY, 0.0, 1.0, 0.0);
		glCallList(13);
	}
	glPopMatrix();

}


void model::makeLeftWing() {
	glNewList(12, GL_COMPILE);
		glBegin(GL_POLYGON);             
			glColor3f(0.0f, 1.0f, 0.0f);     // Green
			glVertex3f(-0.4f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, -0.3125f, 0.541f);
			glVertex3f(-0.35f, -0.3125f, 0.541f);
		glEnd();
		// Front face  (z = 1.0f)
		glBegin(GL_POLYGON); 
			glColor3f(1.0f, 0.0f, 0.0f);     // Red
			glVertex3f(-0.35f,  -0.3125f, 0.541f);
			glVertex3f(0.0f,  -0.3125f, 0.541f);
			glVertex3f(0.0f, -0.9375f, 0.541f);
			glVertex3f(-0.35f, -0.9375f, 0.541f);
		glEnd();

		//Bottom face (y=-1.0f)
		glBegin(GL_POLYGON); 
			glColor3f(1.0f, 0.5f, 0.0f);     // Orange
			glVertex3f(-0.35f, -0.9375f,  0.541f);
			glVertex3f(0.0f, -0.9375f,  0.541f);
			glVertex3f(0.0f, -1.4f, 0.0f);
			glVertex3f(-0.4f, -1.4f,0.0f);
		glEnd();
		
		glBegin(GL_POLYGON);
			glColor3f(0.5f,0.5f, 0.5f);
			glVertex3f(-0.4f, -0.0f, 0.0f);
			glVertex3f(-0.35f, -0.3125f, 0.541f); 
			glVertex3f(-0.35f, -0.9375, 0.541f);
			glVertex3f(-0.4f, -1.4f, 0.0f);
		glEnd(); 
			 		
	glEndList();
}

void model::makeRightWing() {
	glNewList(13, GL_COMPILE);
		glBegin(GL_POLYGON);             
			glColor3f(0.0f, 1.0f, 0.0f);     // Green
			glVertex3f(0.4f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, -0.3125f, 0.541f);
			glVertex3f(0.35f, -0.3125f, 0.541f);
		glEnd();
		// Front face  (z = 1.0f)
		glBegin(GL_POLYGON); 
			glColor3f(1.0f, 0.0f, 0.0f);     // Red
			glVertex3f(0.35f,  -0.3125f, 0.541f);
			glVertex3f(0.0f,  -0.3125f, 0.541f);
			glVertex3f(0.0f, -0.9375f, 0.541f);
			glVertex3f(0.35f, -0.9375f, 0.541f);
		glEnd();

		//Bottom face (y=-1.0f)
		glBegin(GL_POLYGON); 
			glColor3f(1.0f, 0.5f, 0.0f);     // Orange
			glVertex3f(0.35f, -0.9375f,  0.541f);
			glVertex3f(0.0f, -0.9375f,  0.541f);
			glVertex3f(0.0f, -1.4f, 0.0f);
			glVertex3f(0.4f, -1.4f,0.0f);
		glEnd();
		
		glBegin(GL_POLYGON);
			glColor3f(0.5f,0.5f, 0.5f);
			glVertex3f(0.4f, -0.0f, 0.0f);
			glVertex3f(0.35f, -0.3125f, 0.541f); 
			glVertex3f(0.35f, -0.9375, 0.541f);
			glVertex3f(0.4f, -1.4f, 0.0f);
		glEnd(); 
	glEndList();
}


void model::makeHead() {
	glNewList(7, GL_COMPILE);
		glScalef(0.15,0.15,0.15);
		glCallList(9);
	glEndList();
}

void model::makeTorso() {

	glNewList(3, GL_COMPILE);
		glScalef(0.2,0.25,0.1);
		glCallList(9);
	glEndList();
}

void model::makeLeg() {
	glNewList(5, GL_COMPILE);
		glScalef(0.4,0.5,0.3);
		glTranslatef(0,-1,0);
		glCallList(9);
	glEndList();
}

void model::makeThigh() {
	glNewList(4, GL_COMPILE);
		glScalef(0.26,0.5,0.3);
		glTranslatef(0,-1,0);
		glCallList(9);
	glEndList();
}

void model::makeLowerArm() {
	glNewList(2, GL_COMPILE);
		glScalef(0.6,0.1,0.1);
		glTranslatef(1,0,0);
		glCallList(9);
	glEndList();
}

void model::makeUpperArm() {
	glNewList(1, GL_COMPILE);
		glScalef(0.6,0.1,0.3);
		glTranslatef(0.9,0,0);
		glCallList(9);
	glEndList();
}

void model::makeNeck() {
	glNewList(6, GL_COMPILE);
		glScalef(0.1,0.1,0.1);
		glCallList(9);
	glEndList();
}


void model::makeHand(){
	glNewList(10,GL_COMPILE);
		glScalef(0.1,0.1,0.1);
		glCallList(9);
	glEndList();
}

void model::makeFoot(){
	glNewList(11,GL_COMPILE);
		glTranslatef(0,0,-0.1);
		glScalef(0.2,0.1,0.35);
		glCallList(9);
	glEndList();
}


void model::makeWheel(){
	glNewList(14,GL_COMPILE);
		float segs=15;
		float step=(360/segs)*3.14/180;
		float radius=0.4;
		float x, y;
		float thickness=0.3;
		glTranslatef(0,0,-thickness/2);
	glBegin(GL_TRIANGLE_FAN);
		
		glVertex3f(0,0,0);
		for(int i=0;i<segs;++i){
			x=sinf(step*i)*radius;
			y=cosf(step*i)*radius;
			glVertex3f(x,y,0);
		}
		glVertex3f(0,radius,0);
	glEnd();
	
	glTranslatef(0,0,thickness);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0,0,0);
		for(int i=0;i<segs;++i){
			x=sinf(step*i)*radius;
			y=cosf(step*i)*radius;
			glVertex3f(x,y,0);
		}
		glVertex3f(0,radius,0);
	glEnd();
	glTranslatef(0,0,-thickness);
	glBegin(GL_QUAD_STRIP);
		for(int i=0;i<segs;++i){
			x=sinf(step*i)*radius;
			y=cosf(step*i)*radius;
			glVertex3f(x,y,0);
			glVertex3f(x,y,thickness);
		}
		glVertex3f(0,radius,0);
		glVertex3f(0,radius,thickness);
	glEnd();
	glEndList();

}
void model::makeCube() {
	glNewList(9, GL_COMPILE);
		glBegin(GL_POLYGON);             
			glColor3f(0.0f, 1.0f, 0.0f);     // Green
			glVertex3f( 1.0f, 1.0f, -1.0f);
			glVertex3f(1.0f, 1.0f, 1.0f);
			glVertex3f(-1.0f, 1.0f,  1.0f);
			glVertex3f(-1.0f, 1.0f,  -1.0f);
		glEnd();
		// Front face  (z = 1.0f)
		glBegin(GL_POLYGON); 
			glColor3f(1.0f, 0.0f, 0.0f);     // Red
			glVertex3f( 1.0f,  1.0f, 1.0f);
			glVertex3f(1.0f,  -1.0f, 1.0f);
			glVertex3f(-1.0f, -1.0f, 1.0f);
			glVertex3f(-1.0f, 1.0f, 1.0f);
		glEnd();

		//Bottom face (y=-1.0f)
		glBegin(GL_POLYGON); 
			glColor3f(1.0f, 0.5f, 0.0f);     // Orange
			glVertex3f( 1.0f, -1.0f,  1.0f);
			glVertex3f(1.0f, -1.0f,  -1.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f( -1.0f, -1.0f, 1.0f);
		glEnd(); 


		// Back face (z = -1.0f)
		glBegin(GL_POLYGON); 
			glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
			glVertex3f( 1.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f,  1.0f, -1.0f);
			glVertex3f( 1.0f,  1.0f, -1.0f);
		glEnd(); 
		// Left face (x = -1.0f)
		glBegin(GL_POLYGON); 
			glColor3f(0.0f, 0.0f, 1.0f);     // Blue
			glVertex3f(-1.0f,  1.0f,  1.0f);
			glVertex3f(-1.0f,  1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f,  1.0f);
		glEnd(); 
		// Right face (x = 1.0f)
		glBegin(GL_POLYGON); 
			glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
			glVertex3f(1.0f,  1.0f, -1.0f);
			glVertex3f(1.0f,  1.0f,  1.0f);
			glVertex3f(1.0f, -1.0f,  1.0f);
			glVertex3f(1.0f, -1.0f, -1.0f);
		glEnd();
	glEndList();
}


