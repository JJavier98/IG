# fichero Makefile
#
# Domingo Martin Perandres 2017

# nombre del fichero ejecutable
#
TARGETS= practica2

#
GLUT_DIR=/usr
GL_DIR=/usr/X11R6

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuración
#
CFLAGS=    -g -DXWINDOWS -DSHM -I/usr/include -I$(GLUT_DIR)/include -I.
CXXFLAGS=  -g -DXWINDOWS -DSHM -I/usr/include -I$(GLUT_DIR)/include -I.

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS= -L$(GL_DIR)/lib64 -lGL -L$(GLUT_DIR)/lib64 -lglut 

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
$(TARGETS) : basic_object3d.o object3d.o axis.o tetrahedron.o cube.o file_ply_stl.o objeto_ply.o practica2.o cylinder.o cone.o sphere.o base_grua.o tronco_grua.o brazo.o grua.o paralelepipedo.o nodo_3d.o extensor.o

practica2.o: practica2.cc

file_ply_stl.o: file_ply_stl.cc file_ply_stl.h

basic_object3d.o: basic_object3d.cc basic_object3d.h

object3d.o: object3d.cc object3d.h

axis.o: basic_object3d.o axis.cc axis.h

tetrahedron.o: tetrahedron.cc tetrahedron.h

cube.o: cube.cc cube.h

objeto_ply.o: objeto_ply.cc objeto_ply.h

cylinder.o: cylinder.cc cylinder.h

cone.o: cone.cc cone.h

sphere.o: sphere.cc sphere.h

base_grua.o: base_grua.cc base_grua.h

tronco_grua.o: tronco_grua.cc tronco_grua.h

brazo.o: brazo.cc brazo.h

grua.o: grua.cc grua.h

paralelepipedo.o: paralelepipedo.cc paralelepipedo.h

nodo_3d.o: nodo_3d.cc nodo_3d.h

extensor.o: extensor.cc extensor.h


# regla para limpiar
clean:
	rm -f *.o
	rm -f $(TARGETS)

tgz:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *
