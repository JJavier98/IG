#include "cylinder.h"

_cylinder::_cylinder(float Size)
{
   Vertices.resize(2);

   Vertices[0]=_vertex3f(Size/2,-Size/2,0.0);
   Vertices[1]=_vertex3f(Size/2,Size/2,0.0);

   cylinder.load(Vertices, Triangles);
   cylinder.rotarArbitrario(0,1,0);
   cylinder.getData(Vertices, Triangles);
}
