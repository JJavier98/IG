#include "cylinder.h"

_cylinder::_cylinder(float R, float H)
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
	
	Vertices.resize(2);

	Vertices[0]=_vertex3f(R,0.0,0.0);
	Vertices[1]=_vertex3f(R,H,0.0);

	rotarArbitrario(0,1,0);
	
   	calcularNormales();
}
