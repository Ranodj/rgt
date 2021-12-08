
#include <windows.h>
#include <Shlwapi.h>
#include <io.h> 
#include <vector>

#include "core.h"
#include "rmath.h"

//vector2 start

vector2::vector2(float x, float y) {

	this->x = x;
	this->y = y;
}

vector2::vector2(float xy) {

	this->x = xy;
	this->y = xy;
}

vector2::vector2() {

	this->x = 0;
	this->y = 0;
}

//vector2 end -- camera start

void camera::setMode(int mode) {

	switch (mode) {

	case 0:
		this->positionFactor = vector2(
			-this->windowSize.x / 2, -this->windowSize.y / 2
		);
		break;

	case 1:
		this->positionFactor = vector2();
		break;

	case 2:
		this->positionFactor = vector2(
			-this->windowSize.x, 0
		);
		break;

	case 3:
		this->positionFactor = vector2(
			0, -this->windowSize.y
		);
		break;

	case 4:
		this->positionFactor = vector2(
			-this->windowSize.x, -this->windowSize.y
		);

	default:
		this->positionFactor = vector2(
			-this->windowSize.x / 2, -this->windowSize.y / 2
		);
		break;
	}
}

void camera::setWindowSize(vector2 windowSize) {

	//mode is center (0)
	if (this->positionFactor == vector2(-this->windowSize.x / 2, -this->windowSize.y / 2)) {

		this->windowSize = windowSize;
		this->positionFactor == vector2(-this->windowSize.x / 2, -this->windowSize.y / 2);
		return;
	}

	//mode is top_left (1)
	if (this->positionFactor == vector2()) {

		this->windowSize = windowSize;
		return;
	}

	//mode is top_right (2)
	if (this->positionFactor == vector2(this->windowSize.x, 0)) {

		this->windowSize = windowSize;
		this->positionFactor = vector2(this->windowSize.x, 0);
		return;
	}

	//mode is bottom_left (3)
	if (this->positionFactor == vector2(0, this->windowSize.y)) {

		this->windowSize = windowSize;
		this->positionFactor = vector2(0, this->windowSize.y);
		return;
	}

	//mode is bottom_right (4)
	this->windowSize = windowSize;
	this->positionFactor = vector2(-windowSize.x, -windowSize.y);
}

void camera::update(float dt) {

	if (followPosition == nullptr)
		return;

	this->position = lerp(this->position, *this->followPosition + this->followPositionFactor - this->positionFactor, this->followSpeed);
}

void camera::follow(vector2* followPosition, float followSpeed, int followMode) {

	this->followPosition = followPosition;
	this->followSpeed = followSpeed;

	switch (followMode) {

	case 0:
		this->followPositionFactor = vector2(-this->windowSize.x / 2, -this->windowSize.y / 2);
		break;

	case 1:
		this->followPositionFactor = vector2(0, 0);
		break;

	case 2:
		this->followPositionFactor = vector2(-this->windowSize.x, this->windowSize.y / 2);
		break;

	case 3:
		this->followPositionFactor = vector2(this->windowSize.x, -this->windowSize.y / 2);
		break;

	case 4:
		this->followPositionFactor = vector2(-this->windowSize.x, -this->windowSize.y);
		break;
	}
}

void camera::follow(vector2* followPosition, float* followSpeed, int followMode) {

	this->followPosition = followPosition;
	this->followSpeed = *followSpeed;

	switch (followMode) {

	case 0:
		this->followPositionFactor = vector2(-this->windowSize.x / 2, -this->windowSize.y / 2);
		break;

	case 1:
		this->followPositionFactor = vector2(0, 0);
		break;

	case 2:
		this->followPositionFactor = vector2(-this->windowSize.x, this->windowSize.y / 2);
		break;

	case 3:
		this->followPositionFactor = vector2(this->windowSize.x, -this->windowSize.y / 2);
		break;

	case 4:
		this->followPositionFactor = vector2(-this->windowSize.x, -this->windowSize.y);
		break;

	default:
		this->followPosition = nullptr;
		break;
	}
}

void camera::stopFollowing() {

	this->followPosition = nullptr;
}

camera::camera(vector2 position, vector2 windowSize, int mode) {

	this->position = position;
	this->windowSize = windowSize;
	this->followPosition = nullptr;
	this->followSpeed = 0;

	switch (mode) {

	case 0:
		this->positionFactor = vector2(
			-windowSize.x / 2, -windowSize.y / 2
		);
		break;

	case 1:
		this->positionFactor = vector2();
		break;

	case 2:
		this->positionFactor = vector2(
			-windowSize.x, 0
		);
		break;

	case 3:
		this->positionFactor = vector2(
			0, -windowSize.y
		);
		break;

	case 4:
		this->positionFactor = vector2(
			-windowSize.x, -windowSize.y
		);

	default:
		this->positionFactor = vector2(
			-windowSize.x / 2, -windowSize.y / 2
		);
		break;
	}
}

//camera end -- animationHandler start

template <typename T>
animation<T>::animation() {

	this->frames = std::vector<T>();
	this->speed = 0;

	this->frameCount = 0;
	this->currentFrame = 0;
}

template <typename T>
animation<T>::animation(std::vector<T> frames, float speed) {

	this->frames = frames;
	this->speed = speed;

	this->frameCount = frames.size();
	this->currentFrame = 0;
}

//animationHandler end -- file management start

std::string getExePath() {

	char rawPathName[MAX_PATH];
	GetModuleFileNameA(NULL, rawPathName, MAX_PATH);
	return std::string(rawPathName);
}

std::string getExeDir() {

	std::string executablePath = getExePath();
	char* exePath = new char[executablePath.length()];
	strcpy_s(exePath, sizeof(executablePath.length()), executablePath.data());
	PathRemoveFileSpecA(exePath);
	std::string directory = std::string(exePath);
	delete[] exePath;
	return directory;
}

bool fileExists(std::string filepath, bool startInExeDir) {

	if (startInExeDir)
		filepath = getExeDir() + filepath;

	return _access(filepath.data(), 0) == 0;
}

void writeToFile(std::string filepath, std::string contents, bool startInExeDir) {

	if (startInExeDir)
		filepath = getExeDir() + filepath;

	//write to the file at filepath
}

std::string readFromFile(std::string filepath, bool startInExeDir) {

	if (startInExeDir)
		filepath = getExeDir() + filepath;

	//read from file at filepath
	return "";
}

//file management end