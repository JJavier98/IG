/*
 * Practicas de IG
 * Domingo Martin Perandres© 2014-2018
 * dmartin@ugr.es
 *
 * GPL 3
 */

#ifndef AXIS_H
#define AXIS_H

#include "node.h"

namespace _axis_ne {

   const float DEFAULT_AXIS_SIZE=5000;
}

class _axis:public _node
{
public:
   _axis(float Size=_axis_ne::DEFAULT_AXIS_SIZE);

   void draw_line();
};

#endif
