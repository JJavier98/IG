#ifndef BASE_H
#define BASE_H

#include "cylinder.h"
#include "tronco_grua.h"

class _base:public _cylinder
{
protected:
	_tronco tronco;

	float xt, yt, zt;
	float xr, yr, zr;
	float xs, ys, zs;
public:
	_base();

	void draw_point();
	void draw_line();
	void draw_fill();
	void draw_chess();
};

#endif
