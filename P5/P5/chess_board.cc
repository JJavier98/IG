#include "chess_board.h"

_chess_board::_chess_board(float Size,unsigned int Divisions1)
{
	xt = 0.0;
	yt = 0.0;
	zt = 0.0;

	xr = 0.0;
	yr = 1.0;
	zr = 0.0;

	xs = 1.0;
	ys = 1.0;
	zs = 1.0;

	angulo1 = 0;
	velocidad = 1;

	Vertices.resize(8);

	Vertices[0]=_vertex3f(-Size/2,0,Size/2);
	Vertices[1]=_vertex3f(Size/2,0,Size/2);
	Vertices[2]=_vertex3f(Size/2,0,-Size/2);
	Vertices[3]=_vertex3f(-Size/2,0,-Size/2);

	Triangles.resize(2);

	Triangles[0]=_vertex3ui(0,1,2);
	Triangles[1]=_vertex3ui(0,2,3);

	calcularNormales();
}
