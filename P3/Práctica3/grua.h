#ifndef GRUA_H
#define GRUA_H

#include "nodo_3d.h"
#include "base_grua.h"
#include "brazo.h"
#include "extensor.h"
#include <cmath>

class _grua
{
protected:
	_base base;
public:
	_grua();

	void draw_point();
	void draw_line();
	void draw_fill();
	void draw_chess();

	void rotar_tronco();
	void mover_brazo1();
	void deslizar_brazo3();
};

#endif
