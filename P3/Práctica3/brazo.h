#ifndef BRAZO_1_H
#define BRAZO_1_H

#include "cylinder.h"
#include "object3d.h"
#include "objeto_ply.h"

class _brazo:public _object3D
{
private:
	_objectPLY cylinder;
public:
   _brazo();
};

#endif
