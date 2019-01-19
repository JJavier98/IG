#include "node.h"
#include "textura.h"
#include <vector>
#include <iostream>
#include <cmath>

using namespace _colors_ne;
using namespace std;

void _node::dibujarNormales(){
   GLfloat const red[3] = {1,0,0};
   glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
   glBegin(GL_LINES);
   glColor3fv(red);
   for (unsigned int i=0;i<Vertices.size();i++){
      _vertex3f suma = Vertices[i]+vertex_Normals[i];
      glVertex3fv((GLfloat *) &Vertices[i]);
      glVertex3fv((GLfloat *) &suma);
   }
   glEnd();
}

_node::_node()
{
   xt = 0.0;
   yt = 0.0;
   zt = 0.0;

   xr = 0.0;
   yr = 0.0;
   zr = 0.0;

   xs = 1.0;
   ys = 1.0;
   zs = 1.0;

   angulo1 = 0;
   velocidad = 1;

   hijos.clear();
}

_node& _node::operator = (const _node &p)
{
   if(this!=&p)
   {
      Triangles = p.Triangles;
      Vertices = p.Vertices;

      xt = p.xt;
      yt = p.yt;
      zt = p.zt;

      xr = p.xr;
      yr = p.yr;
      zr = p.zr;

      xs = p.xs;
      ys = p.ys;
      zs = p.zs;

      angulo1 = p.angulo1;
      velocidad = p.velocidad;

      hijos = p.hijos;
   }
   return *this;
}

void _node::add_hijo(_node hijo)
{
   hijos.push_back(hijo);
}

void _node::load(const vector<_vertex3f> & V, const vector<_vertex3ui> & T)
{
   Vertices = V;
   Triangles = T;
}

void _node::calcularNormales()
{
	// INICIALIZAR NORMALES
  	vector< vector<_vertex3f> > vn_vertex;
  	vn_vertex.resize(Vertices.size());
   vertex_Normals.resize(Vertices.size());
  	triangle_Normals.resize(Triangles.size());

   _vertex3f normal, //vector normal no unitario
   			 A,		//primer vector para el producto
   			 B,		//segundo vector para el producto
   			 v_normalizado, 	//vector normal unitario
   			 cero, 	//vertice0 del triangulo
   			 uno, 	//vertice1 del triangulo
   			 dos;		//vertice2 del triangulo

   int indice0,
   	 indice1,
   	 indice2;

   for (int i = 0; i < Triangles.size(); ++i)
   {
      // MULTIPLICACION VECTORIAL
   	indice0 = Triangles[i]._0;
   	indice1 = Triangles[i]._1;
   	indice2 = Triangles[i]._2;

      cero 	= Vertices[ indice0 ]; 	   // vertice0
      uno 	= Vertices[ indice1 ];  	// vertice1
      dos 	= Vertices[ indice2 ];  	// vertice2

      // Vector A
      A = uno - cero;

      // Vector B
      B = dos - cero;

      // Vector normal
      normal = A.cross_product(B);

      v_normalizado = normal;
      v_normalizado.normalize();

      for (int i = 0; i < 3; ++i)
      {
         switch(i)
         {
            case 0:
               if(1e-05 > abs(v_normalizado.x))
                  v_normalizado.x = 0;
               break;
            case 1:
               if(1e-05 > abs(v_normalizado.y))
                  v_normalizado.y = 0;
               break;
            case 2:
               if(1e-05 > abs(v_normalizado.z))
                  v_normalizado.z = 0;
               break;
         }
      }

      triangle_Normals[i] = v_normalizado; // vector normal al triangulo

      // vectores normales a los vertices
      if (vn_vertex[indice0].size()==0)
      {
      	vn_vertex[indice0].push_back(v_normalizado);
      }
      else
      {
      	bool salir = false;

      	for (int i = 0; i < vn_vertex[indice0].size() and !salir; ++i)
      	{
      		if(vn_vertex[indice0][i]==v_normalizado)
      			salir = true;
      	}
      	if (!salir)
      	{
      		vn_vertex[indice0].push_back(v_normalizado);
      	}
      }

      if (vn_vertex[indice1].size()==0)
      {
      	vn_vertex[indice1].push_back(v_normalizado);
      }
      else
      {
      	bool salir = false;

      	for (int i = 0; i < vn_vertex[indice1].size() and !salir; ++i)
      	{
      		if(vn_vertex[indice1][i]==v_normalizado)
      			salir = true;
      	}
      	if (!salir)
      	{
      		vn_vertex[indice1].push_back(v_normalizado);
      	}
      }

      if (vn_vertex[indice2].size()==0)
      {
      	vn_vertex[indice2].push_back(v_normalizado);
      }
      else
      {
      	bool salir = false;

      	for (int i = 0; i < vn_vertex[indice2].size() and !salir; ++i)
      	{
      		if(vn_vertex[indice2][i]==v_normalizado)
      			salir = true;
      	}
      	if (!salir)
      	{
      		vn_vertex[indice2].push_back(v_normalizado);
      	}
      }
   }

   for (int i = 0; i < vn_vertex.size(); ++i)
   {
   	for (int j = 0; j < vn_vertex[i].size(); ++j)
   	{
   		if(j==0)
   			vertex_Normals[i] = vn_vertex[i][j];
   		else
   			vertex_Normals[i] += vn_vertex[i][j];
   	}
   }

   for (int i = 0; i < vertex_Normals.size(); ++i)
   {
   	vertex_Normals[i].normalize();
   }
   /*cout << "triangulos: " << endl;
   for (int i = 0; i < triangle_Normals.size(); ++i)
   {
   	cout << triangle_Normals[i].x << " " << triangle_Normals[i].y << " " << triangle_Normals[i].z << endl;
   }
   cout << endl << "vertices: " << endl;
   for (int i = 0; i < vertex_Normals.size(); ++i)
   {
   	cout << vertex_Normals[i].x << " " << vertex_Normals[i].y << " " << vertex_Normals[i].z << endl;
   }*/
}


