#ifndef BRAZO_1_H
#define BRAZO_1_H

#include "cylinder.h"
#include "object3d.h"
#include "objeto_ply.h"
#include "extensor.h"

class _brazo:public _object3D
{
private:
	_objectPLY cylinder;
	_extensor extensor;

	float xt, yt, zt;
	float xr, yr, zr;
	float xs, ys, zs;

	int angulo2 = 0;
public:
  	_brazo();

	void draw_point_();
	void draw_line_();
	void draw_fill_();
	void draw_chess_();
};

#endif
