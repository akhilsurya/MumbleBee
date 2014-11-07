#include "model.hpp"


vector<float> normal(float x1, float y1,float z1,float x2,float y2,float z2, float x3,float y3,float z3){
	float a1=x2-x1;
	float b1=y2-y1;
	float c1=z2-z1;
	float a2=x3-x2;
	float b2=y3-y2;
	float c2=z3-z2;
	vector<float> normal;
	normal.push_back(b1*c2-c1*b2);
	normal.push_back(c1*a2-a1*c2);
	normal.push_back(a1*b2 - b1*a2);
	return normal;
}
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
	bodyAngleX=-90;
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
	carPosZ=0;
	carPosX=0;
	carTurn=0;
	bodyPosX=0;
	bodyPosY=-0.6;
	bodyPosZ=-5;
	headPosY=0;
	mode=1;
	iter=0;
	totalIter=50;
	camera=0;
	//	makeModel();
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


	if(camera==1&&mode==1){
		glRotatef(180-bodyAngleZ, 0,1,0);
		glTranslatef(-bodyPosX,0, -bodyPosZ);
		
	}
	else if(camera==2&&mode==1){
		glTranslatef(-1,-1.5,-3.5);
		glRotatef(180-bodyAngleZ, 0,1,0);
		glTranslatef(-bodyPosX,0, -bodyPosZ);
	}
	else if(camera==2&&mode==0){
		glTranslatef(-0.5,-1.5,-3);
		glRotatef(180-bodyAngleY, 0,1,0);
		glTranslatef(-bodyPosX,0, -bodyPosZ);
	}
	else{
		glTranslatef(1,-2,-0.5);
		glRotatef(10,0,0.8,0);
	}
	GLfloat lightPos1[] = { 1.0f, 1.0f,1.0f, 0.0f};
			GLfloat lightPos0[] = {1.0f, -1.0f, 1.0f, 0.0f};
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	//	glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	//	glRotatef(45,1.0,0,0);
	glColor3f(1,1,1);
	float groundHalfWidth=50;
	float groundSegs=100;
	float groundStep=groundHalfWidth*2/groundSegs;
	glBindTexture (GL_TEXTURE_2D,groundTex);
	for(float x=-groundHalfWidth;x<groundHalfWidth;x+=groundStep){
		for(float z=-groundHalfWidth;z<groundHalfWidth;z+=groundStep){

			glBegin (GL_QUADS);
	glNormal3f(0,1,0);
	glTexCoord2f (0.0, 0.0);

	glVertex3f (x, -1.0, z+groundStep);
	glTexCoord2f (0.9, 0.0);
	glVertex3f (x, -1.0, z);
	glTexCoord2f (0.9, 1.0);
	glVertex3f (x+groundStep, -1.0, z);
	glTexCoord2f (0.0, 1.0);
	glVertex3f (x+groundStep, -1.0, z+groundStep);
	glEnd ();
		}
	}
	


int R=40;
float segs=360;
float texStep=0.9/segs;
float step=(360.0/segs)*3.14/180;
glBindTexture(GL_TEXTURE_2D,skyTex);
glColor3f(0,0,0);
float x, z;
float lastx=0;float lastz=R;
float skyEm[]={0.5,0.5,0.5};
glPushAttrib(GL_LIGHTING_BIT);
glMaterialfv(GL_FRONT, GL_EMISSION,skyEm);
for(int i=1;i<362;i++){
		x=sinf(step*i)*R;
		z=cosf(step*i)*R;
		glBegin(GL_QUADS);
		glNormal3f(-lastx,0,-lastz);
		glTexCoord2f(texStep*(i-1),0);
		glVertex3f(lastx, -1, lastz);
		glNormal3f(-lastx,0,-lastz);
		glTexCoord2f(texStep*(i-1),1);
		glVertex3f(lastx, 100, lastz);

		glNormal3f(-x,0,-z);
		glTexCoord2f(texStep*i,1);		
		glVertex3f(x, 100, z);
		glNormal3f(-x,0,-z);
		glTexCoord2f(texStep*i,0);
		glVertex3f(x,-1,z);
		glEnd();
		lastx=x;lastz=z;
}

