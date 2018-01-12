#pragma once
#include "IGameObject.h"

class Vector : public IGameObject
{
private: 
	float x_; 
	float y_; 
	float z_; 
	float deltax_;
	float deltay_;
	float deltaz_;
	Vector* v;
public:
	Vector(float deltax, float deltay, float deltaz, float x = 0, float y =0, float z =0);
	void scaleVector(float valuex, float valuey, float valuez);
	float getLength() const;
	void normalize();
	float getDeltaX() const;
	float getDeltaY() const;
	float getDeltaZ() const;
	Vector crossProduct(Vector v, Vector v1) const;
	~Vector() = default;
	float inProduct(Vector v, Vector v1) const;
	float calculateAngle(Vector v, Vector v1) const;
	Vector operator+=(const Vector& vector);
	Vector operator-=(const Vector& vector) const;
	Vector operator*=(const Vector& vector);
	Vector operator*=(float scale);
	void Update(float deltaTime) override;
	void Draw() override;
};
