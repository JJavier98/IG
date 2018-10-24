#ifndef BRAZO_1_H
#define BRAZO_1_H

#include "cylinder.h"
#include "object3d.h"
#include "objeto_ply.h"

class _brazo:public _object3D
{
private:
	_objectPLY cylinder;

	float xt, yt, zt;
	float xr, yr, zr;
	float xs, ys, zs;
public:
   _brazo();

	void draw_point();
	void draw_line();
	void draw_fill();
	void draw_chess();
};

#endif
