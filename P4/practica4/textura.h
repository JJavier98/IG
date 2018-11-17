#ifndef __TEXTURA__
#define __TEXTURA__

#include <iostream>
#include <vector>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

// NECESARIO PARA CARGAR LAS IMÁGENES DE DISCO
#include "CImg.h"

class _textura {
  public:

   _textura(const char* fname); //desmostar el constructor
   // poner id de textura a 0
   // hacer un metodo a parte para liberar la textura a parte del destructor
   // crear una funcion para hacer las normales

   GLuint id(void);

   ~_textura();

  protected:
   GLuint _id;

};

#endif
