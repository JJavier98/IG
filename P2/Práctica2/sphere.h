#ifndef SPHERE_H
#define SPHERE_H

#include "object3d.h"
#include "objeto_ply.h"

class _sphere:public _object3D
{
private:
	_objectPLY sphere;
public:
   _sphere(float Size=1.0);
};

#endif
