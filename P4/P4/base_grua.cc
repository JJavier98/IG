#include "base_grua.h"

_base::_base()
{
	
	_cylinder cilindro;
	_tronco tronco;

	Vertices = cilindro.Vertices;
	Triangles = cilindro.Triangles;

	add_hijo(tronco);

	xt = 0.0;
	yt = 0.0;
	zt = 0.0;

	xr = 0.0;
	yr = 0.0;
	zr = 0.0;

	xs = 1.5;
	ys = 0.2;
	zs = 1.5;
	
   	calcularNormales();
}