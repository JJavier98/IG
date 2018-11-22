#include "cuenco.h"
#include <math.h>

_cuenco::_cuenco(float R, float H)
{
	xt = 0.0;
	yt = 0.0;
	zt = 0.0;

	xr = 0.0;
	yr = 0.0;
	zr = 0.0;

	xs = 1.0;
	ys = 1.0;
	zs = 1.0;

	angulo1 = 0;
	velocidad = 1;

	for (float i = -M_PI/2+0.02; i < 0; i+=0.1)
	{
		Vertices.push_back(_vertex3f(cos(i)*R,sin(i)*H,0.0));
	}

	float newR = R-0.03;
	float newH = H-0.03;

	for (float i = 0; i > -M_PI/2; i-=0.1)
	{
		Vertices.push_back(_vertex3f(cos(i)*newR,sin(i)*newH,0.0));
	}
	this->rotarArbitrario(0,1,0,true,true,true,0);
	
   	calcularNormales();
}