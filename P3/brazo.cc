
#include "brazo.h"
#include <iostream>

using namespace std;

_brazo::_brazo()
{
	_extensor extensor;

	add_hijo(extensor);

	Vertices.resize(2);

	Vertices[0]=_vertex3f(0.0,-0.1,0.0);
	Vertices[1]=_vertex3f(-1.0,-0.1,0.0);

	rotarArbitrario(1,0,0);

	xt = 0.0;
	yt = 0.9;
	zt = 0.0;

	xr = 0.0;
	yr = 0.0;
	zr = 1.0;

	xs = 1.0;
	ys = 1.0;
	zs = 1.0;

	angulo1 = -45;
	velocidad = 1;

	limiteInclinacion1 = 31;
	limiteInclinacion2 = -211;
}
