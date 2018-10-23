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
	glScalef(1,0.5,0.5);
	glTranslatef(-0.8,3.0,0.0);
	glRotatef(60,0,0,1);
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
	glScalef(1,0.5,0.5);
	glTranslatef(-0.8,3.0,0.0);
	glRotatef(60,0,0,1);
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
	glScalef(1,0.5,0.5);
	glTranslatef(-0.8,3.0,0.0);
	glRotatef(60,0,0,1);
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
	glScalef(1,0.5,0.5);
	glTranslatef(-0.8,3.0,0.0);
	glRotatef(60,0,0,1);
	(brazo3_n.obj).draw_chess();
	glPopMatrix();
}
