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

void _base::incrementar_desplazamiento_punta()
{
	tronco.incrementar_desplazamiento_punta();
}
void _base::decrementar_desplazamiento_punta()
{
	tronco.decrementar_desplazamiento_punta();
}


void _base::incrementar_inclinacion_extensor()
{
	tronco.incrementar_inclinacion_extensor();
}
void _base::decrementar_inclinacion_extensor()
{
	tronco.decrementar_inclinacion_extensor();
}

void _base::incrementar_inclinacion_brazo()
{
	tronco.incrementar_inclinacion_brazo();
}
void _base::decrementar_inclinacion_brazo()
{
	tronco.decrementar_inclinacion_brazo();
}

void _base::incrementar_rotacion_tronco()
{
	tronco.incrementar_rotacion();
}
void _base::decrementar_rotacion_tronco()
{
	tronco.decrementar_rotacion();
}

void _base::incrementar_velocidad_extensor()
{
	tronco.incrementar_velocidad_extensor();
}
void _base::decrementar_velocidad_extensor()
{
	tronco.decrementar_velocidad_extensor();
}

void _base::incrementar_velocidad_brazo()
{
	tronco.incrementar_velocidad_brazo();
}
void _base::decrementar_velocidad_brazo()
{
	tronco.decrementar_velocidad_brazo();
}

void _base::incrementar_velocidad_tronco()
{
	tronco.incrementar_velocidad();
}
void _base::decrementar_velocidad_tronco()
{
	tronco.decrementar_velocidad();
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
	tronco.draw_line_();

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
	tronco.draw_fill_();

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
	tronco.draw_chess_();

	glMatrixMode(GL_MODELVIEW);
	// base
	glPushMatrix();
	glScalef(xs, ys, zs);		
	cilindro.draw_chess();
	glPopMatrix();
}
