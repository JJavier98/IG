
#include "brazo.h"

_brazo::_brazo()
{
	Vertices.resize(2);

	Vertices[0]=_vertex3f(0.0,-0.1,0.0);
	Vertices[1]=_vertex3f(-1.0,-0.1,0.0);

	cylinder.load(Vertices, Triangles);
	cylinder.rotarArbitrario(1,0,0);
	cylinder.getData(Vertices, Triangles);

	xt = 0.0;
	yt = 0.9;
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
	// brazo
	glPushMatrix();
	glTranslatef(0.0,0.9,0.0);
	glRotatef(-45,0,0,1);
	(brazo1_n.obj).draw_point();
	glPopMatrix();
}

void _base::draw_line()
{
	brazo.draw_line();

	glMatrixMode(GL_MODELVIEW);
	// brazo
	glPushMatrix();
	glTranslatef(xs, ys, zs);
	obj.draw_line();
	glPopMatrix();
}

void _base::draw_fill()
{
	brazo.draw_fill();

	glMatrixMode(GL_MODELVIEW);
	// brazo
	glPushMatrix();
	glTranslatef(xs, ys, zs);
	obj.draw_fill();
	glPopMatrix();
}

void _base::draw_chess()
{
	brazo.draw_chess();

	glMatrixMode(GL_MODELVIEW);
	// brazo
	glPushMatrix();
	glTranslatef(xs, ys, zs);
	obj.draw_chess();
	glPopMatrix();
}
