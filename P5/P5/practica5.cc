#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "stdlib.h"
#include "stdio.h"
#include <ctype.h>
#include <file_ply_stl.h>
#include <vector>
#include <cmath>

#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
#include "cube.h"
#include "cylinder.h"
#include "cone.h"
#include "sphere.h"
#include "grua.h"
#include "cuenco.h"
#include "toro.h"
#include "node.h"
#include "textura.h"
#include "chess_board.h"

using namespace _colors_ne;

const float X_MIN=-.1;
const float X_MAX=.1;
const float Y_MIN=-.1;
const float Y_MAX=.1;
const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
const float BACK_PLANE_PERSPECTIVE=1000;
const float DEFAULT_DISTANCE=2;
const float ANGLE_STEP=1;
float DISTANCIA_ORTOGONAL = 15;

      float ux, uy, uz;

typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE,OBJECT_PLY_,OBJECT_CYLINDER,OBJECT_CONE,OBJECT_SPHERE,OBJECT_HIERARCHY,OBJECT_CUENCO,OBJECT_TORO,OBJECT_C_BOARD} _object;
typedef enum {MODE_RENDERING_SOLID,MODE_RENDERING_SOLID_CHESS, MODE_RENDERING_ILLUMINATION_FLAT_SHADING, MODE_RENDERING_ILLUMINATION_SMOOTH_SHADING,
              MODE_RENDERING_TEXTURE, MODE_RENDERING_TEXTURE_ILLUMINATION_FLAT_SHADING, MODE_RENDERING_TEXTURE_ILLUMINATION_SMOOTH_SHADING} _mode_rendering;

bool animacion = false;
bool cambioR = false;
bool rotar = true;
bool PLY_desplegado = false;
vector<_vertex3f> inicialPLYv;
vector<_vertex3ui> inicialPLYt;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_angle_x=0;
GLfloat Observer_angle_y=0;
GLfloat Observer_distance=DEFAULT_DISTANCE;


// variables que controlan la ventana y la transformacion de perspectiva
// GLfloat Window_width,Window_height,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=800,UI_window_height=800;
float   rx, // coordenadas del raton
        ry,
        Arx = 0, // desplazamiento de coordenadas
        Ary = 0;

_axis Axis;
_tetrahedron Tetrahedron;
_cube Cube;
_node ObjPLY;
_cylinder Cylinder;
_cone Cone;
_sphere Sphere;
_grua Grua;
_cuenco Cuenco;
_toro Toro;
_chess_board C_Board;

unsigned  int   Material_active=0;
          bool  Light0_active=true;
          bool  Light1_active=false;
          float Light1_angle=0;
const     float INC_LIGHT1_ANGLE=1;
          int   angulo = 0;
          int   imagen_actual = 0;
          vector<_textura> imagenes;

_mode_rendering Mode_rendering=MODE_RENDERING_SOLID;

bool Draw_point=false;
bool Draw_line=true;
bool Draw_fill=false;
bool Draw_chess=false;
bool Draw_flat=false;
bool Draw_smooth=false;
bool Draw_flat_tex=false;
bool Draw_smooth_tex=false;
bool textura = false;
bool ortogonal = false;

_object Object=OBJECT_TETRAHEDRON;

/***********************************************************************************************/

/**
*
*@param
*@returns
*/


_vertex3f interpolar(_vertex3f A, _vertex3f B)
{
  static float i = 0;
  static bool modo = true;

  _vertex3f res;
  res = A*i + B*(1-i);

  if(modo)
    i+=0.001;
  else
    i-=0.001;

  if(i >= 1)
    modo = false;
  else if (i <= 0)
    modo = true;

  return res;
}


