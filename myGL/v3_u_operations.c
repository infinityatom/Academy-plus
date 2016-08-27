#include "vector3.h"
#include "myLib/myLib.h"

t_v3float		vector3_length(const t_vector3 *a)
{
	return (sqrt(a->x*a->x + a->y*a->y + a->z*a->z));
}

t_vector3		*vector3_normalize(t_vector3 *a)
{
	t_v3float	normalizeLength;

	normalizeLength = vector3_length(a);
	if(normalizeLength <= EPSILON)
	{
		ft_putstr("Cannot normalize degenerate vector3\n");
		return (a);
	}
	vector3_divide(a, a, normalizeLength);
	return (a);
}

t_vector3		*vector3_invert(t_vector3 *dest, const t_vector3 *v)
{
	dest->x = -v->x;
	dest->y = -v->y;
	dest->z = -v->z;
	return (dest);
}

void		vector3_print(const t_vector3 *v)
{
	ft_printf("%f %f %f\n", v->x, v->y, v->z);
}
