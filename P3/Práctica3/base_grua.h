#ifndef BASE_H
#define BASE_H

#include "cylinder.h"
#include "tronco_grua.h"

class _base
{
protected:
	_cylinder cilindro;
	_tronco tronco;

	float xt, yt, zt;
	float xr, yr, zr;
	float xs, ys, zs;
public:
	_base();

	void draw_point_();
	void draw_line_();
	void draw_fill_();
	void draw_chess_();
};

#endif
