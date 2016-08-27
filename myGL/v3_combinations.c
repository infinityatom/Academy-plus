#include "vector3.h"

t_v3float	vector3_distance(const t_vector3 *a, const t_vector3 *b)
{
	return (sqrt( pow(a->x - b->x, 2) + pow(a->y - b->y, 2) +
				pow(a->z - b->z, 2)));
}

double		vector3_distancesq(t_vector3 *a, t_vector3 *b)
{
	return (pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + pow(a->z - b->z, 2));
}

t_v3float	vector3_angle(const t_vector3 *a, const t_vector3 *b)
{
	return (acos(vector3_dot(a,b) / vector3_length(a) / vector3_length(b)));
}

t_vector3	*vector3_reflect(t_vector3 *dest, const t_vector3 *inc, const t_vector3 *norm)
{
	t_v3float dp;

	dp = 2 * vector3_dot(norm, inc);
	dest->x = inc->x - dp * norm->x;
	dest->y = inc->y - dp * norm->y;
	dest->z = inc->z - dp * norm->z;
	return (dest);
}
