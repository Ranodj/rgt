
#include "physics.h"

//rigidbody start

void rigidbody::update(float* dt) {

	this->velocity += this->force / mass * *dt;
	*this->parentPosition += this->velocity * *dt;

	this->force = vector2();
}

void rigidbody::update(float dt) {

	this->velocity += this->force / mass * dt;
	*this->parentPosition += this->velocity * dt;

	this->force = vector2();
}

rigidbody::rigidbody(float mass) {

	this->parentPosition = nullptr;
	this->mass = mass;

	this->velocity = vector2();
	this->force = vector2();
}

rigidbody::rigidbody(vector2* parentPosition, float mass) {

	this->parentPosition = parentPosition;
	this->mass = mass;

	this->velocity = vector2();
	this->force = vector2();
}

rigidbody::rigidbody(vector2* parentPosition, float* mass) {

	this->parentPosition = parentPosition;
	this->mass = *mass;

	this->velocity = vector2();
	this->force = vector2();
}

//rigidbody end