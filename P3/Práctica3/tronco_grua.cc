
#include "tronco_grua.h"

_tronco::_tronco()
{
	_paralel(0.5, 1.0);
	xt = 0.0;
	yt = 0.1;
	zt = 0.0;

	xr = 0.0;
	yr = 1.0;
	zr = 0.0;

	xs = 1.0;
	ys = 1.0;
	zs = 1.0;
}

void _tronco::draw_point_()
{
	glMatrixMode(GL_MODELVIEW);
	// tronco
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo1,xr,yr,zr);
	glScalef(xs,ys,zs);
	//brazo
		brazo.draw_point_();
	tronco.draw_point();
	glPopMatrix();
}

void _tronco::draw_line_()
{
	glMatrixMode(GL_MODELVIEW);
	// tronco
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo1,xr,yr,zr);
	glScalef(xs,ys,zs);
	//brazo
		brazo.draw_line_();
	tronco.draw_line();
	glPopMatrix();
}

void _tronco::draw_fill_()
{
	glMatrixMode(GL_MODELVIEW);
	// tronco
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo1,xr,yr,zr);
	glScalef(xs,ys,zs);
	//brazo
		brazo.draw_fill_();
	tronco.draw_fill();
	glPopMatrix();
}

void _tronco::draw_chess_()
{
	glMatrixMode(GL_MODELVIEW);
	// tronco
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo1,xr,yr,zr);
	glScalef(xs,ys,zs);
	//brazo
		brazo.draw_chess_();
	tronco.draw_chess();
	glPopMatrix();
}
