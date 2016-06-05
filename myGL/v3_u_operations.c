#include "vector3.h"
#include <unistd.h>
#include <stdio.h>

v3float		vector3_length(const vector3 *a)
{
	return (sqrt(a->x*a->x + a->y*a->y + a->z*a->z));
}

vector3		*vector3_normalize(vector3 *a)
{
	v3float normalizeLength;

	normalizeLength = vector3_length(a);
	if(normalizeLength <= EPSILON)
	{
		write(1, "cannot normalize degenerate vector3\n", 36);
		return (a);
	}
	vector3_divide(a, a, normalizeLength);
	return (a);
}

vector3		*vector3_invert(vector3 *dest, const vector3 *v)
{
	dest->x = -v->x;
	dest->y = -v->y;
	dest->z = -v->z;
	return (dest);
}

void		vector3_print(const vector3 *v)
{
	printf("%.2f %.2f %.2f\n", v->x, v->y, v->z);
}