void _node::incrementar_inclinacion()
{
   if(angulo1 + velocidad < limiteInclinacion1)
      angulo1 += velocidad;
   else
      angulo1 = limiteInclinacion1-velocidad;

}
void _node::decrementar_inclinacion()
{
   if(angulo1 - velocidad > limiteInclinacion2)
      angulo1 -= velocidad;
   else
      angulo1 = limiteInclinacion2-velocidad;

}

void _node::incrementar_velocidad()
{
   if(velocidad < 10)
      velocidad += 1;
}
void _node::decrementar_velocidad()
{
   if(velocidad > 1)
      velocidad -= 1;
}

void _node::incrementar_desplazamiento_x()
{
   if(desplazamiento_x < limiteDesplazamientoX_1)
      desplazamiento_x += 0.2;
   else
      desplazamiento_x = limiteDesplazamientoX_2;
   

   // cambiar en clase correspondiente limiteDesplazamientoX_1 a otro valor para que no dispare
   /*if(desplazamiento_x < limiteDesplazamientoX_1)
      desplazamiento_x += 0.05;
      */
}
void _node::decrementar_desplazamiento_x()
{
   if(desplazamiento_x - 0.2 > limiteDesplazamientoX_2)
      desplazamiento_x -= 0.2;
   else
      desplazamiento_x = limiteDesplazamientoX_2;
   

   /*if(desplazamiento_x - 0.05 > limiteDesplazamientoX_2)
      desplazamiento_x -= 0.05;
   else
      desplazamiento_x = limiteDesplazamientoX_2;
   */
}

