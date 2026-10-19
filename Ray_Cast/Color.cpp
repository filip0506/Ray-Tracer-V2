#include "Color.h"

Color::Color()
{
	r = 0;
	g = 0;
	b = 0;
}

Color::Color(float i, float j, float k)
{
	r = i;
	g = j;
	b = k;
}

float Color::getRed()
{
	return r;
}

float Color::getGreen()
{
	return g;
}

float Color::getBlue()
{
	return b;
}