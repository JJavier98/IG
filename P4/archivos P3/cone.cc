#include "cone.h"

_cone::_cone(float Size)
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
	

	Vertices.push_back(_vertex3f(0.0,Size,0.0));
	Vertices.push_back(_vertex3f(Size/2,0.0,0.0));

	rotarArbitrario(0,1,0);
	
   	calcularNormales();
}