void _node::incrementar_desplazamiento_y()
{
   if(desplazamiento_y < limiteDesplazamientoY_1)
      desplazamiento_y += 0.2;
   else
      desplazamiento_y = limiteDesplazamientoY_2;
   

   // cambiar en clase correspondiente limiteDesplazamientoY_1 a otro valor para que no dispare
   /*if(desplazamiento_y < limiteDesplazamientoY_1)
      desplazamiento_y += 0.05;
      */
}
void _node::decrementar_desplazamiento_y()
{
   if(desplazamiento_y - 0.2 > limiteDesplazamientoY_2)
      desplazamiento_y -= 0.2;
   else
      desplazamiento_y = limiteDesplazamientoY_2;
   

   /*if(desplazamiento_y - 0.05 > limiteDesplazamientoY_2)
      desplazamiento_y -= 0.05;
   else
      desplazamiento_y = limiteDesplazamientoY_2;
   */
}

void _node::incrementar_desplazamiento_z()
{
   if(desplazamiento_z < limiteDesplazamientoZ_1)
      desplazamiento_z += 0.2;
   else
      desplazamiento_z = limiteDesplazamientoZ_2;
   

   // cambiar en clase correspondiente limiteDesplazamientoZ_1 a otro valor para que no dispare
   /*if(desplazamiento_z < limiteDesplazamientoZ_1)
      desplazamiento_z += 0.05;
      */
}
void _node::decrementar_desplazamiento_z()
{
   if(desplazamiento_z - 0.2 > limiteDesplazamientoZ_2)
      desplazamiento_z -= 0.2;
   else
      desplazamiento_z = limiteDesplazamientoZ_2;
   

   /*if(desplazamiento_z - 0.05 > limiteDesplazamientoZ_2)
      desplazamiento_z -= 0.05;
   else
      desplazamiento_z = limiteDesplazamientoZ_2;
   */
}

void _node::incrementar_rotacion()
{
   angulo1 += velocidad;
}
void _node::decrementar_rotacion()
{
   angulo1 -= velocidad;
}

////////////////////////////////////////////////////////
////////// FUNCIONES DE DIBUJADO ///////////////////////
////////////////////////////////////////////////////////

void _node::draw_point_obj()
{
   GLfloat const red[3] = {1,0,0};
   glBegin(GL_POINTS);
   glColor3fv(red);
   for (unsigned int i=0;i<Vertices.size();i++){
      glVertex3fv((GLfloat *) &Vertices[i]);
   }
   glEnd();
}

void _node::draw_line_obj()
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

void _node::draw_fill_obj(_shading_mode modo, int color)
{
	_vertex3f normal;
   GLfloat const purple[3] = {0.5,0,1};
   GLfloat const white[3] = {1,1,1};

   glPolygonMode(GL_FRONT/*_AND_BACK*/,GL_FILL);
   glBegin(GL_TRIANGLES);
   if(color == 1)
      glColor3fv(white);
   else
      glColor3fv(purple);
   for (unsigned int i=0;i<Triangles.size();i++){
   	if(modo == FLAT_MODE)
   	{
   		normal = triangle_Normals[i]; 
   		glNormal3f( normal.x, normal.y, normal.z);

	      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
	      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
	      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
   	}
   	else
   	{
   		normal = vertex_Normals[Triangles[i]._0];
   		glNormal3f( normal.x, normal.y, normal.z);
	      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

   		normal = vertex_Normals[Triangles[i]._1];
   		glNormal3f( normal.x, normal.y, normal.z);
	      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

   		normal = vertex_Normals[Triangles[i]._2];
   		glNormal3f( normal.x, normal.y, normal.z);
	      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
   	}
   }
   glEnd();
}

void _node::draw_chess_obj()
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

void _node::draw_point()
{
   GLfloat const red[3] = {1,0,0};
   glMatrixMode(GL_MODELVIEW);
   
   glPushMatrix();
   glTranslatef(xt+desplazamiento_x, yt+desplazamiento_y, zt+desplazamiento_z);
   glRotatef(angulo1+velocidad,xr,yr,zr);
   glScalef(xs,ys,zs);
   
   dibujarNormales();

      draw_point_obj();  
      
      for(int i = 0; i < hijos.size() ; ++i)
      {
         hijos[i].draw_point();
      }

   glPopMatrix();
}

