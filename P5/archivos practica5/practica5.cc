/*
 * Practicas de IG
 * Domingo Martin Perandres© 2014-2018
 * dmartin@ugr.es
 *
 * GPL 3
 */

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "stdlib.h"
#include "stdio.h"
#include <ctype.h>
#include <iostream>
#include <fstream>

#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"

using namespace _colors_ne;

const float X_MIN=-.1;
const float X_MAX=.1;
const float Y_MIN=-.1;
const float Y_MAX=.1;
const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
const float BACK_PLANE_PERSPECTIVE=1000;
const float DEFAULT_DISTANCE=2;
const float ANGLE_STEP=1;

typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE} _object;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_angle_x=0;
GLfloat Observer_angle_y=0;
GLfloat Observer_distance=DEFAULT_DISTANCE;

// variables que controlan la ventana y la transformacion de perspectiva
// GLfloat Window_width,Window_height,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=800,UI_window_height=800;

_axis Axis;
_tetrahedron Tetrahedron;

bool Draw_point=false;
bool Draw_line=true;
bool Draw_fill=false;
bool Draw_chess=false;

_object Object=OBJECT_TETRAHEDRON;

/***********************************************************************************************/


/**
 * Limpiar ventana
 *
 *@param
 *@returns
 */

void clear_window()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


/**
 * Funcion para definir la transformación de proyeccion
 *
 *@param
 *@returns
 */


void change_projection()
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
   //  Front_plane>0  Back_plane>PlanoDelantero)
   glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}


/**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *@param
 *@returns
 */

void change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0,0,-Observer_distance);
   glRotatef(Observer_angle_x,1,0,0);
   glRotatef(Observer_angle_y,0,1,0);
}


/**
 * Funcion que dibuja los objetos
 *
 *@param
 *@returns
 */

void draw_objects()
{
   Axis.draw_line();

   if (Draw_point){
      glPointSize(5);
      glColor3fv((GLfloat *) &BLACK);
      switch (Object){
	 case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
	 default:break;
      }
   }

   if (Draw_line){
      glLineWidth(3);
      glColor3fv((GLfloat *) &MAGENTA);
      switch (Object){
	 case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
	 default:break;
      }
   }

   if (Draw_fill){
      glColor3fv((GLfloat *) &BLUE);
      switch (Object){
	 case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
	 default:break;
      }
   }

   if (Draw_chess){
      switch (Object){
	 case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
	 default:break;
      }
   }
}


/**
 * Evento de dibujado
 *
 *@param
 *@returns
 */

void draw_scene(void)
{
   clear_window();
   glPushMatrix();
   {
      change_observer();
      draw_objects();
   }
   glPopMatrix();
   glutSwapBuffers();
}


/**
 * Evento de cambio de tamaño de la ventana
 *@param
 *@returns
 */

void resize(int Ancho1,int Alto1)
{
   UI_window_width=Ancho1;
   UI_window_height=Alto1;
   glViewport(0,0,UI_window_width,UI_window_height);
   glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1,int x,int y)
{
   switch (toupper(Tecla1)){
      case '1':Object=OBJECT_TETRAHEDRON;break;
      case '2':Object=OBJECT_CUBE;break;

      case 'P':Draw_point=!Draw_point;break;
      case 'L':Draw_line=!Draw_line;break;
      case 'F':Draw_fill=!Draw_fill;break;
      case 'C':Draw_chess=!Draw_chess;break;

      case 'Q':exit(0);
   }
   glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y)
{
   switch (Tecla1){
      case GLUT_KEY_LEFT:Observer_angle_y--;break;
      case GLUT_KEY_RIGHT:Observer_angle_y++;break;
      case GLUT_KEY_UP:Observer_angle_x--;break;
      case GLUT_KEY_DOWN:Observer_angle_x++;break;
      case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
      case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
   }
   glutPostRedisplay();
}



