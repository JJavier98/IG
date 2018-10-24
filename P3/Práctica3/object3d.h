#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"

class _object3D:public _basic_object3D
{
public:

	vector<_vertex3ui> Triangles;

	void draw_line();
	void draw_fill();
	void draw_chess();

	_object3D();
	_object3D& operator = (const _object3D &p);
};

#endif // OBJECT3D_H