void _node::draw_line()
{
   GLfloat const purple[3] = {0,0,0};
   glMatrixMode(GL_MODELVIEW);
   
   glPushMatrix();
   glTranslatef(xt+desplazamiento_x, yt+desplazamiento_y, zt+desplazamiento_z);
   glRotatef(angulo1+velocidad,xr,yr,zr);
   glScalef(xs,ys,zs);

      draw_line_obj();

      for(int i = 0; i < hijos.size() ; ++i)
         hijos[i].draw_line();
   glPopMatrix();


}

void _node::draw_fill(_shading_mode modo, int color)
{
   GLfloat const purple[3] = {0.5,0,1};
   GLfloat const white[3] = {1,1,1};
   glMatrixMode(GL_MODELVIEW);
   
   glPushMatrix();
   glTranslatef(xt+desplazamiento_x, yt+desplazamiento_y, zt+desplazamiento_z);
   glRotatef(angulo1+velocidad,xr,yr,zr);
   glScalef(xs,ys,zs);

      draw_fill_obj(modo, color);
   
      for(int i = 0; i < hijos.size() ; ++i)
         hijos[i].draw_fill(modo);
   glPopMatrix();

}

void _node::draw_chess()
{
   GLfloat const red[3] = {1,0,0};
   GLfloat const green[3] = {0,1,0};
   GLfloat const blue[3] = {0,0,1};
   GLfloat const light_blue[3] = {0,0.4,1};
   GLfloat const purple[3] = {0.5,0,1};
   GLfloat const pink[3] = {1,0,1};
   GLfloat const orange[3] = {1,0.5,0};
   GLfloat const yellow[3] = {1,1,0};

   glMatrixMode(GL_MODELVIEW);
   
   glPushMatrix();
   glTranslatef(xt+desplazamiento_x, yt+desplazamiento_y, zt+desplazamiento_z);
   glRotatef(angulo1+velocidad,xr,yr,zr);
   glScalef(xs,ys,zs);

         draw_chess_obj();

      for(int i = 0; i < hijos.size() ; ++i)
         hijos[i].draw_chess();
   glPopMatrix();
}

void _node::draw_illumination_flat_shading()
{
	glShadeModel(GL_FLAT);
	glEnable(GL_LIGHTING);

	draw_fill(FLAT_MODE);
}

void _node::draw_illumination_smooth_shading()
{
	GLfloat  luz_ambiente[ ] = {0.1, 0, 0, 1.0},
				luz_difusa[ ] = {0.1, 0, 0, 1.0};

   glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, luz_difusa);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);

	draw_fill(SMOOTH_MODE);
}

