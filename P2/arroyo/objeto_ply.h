#ifndef OBJECT_PLY
#define OBJECT_PLY

#include "file_ply_stl.h"
#include "object3d.h"
#include "basic_object3d.h"
#include "stdio.h"
#include <math.h>

class _objectPLY:public _object3D
{
private:
	const float anguloRotacion = M_PI/36; //Radianes
	const int repeticiones_necesarias = 2*M_PI/anguloRotacion;
public:
	_objectPLY();
	_objectPLY(const vector<_vertex3f> & V, const vector<_vertex3ui> & T);
	void load(const vector<_vertex3f> & V, const vector<_vertex3ui> & T);
	void getData(vector<_vertex3f> & V, vector<_vertex3ui> & T);


//***************************************************************************
// Funciones de rotacion
//***************************************************************************

	void rotarArbitrario(float ux, float uy, float uz);
};

#endif // OBJECT_PLY
