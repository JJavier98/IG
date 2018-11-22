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
	
	for (float i = M_PI/2-0.05; i > -M_PI/2+0.05; i-=0.1)
	{
		Vertices.push_back(_vertex3f(cos(i)*Size,sin(i)*Size,0.0));
	}

	rotarArbitrario(0,1,0);

   	calcularNormales();
}
