#ifndef TRONCO_H
#define TRONCO_H

#include "paralelepipedo.h"
#include "brazo.h"

class _tronco:public _paralel
{
protected:
	_brazo brazo;

	float xt, yt, zt;
	float xr, yr, zr;
	float xs, ys, zs;

	int angulo = 0;
public:
	_tronco();

	void draw_point();
	void draw_line();
	void draw_fill();
	void draw_chess();
};

#endif
