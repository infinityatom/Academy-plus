#include "vector3.h"
#include <stdlib.h>

vector3	*vector3_copy(vector3 *dest, const vector3 *source)
{
	dest->x = source->x;
	dest->y = source->y;
	dest->z = source->z;
	return (dest);
}

vector3	*vector3_random(vector3 *v)
{
	do {
		v->x = (double)rand()/RAND_MAX*2-1;
		v->y = (double)rand()/RAND_MAX*2-1;
		v->z = (double)rand()/RAND_MAX*2-1;
	} while (v->x*v->x + v->y*v->y + v->z*v->z > 1.0);
	return (v);
}

vector3	*vector3_make3f(vector3 *v, v3float x, v3float y, v3float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

vector3	*vector3_make2v(vector3 *v, const vector3 *to, const vector3 *from)
{
	v->x = to->x - from->x;
	v->y = to->y - from->y;
	v->z = to->z - from->z;
	return (v);
}
