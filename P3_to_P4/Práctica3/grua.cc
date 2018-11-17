#include "grua.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <chrono>

using namespace std;

_grua::_grua()
{
	_base base;
	add_hijo(base);
}

void _grua::incrementar_desplazamiento_punta()
{
	hijos[0].hijos[0].hijos[0].hijos[0].hijos[0].incrementar_desplazamiento_y();
}
void _grua::decrementar_desplazamiento_punta()
{
	hijos[0].hijos[0].hijos[0].hijos[0].hijos[0].decrementar_desplazamiento_y();
}

void _grua::incrementar_inclinacion_extensor()
{
	hijos[0].hijos[0].hijos[0].hijos[0].incrementar_inclinacion();
}
void _grua::decrementar_inclinacion_extensor()
{
	hijos[0].hijos[0].hijos[0].hijos[0].decrementar_inclinacion();
}

void _grua::incrementar_inclinacion_brazo()
{
	hijos[0].hijos[0].hijos[0].incrementar_inclinacion();
}
void _grua::decrementar_inclinacion_brazo()
{
	hijos[0].hijos[0].hijos[0].decrementar_inclinacion();
}

void _grua::incrementar_rotacion_tronco()
{
	hijos[0].hijos[0].incrementar_rotacion();
}
void _grua::decrementar_rotacion_tronco()
{
	hijos[0].hijos[0].decrementar_rotacion();
}

void _grua::incrementar_velocidad_extensor()
{
	hijos[0].hijos[0].hijos[0].hijos[0].incrementar_velocidad();
}
void _grua::decrementar_velocidad_extensor()
{
	hijos[0].hijos[0].hijos[0].hijos[0].decrementar_velocidad();
}

void _grua::incrementar_velocidad_brazo()
{
	hijos[0].hijos[0].hijos[0].incrementar_velocidad();
}
void _grua::decrementar_velocidad_brazo()
{
	hijos[0].hijos[0].hijos[0].decrementar_velocidad();
}

void _grua::incrementar_velocidad_tronco()
{
	//base.incrementar_velocidad_tronco();
}
void _grua::decrementar_velocidad_tronco()
{
	//base.decrementar_velocidad_tronco();
}
/*
void _grua::funcion_idle()
{
	using namespace std::chrono;

	system_clock::duration t1 (duration<int>(2));
	system_clock::duration t2 (duration<int>(5));
	system_clock::duration t3 (duration<int>(5));
	system_clock::time_point ahora = system_clock::now();

	if(t1 <= ahora - momento1)
	{
		momento1 = ahora;
		cambio1 = !cambio1;
	}

	if(t2 <= ahora - momento2)
	{
		momento2 = ahora;
		cambio2 = !cambio2;
	}

	if(t3 <= ahora - momento3)
	{
		momento3 = ahora;
		cambio3 = !cambio3;
	}

	if(cambio1)
		incrementar_inclinacion_extensor();
	else
		decrementar_inclinacion_extensor();

	if(cambio2)
		incrementar_inclinacion_brazo();
	else
		decrementar_inclinacion_brazo();

	if(cambio3)
		incrementar_rotacion_tronco();
	else
		decrementar_rotacion_tronco();

	// DISPARA
	incrementar_desplazamiento_punta();

	// PUNTA
	
	if(cambio1)
		incrementar_desplazamiento_punta();
	else
		decrementar_desplazamiento_punta();
	
	
	glutPostRedisplay();
}*/