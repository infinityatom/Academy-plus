#include "myGL.h"
#include "myLib/myLib.h"

void	vector3_make3f1(t_vector3 *v, t_v3float x, t_v3float y, t_v3float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

int		main(void)
{
	t_vector3	vector;

	vector3_make3f1(&vector, 1.24, 23.3, 3.23);

	ft_printf("%f %f %f\n", vector.x, vector.y, vector.z);
	return (0);
}