void set_lights()
{
    if (Light0_active)
    {
        _vertex3f pos={100,100,100};
        pos.normalize();
        _vertex4f Position(pos.x,pos.y,pos.z,0);
        _vertex4f Ambient(0.3,0.3,0.3,1);

        glLightfv(GL_LIGHT0,GL_AMBIENT,(GLfloat *)&Ambient);

        glEnable(GL_LIGHT0);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        //glRotatef(Observer_angle_x, 1, 0, 0);
        //glRotatef(Observer_angle_y, 0, 1, 0);

        glLightfv(GL_LIGHT0,GL_POSITION,(GLfloat *)&Position);
        glPopMatrix();
    }
    else
    {
        glDisable(GL_LIGHT0);
    }

    if(Light1_active)
    {
      _vertex4f Position(100,0,0,1);
      _vertex4f diffuse(0.1,0,0,1);
      _vertex4f specular(0.7,0,0,1);

      glLightfv(GL_LIGHT1,GL_DIFFUSE,(GLfloat *)&diffuse);
      glLightfv(GL_LIGHT1,GL_SPECULAR,(GLfloat *)&specular);

      glEnable(GL_LIGHT1);
      glMatrixMode(GL_MODELVIEW);
      glPushMatrix();
      glLoadIdentity();
      glRotatef(Observer_angle_x, 1, 0, 0);
      glRotatef(Observer_angle_y, 0, 1, 0);

      if(animacion)
        glRotatef(angulo, 0, 1, 0);

      glLightfv(GL_LIGHT1,GL_POSITION,(GLfloat *)&Position);
      glPopMatrix();
    }
    else
    {
      glDisable(GL_LIGHT1);
    }

    if(animacion)
      glutPostRedisplay();
}

/**
 *
 *@param
 *@returns
 */

void set_materials()
{
   switch (Material_active){
    case 0:{
      _vertex3f Material_diffuse(0.3,0.3,0.3);
      _vertex3f Material_specular(0.3,0.3,0.3);
      _vertex3f Material_ambient(0.3,0.3,0.3);
      float Material_shininess=0.3;

      glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,(GLfloat *)&Material_diffuse);
      glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,(GLfloat *)&Material_specular);
      glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,(GLfloat *)&Material_ambient);
      glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,Material_shininess);
        }
      break;
    case 1:{
      _vertex3f Material_diffuse(0.5,0.5,0);
      _vertex3f Material_specular(0.5,0.5,0);
      _vertex3f Material_ambient(0.3,0.3,0);
      float Material_shininess=0.5;

      glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,(GLfloat *)&Material_diffuse);
      glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,(GLfloat *)&Material_specular);
      glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,(GLfloat *)&Material_ambient);
      glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,Material_shininess);
    }
      break;
    case 2:{
      _vertex3f Material_diffuse(0.5,0,0.7);
      _vertex3f Material_specular(0.5,0,0.7);
      _vertex3f Material_ambient(0.3,0,0.3);
      float Material_shininess=0.5;

      glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,(GLfloat *)&Material_diffuse);
      glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,(GLfloat *)&Material_specular);
      glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,(GLfloat *)&Material_ambient);
      glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,Material_shininess);
    }
      break;
    case 3:{
      //brillo
      _vertex3f azul_dif(0,0,0.8);
      _vertex3f rojo_dif(0.8,0,0);
      _vertex3f res_dif = interpolar(azul_dif, rojo_dif);

      //color
      _vertex3f azul_spec(0,0,1);
      _vertex3f rojo_spec(1,0,0);
      _vertex3f res_spec = interpolar(azul_spec, rojo_spec);

      //ambiente
      _vertex3f azul_amb(0,0,0.5);
      _vertex3f rojo_amb(0.5,0,0);
      _vertex3f res_amb = interpolar(azul_amb, rojo_amb);

      _vertex3f Material_diffuse(res_dif);
      _vertex3f Material_specular(res_spec);
      _vertex3f Material_ambient(res_amb);
      float Material_shininess=0.5;

      glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,(GLfloat *)&Material_diffuse);
      glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,(GLfloat *)&Material_specular);
      glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,(GLfloat *)&Material_ambient);
      glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,Material_shininess);
    }
      break;
   }
}

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
   // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
   //  Front_plane>0  Back_plane>PlanoDelantero)
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   if(ortogonal)
   {
        glOrtho(X_MIN*DISTANCIA_ORTOGONAL,X_MAX*DISTANCIA_ORTOGONAL,Y_MIN*DISTANCIA_ORTOGONAL,Y_MAX*DISTANCIA_ORTOGONAL,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
   }
   else
   {
        glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
   }
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


//CAMBIAR PLY
void draw_objects()
{
  Axis.draw_line();

/////// POINT ///////////////////
 if (Draw_point){
    glPointSize(5);
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
      case OBJECT_TETRAHEDRON: Tetrahedron.draw_point();break;
      case OBJECT_CUBE: Cube.draw_point();break;
      case OBJECT_PLY_: ObjPLY.draw_point();break;
      case OBJECT_CYLINDER: Cylinder.draw_point();break;
      case OBJECT_CONE: Cone.draw_point();break;
      case OBJECT_SPHERE: Sphere.draw_point();break;
      case OBJECT_HIERARCHY: Grua.draw_point();break;
      case OBJECT_CUENCO: Cuenco.draw_point();break;
      case OBJECT_TORO: Toro.draw_point();break;
      case OBJECT_C_BOARD: C_Board.draw_point();break;
      default:break;
    }
  }

/////// LINE ///////////////////
  if (Draw_line){
    glLineWidth(3);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
	 	  case OBJECT_TETRAHEDRON: Tetrahedron.draw_line();break;
    	case OBJECT_CUBE: Cube.draw_line();break;
    	case OBJECT_PLY_: ObjPLY.draw_line();break;
      case OBJECT_CYLINDER: Cylinder.draw_line();break;
      case OBJECT_CONE: Cone.draw_line();break;
      case OBJECT_SPHERE: Sphere.draw_line();break;
      case OBJECT_HIERARCHY: Grua.draw_line();break;
      case OBJECT_CUENCO: Cuenco.draw_line();break;
      case OBJECT_TORO: Toro.draw_line();break;
      case OBJECT_C_BOARD: C_Board.draw_line();break;
      default:break;
    }
  }