void _node::draw_texture(_shading_mode mode)
{
   glEnable(GL_TEXTURE_2D);

   glDisable(GL_TEXTURE_GEN_S);
   glDisable(GL_TEXTURE_GEN_T);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
      glTranslatef(xt+desplazamiento_x, yt+desplazamiento_y, zt+desplazamiento_z);
      glRotatef(angulo1+velocidad,xr,yr,zr);
      glScalef(xs,ys,zs);

      draw_texture_obj(mode);

      for (int i = 0; i < hijos.size(); ++i)
         hijos[i].draw_texture(mode);

   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

void _node::draw_texture_obj(_shading_mode mode)
{
   _vertex3f normal;
   glPolygonMode(GL_FRONT, GL_FILL);
   glBegin(GL_TRIANGLES);

   for (int i = 0; i < Triangles.size(); ++i)
   {
      normal = triangle_Normals[i];

      if(mode == FLAT_MODE)
      {
         glNormal3f(normal.x, normal.y, normal.z);
         if(i%2 == 0)
         {
            glTexCoord2f(0.0,1.0);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
            glTexCoord2f(1.0,1.0);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
            glTexCoord2f(1.0,0.0);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
         }
         else
         {
            glTexCoord2f(0.0,1.0);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
            glTexCoord2f(1.0,0.0);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
            glTexCoord2f(0.0,0.0);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
         }
      }
      else
      {
         if(i%2 == 0)
         {
            normal = vertex_Normals[Triangles[i]._0];
            glNormal3f( normal.x, normal.y, normal.z);
            glTexCoord2f(0.0,1.0);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

            normal = vertex_Normals[Triangles[i]._1];
            glNormal3f( normal.x, normal.y, normal.z);
            glTexCoord2f(1.0,1.0);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

            normal = vertex_Normals[Triangles[i]._2];
            glNormal3f( normal.x, normal.y, normal.z);
            glTexCoord2f(1.0,0.0);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
         }
         else
         {
            normal = vertex_Normals[Triangles[i]._0];
            glNormal3f( normal.x, normal.y, normal.z);
            glTexCoord2f(0.0,1.0);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

            normal = vertex_Normals[Triangles[i]._1];
            glNormal3f( normal.x, normal.y, normal.z);
            glTexCoord2f(1.0,0.0);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

            normal = vertex_Normals[Triangles[i]._2];
            glNormal3f( normal.x, normal.y, normal.z);
            glTexCoord2f(0.0,0.0);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
         }
      }
   }
   glEnd();
}

void _node::draw_texture_illumination_flat_shading()
{
   draw_texture(FLAT_MODE);
   draw_illumination_flat_shading();
}

void _node::draw_texture_illumination_smooth_shading()
{
   draw_texture(SMOOTH_MODE);
   draw_illumination_smooth_shading();
}

////////////////////////////////////////////////////////
//////////////// FIN DE DIBUJADO ///////////////////////
////////////////////////////////////////////////////////

void _node::rotarArbitrario(float ux, float uy, float uz, bool triangulos, bool tapas, bool rotar_completo, float angulo)
{
   // CREACION DE VERTICES
   _vertex3f aux;
   aux.x = ux;
   aux.y = uy;
   aux.z = uz;

   aux.normalize();

   ux = aux.x;
   uy = aux.y;
   uz = aux.z;

   vector<_vertex3f> newVertices;

   int iteraciones = 1;
   int vertices_ini = Vertices.size();
   _vertex3f primerVertice = Vertices[0];
   _vertex3f ultimoVertice = Vertices[vertices_ini-1];

   if(!rotar_completo)
   {
      repeticiones_necesarias = 1;
      anguloRotacion = angulo;
   }

   while(iteraciones <= repeticiones_necesarias)
   {
      float matrizX[3][3] = { {cos(anguloRotacion*iteraciones)+ux*ux*(1-cos(anguloRotacion*iteraciones)),
                        ux*uy*(1-cos(anguloRotacion*iteraciones))-uz*sin(anguloRotacion*iteraciones),
                        ux*uz*(1-cos(anguloRotacion*iteraciones))+uy*sin(anguloRotacion*iteraciones)},

                        {uy*ux*(1-cos(anguloRotacion*iteraciones))+uz*sin(anguloRotacion*iteraciones),
                        cos(anguloRotacion*iteraciones)+uy*uy*(1-cos(anguloRotacion*iteraciones)),
                        uy*uz*(1-cos(anguloRotacion*iteraciones))-ux*sin(anguloRotacion*iteraciones)},

                        {uz*ux*(1-cos(anguloRotacion*iteraciones))-uy*sin(anguloRotacion*iteraciones),
                        uz*uy*(1-cos(anguloRotacion*iteraciones))+ux*sin(anguloRotacion*iteraciones),
                        cos(anguloRotacion*iteraciones)+uz*uz*(1-cos(anguloRotacion*iteraciones))}
                        };

      for(int i = 0 ; i < vertices_ini ; ++i)
      {
         _vertex3f newV;
         for(int k = 0; k < 3; ++k)
         {
            float tmp = 0.0;
            float componente;

            for(int j = 0; j < 3 ; ++j)
            {
               switch(j)
               {
                  case 0:
                     componente = Vertices[i].x;
                     break;
                  case 1:
                     componente = Vertices[i].y;
                     break;
                  case 2:
                     componente = Vertices[i].z;
                     break;
               }

               tmp += matrizX[k][j] * componente;
            }

            switch(k)
            {
               case 0:
                  newV.x = tmp;
                  break;
               case 1:
                  newV.y = tmp;
                  break;
               case 2:
                  newV.z = tmp;
                  break;
            }
         }
         Vertices.push_back(newV);
         newVertices.push_back(newV);
      }
      ++iteraciones;
   }

   // CREACION DE TRIANGULOS
   if(triangulos)
   {
      int a = 0;
      for(int i = 0; i < repeticiones_necesarias ; ++i)
      {
         for(int j = 0; j < vertices_ini-1 ; ++j)
         {
            if(primerVertice.y < ultimoVertice.y)
            {
               Triangles.push_back(_vertex3ui(a+1,a,a+vertices_ini));
               Triangles.push_back(_vertex3ui(a+vertices_ini+1,a+1,a+vertices_ini));
            }
            else
            {
               Triangles.push_back(_vertex3ui(a,a+1,a+vertices_ini));
               Triangles.push_back(_vertex3ui(a+1,a+vertices_ini+1,a+vertices_ini));
            }

            ++a;

            if( ( a-(vertices_ini * i) )%(vertices_ini-1) == 0)
               ++a;
         }
      }
   }

   // CREACION DE TAPAS
   if(tapas)
   {
      bool primeraTapa = true;
      bool segundaTapa = true;
      if (primerVertice.x/ux == primerVertice.y/uy and primerVertice.y/uy == primerVertice.z/uz)
         primeraTapa = false;
      if (ultimoVertice.x/ux == ultimoVertice.y/uy and ultimoVertice.y/uy == ultimoVertice.z/uz)
         segundaTapa = false;

      if(primeraTapa)
      {        
         int a = 0;
         float independiente = -(ux*(-primerVertice.x) + uy*(-primerVertice.y) + uz*(-primerVertice.z));
         float divisor = ux*ux + uy*uy + uz*uz;
         float parametro = independiente/divisor;

         _vertex3f tapa1;
         tapa1.x = ux*parametro;
         tapa1.y = uy*parametro;
         tapa1.z = uz*parametro;

         Vertices.push_back(tapa1);
         newVertices.push_back(tapa1);
      }

      if(segundaTapa)
      {
         float independiente = -(ux*(-ultimoVertice.x) + uy*(-ultimoVertice.y) + uz*(-ultimoVertice.z));
         float divisor = ux*ux + uy*uy + uz*uz;
         float parametro = independiente/divisor;

         _vertex3f tapa2;
         tapa2.x = ux*parametro;
         tapa2.y = uy*parametro;
         tapa2.z = uz*parametro;

         Vertices.push_back(tapa2);
         newVertices.push_back(tapa2);
      }

      if(primeraTapa)
      {
         int a = 0;
         for (int i = 0; i < repeticiones_necesarias; ++i)
         {
            if(primerVertice.y < ultimoVertice.y)
            {
               Triangles.push_back(_vertex3ui(Vertices.size()-2,a+vertices_ini,a));
            }
            else
            {
               Triangles.push_back(_vertex3ui(Vertices.size()-2,a,a+vertices_ini));
            }
            a+=vertices_ini;
         }
      }

      if(segundaTapa)
      {
         int b = vertices_ini-1;
         for (int i = 0; i < repeticiones_necesarias; ++i)
         {
            if(primerVertice.y < ultimoVertice.y)
            {
               Triangles.push_back(_vertex3ui(Vertices.size()-1,b,b+vertices_ini));
            }
            else
            {
               Triangles.push_back(_vertex3ui(b,Vertices.size()-1,b+vertices_ini));
            }
            b+=vertices_ini;
         }
      }
   }

   if(!rotar_completo)
      Vertices = newVertices;
}