glPopAttrib();

	//glTranslatef(-0.25, -0.25, 0);
	//glTranslatef(0.25,0.25,0);
	//	glTranslatef(carPosX,0,carPosZ);
	//	glRotatef(carTurn,0.0,1.0,0.0);
	glBindTexture(GL_TEXTURE_2D,0);
	//glPushAttrib(GL_LIGHTING_BIT);
	glTranslatef(bodyPosX,bodyPosY,bodyPosZ);
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
		glScalef(2,1,1);
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
		glScalef(2,1,1);
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
		glPushMatrix();glPushAttrib(GL_LIGHTING_BIT);
		{
			if(headLight) {
				float headLightColor[]={0.8,0.6,0};
				glMaterialfv(GL_FRONT, GL_EMISSION,headLightColor);
			}
			else glColor3f(0.8,0.8,0.8);
			glCallList(11);
		}
		glPopAttrib(); glPopMatrix();
		glTranslatef(0,1,0);
		float params[16];
GLfloat  lightPos2[]={0,0,0,1};


		GLfloat  diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f};
		GLfloat spotDir[]={0,-1,-0.05};
		glLightfv(GL_LIGHT3,GL_DIFFUSE,diffuse);
		glLightfv(GL_LIGHT3,GL_SPOT_DIRECTION,spotDir);
		glLightfv(GL_LIGHT3, GL_POSITION, lightPos2);
		glLightf(GL_LIGHT3,GL_SPOT_CUTOFF,60.0f);
		glLightf(GL_LIGHT3,GL_SPOT_EXPONENT,10.0f);
	}
	glPopMatrix();

	/* Right Leg */

	glPushMatrix();
	{
		glTranslatef(0.17,-0.3,0.0);
		glScalef(0.5,0.5,0.5);

	glColor3f(0.5,0.5,0.0);
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
		glPushMatrix();glPushAttrib(GL_LIGHTING_BIT);
		{
			if(headLight) {float headLightColor[]={0.8,0.6,0};glMaterialfv(GL_FRONT, GL_EMISSION,headLightColor);}
			else glColor3f(0.8,0.8,0.8);
			glCallList(11);
		}
		glPopAttrib(); glPopMatrix();

		GLfloat  lightPos2[]={0,0,0,1};


		GLfloat  diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f};
		GLfloat spotDir[]={0,-1,-0.05};
		glLightfv(GL_LIGHT2,GL_DIFFUSE,diffuse);
		glLightfv(GL_LIGHT2,GL_SPOT_DIRECTION,spotDir);
		glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);
		glLightf(GL_LIGHT2,GL_SPOT_CUTOFF,60.0f);
		glLightf(GL_LIGHT2,GL_SPOT_EXPONENT,10.0f);

	
}	glPopMatrix();

	/* Neck and head */
glColor3f(0.8,0.8,0.8);
	glPushMatrix();
	{
		glTranslatef(0.0, headPosY, 0.0);

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

	glTranslatef(0.0, 0.37, 0.1);
	glScalef(1,0.9,0.8);
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

	glPopAttrib();
}


void model::makeLeftWing() {
	glNewList(12, GL_COMPILE);
	glColor3f(0.8,0.8,0.8);
	vector<float> norm= normal( 0.4, 0.0, 0.0,0.4, 1.0, 0.0, 0.0, 0.0, 0.0);  
	glBegin(GL_POLYGON);
	glNormal3f(norm[0], norm[1], norm[2]);              
	glVertex3f(-0.4f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.3125f, 0.541f);
	glVertex3f(-0.35f, -0.3125f, 0.541f);
	glEnd();
	// Front face  (z = 1.0f)
	norm = normal( 0.0, -0.3125, 0.541,-0.35, -0.3125, 0.541, 0.0, -0.9375, 0.541);
	glBegin(GL_POLYGON);
glColor3f(0,0,0);
	glNormal3f(norm[0], norm[1], norm[2]); 
	glVertex3f(-0.35f,  -0.3125f, 0.541f);
	glVertex3f(0.0f,  -0.3125f, 0.541f);
	glVertex3f(0.0f, -0.9375f, 0.541f);
	glVertex3f(-0.35f, -0.9375f, 0.541f);
	glEnd();
	//Bottom face (y=-1.0f)
	norm = normal( 0.0, -0.9375, 0.541,-0.35, -0.9375, 0.541, 0.0, -1.4, 0.0);
	glBegin(GL_POLYGON);
glColor3f(0.8,0.8,0.8);
	glNormal3f(norm[0], norm[1], norm[2]); 
	glVertex3f(-0.35f, -0.9375f,  0.541f);
	glVertex3f(0.0f, -0.9375f,  0.541f);
	glVertex3f(0.0f, -1.4f, 0.0f);
	glVertex3f(-0.4f, -1.4f,0.0f);
	glEnd();

	norm = normal( -0.35, -0.9375, 0.541, -0.35, -0.3125, 0.541,-0.4, -1.4, 0.0);
	glBegin(GL_POLYGON);
	glNormal3f(norm[0], norm[1], norm[2]); 
	glVertex3f(-0.4f, -0.0f, 0.0f);
	glVertex3f(-0.35f, -0.3125f, 0.541f); 
	glVertex3f(-0.35f, -0.9375, 0.541f);
	glVertex3f(-0.4f, -1.4f, 0.0f);
	glEnd(); 

	glEndList();
}

