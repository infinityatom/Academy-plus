#include "vector3.h"

vector3	*vector3_add(vector3 *dest, const vector3 *v1, const vector3 *v2)
{
	dest->x = v1->x + v2->x;
	dest->y = v1->y + v2->y;
	dest->z = v1->z + v2->z;
	return (dest);
}

vector3	*vector3_subtract(vector3 *dest, const vector3 *min, const vector3 *sub)
{
	dest->x = min->x - sub->x;
	dest->y = min->y - sub->y;
	dest->z = min->z - sub->z;
	return (dest);
}

vector3	*vector3_multiply(vector3 *dest, const vector3 *v, const v3float n)
{
	dest->x = v->x * n;
	dest->y = v->y * n;
	dest->z = v->z * n;
	return (dest);
}

vector3	*vector3_divide(vector3 *dest, const vector3 *v, const  v3float n)
{
	dest->x = v->x / n;
	dest->y = v->y / n;
	dest->z = v->z / n;
	return (dest);
}
