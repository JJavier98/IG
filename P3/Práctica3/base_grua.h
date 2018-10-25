#ifndef BASE_H
#define BASE_H

#include "cylinder.h"
#include "tronco_grua.h"

class _base
{
protected:
	_cylinder cilindro;
	_tronco tronco;

	float xt, yt, zt;
	float xr, yr, zr;
	float xs, ys, zs;
public:
	_base();

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

	void incrementar_rotacion_tronco();
	void decrementar_rotacion_tronco();

	void incrementar_velocidad_extensor();
	void decrementar_velocidad_extensor();
	
	void incrementar_velocidad_brazo();
	void decrementar_velocidad_brazo();

	void incrementar_velocidad_tronco();
	void decrementar_velocidad_tronco();
};

#endif
