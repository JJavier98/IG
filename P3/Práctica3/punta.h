#ifndef PUNTA_H
#define PUNTA_H

#include "cylinder.h"
#include "object3d.h"
#include "objeto_ply.h"

class _punta:public _object3D
{
private:
	_objectPLY cylinder;

	float xt, yt, zt;
	float xr, yr, zr;
	float xs, ys, zs;

	int angulo3 = 0;
public:
	_punta();

	void draw_point_();
	void draw_line_();
	void draw_fill_();
	void draw_chess_();
};

#endif
