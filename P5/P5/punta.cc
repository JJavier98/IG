
#include "punta.h"
#include <iostream>

using namespace std;

_punta::_punta()
{
	Vertices.resize(2);

	Vertices[0]=_vertex3f(0.0,-0.1,0.0);
	Vertices[1]=_vertex3f(-1.0,-0.1,0.0);

	rotarArbitrario(1,0,0);

	xt = 0.0;
	yt = 1.0;
	zt = 0.0;

	xr = 0.0;
	yr = 0.0;
	zr = 1.0;

	xs = 1.0;
	ys = 0.5;
	zs = 0.5;

	desplazamiento_y = 0;
	angulo1 = -90;


	limiteDesplazamientoY_1 = 5;

	limiteDesplazamientoY_2 = -0.9;
	
   	calcularNormales();
   	
   asignarIdentificadores();
}