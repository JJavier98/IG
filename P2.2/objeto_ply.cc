#include "objeto_ply.h"

_objectPLY::_objectPLY(){}

_objectPLY::_objectPLY(const vector<_vertex3f> & V, const vector<_vertex3ui> & T)
{
	this.Vertices = V;
	this.Triangles = T;
}

void _objectPLY::load(const vector<_vertex3f> & V, const vector<_vertex3ui> & T)
{
	this.Vertices = V;
	this.Triangles = T;
}