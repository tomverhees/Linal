#pragma once
#include "Matrix.h"
#include <chrono>

class Piramide : public IGameObject
{
public:
	Piramide();
	~Piramide();
	void createPiramide(int depth, int width, int height, int startX, int startY, int startZ);
	std::vector<Matrix<float>>& getSides();
	void Update(float deltaTime) override;
	void Pulsesate();
private:
	std::vector<Matrix<float>> sides;
	float scaleFactor_; 
	float pulse = 0; 
	float pulsefrequency = 180.0; 
	std::chrono::system_clock::time_point startTime_; 
};

