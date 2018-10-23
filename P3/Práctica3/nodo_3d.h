#ifndef NODE_H
#define NODE_H

#include "object3d.h"

class _node3d:public _object3D
{
private:
public:
	_object3D obj;
	_node3d * hijo;

	_node3d();
	_node3d(const _object3D o, _node3d * h = NULL);
	_node3d& operator = (const _node3d &p);

	/*void draw_line();
	void draw_fill();
	void draw_chess();*/
};

#endif
