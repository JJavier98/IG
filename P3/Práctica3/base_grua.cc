#include "base_grua.h"

_base::_base()
{
	_cylinder();
	xt = 0.0;
	yt = 0.0;
	zt = 0.0;

	xr = 1.0;
	yr = 1.0;
	zr = 1.0;

	xs = 1.5;
	ys = 0.2;
	zs = 1.5;
}

void _base::draw_point()
{
	tronco.draw_point();

	glMatrixMode(GL_MODELVIEW);
	// base
	glPushMatrix();
	glScalef(xs, ys, zs);
	obj.draw_point();
	glPopMatrix();
}

void _base::draw_line()
{
	tronco.draw_line();

	glMatrixMode(GL_MODELVIEW);
	// base
	glPushMatrix();
	glScalef(xs, ys, zs);
	obj.draw_line();
	glPopMatrix();
}

void _base::draw_fill()
{
	tronco.draw_fill();

	glMatrixMode(GL_MODELVIEW);
	// base
	glPushMatrix();
	glScalef(xs, ys, zs);
	obj.draw_fill();
	glPopMatrix();
}

void _base::draw_chess()
{
	tronco.draw_chess();

	glMatrixMode(GL_MODELVIEW);
	// base
	glPushMatrix();
	glScalef(xs, ys, zs);
	obj.draw_chess();
	glPopMatrix();
}
