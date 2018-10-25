#ifndef BRAZO_1_H
#define BRAZO_1_H

#include "cylinder.h"
#include "object3d.h"
#include "objeto_ply.h"
#include "extensor.h"

class _brazo:public _object3D
{
private:
	_objectPLY cylinder;
	_extensor extensor;

	float xt, yt, zt;
	float xr, yr, zr;
	float xs, ys, zs;

	int angulo2;
	int velocidad;
public:
  	_brazo();

	void draw_point_();
	void draw_line_();
	void draw_fill_();
	void draw_chess_();

	void incrementar_desplazamiento_punta();
	void decrementar_desplazamiento_punta();

	void incrementar_inclinacion_extensor();
	void decrementar_inclinacion_extensor();

	void incrementar_inclinacion();
	void decrementar_inclinacion();

	void incrementar_velocidad();
	void decrementar_velocidad();

	void incrementar_velocidad_extensor();
	void decrementar_velocidad_extensor();
};

#endif
