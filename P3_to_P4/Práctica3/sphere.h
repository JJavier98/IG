#ifndef SPHERE_H
#define SPHERE_H

#include "node.h"
#include "objeto_ply.h"

class _sphere:public _node
{
private:
	_objectPLY sphere;
public:
   _sphere(float Size=1.0);
};

#endif
