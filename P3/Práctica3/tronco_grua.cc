
#include "tronco_grua.h"

_tronco::_tronco()
{
	_paralel(0.5, 1.0);
	xt = 0.0;
	yt = 0.1;
	zt = 0.0;

	xr = 1.0;
	yr = 1.0;
	zr = 1.0;

	xs = 1.0;
	ys = 1.0;
	zs = 1.0;
}

void _base::draw_point()
{
	brazo.draw_point();

	glMatrixMode(GL_MODELVIEW);
	// tronco
	glPushMatrix();
	glTranslatef(xs, ys, zs);
	obj.draw_point();
	glPopMatrix();
}

void _base::draw_line()
{
	brazo.draw_line();

	glMatrixMode(GL_MODELVIEW);
	// tronco
	glPushMatrix();
	glTranslatef(xs, ys, zs);
	obj.draw_line();
	glPopMatrix();
}

void _base::draw_fill()
{
	brazo.draw_fill();

	glMatrixMode(GL_MODELVIEW);
	// tronco
	glPushMatrix();
	glTranslatef(xs, ys, zs);
	obj.draw_fill();
	glPopMatrix();
}

void _base::draw_chess()
{
	brazo.draw_chess();

	glMatrixMode(GL_MODELVIEW);
	// tronco
	glPushMatrix();
	glTranslatef(xs, ys, zs);
	obj.draw_chess();
	glPopMatrix();
}
