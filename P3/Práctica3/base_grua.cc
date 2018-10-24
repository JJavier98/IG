#include "base_grua.h"

_base::_base()
{
	_cylinder();
	xt = 0.0;
	yt = 0.0;
	zt = 0.0;

	xr = 0.0;
	yr = 0.0;
	zr = 0.0;

	xs = 1.5;
	ys = 0.2;
	zs = 1.5;
}

void _base::draw_point_()
{
	// tronco
	tronco.draw_point_();

	glMatrixMode(GL_MODELVIEW);
	// base
	glPushMatrix();
	glScalef(xs, ys, zs);		
	cilindro.draw_point();
	glPopMatrix();
}

void _base::draw_line_()
{
	// tronco
	tronco.draw_point_();

	glMatrixMode(GL_MODELVIEW);
	// base
	glPushMatrix();
	glScalef(xs, ys, zs);		
	cilindro.draw_line();
	glPopMatrix();
}

void _base::draw_fill_()
{
	// tronco
	tronco.draw_point_();

	glMatrixMode(GL_MODELVIEW);
	// base
	glPushMatrix();
	glScalef(xs, ys, zs);		
	cilindro.draw_fill();
	glPopMatrix();
}

void _base::draw_chess_()
{
	// tronco
	tronco.draw_point_();

	glMatrixMode(GL_MODELVIEW);
	// base
	glPushMatrix();
	glScalef(xs, ys, zs);		
	cilindro.draw_chess();
	glPopMatrix();
}
