#pragma once
#include <iostream>

class Vector
{
private:
	float x = 0, y = 0, z = 0;

public:

	Vector();

	Vector(float x, float y, float z);

	float getXPos() const;
	
	float getYPos() const;

	float getZPos() const;

	float magnitude() const; //length // 

	Vector normalize() const;

	Vector operator - (const Vector &v) const;

	Vector operator - () const;

	Vector operator + (const Vector &v) const;

	Vector operator / (const Vector &v) const;

	Vector operator * (const Vector &v) const;

	Vector operator * (const float &t) const; //scalar mult

	friend std::ostream& operator << (std::ostream& os, const Vector &v);
		

};