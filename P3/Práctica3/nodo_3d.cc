#include "nodo_3d.h"

_node3d::_node3d()
{
	hijo = NULL;
}

_node3d::_node3d(const _object3D o, _node3d * h)
{
	obj = o;
	hijo = h;
}

_node3d& _node3d::operator = (const _node3d &p)
{
	if(this!=&p)
	{
		obj = p.obj;
		hijo = p.hijo;
	}
	return *this;
}

/*void _node3d::draw_line()
{
	if(hijo == NULL)
	{
		obj.draw_line();
	}
	else
	{
		hijo->obj.draw_line();
	}
}

void _node3d::draw_fill()
{
	if(hijo == NULL)
	{
		obj.draw_fill();
	}
	else
	{
		hijo->obj.draw_fill();
	}
}

void _node3d::draw_chess()
{
	if(hijo == NULL)
	{
		obj.draw_chess();
	}
	else
	{
		hijo->obj.draw_chess();
	}
}*/
