#pragma once
#include "Vector.h"
#include "Color.h"
#include "Ray.h"
#include "MyMath.h"

class Sphere
{
private:
	Vector center;
	float radius = 0;
	Color color;

public:
	Sphere(const Vector& i, const float j, const Color& col);

	bool intersect(const Ray& ray, float* t);

	Vector getCenter() const;

	float getRadius() const;

	Color getColor() const;
};

class Plane
{
private:
	Vector normal;//n = 0,0,1
	Vector point;
	Color color;


public:

	Plane(const Vector& p, const Vector& n, const Color& col);


	bool intersect(const Ray &ray, float* t);


	Color getColor() const;

};

class Box
{
private:


	Vector center;
	Color color;

	float hU = 0, hV = 0, hW = 0;
	float halfLengthArray[3];


	//a u,v,w are normazlsed side directions
	Vector a[3] = { Vector(1, 0, 0).normalize(), Vector(0, 1, 0).normalize(), Vector(0, 0, 1).normalize() };

public:

	Box(const Vector& c, const Vector& n0, const Vector& n1, const Vector& n2, const float w, const float h, const Color& col);

	bool  intersect(const Ray& ray, float* t);

	Color getColor() const;
};

class Triangle
{
private:
	Vector p0;
	Vector p1;
	Vector p2;
	Color color;

public:
	Triangle(const Vector& a, const Vector& b, const Vector& c, const Color& col);

	Color getColor() const;


	bool intersect(const Ray& ray, float* t);

};

