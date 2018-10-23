#include "grua.h"

_grua::_grua()
{
	_base base;
	_tronco tronco;
	_brazo brazo1;
	_extensor brazo2;
	_brazo brazo3;


	obj = base;
	hijo = &tronco_n;
	hijo->obj = tronco;
	hijo->hijo = &brazo1_n;
	hijo->hijo->obj = brazo1;
	hijo->hijo->hijo = &brazo2_n;
	hijo->hijo->hijo->obj = brazo2;
	hijo->hijo->hijo->hijo = &brazo3_n;
	hijo->hijo->hijo->hijo->obj = brazo3;
	hijo->hijo->hijo->hijo->hijo = NULL;
}


void _grua::rotarArbitrario(float ux, float uy, float uz)
{
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
	for (int i = 0; i < repeticiones_necesarias; ++i)
	{
		if(primerVertice.y < ultimoVertice.y)
		{
			Triangles.push_back(_vertex3ui(Vertices.size()-2,a+vertices_ini,a));
		}
		else
		{
			Triangles.push_back(_vertex3ui(Vertices.size()-2,a,a+vertices_ini));
		}
		a+=vertices_ini;
	}

	int b = vertices_ini-1;
	for (int i = 0; i < repeticiones_necesarias; ++i)
	{
		if(primerVertice.y < ultimoVertice.y)
		{
			Triangles.push_back(_vertex3ui(Vertices.size()-1,b,b+vertices_ini));
		}
		else
		{
			Triangles.push_back(_vertex3ui(b,Vertices.size()-1,b+vertices_ini));
		}
		b+=vertices_ini;
	}
}

void _grua::rotar_tronco()
{

}

void _grua::mover_brazo1()
{

}

void _grua::deslizar_brazo3()
{

}

void _grua::draw_point()
{
	glMatrixMode(GL_MODELVIEW);
	// base
	glPushMatrix();
	glScalef(1.5,0.2,1.5);
	obj.draw_point();
	glPopMatrix();

	// tronco
	glPushMatrix();
	glTranslatef(0.0,0.1,0.0);
	(tronco_n.obj).draw_point();
	glPopMatrix();

	// brazo1
	glPushMatrix();
	//glScalef(1.0,1.5,1.0);
	glTranslatef(0.0,0.9,0.0);
	glRotatef(-45,0,0,1);
	(brazo1_n.obj).draw_point();
	glPopMatrix();

	// brazo2
	glPushMatrix();
	glScalef(0.5,0.5,0.5);
	glTranslatef(-1.45,3.2,0.0);
	glRotatef(135,0,0,1);
	(brazo2_n.obj).draw_point();
	glPopMatrix();

	//brazo3
	glPushMatrix();
	glTranslatef(-0.825,1.5,0.0);
	glRotatef(45,0,0,1);
	glScalef(0.6,0.5,0.5);
	(brazo3_n.obj).draw_point();
	glPopMatrix();
}

void _grua::draw_line()
{
	glMatrixMode(GL_MODELVIEW);
	// base
	glPushMatrix();
	glScalef(1.5,0.2,1.5);
	obj.draw_line();
	glPopMatrix();

	// tronco
	glPushMatrix();
	glTranslatef(0.0,0.1,0.0);
	(tronco_n.obj).draw_line();
	glPopMatrix();

	// brazo1
	glPushMatrix();
	//glScalef(1.0,1.5,1.0);
	glTranslatef(0.0,0.9,0.0);
	glRotatef(-45,0,0,1);
	(brazo1_n.obj).draw_line();
	glPopMatrix();

	// brazo2
	glPushMatrix();
	glScalef(0.5,0.5,0.5);
	glTranslatef(-1.45,3.2,0.0);
	glRotatef(135,0,0,1);
	(brazo2_n.obj).draw_line();
	glPopMatrix();

	//brazo3
	glPushMatrix();
	glTranslatef(-0.825,1.5,0.0);
	glRotatef(45,0,0,1);
	glScalef(0.6,0.5,0.5);
	(brazo3_n.obj).draw_line();
	glPopMatrix();
}

void _grua::draw_fill()
{
	glMatrixMode(GL_MODELVIEW);
	// base
	glPushMatrix();
	glScalef(1.5,0.2,1.5);
	obj.draw_fill();
	glPopMatrix();

	// tronco
	glPushMatrix();
	glTranslatef(0.0,0.1,0.0);
	(tronco_n.obj).draw_fill();
	glPopMatrix();

	// brazo1
	glPushMatrix();
	//glScalef(1.0,1.5,1.0);
	glTranslatef(0.0,0.9,0.0);
	glRotatef(-45,0,0,1);
	(brazo1_n.obj).draw_fill();
	glPopMatrix();

	// brazo2
	glPushMatrix();
	glScalef(0.5,0.5,0.5);
	glTranslatef(-1.45,3.2,0.0);
	glRotatef(135,0,0,1);
	(brazo2_n.obj).draw_fill();
	glPopMatrix();

	//brazo3
	glPushMatrix();
	glTranslatef(-0.825,1.5,0.0);
	glRotatef(45,0,0,1);
	glScalef(0.6,0.5,0.5);
	(brazo3_n.obj).draw_fill();
	glPopMatrix();
}

void _grua::draw_chess()
{
	glMatrixMode(GL_MODELVIEW);
	// base
	glPushMatrix();
	glScalef(1.5,0.2,1.5);
	obj.draw_chess();
	glPopMatrix();

	// tronco
	glPushMatrix();
	glTranslatef(0.0,0.1,0.0);
	(tronco_n.obj).draw_chess();
	glPopMatrix();

	// brazo1
	glPushMatrix();
	//glScalef(1.0,1.5,1.0);
	glTranslatef(0.0,0.9,0.0);
	glRotatef(-45,0,0,1);
	(brazo1_n.obj).draw_chess();
	glPopMatrix();

	// brazo2
	glPushMatrix();
	glScalef(0.5,0.5,0.5);
	glTranslatef(-1.45,3.2,0.0);
	glRotatef(135,0,0,1);
	(brazo2_n.obj).draw_chess();
	glPopMatrix();

	//brazo3
	glPushMatrix();
	glTranslatef(-0.825,1.5,0.0);
	glRotatef(45,0,0,1);
	glScalef(0.6,0.5,0.5);
	(brazo3_n.obj).draw_chess();
	glPopMatrix();
}
