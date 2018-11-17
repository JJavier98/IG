#ifndef CONE_H
#define CONE_H

#include "node.h"
#include "objeto_ply.h"

class _cone:public _node
{
private:
	_objectPLY cone;
public:
   _cone(float Size=1.0);
};

#endif
