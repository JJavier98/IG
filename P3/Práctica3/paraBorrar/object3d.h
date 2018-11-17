#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"
#include <vector>
#include "vertex.h"

class _object3D:public _basic_object3D
{
private:
	float anguloRotacion = M_PI/36; //Radianes
	int repeticiones_necesarias = 2*M_PI/anguloRotacion;

public:
	vector<_vertex3ui> Triangles;

	void draw_line();
	void draw_fill();
	void draw_chess();

	_object3D();
	_object3D& operator = (const _object3D &p);

	void rotarArbitrario(float ux, float uy, float uz, bool triangulos=true,
	 					bool tapas=true, bool rotar_completo = false, float angulo = 0);
};

#endif // OBJECT3D_H
