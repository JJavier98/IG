
#include "brazo.h"
#include <iostream>

using namespace std;

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

	xr = 0.0;
	yr = 0.0;
	zr = 1.0;

	xs = 1.0;
	ys = 1.0;
	zs = 1.0;

	angulo2 = -45;
	velocidad = 1;
}

void _brazo::incrementar_desplazamiento_punta()
{
	extensor.incrementar_desplazamiento_punta();
}
void _brazo::decrementar_desplazamiento_punta()
{
	extensor.decrementar_desplazamiento_punta();
}

void _brazo::incrementar_inclinacion_extensor()
{
	extensor.incrementar_inclinacion();
}
void _brazo::decrementar_inclinacion_extensor()
{
	extensor.decrementar_inclinacion();
}

void _brazo::incrementar_inclinacion()
{
	if(angulo2 + velocidad < 31)
		angulo2 += velocidad;
	else
		angulo2 = 31;
}
void _brazo::decrementar_inclinacion()
{
	if(angulo2 - velocidad > -211)
		angulo2 -= velocidad;
	else
		angulo2 = -211;
}

void _brazo::incrementar_velocidad_extensor()
{
	extensor.incrementar_velocidad();
}
void _brazo::decrementar_velocidad_extensor()
{
	extensor.decrementar_velocidad();
}

void _brazo::incrementar_velocidad()
{
	velocidad += 1;
}
void _brazo::decrementar_velocidad()
{
	if(velocidad > 1)
		velocidad -= 1;
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
