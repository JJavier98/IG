#ifndef NODE_H
#define NODE_H

#include <vector>
#include "vertex.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include "colors.h"
#include "vertex.h"
#include "stdio.h"
#include <map>

using namespace std;

typedef enum {FLAT_MODE, SMOOTH_MODE} _shading_mode;

class _node
{
public:
	// DATOS MIEMBRO
	float anguloRotacion = 5*M_PI/180; //Radianes
	int repeticiones_necesarias = 2*M_PI/anguloRotacion;

	float xt, yt, zt;
	float xr, yr, zr;
	float xs, ys, zs;

	int angulo1;
	int velocidad;
	float desplazamiento_x = 0;
	float desplazamiento_y = 0;
	float desplazamiento_z = 0;

	float limiteInclinacion1;
	float limiteInclinacion2;

	float limiteDesplazamientoX_1;
	float limiteDesplazamientoY_1;
	float limiteDesplazamientoZ_1;

	float limiteDesplazamientoX_2;
	float limiteDesplazamientoY_2;
	float limiteDesplazamientoZ_2;
	
	vector<_vertex3ui> Triangles;
	vector<_vertex3f> Vertices;

	vector<_node> hijos;

	vector<_vertex3f> vertex_Normals;
	vector<_vertex3f> triangle_Normals;

	// MÉTODOS

	_node();
	_node& operator = (const _node &p);

	void rotarArbitrario(float ux, float uy, float uz, bool triangulos=true,
						bool tapas=true, bool rotar_completo = true, float angulo = 0);

	void add_hijo(_node hijo);
	void load(const vector<_vertex3f> & V, const vector<_vertex3ui> & T);
	void calcularNormales();
	void dibujarNormales();

	void draw_line();
	void draw_fill(_shading_mode modo = FLAT_MODE, int color = 0);
	void draw_chess();
	void draw_point();

	void draw_line_obj();
	void draw_fill_obj(_shading_mode modo = FLAT_MODE, int color = 0);
	void draw_chess_obj();
	void draw_point_obj();
	void draw_texture_obj(_shading_mode mode = FLAT_MODE);

	void draw_illumination_flat_shading();
	void draw_illumination_smooth_shading();
	void draw_texture(_shading_mode mode = FLAT_MODE);
	void draw_texture_illumination_flat_shading();
	void draw_texture_illumination_smooth_shading();

	void incrementar_inclinacion();
	void decrementar_inclinacion();

	void incrementar_velocidad();
	void decrementar_velocidad();

	void incrementar_desplazamiento_x();
	void decrementar_desplazamiento_x();

	void incrementar_desplazamiento_y();
	void decrementar_desplazamiento_y();

	void incrementar_desplazamiento_z();
	void decrementar_desplazamiento_z();

	void incrementar_rotacion();
	void decrementar_rotacion();
};

#endif // OBJECT3D_H
