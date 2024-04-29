#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include <vector>

class Physics {
protected:
	Physics() {
		const size_t size = sizeof(float) * 2;

		Velocity = (float*)malloc(size);
		memset(Velocity, 0x00, size);

		Acceleration = (float*)malloc(size);
		memset(Acceleration, 0x00, size);
	}

	float maxVelocity = 1;
	float maxAcceleration = 1;
	float drag = 0.9f;

	float* Velocity;
	float* Acceleration;
	float heading;

	virtual void applyPosition(float* move) { return; }
public:
	bool disabled = false;

	virtual bool interactable() { return false; }
	virtual bool canInteract() { return false; }

	float distance(float* pos) {
		float* curPos = getPosition();

		if (curPos && pos) {
			return sqrtf(pow(pos[0] - curPos[0], 2) + pow(pos[1] - curPos[1], 2));
		}

		return NULL;
	}

	virtual void interact(Physics* object) { return; }
	virtual float* getPosition() { return nullptr; }

	virtual void setPosition(float* pos) {
		float* curPos = getPosition();

		if (curPos && pos) {
			curPos[0] = pos[0];
			curPos[1] = pos[1];
		}
	}

	void updatePhysics() {
		if (Physics::magnitude(Acceleration)) {
			applyVelocity(Acceleration);
		}

		applyPosition(Velocity);

		if (Physics::magnitude(Velocity) > 0.1) {
			applyHeading();
		}

		Physics::clamp(Velocity, -maxVelocity, maxVelocity);
		Physics::clamp(Acceleration, -maxAcceleration, maxAcceleration);

		Physics::multiply(Velocity, drag);
		Physics::multiply(Acceleration, 0);
	}

	void applyAcceleration(float* move) {
		Acceleration[0] += move[0];
		Acceleration[1] += move[1];
	}

	void applyVelocity(float* move) {
		Velocity[0] += move[0];
		Velocity[1] += move[1];
	}

	void applyHeading() {
		heading = atan(Velocity[1] / Velocity[0]);
	}

	static float getHeading(float* val) { // returns radians!!!
		return atan(val[1] / val[0]);
	}

	static float magnitude(float* val) {
		return sqrt(powf(val[0], 2) + powf(val[1], 2));
	}

	static void setMagnitude(float* val, float mag) {
		float heading = Physics::getHeading(val);

		int negX = 1;
		if (val[0] < 0) {
			negX = -1;
		}

		int negY = 1;
		if (val[1] < 0) {
			negY = -1;
		}

		val[0] = negX * cos(heading) * mag;
		val[1] = negY * sin(heading) * mag;
	}

	static void clamp(float* val, float min, float max) {
		if (val[0] > max) {
			val[0] = max;
		}
		else if (val[0] < min) {
			val[0] = min;
		}

		if (val[1] > max) {
			val[1] = max;
		}
		else if (val[1] < min) {
			val[1] = min;
		}
	}

	static void multiply(float* val, float scaler) {
		val[0] *= scaler;
		val[1] *= scaler;
	}

};

#endif //PHYSICS_HPP