void model::makeRightWing() {
	glNewList(13, GL_COMPILE);
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	vector<float> norm= normal( 0.4, 0.0, 0.0, 0.4, 1.0, 0.0,0.0, 0.0, 0.0);  
	glNormal3f(norm[0], norm[1], norm[2]);           
	glVertex3f(0.4f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.3125f, 0.541f);
	glVertex3f(0.35f, -0.3125f, 0.541f);
	glEnd();
	// Front face  (z = 1.0f)
	norm = normal(0.35, -0.3125, 0.541, 0.0, -0.3125, 0.541, 0.0, -0.9375, 0.541);
	glBegin(GL_POLYGON); 
glColor3f(0,0,0);
	glNormal3f(norm[0], norm[1], norm[2]); 
	glVertex3f(0.35f,  -0.3125f, 0.541f);
	glVertex3f(0.0f,  -0.3125f, 0.541f);
	glVertex3f(0.0f, -0.9375f, 0.541f);
	glVertex3f(0.35f, -0.9375f, 0.541f);
	glEnd();

	//Bottom face (y=-1.0f)
	norm = normal(0.35, -0.9375, 0.541, 0.0, -0.9375, 0.541, 0.0, -1.4, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(0.8,0.8,0.8);
	glNormal3f(norm[0], norm[1], norm[2]);  
	glVertex3f(0.35f, -0.9375f,  0.541f);
	glVertex3f(0.0f, -0.9375f,  0.541f);
	glVertex3f(0.0f, -1.4f, 0.0f);
	glVertex3f(0.4f, -1.4f,0.0f);
	glEnd();


	norm = normal(0.35, -0.3125, 0.541, 0.35, -0.9375, 0.541, 0.4, -1.4, 0.0);
	glBegin(GL_POLYGON);
	glNormal3f(norm[0], norm[1], norm[2]); 
	glVertex3f(0.4f, -0.0f, 0.0f);
	glVertex3f(0.35f, -0.3125f, 0.541f); 
	glVertex3f(0.35f, -0.9375, 0.541f);
	glVertex3f(0.4f, -1.4f, 0.0f);
	glEnd(); 
	glEndList();
}


void model::makeHead() {
	glNewList(7, GL_COMPILE);
	glScalef(0.12,0.12,0.12);

	glBegin(GL_POLYGON);  
	glNormal3f( 0.0f, 1.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f,  1.0f);
	glVertex3f(-1.0f, 1.0f,  -1.0f);
	glEnd();

	// Front face  (z = 1.0f)
	
	glBegin(GL_POLYGON); 
	glNormal3f(0,0,1);
	//glColor3f(0,0,0);
	glVertex3f( 1.0f,  1.0f, 1.0f);
	glVertex3f(1.0f,  -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();

	//Bottom face (y=-1.0f)
	glBegin(GL_POLYGON); 
	glNormal3f(0,-1,0);
	glVertex3f( 1.0f, -1.0f,  1.0f);
	glVertex3f(1.0f, -1.0f,  -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f( -1.0f, -1.0f, 1.0f);
	glEnd(); 



	// Back face (z = -1.0f)
	//glBindTexture(GL_TEXTURE_2D, 4);
	glBegin(GL_POLYGON); 
	glColor3f(1,1,1);
	glNormal3f(0,0,-1);
	//glTexCoord2f(0,0);
	glVertex3f( 1.0f, -1.0f, -1.0f);
	//glTexCoord2f(1,0);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	//glTexCoord2f(1,1);
	glVertex3f(-1.0f,  1.0f, -1.0f);
	//glTexCoord2f(0,1);
	glVertex3f( 1.0f,  1.0f, -1.0f);
	glEnd(); 

glBindTexture(GL_TEXTURE_2D, 0);
	// Left face (x = -1.0f)
	glBegin(GL_POLYGON);
	glNormal3f(-1,0,0);
	glVertex3f(-1.0f,  1.0f,  1.0f);
	glVertex3f(-1.0f,  1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f,  1.0f);
	glEnd(); 

	// Right face (x = 1.0f)
	glBegin(GL_POLYGON); 
	glNormal3f(1,0,0);
	glVertex3f(1.0f,  1.0f, -1.0f);
	glVertex3f(1.0f,  1.0f,  1.0f);
	glVertex3f(1.0f, -1.0f,  1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glEnd();
	glEndList();
}

void model::makeTorso() {

	glNewList(3, GL_COMPILE);
	glColor3f(1.0,0,0);
	glScalef(0.2,0.25,0.1);
	glBegin(GL_POLYGON);  
	glNormal3f( 0.0f, 1.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f,  1.0f);
	glVertex3f(-1.0f, 1.0f,  -1.0f);
	glEnd();

	// Back face  (z = 1.0f)
	glBegin(GL_POLYGON); 
	glNormal3f(0,0,0);
	glVertex3f( 1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f,  1.0f, 1.0f);
	glVertex3f( 1.0f,  1.0f, 1.0f);
	glEnd(); 
	


	//Bottom face (y=-1.0f)
	glBegin(GL_POLYGON); 
	glNormal3f(0,-1,0);

	glVertex3f( 1.0f, -1.0f,  1.0f);
	glVertex3f(1.0f, -1.0f,  -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f( -1.0f, -1.0f, 1.0f);
	glEnd(); 


	// Front face (z = -1.0f)
	
	glBindTexture (GL_TEXTURE_2D,3);
	glBegin(GL_QUADS); 
	glColor3f(1,1,1);
	glNormal3f(0,0,-1);
		glTexCoord2f (0.0, 1.0);
	glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f (0.0, 0.0);
	glVertex3f(1.0f,  -1.0f, -1.0f);
		glTexCoord2f (0.95, 0.0);
	glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f (0.95, 1.0);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

glBindTexture (GL_TEXTURE_2D,0);

	// Left face (x = -1.0f)
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	glNormal3f(-1,0,0);
	glVertex3f(-1.0f,  1.0f,  1.0f);
	glVertex3f(-1.0f,  1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f,  1.0f);
	glEnd(); 

	// Right face (x = 1.0f)
	glBegin(GL_POLYGON); 
	glNormal3f(1,0,0);
	glVertex3f(1.0f,  1.0f, -1.0f);
	glVertex3f(1.0f,  1.0f,  1.0f);
	glVertex3f(1.0f, -1.0f,  1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glEnd();
	glEndList();
}

void model::makeLeg() {
	glNewList(5, GL_COMPILE);
	glColor3f(0,0,1);
	glScalef(0.4,0.5,0.3);
	glTranslatef(0,-1,0);
	glCallList(9);
	glEndList();
}

void model::makeThigh() {
	glNewList(4, GL_COMPILE);
	glColor3f(0.8,0.8,0.8);
	glScalef(0.2,0.5,0.25);
	glTranslatef(0,-1,0);
	glCallList(9);
	glEndList();
}

void model::makeLowerArm() {
	glNewList(2, GL_COMPILE);
	glColor3f(0,0,1);
	glScalef(0.5,0.2,0.2);
	glTranslatef(1,0,0);
	glCallList(9);
	glEndList();
}

void model::makeUpperArm() {
	glNewList(1, GL_COMPILE);
	glColor3f(0.8,0.8,0.8);

	glScalef(0.6,0.15,0.15);
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
	glColor3f(0.0,0.0,.0);
	float segs=15;
	float step=(360/segs)*3.14/180;
	float radius=0.4;
	float x, y;
	float thickness=0.3;
	glTranslatef(0,0,-thickness/2);
	glBegin(GL_TRIANGLE_FAN);
	glNormal3f(0,0,-1.0f);
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
	glNormal3f(0,0,1.0f);

	glVertex3f(0,0,0);
	for(int i=0;i<segs;++i){
		x=sinf(step*i)*radius;
		y=cosf(step*i)*radius;
		glVertex3f(x,y,0);
	}
	glVertex3f(0,radius,0);
	glEnd();
	glTranslatef(0,0,-thickness);

	float x1, y1;
	for(int i=0;i<segs;++i){
		glBegin(GL_QUADS);



		x=sinf(step*i)*radius;
		y=cosf(step*i)*radius;
		x1=sinf(step*(i+1))*radius;
		y1=cosf(step*(i+1))*radius;
		vector<float> norm= normal(x,y,0,x,y,thickness,x1,y1,thickness);  

		glNormal3f(norm[0], norm[1], norm[2]);   
		glVertex3f(x,y,0);
		glVertex3f(x,y,thickness);
		glVertex3f(x1,y1,thickness);
		glVertex3f(x1,y1,0);
		glEnd();

	}
	//	glVertex3f(0,radius,0);
	//	glVertex3f(0,radius,thickness);
	//	glEnd();
	glEndList();

}
void model::makeCube() {

	glNewList(9, GL_COMPILE);
	glBegin(GL_POLYGON);  
	glNormal3f( 0.0f, 1.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f,  1.0f);
	glVertex3f(-1.0f, 1.0f,  -1.0f);
	glEnd();

	// Front face  (z = 1.0f)
	glBegin(GL_POLYGON); 
	glNormal3f(0,0,1);
	glVertex3f( 1.0f,  1.0f, 1.0f);
	glVertex3f(1.0f,  -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();

	//Bottom face (y=-1.0f)
	glBegin(GL_POLYGON); 
	glNormal3f(0,-1,0);
	glVertex3f( 1.0f, -1.0f,  1.0f);
	glVertex3f(1.0f, -1.0f,  -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f( -1.0f, -1.0f, 1.0f);
	glEnd(); 


	// Back face (z = -1.0f)
	glBegin(GL_POLYGON); 
	glNormal3f(0,0,-1);
	glVertex3f( 1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f,  1.0f, -1.0f);
	glVertex3f( 1.0f,  1.0f, -1.0f);
	glEnd(); 

	// Left face (x = -1.0f)
	glBegin(GL_POLYGON);
	glNormal3f(-1,0,0);
	glVertex3f(-1.0f,  1.0f,  1.0f);
	glVertex3f(-1.0f,  1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f,  1.0f);
	glEnd(); 

	// Right face (x = 1.0f)
	glBegin(GL_POLYGON); 
	glNormal3f(1,0,0);
	glVertex3f(1.0f,  1.0f, -1.0f);
	glVertex3f(1.0f,  1.0f,  1.0f);
	glVertex3f(1.0f, -1.0f,  1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glEnd();
	glEndList();
}

void model::toCar(){
	if(iter<40){
		headPosY-=0.01;
		iter++;
	}

	else if(iter<30+40){
		leftThighAngleZ += 0.25;

		rightThighAngleZ -= 0.25;

		leftFootAngleZ -= 0.25;

		rightFootAngleZ += 0.25;  

		iter++;
	}
	else if(iter<60+40){
		leftShoulderAngleZ+=0.35;

		leftElbowAngleZ-=0.1;

		rightShoulderAngleZ+=0.35;

		rightElbowAngleZ -=0.1;
		iter++;
	}

	else if(iter<110+40){
		rightWingAngleX +=0.25 ;
		rightWingAngleZ += 1;
		leftWingAngleZ -= 1;
		leftWingAngleX += 0.25;
		iter++;
	}
	else if(iter<140+40){
		bodyAngleX+=3;	
		iter++;
	}

	else if(iter<170+40){
		bodyAngleZ-=6;
		//bodyAngleY+=1;

		iter++;
	}
	else if(iter<220){
		bodyPosY-=0.1;
		iter++;
	}
	else {
		mode=1;
		iter=0;
	}
}

void model::toHumanoid(){
	if(iter<10){
		bodyPosY+=0.1;
		iter++;
	}
	else if(iter<30+10){
		bodyAngleZ+=(180-bodyAngleZ)/(40.0-iter);
		//bodyAngleY-=1;
		iter++;
	}
	else if(iter<60+10){
		bodyAngleX-=3;	
		iter++;
	}
	else if(iter<50+60+10){
		rightWingAngleX -=0.25;
		rightWingAngleZ -= 1;
		leftWingAngleZ += 1;
		leftWingAngleX -= 0.25;

		iter++;
	}

	else if(iter<80+60+10){
		leftShoulderAngleZ-=0.35;
		leftElbowAngleZ+=0.1;
		rightShoulderAngleZ-=0.35;
		rightElbowAngleZ +=0.1;
		iter++;
	}
	else if(iter<110+60+10){
		leftThighAngleZ -= 0.25;
		rightThighAngleZ += 0.25;
		leftFootAngleZ += 0.25;
		rightFootAngleZ -= 0.25;  

		iter++;
	}
	else if(iter<110+60+40+10){
		headPosY+=0.01;
		iter++;
	}
	else {
		mode=0;
		iter=0;
	}
}
