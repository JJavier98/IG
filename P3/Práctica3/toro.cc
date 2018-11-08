#include "toro.h"
#include "cuerpo_toro.h"
#include "piernas_toro.h"
#include "cabeza_toro.h"
#include "node.h"

_toro::_toro()
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

	_cuerpo_toro cuerpo;

	add_hijo(cuerpo);
}
