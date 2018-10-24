#ifndef EXTENSOR_H
#define EXTENSOR_H

#include "paralelepipedo.h"
#include "punta.h"

class _extensor:public _paralel
{
private:
	_punta punta;

	float xt, yt, zt;
	float xr, yr, zr;
	float xs, ys, zs;

	int angulo3 = 0;
public:
	_extensor();

	void draw_point_();
	void draw_line_();
	void draw_fill_();
	void draw_chess_();
};

#endif
