#include <GL/glew.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>
#include <vector>
#include <stdio.h>
using namespace std;	
struct model{
	float leftShoulderAngleX;
	float leftShoulderAngleY;
	float leftShoulderAngleZ;

	float leftElbowAngleX;
	float leftElbowAngleY;
	float leftElbowAngleZ;

	float rightShoulderAngleX;
	float rightShoulderAngleY;
	float rightShoulderAngleZ;

	float rightElbowAngleX;
	float rightElbowAngleY;
	float rightElbowAngleZ;

	float leftThighAngleX;
	float leftThighAngleY;
	float leftThighAngleZ;

	float rightThighAngleX;
	float rightThighAngleY;
	float rightThighAngleZ;

	float leftLegAngleX;
	float leftLegAngleY;
	float leftLegAngleZ;

	float rightLegAngleX;
	float rightLegAngleY;
	float rightLegAngleZ;

	float neckAngleX;
	float neckAngleY;
	float neckAngleZ;

	float headAngleX;
	float headAngleY;
	float headAngleZ;

	float bodyAngleX;
	float bodyAngleY;
	float bodyAngleZ;

	float leftWristAngleX;
	float leftWristAngleY;
	float leftWristAngleZ;

	float rightWristAngleX;
	float rightWristAngleY;
	float rightWristAngleZ;

	float leftFootAngleX;
	float leftFootAngleY;
	float leftFootAngleZ;

	float rightFootAngleX;
	float rightFootAngleY;
	float rightFootAngleZ;

	float rightWingAngleX;
	float rightWingAngleY;
	float rightWingAngleZ;

	float leftWingAngleX;
	float leftWingAngleY;
	float leftWingAngleZ;
	float bodyPosX;
	float bodyPosY;
	float bodyPosZ;
	int mode;
	float carPosZ;
	float carPosX;
	float carTurn;
	void toCar();
	void toHumanoid();	
	bool headLight;
	float headPosY;
	model();
	int skyTex;
	int groundTex;
	int logoTex;
	void makeModel();

	void drawModel();
	int camera;	

	private :

	void makeUpperArm();
	void makeLowerArm();
	void makeTorso();
	void makeThigh();
	void makeLeg();
	void makeNeck();
	void makeHead();
	void makeCube();
	void makeFoot();
	void makeHand();
	void makeLeftWing();
	void makeRightWing();

	void makeWheel();
	
	int iter;
	int totalIter;


};
GLuint loadBMP_custom(const char * imagepath);

GLuint LoadTexture(const char* TextureName);
