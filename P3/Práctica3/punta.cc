
#include "punta.h"
#include <iostream>

using namespace std;

_punta::_punta()
{
	Vertices.resize(2);

	Vertices[0]=_vertex3f(0.0,-0.1,0.0);
	Vertices[1]=_vertex3f(-1.0,-0.1,0.0);

	cylinder.load(Vertices, Triangles);
	cylinder.rotarArbitrario(1,0,0);
	cylinder.getData(Vertices, Triangles);

	xt = 0.0;
	yt = 1.0;
	zt = 0.0;

	xr = 0.0;
	yr = 0.0;
	zr = 1.0;

	xs = 1.0;
	ys = 0.5;
	zs = 0.5;

	desplazamiento = 0;
}


void _punta::incrementar_desplazamiento()
{
	 

	// DISPARAR

		if(desplazamiento < 5)
		desplazamiento += 0.5;
	else
		desplazamiento = -0.9;
	

	// PUNTA

	/*if(desplazamiento < 0)
		desplazamiento += 0.05;
		*/
}
void _punta::decrementar_desplazamiento()
{
	

	// DISPARAR

	if(desplazamiento - 0.5 > -0.9)
		desplazamiento -= 0.5;
	else
		desplazamiento = -0.9;
	

	// PUNTA

	/*if(desplazamiento - 0.05 > -1)
		desplazamiento -= 0.05;
	else
		desplazamiento = -1;
*/
}

void _punta::draw_point_()
{
	glMatrixMode(GL_MODELVIEW);
	// punta
	glPushMatrix();
	glTranslatef(xt, yt+desplazamiento, zt);
	glRotatef(-90,xr,yr,zr);
	glScalef(xs,ys,zs);
	cylinder.draw_point();
	glPopMatrix();
}

void _punta::draw_line_()
{
	glMatrixMode(GL_MODELVIEW);
	// punta
	glPushMatrix();
	glTranslatef(xt, yt+desplazamiento, zt);
	glRotatef(-90,xr,yr,zr);
	glScalef(xs,ys,zs);
	cylinder.draw_line();
	glPopMatrix();
}

void _punta::draw_fill_()
{
	glMatrixMode(GL_MODELVIEW);
	// punta
	glPushMatrix();
	glTranslatef(xt, yt+desplazamiento, zt);
	glRotatef(-90,xr,yr,zr);
	glScalef(xs,ys,zs);
	cylinder.draw_fill();
	glPopMatrix();
}

void _punta::draw_chess_()
{
	glMatrixMode(GL_MODELVIEW);
	// punta
	glPushMatrix();
	glTranslatef(xt, yt+desplazamiento, zt);
	glRotatef(-90,xr,yr,zr);
	glScalef(xs,ys,zs);
	cylinder.draw_chess();
	glPopMatrix();
}
