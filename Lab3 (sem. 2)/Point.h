#pragma once

class Point {
private:
	float x_, y_;
public:
	Point();
	Point(const float, const float);
	float getX() const;
	float getY() const;
	void setX(float);
	void setY(float);
};