//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{
   // se indica cual sera el color para limpiar la ventana	(r,v,a,al)
   glClearColor(1,1,1,1);

   // se habilita el z-bufer
   glEnable(GL_DEPTH_TEST);
   //
   change_projection();
   //
   glViewport(0,0,UI_window_width,UI_window_height);
}


/**
 *
 *@param
 *@returns
 */
void captura(const char* fname)
{
   // Graba un fichero PPM
   size_t size = UI_window_width * UI_window_height * 3;
   unsigned char *img = new unsigned char[size];
   glReadPixels(0,0,UI_window_width, UI_window_height,GL_RGB,GL_UNSIGNED_BYTE,img);
   ofstream myfile (fname, ios::out | ios::binary);
   myfile << "P6" << "\n# GL Screenshot\n" << UI_window_width << " " << UI_window_height << " " << "255" << "\n";
   myfile.write ((const char*) img, size);
   myfile.close();
}


/**
 *
 *@param
 *@returns
 */
void pick(GLint Selection_position_x, GLint Selection_position_y)
{
   glDrawBuffer(GL_BACK);

   /*************************/
   // dibujar con colores de seleccion
   glClearColor(0, 0, 0, 1);
   clear_window();
   change_projection();
   change_observer();
   draw_objects(); // Cambiar para que dibuje con los identificadores
   /*************************/

   std::vector<unsigned char> Color(3);
   glPixelStorei(GL_PACK_ALIGNMENT,1);
   glReadBuffer(GL_BACK); // seleccionamos el buffer trasero

   /*************************/
   // captura el pixel
   glReadPixels(Selection_position_x,UI_window_height-Selection_position_y,1,1,GL_RGB,GL_UNSIGNED_BYTE, &Color[0]);


   // Depura lo que dibujamos y lo que capturamos:
   captura("/tmp/screenshot.ppm");
   std::cout << "Color (RGB): "
	     << (int) Color[0] << ", "
	     << (int) Color[1] << ", "
   	     << (int) Color[2] << std::endl;

   // convertir de RGB a identificador
   // actualizar el identificador en el objeto
   /*************************/

   /* Dibuja normal la segunda pasada */
   glClearColor(1, 1, 1, 1);
   draw_scene();
}

void mousefunc(int button, int state, int x, int y)
{
   if ((button == 0) && (state == 0))
   {
      //std::cout << "Mouse: " << x << ", " << y << "; " << button << "[" << state  << "]" << std::endl;
      pick(x, y);
   }
}

//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv)
{
   // se llama a la inicialización de glut
   glutInit(&argc, argv);

   // se indica las caracteristicas que se desean para la visualización con OpenGL
   // Las posibilidades son:
   // GLUT_SIMPLE -> memoria de imagen simple
   // GLUT_DOUBLE -> memoria de imagen doble
   // GLUT_INDEX -> memoria de imagen con color indizado
   // GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
   // GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
   // GLUT_DEPTH -> memoria de profundidad o z-bufer
   // GLUT_STENCIL -> memoria de estarcido
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

   // posicion de la esquina inferior izquierdad de la ventana
   glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);

   // tamaño de la ventana (ancho y alto)
   glutInitWindowSize(UI_window_width,UI_window_height);

   // llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
   // al bucle de eventos)
   glutCreateWindow("Practica 5");

   // asignación de la funcion llamada "dibujar" al evento de dibujo
   glutDisplayFunc(draw_scene);
   // asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
   glutReshapeFunc(resize);
   // asignación de la funcion llamada "tecla_normal" al evento correspondiente
   glutKeyboardFunc(normal_keys);
   // asignación de la funcion llamada "tecla_Especial" al evento correspondiente
   glutSpecialFunc(special_keys);
   // asignación de la funcion del raton
   glutMouseFunc(mousefunc);

   // funcion de inicialización
   initialize();

   // inicio del bucle de eventos
   glutMainLoop();
   return 0;
}
