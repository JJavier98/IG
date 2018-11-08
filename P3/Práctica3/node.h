#ifndef NODE_H
#define NODE_H

#include <vector>
#include "vertex.h"
#include <GL/gl.h>
#include "colors.h"
#include "vertex.h"

class _node
{
public:

	float anguloRotacion = M_PI/36; //Radianes
	int repeticiones_necesarias = 2*M_PI/anguloRotacion;

	float xt, yt, zt;
	float xr, yr, zr;
	float xs, ys, zs;

	int angulo1;
	int velocidad;
	
	vector<_vertex3ui> Triangles;
	vector<_vertex3f> Vertices;

	std::vector<_node> hijos;

	void draw_line();
	void draw_fill();
	void draw_chess();
	void draw_point();

	void add_hijo(_node hijo);

	_node();
	_node& operator = (const _node &p);

	void rotarArbitrario(float ux, float uy, float uz, bool triangulos=true,
						bool tapas=true, bool rotar_completo = false, float angulo = 0);


	void funcion_idle();
};

#endif // OBJECT3D_H
