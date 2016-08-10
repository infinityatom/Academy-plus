
#ifndef MYGL_H
# define MYGL_H

# include "vector3.h"

# define ullong	unsigned long long
# define value unsigned char
# define rgba unsigned long
# define rgb unsigned long

typedef struct	s_ullong3 {
	ullong		a;
	ullong		b;
	ullong		c;
}				ullong3;

typedef struct	s_camera {
	vector3		position;
	vector3		direction;
}				camera;

typedef struct	s_mesh {
	vector3		coord;
	vector3		rotation;
	v3float		scale;
	vector3		*vertices;
	ullong3		*poligons;
}				mesh;

typedef struct	s_material {
	rgba		color;
}				material;

rgba	new_rgba(value r, value g, value b, value a);
rgb		new_rgb(value r, value g, value b);

#endif
