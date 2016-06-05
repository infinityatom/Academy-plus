#include "vector3.h"

v3float	vector3_distance(const vector3 *a, const vector3 *b)
{
	return (sqrt( pow(a->x - b->x, 2) + pow(a->y - b->y, 2) +
				pow(a->z - b->z, 2)));
}

double	vector3_distancesq(vector3 *a, vector3 *b)
{
	return (pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + pow(a->z - b->z, 2));
}

v3float	vector3_angle(const vector3 *a, const vector3 *b)
{
	return (acos(vector3_dot(a,b) / vector3_length(a) / vector3_length(b)));
}

vector3	*vector3_reflect(vector3 *dest, const vector3 *inc, const vector3 *norm)
{
	v3float dp;

	dp = 2 * vector3_dot(norm, inc);
	dest->x = inc->x - dp * norm->x;
	dest->y = inc->y - dp * norm->y;
	dest->z = inc->z - dp * norm->z;
	return (dest);
}
