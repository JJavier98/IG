#include "sphere.h"
#include <math.h>

_sphere::_sphere(float Size)
{
	xt = 0.0;
	yt = 0.1;
	zt = 0.0;

	xr = 0.0;
	yr = 1.0;
	zr = 0.0;

	xs = 1.0;
	ys = 1.0;
	zs = 1.0;

	angulo1 = 0;
	velocidad = 1;
	
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
