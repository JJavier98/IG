
#include "brazo.h"

_brazo::_brazo()
{
	Vertices.resize(2);

	Vertices[0]=_vertex3f(0.0,-0.1,0.0);
	Vertices[1]=_vertex3f(-1.0,-0.1,0.0);

	cylinder.load(Vertices, Triangles);
	cylinder.rotarArbitrario(1,0,0);
	cylinder.getData(Vertices, Triangles);
}
