#include "object3d.h"

using namespace _colors_ne;

void _object3D::draw_line()
{
   glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
   glBegin(GL_TRIANGLES);
   for (unsigned int i=0;i<Triangles.size();i++){
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
   }
   glEnd();
}

void _object3D::draw_fill()
{
   glPolygonMode(GL_FRONT/*_AND_BACK*/,GL_FILL);
   glBegin(GL_TRIANGLES);
   for (unsigned int i=0;i<Triangles.size();i++){
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
   }
   glEnd();
}


/**
 *
 *@param
 *@returns
 */

void _object3D::draw_chess()
{
   glPolygonMode(GL_FRONT/*_AND_BACK*/,GL_FILL);
   glBegin(GL_TRIANGLES);
   for (unsigned int i=0;i<Triangles.size();i++){
      if (i%2==0) glColor3fv((GLfloat *) &RED);
      else glColor3fv((GLfloat *) &GREEN);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
   }
   glEnd();
}

_object3D::_object3D()
{
}

_object3D& _object3D::operator = (const _object3D &p)
{
   if(this!=&p)
   {
      Triangles = p.Triangles;
      Vertices = p.Vertices;
   }
   return *this;
}