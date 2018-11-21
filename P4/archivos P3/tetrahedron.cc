/*
 * Practicas de IG
 * Domingo Martin Perandres© 2014-2018
 * dmartin@ugr.es
 *
 * GPL 3
 */

#include "tetrahedron.h"

/**
 *
 *@param
 *@returns
 */

_tetrahedron::_tetrahedron(float Size)
{
   xt = 0.0;
   yt = 0.1;
   zt = 0.0;

   xr = 0.0;
   yr = 1.0;
   zr = 0.0;

   xs = 1.0;
   ys = 1.0;
   zs = 1.0;

   angulo1 = 0;
   velocidad = 1;
   
   Vertices.resize(4);

   Vertices[0]=_vertex3f(-Size/2,-Size/2,-Size/2);
   Vertices[1]=_vertex3f(0,-Size/2,Size/2);
   Vertices[2]=_vertex3f(Size/2,-Size/2,-Size/2);
   Vertices[3]=_vertex3f(0,Size/2,0);

   Triangles.resize(4);

   Triangles[0]=_vertex3ui(0,1,3);
   Triangles[1]=_vertex3ui(1,2,3);
   Triangles[2]=_vertex3ui(2,0,3);
   Triangles[3]=_vertex3ui(0,2,1);

                     //x,y,z,triangulos,tapas,giro_completo,angulo
   //this->rotarArbitrario(0,1,0,false,false,false,200);
}

