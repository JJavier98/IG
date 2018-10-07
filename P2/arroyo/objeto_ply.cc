#include "objeto_ply.h"

_objectPLY::_objectPLY(){}

_objectPLY::_objectPLY(const vector<_vertex3f> & V, const vector<_vertex3ui> & T)
{
	Vertices = V;
	Triangles = T;
}

void _objectPLY::load(const vector<_vertex3f> & V, const vector<_vertex3ui> & T)
{
	Vertices = V;
	Triangles = T;
}


void _objectPLY::getData(vector<_vertex3f> & V, vector<_vertex3ui> & T)
{
	V = Vertices;
	T = Triangles;
}

//***************************************************************************
// Funcion de rotacion
//***************************************************************************

	void _objectPLY::rotarArbitrario(float ux, float uy, float uz)
	{
		// CREACION DE VERTICES

		int iteraciones = 1;
		int vertices_ini = Vertices.size();
		_vertex3f primerVertice = Vertices[0];
		_vertex3f ultimoVertice = Vertices[vertices_ini-1];

		while(iteraciones <= repeticiones_necesarias)
		{
			float matrizX[3][3] = { {cos(anguloRotacion*iteraciones)+ux*ux*(1-cos(anguloRotacion*iteraciones)),
									ux*uy*(1-cos(anguloRotacion*iteraciones))-uz*sin(anguloRotacion*iteraciones),
									ux*uz*(1-cos(anguloRotacion*iteraciones))+uy*sin(anguloRotacion*iteraciones)},

									{uy*ux*(1-cos(anguloRotacion*iteraciones))+uz*sin(anguloRotacion*iteraciones),
									cos(anguloRotacion*iteraciones)+uy*uy*(1-cos(anguloRotacion*iteraciones)),
									uy*uz*(1-cos(anguloRotacion*iteraciones))-ux*sin(anguloRotacion*iteraciones)},

									{uz*ux*(1-cos(anguloRotacion*iteraciones))-uy*sin(anguloRotacion*iteraciones),
									uz*uy*(1-cos(anguloRotacion*iteraciones))+ux*sin(anguloRotacion*iteraciones),
									cos(anguloRotacion*iteraciones)+uz*uz*(1-cos(anguloRotacion*iteraciones))}
									};

			for(int i = 0 ; i < vertices_ini ; ++i)
			{
				_vertex3f newV;
				for(int k = 0; k < 3; ++k)
				{
					float tmp = 0.0;
					float componente;

					for(int j = 0; j < 3 ; ++j)
					{
						switch(j)
						{
							case 0:
								componente = Vertices[i].x;
								break;
							case 1:
								componente = Vertices[i].y;
								break;
							case 2:
								componente = Vertices[i].z;
								break;
						}

						tmp += matrizX[k][j] * componente;
					}

					switch(k)
					{
						case 0:
							newV.x = tmp;
							break;
						case 1:
							newV.y = tmp;
							break;
						case 2:
							newV.z = tmp;
							break;
					}
				}
				Vertices.push_back(newV);
			}
			++iteraciones;
		}

		// CREACION DE TRIANGULOS
		int a = 0;
		for(int i = 0; i < repeticiones_necesarias ; ++i)
		{
			for(int j = 0; j < vertices_ini-1 ; ++j)
			{
				if(primerVertice.y < ultimoVertice.y)
				{
					Triangles.push_back(_vertex3ui(a+1,a,a+vertices_ini));
					Triangles.push_back(_vertex3ui(a+vertices_ini+1,a+1,a+vertices_ini));
				}
				else
				{
					Triangles.push_back(_vertex3ui(a,a+1,a+vertices_ini));
					Triangles.push_back(_vertex3ui(a+1,a+vertices_ini+1,a+vertices_ini));
				}

				++a;

				if( ( a-(vertices_ini * i) )%(vertices_ini-1) == 0)
					++a;
			}
		}

		// CREACION DE TAPAS

		float independiente = -(ux*(-primerVertice.x) + uy*(-primerVertice.y) + uz*(-primerVertice.z));
		float divisor = ux*ux + uy*uy + uz*uz;
		float parametro = independiente/divisor;

		_vertex3f tapa1;
		tapa1.x = ux*parametro;
		tapa1.y = uy*parametro;
		tapa1.z = uz*parametro;

		Vertices.push_back(tapa1);

		independiente = -(ux*(-ultimoVertice.x) + uy*(-ultimoVertice.y) + uz*(-ultimoVertice.z));
		divisor = ux*ux + uy*uy + uz*uz;
		parametro = independiente/divisor;

		_vertex3f tapa2;
		tapa2.x = ux*parametro;
		tapa2.y = uy*parametro;
		tapa2.z = uz*parametro;

		Vertices.push_back(tapa2);

		a = 0;
		int b = vertices_ini-1;
		for (int i = 0; i < 72; ++i)
		{
			if(primerVertice.y < ultimoVertice.y)
			{
				Triangles.push_back(_vertex3ui(Vertices.size()-2,a+vertices_ini,a));
				Triangles.push_back(_vertex3ui(Vertices.size()-1,b,b+vertices_ini));
			}
			else
			{
				Triangles.push_back(_vertex3ui(Vertices.size()-2,a,a+vertices_ini));
				Triangles.push_back(_vertex3ui(b,Vertices.size()-1,b+vertices_ini));
			}
			a+=vertices_ini;
			b+=vertices_ini;
		}
	}