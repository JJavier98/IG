#ifndef CYLINDER_H
#define CYLINDER_H

#include "object3d.h"
#include "objeto_ply.h"

class _cylinder:public _object3D
{
private:
	_objectPLY cylinder;
public:
   _cylinder(float R=0.5, float H=1.0);
};

#endif
