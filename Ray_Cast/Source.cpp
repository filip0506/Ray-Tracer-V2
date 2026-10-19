#include <iostream>
#include <fstream>
#include "Vector.h"
#include "Shapes.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	const int width = 256;
	const int height = 256;
	const int nChannels = 3;

	
	Color red(255, 0, 0);
	Color blue(0, 0, 255);
	Color neonPurple(194, 14, 213);
	Color gray(220, 220, 220);

	float triCod = 500;

	Plane plane(Vector(0,0,2000), Vector(0, 0, 1),gray);
	Sphere sphere(Vector(width / 2,height / 2,100),55,blue);
	Box box(Vector(0.0f, 0.0f, 300), Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 1), width, height, red);
	Triangle triangle(Vector(256, 0,triCod), Vector(100, 128, triCod), Vector(100, 50, triCod), neonPurple);


	uint8_t* image = new uint8_t[width * height * nChannels];

	int index = 0;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) {

			Color currentPixelColor(0.0f, 0.0f, 0.0f);
			Ray ray(Vector(j, i, 0.0f), Vector(0.0f, 0.0f, 1.0f));

			float tMin = std::numeric_limits<float>::infinity();
			float t = 0.0f;

			if (plane.intersect(ray, &t) == true)
			{
				if (t < tMin && t > 0.0f)
				{
					currentPixelColor = plane.getColor();
					tMin = t;

				}
			}

			t = 0.0f;
			if (sphere.intersect(ray, &t) == true)
			{
				if (t < tMin && t > 0.0f)
				{
					currentPixelColor = sphere.getColor();
					tMin = t;

				}

			}

			t = 0.0f;
			if (triangle.intersect(ray, &t) == true)
			{
				if (t < tMin && t > 0.0f) 
				{
					currentPixelColor = triangle.getColor();
					tMin = t;

				}
			}

			t = 0.0f;
			if (box.intersect(ray, &t) == true)
			{
				if (t < tMin && t > 0.0f)
				{
					currentPixelColor = box.getColor();
					tMin = t;

				}
			}
			
			image[index++] = currentPixelColor.getRed();
			image[index++] = currentPixelColor.getGreen();
			image[index++] = currentPixelColor.getBlue();

		}
	}

	stbi_write_png("image.png", width, height, nChannels, image, width * nChannels);

	delete []image;
	image = nullptr;

	std::cout << "Done press enter" << std::endl;
	getchar();
	return 0;
}




