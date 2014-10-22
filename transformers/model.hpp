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

	int mode;
	void toCar();
	void toHumanoid();	
	
	float headPosY;
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
	void makeFoot();
	void makeHand();
	void makeLeftWing();
	void makeRightWing();

	void makeWheel();
	
	int iter;
	int totalIter;
	
};

