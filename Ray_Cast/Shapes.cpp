#include "Shapes.h"

Sphere::Sphere(const Vector& i, const float j, const Color& col)
{
	center = i;
	radius = j;
	color = col;
}

bool Sphere::intersect(const Ray& ray, float* t)
{
	Vector direction = ray.getDirection();
	Vector l = center - ray.getOrigin(); // vector from the ray origin to the center

	float r2, s, s2, l2, m2, q;

	r2 = radius * radius;
	s = Math::dotProduct(l, direction); //projection of l onto the ray direction
	s2 = s * s;
	l2 = Math::dotProduct(l, l);

	if (s < 0 && l2 >= r2) // if s < 0 and ray orgin is outside the sphere, the sphere is behind ray orgin
	{
		return false;
	}
	m2 = l2 - s2; // Pythagorean Theorem
	if (m2 > r2) // the ray will miss if m2 > r2
	{
		return false;
	}
	q = sqrt(r2 - m2);
	if (l2 > r2)
	{
		*t = s - q; //ray orgin is outside the sphere
	}
	else
	{
		*t = s + q; //ray orgin is inside the sphere
	}

	return true;
}

Vector Sphere::getCenter() const
{
	return center;
}

float Sphere::getRadius() const
{
	return radius;
}

Color Sphere::getColor() const
{
	return color;
}

//Plane

Plane::Plane(const Vector& p, const Vector& n, const Color& col)
{
	point = p;
	normal = n;
	color = col;
}


bool Plane::intersect(const Ray& ray, float* t)
{
	Vector direction = ray.getDirection();
	Vector origin = ray.getOrigin();

	float dotND = Math::dotProduct(normal, direction);


	if (std::abs(dotND) > Math::epsilon)
	{
		Vector pointMinusOrgin = point - origin;
		float tempT = Math::dotProduct(pointMinusOrgin, normal) / dotND;
		if (tempT >= 0)
		{
			*t = tempT;
			return true;
		}
	}
	return false;
}

Color Plane::getColor() const
{
	return color;
}

//Box

Box::Box(const Vector& c, const Vector& n0, const Vector& n1, const Vector& n2, const float w, const float h, const Color& col)
{
	center = c;
	color = col;
	halfLengthArray[0] = h / 2;
	halfLengthArray[1] = w / 2;
	halfLengthArray[2] = h / 2;
	a[0] = n0.normalize();
	a[1] = n1.normalize();
	a[2] = n2.normalize();
}

bool Box::intersect(const Ray& ray, float* t)
{
	float localTMin = -std::numeric_limits<float>::infinity();
	float localTMax = std::numeric_limits<float>::infinity();
	float t1;
	float t2;

	Vector origin = ray.getOrigin();
	Vector direction = ray.getDirection();

	Vector p = center - origin;

	for (int i = 0; i < 3; i++)
	{

		float e = Math::dotProduct(a[i], p);
		float f = Math::dotProduct(a[i], direction);

		if (abs(f) > Math::epsilon)
		{
			t1 = (e + halfLengthArray[i]) / f;
			t2 = (e - halfLengthArray[i]) / f;

			if (t1 > t2)
			{
				std::swap(t1, t2);
			}

			if (t1 > localTMin)//line 11
			{
				localTMin = t1;
			}

			if (t2 < localTMax)//line 12
			{
				localTMax = t2;

			}

			if (localTMin > localTMax)//line 13 if ray misses
			{
				return false;
			}
			if (localTMax < 0) //line 14 behind ray orgin
			{
				return false;
			}
		}
		else if (-e - halfLengthArray[i] > 0 || -e + halfLengthArray[i] < 0) //line 15 
		{
			return false;
		}

	}
	if (localTMin > 0)
	{
		*t = localTMin;
		return true;
	}
	else
	{
		*t = localTMax;
		return true;
	}
}

Color Box::getColor() const
{
	return color;

}

Triangle::Triangle(const Vector& a, const Vector& b, const Vector& c, const Color& col)
{
	p0 = a;
	p1 = b;
	p2 = c;
	color = col;
}

Color Triangle::getColor() const
{
	return color;
}

bool Triangle::intersect(const Ray& ray, float* t)
{
	float u, v, a, f;
	Vector e1, e2, q, s, r;

	Vector direction = ray.getDirection();
	Vector origin = ray.getOrigin();

	e1 = p1 - p0; //Edge1
	e2 = p2 - p0; //Edge2

	q = Math::crossProduct(direction, e2);
	a = Math::dotProduct(e1, q); // determinant of matrix M

	if (a > -Math::epsilon && a < Math::epsilon)
	{

		return false;
	}

	f = 1 / a; //inverse determinant
	s = origin - p0;
	u = f * Math::dotProduct(s, q);

	if (u < 0.0f)
	{
		return false;
	}
	r = Math::crossProduct(s, e1);
	v = f * Math::dotProduct(direction, r);
	if (v < 0.0f || (u + v) > 1.0f)
	{

		return false;
	}
	*t = f * Math::dotProduct(e2, r);

	if (*t < 0)
	{
		return false;
	}

	return true;
}


