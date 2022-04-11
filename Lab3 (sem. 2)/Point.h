#pragma once

class Point {
private:
	float x_, y_;
public:
	Point();
	Point(float, float);
	float getX();
	float getY();
	void setX(float);
	void setY(float);
};