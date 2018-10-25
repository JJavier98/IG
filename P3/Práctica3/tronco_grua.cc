
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

	angulo1 = 0;
	velocidad = 1;
}

void _tronco::incrementar_desplazamiento_punta()
{
	brazo.incrementar_desplazamiento_punta();
}
void _tronco::decrementar_desplazamiento_punta()
{
	brazo.decrementar_desplazamiento_punta();
}

void _tronco::incrementar_inclinacion_extensor()
{
	brazo.incrementar_inclinacion_extensor();
}
void _tronco::decrementar_inclinacion_extensor()
{
	brazo.decrementar_inclinacion_extensor();
}

void _tronco::incrementar_inclinacion_brazo()
{
	brazo.incrementar_inclinacion();
}
void _tronco::decrementar_inclinacion_brazo()
{
	brazo.decrementar_inclinacion();
}

void _tronco::incrementar_rotacion()
{
	angulo1 += velocidad;
}
void _tronco::decrementar_rotacion()
{
	angulo1 -= velocidad;
}

void _tronco::incrementar_velocidad_extensor()
{
	brazo.incrementar_velocidad_extensor();
}
void _tronco::decrementar_velocidad_extensor()
{
	brazo.decrementar_velocidad_extensor();
}

void _tronco::incrementar_velocidad_brazo()
{
	brazo.incrementar_velocidad();
}
void _tronco::decrementar_velocidad_brazo()
{
	brazo.decrementar_velocidad();
}

void _tronco::incrementar_velocidad()
{
	velocidad += 1;
}
void _tronco::decrementar_velocidad()
{
	if(velocidad > 1)
		velocidad -= 1;
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
