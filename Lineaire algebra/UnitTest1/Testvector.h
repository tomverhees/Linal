#pragma once
class Testvector
{
private:
	float x_;
	float y_;
	float z_;
	float extra_;
	float deltax_;
	float deltay_;
	float deltaz_;
	Testvector* v;
public:
	Testvector(float deltax, float deltay, float deltaz, float extra = 0, float x = 0, float y = 0, float z = 0);
	void scaleVector(float valuex, float valuey, float valuez);
	float getLength() const;
	void normalize();
	float getDeltaX() const;
	float getDeltaY() const;
	float getDeltaZ() const;
	Testvector crossProduct(const Testvector& vector) const;
	~Testvector() = default;
	float inProduct(const Testvector& vector) const;
	float calculateAngle(const Testvector& vector) const;
	Testvector operator+(const Testvector& vector) const;
	Testvector operator-(const Testvector& vector) const;
	Testvector operator*(const Testvector& vector) const;
	Testvector operator*(float scale) const;
};

