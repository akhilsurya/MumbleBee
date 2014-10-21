#include <GL/glew.h>
#include <iostream>
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
	
	model();
	
	void makeModel();
	
	void drawModel();
	
	private :
	
	void makeUpperArm();
	void makeLowerArm();
	void makeTorso();
	void makeThigh();
	void makeLeg();
	void makeNeck();
	void makeHead();
	
	void makeCube();
	
};

