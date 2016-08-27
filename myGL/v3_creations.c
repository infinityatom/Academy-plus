#include "vector3.h"
#include <stdlib.h>

t_vector3	*new_vector3(t_v3float x, t_v3float y, t_v3float z)
{
	t_vector3	*v;

	if (!(v = (t_vector3 *)malloc(sizeof(t_vector3))))
		return (NULL);
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_vector3	vector3_make_between(const t_vector3 *to, const t_vector3 *from)
{
	return ((t_vector3){to->x - from->x, to->y - from->y, to->z - from->z});
}

void		vector3_copy(t_vector3 *dest, const t_vector3 *source)
{
	dest->x = source->x;
	dest->y = source->y;
	dest->z = source->z;
}
