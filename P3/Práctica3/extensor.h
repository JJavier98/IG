#ifndef EXTENSOR_H
#define EXTENSOR_H

#include "paralelepipedo.h"
#include "punta.h"

class _extensor
{
private:
	_punta punta;
	_paralel extend;

	float xt, yt, zt;
	float xr, yr, zr;
	float xs, ys, zs;

	int angulo3;
	int velocidad;
public:
	_extensor();

	void draw_point_();
	void draw_line_();
	void draw_fill_();
	void draw_chess_();

	void incrementar_desplazamiento_punta();
	void decrementar_desplazamiento_punta();

	void incrementar_inclinacion();
	void decrementar_inclinacion();

	void incrementar_velocidad();
	void decrementar_velocidad();
};

#endif
