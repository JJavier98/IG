/*
 * Practicas de IG
 * Domingo Martin Perandres© 2014-2018
 * dmartin@ugr.es
 *
 * GPL 3
 */

#include "basic_object3d.h"

/**
 *
 *@param
 *@returns
 */

void _basic_object3D::draw_point()
{
   GLfloat const red[3] = {1,0,0};
   glBegin(GL_POINTS);
   glColor3fv(red);
   for (unsigned int i=0;i<Vertices.size();i++){
      glVertex3fv((GLfloat *) &Vertices[i]);
   }
   glEnd();
}
