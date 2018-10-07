#include "cone.h"

_cone::_cone(float Size)
{
   Vertices.resize(2);

   Vertices[0]=_vertex3f(Size/2,0.0,0.0);
   Vertices[1]=_vertex3f(0.0,Size,0.0);

   cone.load(Vertices, Triangles);
   cone.rotarArbitrario(0,1,0);
   cone.getData(Vertices, Triangles);
}
