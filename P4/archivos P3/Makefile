# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= practica3

#
GLUT_DIR=/usr
GL_DIR=/usr/X11R6

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuración
#
CFLAGS=    -g -DXWINDOWS -DSHM -I/usr/include -I$(GLUT_DIR)/include -I. -I./CImg-2.1.5 --std=c++11
CXXFLAGS=  -g -DXWINDOWS -DSHM -I/usr/include -I$(GLUT_DIR)/include -I. -I./CImg-2.1.5 --std=c++11

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS= -L$(GL_DIR)/lib64 -lGL -L$(GLUT_DIR)/lib64 -lglut -L/usr/X11R6/lib/ -lGLU -lm -lX11 -lpthread

# definicion del compilador
#
CC = g++

# sufijos
.SUFFIXES: .cc .c .o

# Reglas
# $< -> todas las dependencias que han cambiado
# $@ -> el objetivo
# $^ -> todas las dependencias

# como pasar de .cc a .o

.cc.o:
	$(CC) $(CXXFLAGS) -c $<

# como pasar de .o a ejecutable (sin sufijo)

.o:
	$(CC) -o $@ $^ $(LDFLAGS)

# orden que sera ejecutada por defecto
#

default : $(TARGETS)

# regla de dependencias
#
$(TARGETS) : axis.o tetrahedron.o cube.o file_ply_stl.o practica3.o cylinder.o cone.o sphere.o base_grua.o tronco_grua.o brazo.o\
		grua.o paralelepipedo.o extensor.o punta.o cuenco.o toro.o cuerpo_toro.o cabeza_toro.o piernas_toro.o node.o textura.o

practica3.o: practica3.cc

file_ply_stl.o: file_ply_stl.cc file_ply_stl.h

axis.o: node.o axis.cc axis.h

tetrahedron.o: tetrahedron.cc tetrahedron.h

cube.o: cube.cc cube.h

cylinder.o: cylinder.cc cylinder.h

cone.o: cone.cc cone.h

sphere.o: sphere.cc sphere.h

base_grua.o: base_grua.cc base_grua.h

tronco_grua.o: tronco_grua.cc tronco_grua.h

brazo.o: brazo.cc brazo.h

grua.o: grua.cc grua.h

paralelepipedo.o: paralelepipedo.cc paralelepipedo.h

extensor.o: extensor.cc extensor.h

punta.o: punta.cc punta.h

cuenco.o: cuenco.cc cuenco.h

toro.o: toro.cc toro.h

cuerpo_toro.o: cuerpo_toro.cc cuerpo_toro.h

cabeza_toro.o: cabeza_toro.cc cabeza_toro.h

piernas_toro.o: piernas_toro.cc piernas_toro.h

node.o: node.cc node.h

textura.o: textura.cc textura.h


# regla para limpiar
clean:
	rm -f *.o
	rm -f $(TARGETS)

tgz:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *
