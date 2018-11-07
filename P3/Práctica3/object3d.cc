#include "object3d.h"

using namespace _colors_ne;

void _object3D::draw_line()
{
   GLfloat const purple[3] = {0,0,0};
   glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
   glBegin(GL_TRIANGLES);
   glColor3fv(purple);
   for (unsigned int i=0;i<Triangles.size();i++){
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
   }
   glEnd();
}

void _object3D::draw_fill()
{
   GLfloat const purple[3] = {0.5,0,1};
   glPolygonMode(GL_FRONT/*_AND_BACK*/,GL_FILL);
   glBegin(GL_TRIANGLES);
   glColor3fv(purple);
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
   GLfloat const red[3] = {1,0,0};
   GLfloat const green[3] = {0,1,0};
   GLfloat const blue[3] = {0,0,1};
   GLfloat const light_blue[3] = {0,0.4,1};
   GLfloat const purple[3] = {0.5,0,1};
   GLfloat const pink[3] = {1,0,1};
   GLfloat const orange[3] = {1,0.5,0};
   GLfloat const yellow[3] = {1,1,0};

   glPolygonMode(GL_FRONT/*_AND_BACK*/,GL_FILL);
   glBegin(GL_TRIANGLES);
   for (unsigned int i=0;i<Triangles.size();i++){
      if (i%2==0) glColor3fv(light_blue);
      else glColor3fv(yellow);
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