#ifndef GRUA_H
#define GRUA_H

#include "nodo_3d.h"
#include "base_grua.h"
#include "tronco_grua.h"
#include "brazo.h"
#include "extensor.h"

class _grua:public _node3d
{
private:
	void rotarArbitrario(float ux, float uy, float uz);
protected:
	_node3d base_n;
	_node3d tronco_n;
	_node3d brazo1_n;
	_node3d brazo2_n;
	_node3d brazo3_n;
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
