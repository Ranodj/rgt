
#include "core.h"

struct rigidbody {

	vector2* parentPosition;

	vector2 velocity;
	vector2 force;
	float mass;

	void update(float* dt);
	void update(float dt);

	rigidbody(float mass = 1);
	rigidbody(vector2* parentPosition, float mass = 1);
	rigidbody(vector2* parentPosition, float* mass);
};