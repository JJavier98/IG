#ifndef TRONCO_H
#define TRONCO_H

#include "paralelepipedo.h"
#include "brazo.h"

class _tronco
{
protected:
	
	_brazo brazo;

	float xt, yt, zt;
	float xr, yr, zr;
	float xs, ys, zs;

	int angulo1;
	int velocidad;
public:
	_paralel tronco;
	_tronco();

	void draw_point_();
	void draw_line_();
	void draw_fill_();
	void draw_chess_();

	void incrementar_desplazamiento_punta();
	void decrementar_desplazamiento_punta();

	void incrementar_inclinacion_extensor();
	void decrementar_inclinacion_extensor();

	void incrementar_inclinacion_brazo();
	void decrementar_inclinacion_brazo();

	void incrementar_rotacion();
	void decrementar_rotacion();

	void incrementar_velocidad();
	void decrementar_velocidad();

	void incrementar_velocidad_extensor();
	void decrementar_velocidad_extensor();

	void incrementar_velocidad_brazo();
	void decrementar_velocidad_brazo();
};

#endif
