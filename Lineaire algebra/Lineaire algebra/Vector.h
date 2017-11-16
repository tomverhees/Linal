#pragma once
class Vector
{
private: 
	int direction; 
	int length;
	Vector* v;
public:
	Vector(int length, int direction); 
	~Vector();
	void setdirection(int value); 
	void setLength(int value);
	int getlength(); 
	int getdirection();
	void addVectors(int richting, int lengte); 
	Vector* scaleVector(int value); 
	Vector* combineVectors(Vector &v);
	Vector* subtractVectors(Vector &v);
	void show(); 
};