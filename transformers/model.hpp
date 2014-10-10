#include <GL/glew.h>
namespace model{
	void makeModel();
	void makeUpperArm();
	void makeLowerArm();
	void makeTorso();
	void makeThigh();
	void makeLeg();
	void makeNeck();
	void makeHead();
}


struct model {
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
	
	private :
	
	void makeUpperArm();
	void makeLowerArm();
	void makeTorso();
	void makeThigh();
	void makeLeg();
	void makeNeck();
	void makeHead();
}
