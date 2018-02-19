#pragma once
#include "IGameObject.h"

class Vector : public IGameObject
{
private:
	float x_;
	float y_;
	float z_;
	float extra_; 
	float deltax_;
	float deltay_;
	float deltaz_;
	Vector* v;
public:
	Vector(float deltax, float deltay, float deltaz, float extra= 0,float x = 0, float y = 0, float z = 0);
	void scaleVector(float valuex, float valuey, float valuez);
	float getLength() const;
	void normalize();
	float getDeltaX() const;
	float getDeltaY() const;
	float getDeltaZ() const;
	Vector crossProduct(const Vector& vector) const;
	~Vector() = default;
	float inProduct(const Vector& vector) const;
	float calculateAngle(const Vector& vector) const;
	Vector operator+(const Vector& vector) const;
	Vector operator-(const Vector& vector) const;
	Vector operator*(const Vector& vector) const;
	Vector operator*(float scale) const;
	void Update(float deltaTime) override;
	void Draw() override;
};
