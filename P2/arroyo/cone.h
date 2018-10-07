#ifndef CONE_H
#define CONE_H

#include "object3d.h"
#include "objeto_ply.h"

class _cone:public _object3D
{
private:
	_objectPLY cone;
public:
   _cone(float Size=1.0);
};

#endif
