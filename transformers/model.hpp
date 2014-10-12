#include <GL/glew.h>
#include <iostream>
using namespace std;	
struct model{
	float leftShoulderAngle;
	float leftElbowAngle;
	float rightShoulderAngle;
	float rightElbowAngle;

	float leftThighAngle;
	float rightThighAngle;

	float leftLegAngle;
	float rightLegAngle;

	float neckAngle;
	float headAngle;
	
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

