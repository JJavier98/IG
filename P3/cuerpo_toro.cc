#include "cuerpo_toro.h"
#include "cabeza_toro.h"
#include "piernas_toro.h"
#include "node.h"


_cuerpo_toro::_cuerpo_toro(float W, float H)
{
	xt = 0.0;
	yt = 0.0;
	zt = 0.0;

	xr = 0.0;
	yr = 0.0;
	zr = 0.0;

	xs = 1.0;
	ys = 1.0;
	zs = 1.0;

	angulo1 = 0;
	velocidad = 1;

	Vertices.resize(8);

   Vertices[0]=_vertex3f(-W/2,0.0,W/4);
   Vertices[1]=_vertex3f(W/2,0.0,W/4);
   Vertices[2]=_vertex3f(W/2,H,W/4);
   Vertices[3]=_vertex3f(-W/2,H,W/4);
   Vertices[4]=_vertex3f(W/2,0.0,-W/4);
   Vertices[5]=_vertex3f(W/2,H,-W/4);
   Vertices[6]=_vertex3f(-W/2,H,-W/4);
   Vertices[7]=_vertex3f(-W/2,0.0,-W/4);

   Triangles.resize(12);

   Triangles[0]=_vertex3ui(0,1,2);
   Triangles[1]=_vertex3ui(0,2,3);

   Triangles[2]=_vertex3ui(1,4,5);
   Triangles[3]=_vertex3ui(1,5,2);

   Triangles[4]=_vertex3ui(4,7,6);
   Triangles[5]=_vertex3ui(4,6,5);

   Triangles[6]=_vertex3ui(7,0,3);
   Triangles[7]=_vertex3ui(7,3,6);

   Triangles[8]=_vertex3ui(7,4,1);
   Triangles[9]=_vertex3ui(7,1,0);

   Triangles[10]=_vertex3ui(3,2,5);
   Triangles[11]=_vertex3ui(3,5,6);

	//_piernas_toro piernas;
	_cabeza_toro cabeza;

	add_hijo(cabeza);
	//add_hijo(piernas);
}
