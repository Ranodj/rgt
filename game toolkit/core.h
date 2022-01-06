#pragma once

#include <cmath>
#include <vector>
#include <string>

//vector2 start

struct vector2 {

	float x, y;

	vector2(float x, float y);
	vector2(float xy);
	vector2();

	inline vector2 operator +(vector2 other) {

		return vector2(this->x + other.x, this->y + other.y);
	}

	inline vector2 operator -(vector2 other) {

		return vector2(this->x - other.x, this->y - other.y);
	}

	inline vector2 operator *(vector2 other) {

		return vector2(this->x * other.x, this->y * other.y);
	}

	inline vector2 operator /(vector2 other) {

		return vector2(this->x / other.x, this->y / other.y);
	}

	inline vector2 operator +(float other) {

		return vector2(this->x + other, this->y + other);
	}

	inline vector2 operator -(float other) {

		return vector2(this->x - other, this->y - other);
	}

	inline vector2 operator *(float other) {

		return vector2(this->x * other, this->y * other);
	}

	inline vector2 operator /(float other) {

		return vector2(this->x / other, this->y / other);
	}

	inline vector2 operator +=(vector2 other) {

		this->x += other.x;
		this->y += other.y; 
		return *this;
	}

	inline vector2 operator -=(vector2 other) {

		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}

	inline vector2 operator *=(vector2 other) {

		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}

	inline vector2 operator /=(vector2 other) {

		this->x /= other.x;
		this->y /= other.y;
		return *this;
	}

	inline vector2 operator +=(float other) {

		this->x += other;
		this->y += other;
		return *this;
	}

	inline vector2 operator -=(float other) {

		this->x -= other;
		this->y -= other;
		return *this;
	}

	inline vector2 operator *=(float other) {

		this->x *= other;
		this->y *= other;
		return *this;
	}

	inline vector2 operator /=(float other) {

		this->x /= other;
		this->y /= other;
		return *this;
	}

	inline bool operator ==(vector2 other) {

		return this->x == other.x && this->y == other.y;
	}

	inline bool operator ==(float other) {

		return this->x == other && this->y == other;
	}
};

inline float distance(vector2* a, vector2* b) {

	return std::sqrt(
		(a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y)
	);
}

inline float distance(vector2 a, vector2 b) {

	return std::sqrt(
		(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)
	);
}

inline float distanceSquared(vector2* a, vector2* b) {

	return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y);
}

inline float distanceSquared(vector2 a, vector2 b) {

	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

//vector2 end -- camera start

#define CAMERAMODE_CENTER	   0
#define CAMERAMODE_TOPLEFT	   1
#define CAMERAMODE_TOPRIGHT    2
#define CAMERAMODE_BOTTOMLEFT  3
#define CAMERAMODE_BOTTOMRIGHT 4

struct camera {

public:
	vector2 position;

	inline vector2 applyPosition(vector2* objectPosition) {

		return *objectPosition - (this->position + this->positionFactor);
	}

	inline vector2 applyPosition(vector2 objectPosition) {

		return objectPosition - (this->position + this->positionFactor);
	}

	void follow(vector2* followPosition, float followSpeed, int followMode = 0);
	void follow(vector2* followPosition, float* followSpeed, int followMode = 0);
	void stopFollowing();

	void setMode(int mode);
	void setWindowSize(vector2 windowSize);

	void update(float dt);

	camera(vector2 position, vector2 windowSize, int mode = 0);

private:
	vector2 windowSize;
	vector2 positionFactor;

	vector2* followPosition;
	vector2 followPositionFactor;
	float followSpeed;
};

//camera end -- animation start

template <typename T>
struct animation {

public:
	std::vector<T> frames;
	float speed;

	float currentFrame;

	inline void update(float* dt) {

		this->currentFrame += this->speed * *dt;
	}
	
	inline void update(float dt) {
		
		this->currentFrame += this->speed * dt;	
	}

	inline T* getCurrentFrame() {

		return &frames[(int)this->currentFrame % this->frameCount];
	}

	animation();
	animation(std::vector<T> frames, float speed);
	
private:
	int frameCount;
};

//animation end -- file management start

std::string getExePath();
std::string getExeDir();
bool fileExists(std::string filepath, bool startInExeDir = true);

void writeToFile(std::string filepath, std::string contents, bool startInExeDir = true);
std::string readFromFile(std::string filepath, bool startInExeDir = true);

//file management end -- deltaTime start

#define DTMODE_SECONDS		0.001
#define DTMODE_MILLISECONDS 1
#define DTMODE_MINUTES		0.00001666666667

float getDeltaTime(float dtMode = DTMODE_SECONDS);

//deltaTime end