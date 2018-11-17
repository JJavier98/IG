#ifndef CUERPO_TORO_H
#define CUERPO_TORO_H

#include "piernas_toro.h"
#include "cabeza_toro.h"
#include "paralelepipedo.h"
#include "toro.h"
#include <cmath>
#include "node.h"


class _cuerpo_toro:public _node
{
public:
	_cuerpo_toro(float W = 1.5, float H = 0.5);

};

#endif
