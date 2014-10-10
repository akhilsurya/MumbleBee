#include "model.hpp"
namespace model{
	void makeModel(){
		makeUpperArm();
		makeLowerArm();
		makeTorso();
		makeThigh();
		makeLeg();
		makeNeck();
		makeHead();
	};
}

model::mode(){
	leftShoulderAngle=0;
    leftElbowAngle=0;
    rightShoulderAngle=0;
    rightElbowAngle =0;

    leftThighAngle = 0;
    rightThighAngle = 0;

    leftLegAngle = 0;
    rightLegAngle = 0;
    
    neckAngle = 0;
    headAngle = 0;
}

void model::makeModel() {
	makeUpperArm();
	makeLowerArm();
	makeTorso();
	makeThigh();
	makeLeg();
	makeNeck();
	makeHead();
}
