#ifndef GRUA_H
#define GRUA_H

#include "base_grua.h"
#include "brazo.h"
#include "extensor.h"
#include <chrono>
#include <cmath>
#include "node.h"

using std::chrono::system_clock;

class _grua:public _node
{
protected:
	system_clock::time_point momento1 = system_clock::now(),
							 momento2 = system_clock::now(),
							 momento3 = system_clock::now();


	bool cambio1 = false,
		 cambio2 = false,
		 cambio3 = false;
public:
	_grua();

	void incrementar_desplazamiento_punta();
	void decrementar_desplazamiento_punta();
	
	void incrementar_inclinacion_extensor();
	void decrementar_inclinacion_extensor();

	void incrementar_inclinacion_brazo();
	void decrementar_inclinacion_brazo();

	void incrementar_rotacion_tronco();
	void decrementar_rotacion_tronco();
	
	void incrementar_velocidad_extensor();
	void decrementar_velocidad_extensor();
	
	void incrementar_velocidad_brazo();
	void decrementar_velocidad_brazo();

	void incrementar_velocidad_tronco();
	void decrementar_velocidad_tronco();

	void funcion_idle();
};

#endif
