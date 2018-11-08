#include "cuenco.h"
#include <math.h>

_cuenco::_cuenco(float R, float H)
{
	for (float i = -M_PI/2; i < 0; i+=0.1)
	{
		Vertices.push_back(_vertex3f(cos(i)*R,sin(i)*H,0.0));
	}

	float newR = R-0.03;
	float newH = H-0.03;

	for (float i = 0; i > -M_PI/2; i-=0.1)
	{
		Vertices.push_back(_vertex3f(cos(i)*newR,sin(i)*newH,0.0));
	}
	this->rotarArbitrario(0,1,0,true,true,true,0);
}