
#include "tronco_grua.h"

_tronco::_tronco()
{
	
	_paralel tronco(0.5,1);
	_brazo brazo;

	Vertices = tronco.Vertices;
	Triangles = tronco.Triangles;

	add_hijo(brazo);

	xt = 0.0;
	yt = 1;
	zt = 0.0;

	xr = 0.0;
	yr = 1.0;
	zr = 0.0;

	xs = 1.0;
	ys = 6;
	zs = 1.0;

	angulo1 = 0;
	velocidad = 1;
	
   	calcularNormales();
}