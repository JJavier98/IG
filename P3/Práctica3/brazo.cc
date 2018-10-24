
#include "brazo.h"

_brazo::_brazo()
{
	Vertices.resize(2);

	Vertices[0]=_vertex3f(0.0,-0.1,0.0);
	Vertices[1]=_vertex3f(-1.0,-0.1,0.0);

	cylinder.load(Vertices, Triangles);
	cylinder.rotarArbitrario(1,0,0);
	cylinder.getData(Vertices, Triangles);
}

void _brazo::draw_point_()
{
	glMatrixMode(GL_MODELVIEW);
	// brazo
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo2,xr,yr,zr);
	glScalef(xs,ys,zs);
	// extensor
		extensor.draw_point_();
	cylinder.draw_point();
	glPopMatrix();
}

void _brazo::draw_line_()
{
	glMatrixMode(GL_MODELVIEW);
	// brazo
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo2,xr,yr,zr);
	glScalef(xs,ys,zs);
	// extensor
		extensor.draw_line_();
	cylinder.draw_line();
	glPopMatrix();
}

void _brazo::draw_fill_()
{
	glMatrixMode(GL_MODELVIEW);
	// brazo
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo2,xr,yr,zr);
	glScalef(xs,ys,zs);
	// extensor
		extensor.draw_fill_();
	cylinder.draw_fill();
	glPopMatrix();
}

void _brazo::draw_chess_()
{
	glMatrixMode(GL_MODELVIEW);
	// brazo
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glRotatef(angulo2,xr,yr,zr);
	glScalef(xs,ys,zs);
	// extensor
		extensor.draw_chess_();
	cylinder.draw_chess();
	glPopMatrix();
}
