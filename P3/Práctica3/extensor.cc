
#include "extensor.h"

_extensor::_extensor()
{
	xt = -1.0;
	yt = 0.0;
	zt = 0.0;

	xr = 0.0;
	yr = 0.0;
	zr = 1.0;

	xs = 0.5;
	ys = 0.5;
	zs = 0.5;

	angulo3 = 180;
	velocidad = 1.0;
}


void _extensor::incrementar_desplazamiento_punta()
{
	punta.incrementar_desplazamiento();
}
void _extensor::decrementar_desplazamiento_punta()
{
	punta.decrementar_desplazamiento();
}

void _extensor::incrementar_inclinacion()
{
	if(angulo3 + velocidad < 245)
		angulo3 += velocidad;
	else
		angulo3 = 245;
}
void _extensor::decrementar_inclinacion()
{
	if(angulo3 - velocidad > -64)
		angulo3 -= velocidad;
	else
		angulo3 = -64;
}

void _extensor::incrementar_velocidad()
{
	velocidad += 1;
}
void _extensor::decrementar_velocidad()
{
	if(velocidad > 1)
		velocidad -= 1;
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
	extend.draw_point();
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
	extend.draw_line();
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
	extend.draw_fill();
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
	extend.draw_chess();
	glPopMatrix();
}
