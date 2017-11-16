#pragma once
class Vector
{
private: 
	float direction; 
	float length;
	Vector* v;
public:
	Vector(float length, float direction); 
	~Vector();
	void setdirection(float value); 
	void setLength(float value);
	float getlength(); 
	float getdirection();
	void addVectors(float richting, float lengte); 
	Vector* scaleVector(float value); 
	Vector* combineVectors(Vector &v);
	Vector* subtractVectors(Vector &v);
	void show(); 
};