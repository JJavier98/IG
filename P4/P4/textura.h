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
	_textura(const char* fname);

	void id_0(){ _id=0; }

	GLuint id(void);

	void destructor();

	~_textura();

protected:
	GLuint _id;
};

#endif
