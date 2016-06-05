#include "vector3.h"

vector3	*vector3_scalar_add(vector3 *dest, const vector3 *v, const v3float s)
{
	dest->x = v->x + s;
	dest->y = v->y + s;
	dest->z = v->z + s;
	return (dest);
}

vector3	*vector3_scalar_sub(vector3 *dest, const vector3 *v, const v3float s)
{
	dest->x = v->x - s;
	dest->y = v->y - s;
	dest->z = v->z - s;
	return (dest);
}

v3float	vector3_dot(const vector3 *a, const vector3 *b)
{
	return (a->x*b->x + a->y*b->y + a->z*b->z);
}

vector3	*vector3_cross(vector3 *dest, const vector3 *a, const vector3 *b)
{
	dest->x = a->y*b->z - a->z*b->y;
	dest->y = a->z*b->x - a->x*b->z;
	dest->z = a->x*b->y - a->y*b->x;
	return (dest);
}