/////// FILL ///////////////////
    
  switch (Mode_rendering){
    case MODE_RENDERING_SOLID:  //F1
    {
        if (Draw_fill)
            switch (Object)
            {
                case OBJECT_TETRAHEDRON: Tetrahedron.draw_fill();break;
                case OBJECT_CUBE: Cube.draw_fill();break;
                case OBJECT_PLY_: ObjPLY.draw_fill();break;
                case OBJECT_CYLINDER: Cylinder.draw_fill();break;
                case OBJECT_CONE: Cone.draw_fill();break;
                case OBJECT_SPHERE: Sphere.draw_fill();break;
                case OBJECT_HIERARCHY: Grua.draw_fill();break;
                case OBJECT_CUENCO: Cuenco.draw_fill();break;
                case OBJECT_TORO: Toro.draw_fill();break;
                case OBJECT_C_BOARD: C_Board.draw_fill();break;
                default:break;
            }
    }
    break;

    case MODE_RENDERING_SOLID_CHESS:  //F2
    {
        if(Draw_chess)
            switch (Object)
            {
                case OBJECT_TETRAHEDRON: Tetrahedron.draw_chess();break;
                case OBJECT_CUBE: Cube.draw_chess();break;
                case OBJECT_PLY_: ObjPLY.draw_chess();break;
                case OBJECT_CYLINDER: Cylinder.draw_chess();break;
                case OBJECT_CONE: Cone.draw_chess();break;
                case OBJECT_SPHERE: Sphere.draw_chess();break;
                case OBJECT_HIERARCHY: Grua.draw_chess();break;
                case OBJECT_CUENCO: Cuenco.draw_chess();break;
                case OBJECT_TORO: Toro.draw_chess();break;
                case OBJECT_C_BOARD: C_Board.draw_chess();break;
                default:break;
            }
    }
    break;

    case MODE_RENDERING_ILLUMINATION_FLAT_SHADING:  //F3
    {
        if(Draw_flat)
        {
            _vertex4f Ambient(0.1,0.1,0.1,1);

            glLightModelfv(GL_LIGHT_MODEL_AMBIENT,(GLfloat *)&Ambient);

            set_lights();
            set_materials();

            glEnable(GL_LIGHTING);
            switch (Object)
            {
                case OBJECT_TETRAHEDRON: Tetrahedron.draw_illumination_flat_shading();break;
                case OBJECT_CUBE: Cube.draw_illumination_flat_shading();break;
                case OBJECT_PLY_: ObjPLY.draw_illumination_flat_shading();break;
                case OBJECT_CYLINDER: Cylinder.draw_illumination_flat_shading();break;
                case OBJECT_CONE: Cone.draw_illumination_flat_shading();break;
                case OBJECT_SPHERE: Sphere.draw_illumination_flat_shading();break;
                case OBJECT_HIERARCHY: Grua.draw_illumination_flat_shading();break;
                case OBJECT_CUENCO: Cuenco.draw_illumination_flat_shading();break;
                case OBJECT_TORO: Toro.draw_illumination_flat_shading();break;
                case OBJECT_C_BOARD: C_Board.draw_illumination_flat_shading();break;
                default:break;
            }
            glDisable(GL_LIGHTING);
        }
    }
    break;

    case MODE_RENDERING_ILLUMINATION_SMOOTH_SHADING:  //F4
    {
        if(Draw_smooth)
        {
            _vertex4f Ambient(0.1,0.1,0.1,1);
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT,(GLfloat *)&Ambient);

            set_lights();
            set_materials();

            glEnable(GL_LIGHTING);
            switch (Object)
            {
                case OBJECT_TETRAHEDRON: Tetrahedron.draw_illumination_smooth_shading();break;
                case OBJECT_CUBE: Cube.draw_illumination_smooth_shading();break;
                case OBJECT_PLY_: ObjPLY.draw_illumination_smooth_shading();break;
                case OBJECT_CYLINDER: Cylinder.draw_illumination_smooth_shading();break;
                case OBJECT_CONE: Cone.draw_illumination_smooth_shading();break;
                case OBJECT_SPHERE: Sphere.draw_illumination_smooth_shading();break;
                case OBJECT_HIERARCHY: Grua.draw_illumination_smooth_shading();break;
                case OBJECT_CUENCO: Cuenco.draw_illumination_smooth_shading();break;
                case OBJECT_TORO: Toro.draw_illumination_smooth_shading();break;
                case OBJECT_C_BOARD: C_Board.draw_illumination_smooth_shading();break;
                default:break;
            }
            glDisable(GL_LIGHTING);
        }
    }
    break;

    case MODE_RENDERING_TEXTURE:  //F5
        glBindTexture(GL_TEXTURE_2D, imagenes[imagen_actual].id());
        glColor3fv((GLfloat *) &WHITE );
        if(textura)
        switch (Object){
            case OBJECT_TETRAHEDRON: Tetrahedron.draw_texture();break;
            case OBJECT_CUBE: Cube.draw_texture();break;
            case OBJECT_PLY_: ObjPLY.draw_texture();break;
            case OBJECT_CYLINDER: Cylinder.draw_texture();break;
            case OBJECT_CONE: Cone.draw_texture();break;
            case OBJECT_SPHERE: Sphere.draw_texture();break;
            case OBJECT_HIERARCHY: Grua.draw_texture();break;
            case OBJECT_CUENCO: Cuenco.draw_texture();break;
            case OBJECT_TORO: Toro.draw_texture();break;
            case OBJECT_C_BOARD: C_Board.draw_texture();break;
            default:break;
        }
        glBindTexture(GL_TEXTURE_2D, 0);
    break;

    case MODE_RENDERING_TEXTURE_ILLUMINATION_FLAT_SHADING:  //F6
    {
        glBindTexture(GL_TEXTURE_2D, imagenes[imagen_actual].id());
        if(Draw_flat_tex)
        {
            _vertex4f Ambient(0.1,0.1,0.1,1);

            glLightModelfv(GL_LIGHT_MODEL_AMBIENT,(GLfloat *)&Ambient);

            set_lights();
            set_materials();

            glEnable(GL_LIGHTING);
            // parametros de aplicacion de la textura
            glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
            switch (Object){
                case OBJECT_TETRAHEDRON: Tetrahedron.draw_texture_illumination_flat_shading();break;
                case OBJECT_CUBE: Cube.draw_texture_illumination_flat_shading();break;
                case OBJECT_PLY_: ObjPLY.draw_texture_illumination_flat_shading();break;
                case OBJECT_CYLINDER: Cylinder.draw_texture_illumination_flat_shading();break;
                case OBJECT_CONE: Cone.draw_texture_illumination_flat_shading();break;
                case OBJECT_SPHERE: Sphere.draw_texture_illumination_flat_shading();break;
                case OBJECT_HIERARCHY: Grua.draw_texture_illumination_flat_shading();break;
                case OBJECT_CUENCO: Cuenco.draw_texture_illumination_flat_shading();break;
                case OBJECT_TORO: Toro.draw_texture_illumination_flat_shading();break;
                case OBJECT_C_BOARD: C_Board.draw_texture_illumination_flat_shading();break;
                default:break;
            }
            glDisable(GL_LIGHTING);
        }
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    break;

    case MODE_RENDERING_TEXTURE_ILLUMINATION_SMOOTH_SHADING:  //F6
    {
        glBindTexture(GL_TEXTURE_2D, imagenes[imagen_actual].id());
        if(Draw_smooth_tex)
        {
            _vertex4f Ambient(0.1,0.1,0.1,1);

            glLightModelfv(GL_LIGHT_MODEL_AMBIENT,(GLfloat *)&Ambient);

            set_lights();
            set_materials();

            glEnable(GL_LIGHTING);
            // parametros de aplicacion de la textura
            glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
            switch (Object){
                case OBJECT_TETRAHEDRON: Tetrahedron.draw_texture_illumination_smooth_shading();break;
                case OBJECT_CUBE: Cube.draw_texture_illumination_smooth_shading();break;
                case OBJECT_PLY_: ObjPLY.draw_texture_illumination_smooth_shading();break;
                case OBJECT_CYLINDER: Cylinder.draw_texture_illumination_smooth_shading();break;
                case OBJECT_CONE: Cone.draw_texture_illumination_smooth_shading();break;
                case OBJECT_SPHERE: Sphere.draw_texture_illumination_smooth_shading();break;
                case OBJECT_HIERARCHY: Grua.draw_texture_illumination_smooth_shading();break;
                case OBJECT_CUENCO: Cuenco.draw_texture_illumination_smooth_shading();break;
                case OBJECT_TORO: Toro.draw_texture_illumination_smooth_shading();break;
                case OBJECT_C_BOARD: C_Board.draw_texture_illumination_smooth_shading();break;
                default:break;
            }
            glDisable(GL_LIGHTING);
        }
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    break;
  }
}

