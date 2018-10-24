
#include "punta.h"

_punta::_punta()
{
	Vertices.resize(2);

	Vertices[0]=_vertex3f(0.0,-0.1,0.0);
	Vertices[1]=_vertex3f(-1.0,-0.1,0.0);

	cylinder.load(Vertices, Triangles);
	cylinder.rotarArbitrario(1,0,0);
	cylinder.getData(Vertices, Triangles);

	xt = -0.825;
	yt = 1.5;
	zt = 0.0;

	xr = 0.0;
	yr = 0.0;
	zr = 1.0;

	xs = 0.6;
	ys = 0.5;
	zs = 0.5;
}

void _punta::draw_point_()
{
	glMatrixMode(GL_MODELVIEW);
	// punta
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo3,xr,yr,zr);
	glScalef(xs,ys,zs);
	this->draw_point();
	glPopMatrix();
}

void _punta::draw_line_()
{
	glMatrixMode(GL_MODELVIEW);
	// punta
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo3,xr,yr,zr);
	glScalef(xs,ys,zs);
	this->draw_line();
	glPopMatrix();
}

void _punta::draw_fill_()
{
	glMatrixMode(GL_MODELVIEW);
	// punta
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo3,xr,yr,zr);
	glScalef(xs,ys,zs);
	this->draw_fill();
	glPopMatrix();
}

void _punta::draw_chess_()
{
	glMatrixMode(GL_MODELVIEW);
	// punta
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo3,xr,yr,zr);
	glScalef(xs,ys,zs);
	this->draw_chess();
	glPopMatrix();
}
