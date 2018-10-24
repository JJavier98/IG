
#include "extensor.h"

_extensor::_extensor()
{
	_paralel(0.5, 1.0);

	xt = -1.45;
	yt = 3.2;
	zt = 0.0;

	xr = 0.0;
	yr = 0.0;
	zr = 1.0;

	xs = 0.5;
	ys = 0.5;
	zs = 0.5;
}

void _extensor::draw_point_()
{
	glMatrixMode(GL_MODELVIEW);
	// extensor
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo3,xr,yr,zr);
	glScalef(xs,ys,zs);
	// punta
		punta.draw_point_();
	this->draw_point();
	glPopMatrix();
}

void _extensor::draw_line_()
{
	glMatrixMode(GL_MODELVIEW);
	// extensor
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo3,xr,yr,zr);
	glScalef(xs,ys,zs);
	// punta
		punta.draw_line_();
	this->draw_line();
	glPopMatrix();
}

void _extensor::draw_fill_()
{
	glMatrixMode(GL_MODELVIEW);
	// extensor
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo3,xr,yr,zr);
	glScalef(xs,ys,zs);
	// punta
		punta.draw_fill_();
	this->draw_fill();
	glPopMatrix();
}

void _extensor::draw_chess_()
{
	glMatrixMode(GL_MODELVIEW);
	// extensor
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo3,xr,yr,zr);
	glScalef(xs,ys,zs);
	// punta
		punta.draw_chess_();
	this->draw_chess();
	glPopMatrix();
}
