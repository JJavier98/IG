#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>



void Ejes (int width)
{   
    glLineWidth(width);
    glBegin(GL_LINES);
       glColor3f(1.0,0.0,0.0);
       glVertex3f(-1.0,0.0,0.0);
       glVertex3f(1.0,0.0,0.0);
       glColor3f(0.0,1.0,0.0);
       glVertex3f(0.0,-1.0,0.0);
       glColor3f(1.0,1.0,0.0);
       glVertex3f(0.0,1.0,0.0);   
    glEnd();
   
       
}


void Monigote ()
{
  
 
// cara
	glLineWidth(1);
	glColor3f(1.0,0.8,0.6);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glVertex3f(-0.2,0.0,0.0);
		glVertex3f(0.2,0.0,0.0);
		glVertex3f(0.2,0.55,0.0);
		glVertex3f(-0.2,0.55,0.0);
	glEnd(); 

	glColor3f(0.0,0.0,0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
		glVertex3f(-0.2,0.0,0.0);
		glVertex3f(0.2,0.0,0.0);
		glVertex3f(0.2,0.55,0.0);
		glVertex3f(-0.2,0.55,0.0);
	glEnd(); 

	
// nariz
	glColor3f(1.0,0.0,0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glVertex3f(-0.05,0.2,0.0);
		glVertex3f(0.0,0.3,0.0);
		glVertex3f(0.05,0.2,0.0);
	glEnd();

// oreja dcha
	glColor3f(1.0,0.8,0.6);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glVertex3f(0.2,0.2,0.0);
		glVertex3f(0.27,0.2,0.0);
		glVertex3f(0.27,0.4,0.0);
		glVertex3f(0.2,0.4,0.0);
	glEnd(); 

	glColor3f(0.0,0.0,0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
		glVertex3f(0.2,0.2,0.0);
		glVertex3f(0.27,0.2,0.0);
		glVertex3f(0.27,0.4,0.0);
		glVertex3f(0.2,0.4,0.0);
	glEnd(); 

// oreja izda
	glColor3f(1.0,0.8,0.6);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glVertex3f(-0.2,0.2,0.0);
		glVertex3f(-0.27,0.2,0.0);
		glVertex3f(-0.27,0.4,0.0);
		glVertex3f(-0.2,0.4,0.0);
	glEnd(); 

	glColor3f(0.0,0.0,0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
		glVertex3f(-0.2,0.2,0.0);
		glVertex3f(-0.27,0.2,0.0);
		glVertex3f(-0.27,0.4,0.0);
		glVertex3f(-0.2,0.4,0.0);
	glEnd(); 
// ojos
	const float RADIO_OJOS = 0.05;
	const float ALTURA_OJOS = 0.4;
	const float X_DCHA = 0.1;
	const float X_IZDA = -0.1;
// ojo dcho
	float cordx, cordy;
	glColor3f(0.0,0.0,1.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		for (float i = 0; i < 10; i+=0.01)
		{
			cordx = RADIO_OJOS * cos(i);
			cordy = RADIO_OJOS * sin(i);
			glVertex3f(cordx + X_DCHA, cordy + ALTURA_OJOS, 0.0);
		}
	glEnd(); 

// ojo izdo
	glColor3f(0.0,0.0,1.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		for (float i = 0; i < 10; i+=0.01)
		{
			cordx = RADIO_OJOS * cos(i);
			cordy = RADIO_OJOS * sin(i);
			glVertex3f(cordx + X_IZDA, cordy + ALTURA_OJOS, 0.0);
		}
	glEnd(); 

// sombrero
	glColor3f(0.0,0.0,0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glVertex3f(0.27, 0.55, 0.0);
		glVertex3f(0.27, 0.67, 0.0);
		glVertex3f(-0.27, 0.67, 0.0);
		glVertex3f(-0.27, 0.55, 0.0);
	glEnd(); 

	glColor3f(0.0,0.0,0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glVertex3f(0.2, 0.67, 0.0);
		glVertex3f(0.2, 0.9, 0.0);
		glVertex3f(-0.2, 0.9, 0.0);
		glVertex3f(-0.2, 0.67, 0.0);
	glEnd(); 

// boca
	const float RADIO_BOCA = 0.03;
	const float ALTURA_BOCA = 0.1;
	
	glColor3f(1.0,0.7,0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		for (float i = +3.141592/2; i < 3.1415926+3.1415926/2; i+=0.001)
		{
			cordx = RADIO_BOCA * cos(i);
			cordy = RADIO_BOCA * sin(i);
			glVertex3f(cordx + X_IZDA, cordy + ALTURA_BOCA, 0.0);
		}
	glEnd(); 

	glColor3f(1.0,0.7,0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		for (float i = -3.141592/2; i < 3.1415926-3.1415926/2; i+=0.001)
		{
			cordx = RADIO_BOCA * cos(i);
			cordy = RADIO_BOCA * sin(i);
			glVertex3f(cordx + X_DCHA, cordy + ALTURA_BOCA, 0.0);
		}
	glEnd(); 

	glColor3f(1.0,0.7,0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glVertex3f(0.1, 0.07, 0.0);
		glVertex3f(0.1, 0.13, 0.0);
		glVertex3f(-0.1, 0.13, 0.0);
		glVertex3f(-0.1, 0.07, 0.0);
	glEnd(); 
}


static void Init( )
{

   glShadeModel( GL_FLAT);
}


static void Reshape( int width, int height )
{
    glViewport(0, 0, (GLint)width, (GLint)height);
    glOrtho (-1.0, 1.0,-1.0, 1.0, -10, 10.0);
}

static void Display( )
{

  glClearColor(0.5,0.5,0.5,0.0);
  glClear( GL_COLOR_BUFFER_BIT );
   
  
   
   Ejes(6);
   Monigote();
   
   glFlush();
}


static void Keyboard(unsigned char key, int x, int y )
{
 
  if (key==27)
      exit(0);

}


int main( int argc, char **argv )
{
   glutInit(&argc,argv);
   glutInitDisplayMode( GLUT_RGB );

   glutInitWindowPosition( 20, 100 );
   glutInitWindowSize(500, 500 );
   glutCreateWindow("Practica 0 IG");


   Init();

   glutReshapeFunc(Reshape);
   glutDisplayFunc(Display);
   glutKeyboardFunc(Keyboard);
  
   glutMainLoop( );

   return 0;
}

