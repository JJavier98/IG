#include "objeto_ply.h"

_objectPLY::_objectPLY(){}

_objectPLY::_objectPLY(const vector<_vertex3f> & V, const vector<_vertex3ui> & T)
{
	Vertices = V;
	Triangles = T;
}

void _objectPLY::load(const vector<_vertex3f> & V, const vector<_vertex3ui> & T)
{
	Vertices = V;
	Triangles = T;
}