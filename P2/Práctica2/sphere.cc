#include "sphere.h"
#include <math.h>

_sphere::_sphere(float Size)
{
	float x, y;
	for (float i = -1; i <= 1; i+=0.01)
	{
		y = i;
		x = sqrt(Size-y*y);
		Vertices.push_back(_vertex3f(x,y,0.0));
	}

	sphere.load(Vertices, Triangles);
	sphere.rotarArbitrario(0,1,0);
	sphere.getData(Vertices, Triangles);
}
