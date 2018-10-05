#ifndef OBJECT_PLY
#define OBJECT_PLY

#include "file_ply_stl.h"
#include "object3d.h"
#include "basic_object3d.h"

class _objectPLY:public _object3D
{
public:
	_objectPLY();
	_objectPLY(const vector<_vertex3f> & V, const vector<_vertex3ui> & T);
	void load(const vector<_vertex3f> & V, const vector<_vertex3ui> & T);
};

#endif // OBJECT_PLY