void draw_identificadores()
{
    switch (Object){
        case OBJECT_TETRAHEDRON: Tetrahedron.draw_identificadores();break;
        case OBJECT_CUBE: Cube.draw_identificadores();break;
        case OBJECT_PLY_: ObjPLY.draw_identificadores();break;
        case OBJECT_CYLINDER: Cylinder.draw_identificadores();break;
        case OBJECT_CONE: Cone.draw_identificadores();break;
        case OBJECT_SPHERE: Sphere.draw_identificadores();break;
        case OBJECT_HIERARCHY: Grua.draw_identificadores();break;
        case OBJECT_CUENCO: Cuenco.draw_identificadores();break;
        case OBJECT_TORO: Toro.draw_identificadores();break;
        case OBJECT_C_BOARD: C_Board.draw_identificadores();break;
        default:break;
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
   change_observer();
   draw_objects();
   glutSwapBuffers();
}


/**
 * Evento de cambio de tamaño de la ventana
 *@param
 *@returns
 */

void resize(int Ancho1,int Alto1)
{
// 	change_projection();
   glViewport(0,0,Ancho1,Alto1);
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

/**
* Funcion conmutar animacion
*
*/
void funcion_idle()
{
  Grua.funcion_idle();
}

void funcion_idle2()
{
  angulo += 2;
  if(angulo == 360)
    angulo = 0;
  set_lights();
  glutPostRedisplay();
}

void funcion_idle3()
{
  if(Material_active==3)
  {
    set_materials();
    glutPostRedisplay();
  }
}

void cambiarAnimacion()
{
  animacion = !animacion;
  if(animacion and Material_active==3)
    glutIdleFunc(funcion_idle3);
  else if(animacion and Object==OBJECT_HIERARCHY)
    glutIdleFunc(funcion_idle);
  else if(animacion)
    glutIdleFunc(funcion_idle2);
  else
    glutIdleFunc(nullptr);
}

void funcionPLY()
{
  if(rotar and Object == OBJECT_PLY_)
  {  
    cambioR = !cambioR;
    if(cambioR)
    {
      ObjPLY.rotarArbitrario(ux,uy,uz);
    }
    else
    {
      ObjPLY.load(inicialPLYv, inicialPLYt);
    }
  }
  ObjPLY.calcularNormales();
  ObjPLY.asignarIdentificadores();
}

// CAMBIAR PLY
void normal_keys(unsigned char Tecla1,int x,int y)
{
    switch (toupper(Tecla1)){
        case '1':Object=OBJECT_TETRAHEDRON;break;
        case '2':Object=OBJECT_CUBE;break;
        case '3':Object=OBJECT_CONE;break;
        case '4':Object=OBJECT_CYLINDER;break;
        case '5':Object=OBJECT_SPHERE;break;
        case '6':Object=OBJECT_PLY_;if(PLY_desplegado)funcionPLY();break;
        case '7':Object=OBJECT_HIERARCHY;break;
        case '8':Object=OBJECT_CUENCO;break;
        case '9':Object=OBJECT_C_BOARD;break;

        case 'P':Draw_point=!Draw_point;break;
        case 'L':Draw_line=!Draw_line;break;

        case 'J':Light0_active=!Light0_active;break;
        case 'K':Light1_active=!Light1_active;break;

        case 'C':ortogonal = false;change_projection();break;
        case 'V':ortogonal = true;change_projection();break;

        case 'Q':Grua.incrementar_desplazamiento_punta();break;
        case 'W':Grua.decrementar_desplazamiento_punta();break;

        case 'S':Grua.incrementar_inclinacion_extensor();break;
        case 'D':Grua.decrementar_inclinacion_extensor();break;

        case 'Z':Grua.incrementar_inclinacion_brazo();break;
        case 'X':Grua.decrementar_inclinacion_brazo();break;
        
        case 'E':Grua.incrementar_rotacion_tronco();break;
        case 'R':Grua.decrementar_rotacion_tronco();break;
        
        case 'T':Grua.incrementar_velocidad_extensor();break;
        case 'Y':Grua.decrementar_velocidad_extensor();break;

        case 'U':Grua.incrementar_velocidad_brazo();break;
        case 'I':Grua.decrementar_velocidad_brazo();break;

        case 'B':Grua.incrementar_velocidad_tronco();break;
        case 'N':Grua.decrementar_velocidad_tronco();break;

        case 'M':Material_active=(Material_active+1)%4;break;
        case 'G':imagen_actual=(imagen_actual+1)%3;break;

        case 'A':cambiarAnimacion();break;
        case 'F':funcionPLY();break;

        case '0':exit(0);
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

        case GLUT_KEY_PAGE_UP:  Observer_distance*=1.2;
                                DISTANCIA_ORTOGONAL*=1.2;
                                change_projection();break;

        case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;
                                DISTANCIA_ORTOGONAL/=1.2;
                                change_projection();break;

        case GLUT_KEY_F1:
             Mode_rendering=MODE_RENDERING_SOLID;
             Draw_fill=!Draw_fill;
             Draw_chess=false;
             Draw_flat = false;
             Draw_smooth = false;
             textura = false;
             Draw_flat_tex=false;
             Draw_smooth_tex=false;
             glDisable(GL_TEXTURE_2D);
             break;

        case GLUT_KEY_F2:
             Mode_rendering=MODE_RENDERING_SOLID_CHESS;
             Draw_chess=!Draw_chess;
             Draw_fill=false;
             Draw_flat = false;
             Draw_smooth = false;
             textura = false;
             Draw_flat_tex=false;
             Draw_smooth_tex=false;
             glDisable(GL_TEXTURE_2D);
             break;

        case GLUT_KEY_F3:
             Mode_rendering=MODE_RENDERING_ILLUMINATION_FLAT_SHADING;
             Draw_flat = !Draw_flat;
             Draw_chess=false;
             Draw_fill=false;
             Draw_smooth = false;
             textura = false;
             Draw_flat_tex=false;
             Draw_smooth_tex=false;
             glDisable(GL_TEXTURE_2D);
             break;

        case GLUT_KEY_F4:
             Mode_rendering=MODE_RENDERING_ILLUMINATION_SMOOTH_SHADING;
             Draw_smooth = !Draw_smooth;
             Draw_chess=false;
             Draw_fill=false;
             Draw_flat = false;
             textura = false;
             Draw_flat_tex=false;
             Draw_smooth_tex=false;
             glDisable(GL_TEXTURE_2D);
             break;

        case GLUT_KEY_F5:
             Mode_rendering=MODE_RENDERING_TEXTURE;
             Draw_flat = false;
             Draw_smooth = false;
             Draw_chess=false;
             Draw_fill=false;
             Draw_flat_tex=false;
             Draw_smooth_tex=false;
             textura = !textura;
             if(!textura)
                glDisable(GL_TEXTURE_2D);
             break;

        case GLUT_KEY_F6:
             Mode_rendering=MODE_RENDERING_TEXTURE_ILLUMINATION_FLAT_SHADING;
             Draw_flat_tex = !Draw_flat_tex;
             textura = false;
             Draw_flat = false;
             Draw_smooth = false;
             Draw_chess=false;
             Draw_fill=false;
             Draw_smooth_tex=false;
             break;

        case GLUT_KEY_F7:
             Mode_rendering=MODE_RENDERING_TEXTURE_ILLUMINATION_SMOOTH_SHADING;
             Draw_smooth_tex = !Draw_smooth_tex;             
             Draw_flat = false;
             Draw_smooth = false;
             Draw_chess=false;
             Draw_fill=false;
             Draw_flat_tex=false;
             textura = false;
             break;
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
 *CAMBIAR
 */
void captura(const char* fname)
{
   // Graba un fichero PPM
   size_t size = UI_window_width * UI_window_height * 3;
   unsigned char *img = new unsigned char[size];
   glReadPixels(0,0,UI_window_width, UI_window_height,GL_RGB,GL_UNSIGNED_BYTE,img);
   ofstream myfile (fname, ios::out | ios::binary);
   myfile << "P5" << "\n# GL Screenshot\n" << UI_window_width << " " << UI_window_height << " " << "255" << "\n";
   myfile.write ((const char*) img, size);
   myfile.close();
}


/**
 *
 *@param
 *@returns
 *CAMBIAR
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
    draw_identificadores(); // Cambiar para que dibuje con los identificadores
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
        << (int) Color[0] << ", "         //R -> first
        << (int) Color[1] << ", "         //G -> second
        << (int) Color[2] << std::endl; //B -> third

   // convertir de RGB a identificador
    switch (Object)
    {
        case OBJECT_TETRAHEDRON: Tetrahedron.marcar_seleccionados(Color[0], Color[1], Color[2]);break;
        case OBJECT_CUBE: Cube.marcar_seleccionados(Color[0], Color[1], Color[2]);break;
        case OBJECT_PLY_: ObjPLY.marcar_seleccionados(Color[0], Color[1], Color[2]);break;
        case OBJECT_CYLINDER: Cylinder.marcar_seleccionados(Color[0], Color[1], Color[2]);break;
        case OBJECT_CONE: Cone.marcar_seleccionados(Color[0], Color[1], Color[2]);break;
        case OBJECT_SPHERE: Sphere.marcar_seleccionados(Color[0], Color[1], Color[2]);break;
        case OBJECT_HIERARCHY: Grua.marcar_seleccionados(Color[0], Color[1], Color[2]);break;
        case OBJECT_CUENCO: Cuenco.marcar_seleccionados(Color[0], Color[1], Color[2]);break;
        case OBJECT_TORO: Toro.marcar_seleccionados(Color[0], Color[1], Color[2]);break;
        case OBJECT_C_BOARD: C_Board.marcar_seleccionados(Color[0], Color[1], Color[2]);break;
        default:break;
    }
   // actualizar el identificador en el objeto
   /*************************/

   /* Dibuja normal la segunda pasada */
   glClearColor(1, 1, 1, 1);
   draw_scene();
}


void motion(GLsizei x, GLsizei y){
  
    if(x > Arx)
        Observer_angle_y+=0.5;
    else if (x < Arx)
        Observer_angle_y-=0.5;

    if(y > Ary)
        Observer_angle_x+=0.5;
    else if (y < Ary)
        Observer_angle_x-=0.5;

    Arx = GLfloat(x);
    Ary = GLfloat(y);

    glutPostRedisplay();
}

void mousefunc(int button, int state, int mouse_x, int mouse_y)
{
    if( (button == GLUT_LEFT_BUTTON) and (state == GLUT_DOWN))
    {
        Arx = rx = float(mouse_x);
        Ary = ry = (UI_window_height - float(mouse_x));

        std::cout << "Mouse: " << mouse_x << ", " << mouse_y << "; " << button << "[" << state  << "]" << std::endl;
    }
    if( (button == GLUT_RIGHT_BUTTON) and (state == GLUT_UP))
    {
        pick(mouse_x, mouse_y);
    }
    if(button == 3 and (state == GLUT_UP))
    {
        Observer_distance/=1.2;
        DISTANCIA_ORTOGONAL/=1.2;
        change_projection();
        glutPostRedisplay();
    }
    if(button == 4 and (state == GLUT_UP))
    {
        Observer_distance*=1.2;
        DISTANCIA_ORTOGONAL*=1.2;
        change_projection();
        glutPostRedisplay();
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
	if(argc == 2)
	{
		_file_ply File_ply;

		vector<_vertex3f> Vertices;
		vector<_vertex3ui> Triangles;
		
		if ( File_ply.open(argv[1]) )
		{
            std::cout << endl << endl << "Archivo abierto con éxito" << std::endl;

			File_ply.read(Vertices,Triangles);
            inicialPLYv = Vertices;
            inicialPLYt = Triangles;

			ObjPLY.load(Vertices, Triangles);
            ObjPLY.calcularNormales();

            int selec;

            std::cout << "<0> No rotar" << endl << "<1> Rotar eje X" << endl << "<2> Rotar eje Y" << endl << "<3> Rotar eje Z" <<
            endl <<"<4> Rotar vector arbitrario:" << std::endl;

            std::cin >> selec;

      switch(selec)
      {
        default:
          rotar = false;
          break;
        case 0:
          rotar = false;
          break;
        case 1:
          ux = 1;
          uy = uz = 0;
          break;
        case 2:
          ux = uz = 0;
          uy = 1;
          break;
        case 3:
          ux = uy = 0;
          uz = 1;
          break;
        case 4:
          std::cout << "Introduce Ux:" << std::endl;

          std::cin >> ux;

          std::cout << "Introduce Uy:" << std::endl;

          std::cin >> uy;

          std::cout << "Introduce Uz:" << std::endl;

          std::cin >> uz;
          break;
      }
      PLY_desplegado = true;
		}
		else
			std::cout << "No se ha podido abrir el archivo" << std::endl;
	}

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

    // Borrar z-Buffer
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Activar EPO
    glEnable(GL_DEPTH_TEST);

    // Eliminacion de la cara trasera
    glCullFace(GL_BACK); 
    glEnable(GL_CULL_FACE);

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
    // movimiento del raton
    glutMotionFunc(motion);
    // asignación de la funcion del raton
    glutMouseFunc(mousefunc);

	// funcion de inicialización
	initialize();
    _textura imagen1("./images/1.jpg");
    _textura imagen2("./images/2.jpg");
    _textura imagen3("./images/3.jpg");

    imagenes.push_back(imagen1);
    imagenes.push_back(imagen2);
    imagenes.push_back(imagen3);

	// inicio del bucle de eventos
	glutMainLoop();
    imagen1.destructor();
    imagen2.destructor();
    imagen3.destructor();
	return 0;
}

