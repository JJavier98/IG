#include "grua.h"
#include <iostream>

using namespace std;

_grua::_grua()
{

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
