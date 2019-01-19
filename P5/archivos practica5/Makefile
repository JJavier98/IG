# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= practica5

#
INC=-I./
GLUT_DIR=/usr/X11R6
GL_DIR=/usr/X11R6

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuración
#
CFLAGS=   -std=c++11 -g -DXWINDOWS -DSHM -I/usr/include $(INC)
CXXFLAGS= -std=c++11 -g -DXWINDOWS -DSHM -I/usr/include $(INC)

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -L$(GL_DIR)/lib64 -lGL -L$(GLUT_DIR)/lib64 -lglut

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
$(TARGETS) : basic_object3d.o object3d.o axis.o tetrahedron.o practica5.o

practica5.o: practica5.cc

basic_object3d.o: basic_object3d.cc basic_object3d.h

object3d.o: object3d.cc object3d.h

axis.o: basic_object3d.o axis.cc axis.h

tetrahedron.o: tetrahedron.cc tetrahedron.h

#
#
clean:
	rm -f *.o
	rm -f $(TARGETS)

#
#
redo:
	touch *.cc
	make

#
#
superclean:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)

#
#
tgz:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *

