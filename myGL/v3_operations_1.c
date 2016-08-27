#include "vector3.h"

t_vector3	*vector3_add(t_vector3 *dest, const t_vector3 *v1, const t_vector3 *v2)
{
	dest->x = v1->x + v2->x;
	dest->y = v1->y + v2->y;
	dest->z = v1->z + v2->z;
	return (dest);
}

t_vector3	*vector3_subtract(t_vector3 *dest, const t_vector3 *min, const t_vector3 *sub)
{
	dest->x = min->x - sub->x;
	dest->y = min->y - sub->y;
	dest->z = min->z - sub->z;
	return (dest);
}

t_vector3	*vector3_multiply(t_vector3 *dest, const t_vector3 *v, const t_v3float n)
{
	dest->x = v->x * n;
	dest->y = v->y * n;
	dest->z = v->z * n;
	return (dest);
}

t_vector3	*vector3_divide(t_vector3 *dest, const t_vector3 *v, const  t_v3float n)
{
	dest->x = v->x / n;
	dest->y = v->y / n;
	dest->z = v->z / n;
	return (dest);
}
