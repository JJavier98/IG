
#include "extensor.h"

_extensor::_extensor()
{
	_punta punta;
	_paralel extend;

	add_hijo(punta);

	Vertices = extend.Vertices;
	Triangles = extend.Triangles;

	xt = -1.0;
	yt = 0.0;
	zt = 0.0;

	xr = 0.0;
	yr = 0.0;
	zr = 1.0;

	xs = 0.5;
	ys = 0.5;
	zs = 0.5;

	angulo1 = 180;
	velocidad = 1.0;

	limiteInclinacion1 = 238;
	limiteInclinacion2 = -55;
	
   	calcularNormales();
   asignarIdentificadores();
}

