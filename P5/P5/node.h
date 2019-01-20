#ifndef NODE_H
#define NODE_H

// LIBRARIES
#include <vector>
#include "vertex.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include "colors.h"
#include "vertex.h"
#include "stdio.h"
#include <map>

// NAMESPACES
using namespace std;

// MODES FOR SHADING
typedef enum {FLAT_MODE, SMOOTH_MODE} _shading_mode;

// MAIN CLASS TO CREATE OBJECTS
class _node
{
public:
	// DATOS MIEMBRO

	/*
	** STRUCT PARA IDENTIFICAR LAS
	** CARAS DE UN OBJETO POR MEDIO
	** DE SU COLOR
	*/
	struct Identificador
	{
		unsigned first 	= 0,
				 second = 0,
				 third 	= 0;
		bool	 colored = false;
	};

	float anguloRotacion = 5*M_PI/180; //Radianes
	// REPETICIONES NECESARIAS PARA COMPLETAR 360º
	int repeticiones_necesarias = 2*M_PI/anguloRotacion;

	// VARIABLES DE COLOCACION INICIALES
	float xt, yt, zt; // VARIABLES DE TRASLACIÓN
	float xr, yr, zr; // VARIABLES DE ROTACIÓN
	float xs, ys, zs; // VARIABLES DE ESCALADO

	// ANGULO QUE SE APLICARÁ JUNTO A LAS VARIABLES DE ROTACION
	int angulo1;
	// VELOCIDAD DE LOS DISTINTOS MOVIMIENTOS
	int velocidad;

	//VARIABLES DE DESPLAZAMIENTO EN ANIMACION
	float desplazamiento_x = 0;
	float desplazamiento_y = 0;
	float desplazamiento_z = 0;

	// VARIABLES QUE INDICAN UN LÍMITE DE MOVIMIENTO EN LA ANMACION
	float limiteInclinacion1;
	float limiteInclinacion2;

	float limiteDesplazamientoX_1;
	float limiteDesplazamientoY_1;
	float limiteDesplazamientoZ_1;

	float limiteDesplazamientoX_2;
	float limiteDesplazamientoY_2;
	float limiteDesplazamientoZ_2;
	
	// VECTORES PARA GUARDAR LOS TRIANGULOS Y VERTICES
	// QUE FORMAN UN OBJETO
	vector<_vertex3ui> Triangles;
	vector<_vertex3f> Vertices;

	// VECTOR QUE ALMACENA LOS HIJOS QUE TIENE UN OBJETO JERARQUICO
	vector<_node> hijos;

	// VECTOR DE NORMALES PARA EL SOMBREADO DE OBJETOS
	vector<_vertex3f> vertex_Normals;
	vector<_vertex3f> triangle_Normals;

	// VECTOR DE IDENTIFICADORES DE TRIANGULOS
	vector<Identificador> triangle_Identificator;

	// MÉTODOS

	_node(); // CONSTRUCTOR DE OBJETO GENÉRICO
	_node& operator = (const _node &p); // OPERADOR DE IGUALDAD

	void rotarArbitrario(float ux, float uy, float uz, bool triangulos=true,
						bool tapas=true, bool rotar_completo = true, float angulo = 0); // PERMITE ROTAR EL OBJETO

	void add_hijo(_node hijo); // AÑADE HIJOS AL VECTOR DE HIJOS DEL OBJETO
	void load(const vector<_vertex3f> & V, const vector<_vertex3ui> & T); // CARGA LOS VECTORES DE TRIANGULOS(T) Y VERTICES(V)
	void calcularNormales(); // CALCULA LAS NORMALES DE LOS VERTICES Y CARAS DEL OBJETO
	void dibujarNormales(); // DIBUJA LAS NORMALES DE LOS VERTICES DEL OBJETO

	// MÉTODOS PARA ASIGNAR LOS IDENTIFICADORES A LOS TRIANGULOS DEL OBJETO
	void asignarIdentificadores(unsigned f = 0, unsigned s = 0, unsigned t = 0);
	_vertex3ui asignarIdentificadores_obj(unsigned f, unsigned s, unsigned t);

	// MÉTODOS PARA DIBUJAR LOS TRIANULOS SELECCIONDOS
	void draw_identificadores();
	void draw_identificadores_obj();

	// MÉTODOS PARA SELECCIONAR LOS TRIANGULOS CLICADOS
	void marcar_seleccionados(unsigned r, unsigned g, unsigned b);
	void marcar_seleccionados_obj(unsigned r, unsigned g, unsigned b);

	// DIBUJA LAS LÍNEAS Y PUNTOS DEL OBJETO
	// TAMBIÉN RELLENA DE UN ÚNICO COLOR O DOS EL OBJETO
	void draw_line();
	void draw_fill(_shading_mode modo = FLAT_MODE, int color = 0);
	void draw_chess();
	void draw_point();

	void draw_line_obj();
	void draw_fill_obj(_shading_mode modo = FLAT_MODE, int color = 0);
	void draw_chess_obj();
	void draw_point_obj();
	void draw_texture_obj(_shading_mode mode = FLAT_MODE);

	// MODOS DE DIBUJADO CON SOMBRAS Y TEXTURAS
	void draw_illumination_flat_shading();
	void draw_illumination_smooth_shading();
	void draw_texture(_shading_mode mode = FLAT_MODE);
	void draw_texture_illumination_flat_shading();
	void draw_texture_illumination_smooth_shading();

	// MÉTODOS DE MODIFICACION DEL ESTADO DEL OBJETO POR MEDIO DE ANIMACION
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
