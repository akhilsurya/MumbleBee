#include "model.hpp"

model::model(){
	leftShoulderAngleX=0;
	leftShoulderAngleY=0;
	leftShoulderAngleZ=0;
	
    leftElbowAngleX=0;
    leftElbowAngleY=0;
    leftElbowAngleZ=0;
    
    rightShoulderAngleX=0;
    rightShoulderAngleY=0;
    rightShoulderAngleZ=0;
    
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
}


void model::drawModel() {
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
		glRotatef(-rightShoulderAngleX,1.0,0,0.0);
		glRotatef(-rightShoulderAngleY,0,1.0,0.0);
		glRotatef(-rightShoulderAngleZ,0,0,1.0);

		glPushMatrix(); 
		{
			glCallList(1);
		}
		glPopMatrix();

		glTranslatef(0.9,0,0);
		glRotatef(-rightElbowAngleX,1.0, 0.0,0.0);
		glRotatef(-rightElbowAngleY,0.0, 1.0,0.0);
		glRotatef(-rightElbowAngleZ,0, 0.0,1.0);
		glCallList(2);
	}
	glPopMatrix();

	/* The left arm */
	glPushMatrix();
	{
		glScalef(0.5,0.5,0.5);

		glTranslatef(-0.8,0.65,0.0);
		glRotatef(-180,0,0,1);
		glRotatef(leftShoulderAngleX,1.0,0,0.0);
		glRotatef(leftShoulderAngleY,0,1.0,0.0);
		glRotatef(leftShoulderAngleZ,0,0,1.0);

		glPushMatrix(); 
		{
			glCallList(1);
		}
		glPopMatrix();

		glTranslatef(0.9,0,0);
		glRotatef(leftElbowAngleX,1, 0.0,0.0);
		glRotatef(leftElbowAngleY,0, 1.0,0.0);
		glRotatef(leftElbowAngleZ,0, 0.0,1.0);
		glCallList(2);
	}
	glPopMatrix();
	
	/* Left Leg */
	glPushMatrix();
	{
		glScalef(0.5,0.5,0.5);

		glTranslatef(-0.4,-0.65,0.0);
		glRotatef(90,0,0,1);
		glRotatef(leftThighAngleX,1.0,0.0,0.0);
		glRotatef(leftThighAngleY,0.0,1.0,0.0);
		glRotatef(leftThighAngleZ,0.0,0.0,1.0);

		glPushMatrix(); 
		{
			glCallList(4);
		}
		glPopMatrix();

		glTranslatef(-1,0,0);
		glRotatef(leftLegAngleX,1.0,0.0,0.0);
		glRotatef(leftLegAngleY,0, 1.0,0.0);
		glRotatef(leftLegAngleZ,0, 0.0,1.0);
		glCallList(5);
	}
	glPopMatrix();
	
	/* Right Leg */

	glPushMatrix();
	{
		glScalef(0.5,0.5,0.5);

		glTranslatef(+0.4,-0.65,0.0);
		glRotatef(90,0,0,1);
		glRotatef(rightThighAngleX,1.0,0.0,0.0);
		glRotatef(rightThighAngleY,0.0,1.0,0.0);
		glRotatef(rightThighAngleZ,0.0,0.0,1.0);

		glPushMatrix(); 
		{
			glCallList(4);
		}
		glPopMatrix();

		glTranslatef(-1,0,0);
		glRotatef(rightLegAngleX,1.0,0.0,0.0);
		glRotatef(rightLegAngleY,0.0,1.0,0.0);
		glRotatef(rightLegAngleZ,0.0,0.0,1.0);
		glCallList(5);
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
}

void model::makeHead() {
	glNewList(7, GL_COMPILE);
		glScalef(0.15,0.15,0.15);
		
		glCallList(9);
	glEndList();
}

void model::makeTorso() {
	glNewList(3, GL_COMPILE);
		glScalef(0.2,0.2,0.1);
		glCallList(9);
	glEndList();
}

void model::makeLeg() {
	glNewList(5, GL_COMPILE);
		glScalef(0.5,0.2,0.2);
		glTranslatef(-1,0,0);
		glCallList(9);
	glEndList();
}

void model::makeThigh() {
	glNewList(4, GL_COMPILE);
		glScalef(0.5,0.2,0.2);
		glTranslatef(-1,0,0);
		glCallList(9);
	glEndList();
}

void model::makeLowerArm() {
	glNewList(2, GL_COMPILE);
		glScalef(0.5,0.1,0.1);
		glTranslatef(1,0,0);
		glCallList(9);
	glEndList();
}

void model::makeUpperArm() {
	glNewList(1, GL_COMPILE);
		glScalef(0.5,0.1,0.1);
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


