#ifndef TRONCO_H
#define TRONCO_H

#include "paralelepipedo.h"
#include "brazo.h"

class _tronco
{
protected:
	_paralel tronco;
	_brazo brazo;

	float xt, yt, zt;
	float xr, yr, zr;
	float xs, ys, zs;

	int angulo1 = 0;
public:
	_tronco();

	void draw_point_();
	void draw_line_();
	void draw_fill_();
	void draw_chess_();
};

#endif
