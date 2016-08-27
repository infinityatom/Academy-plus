
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
}				t_ullong3;

typedef struct	s_camera {
	t_vector3	posit;
	t_vector3	direc;
}				t_camera;

typedef struct	s_mesh {
	t_vector3	coord;
	t_vector3	rotat;
	t_v3float	scale;
	t_vector3	*vert;
	ullong		vert_nr;
	enum {
		gl_points,
		gl_quad,
		gl_lines,
		gl_polygon,
		gl_triangle,
		gl_quad_strip,
		gl_triangle_strip,
		gl_triangle_fan
	}	primitive;
}				t_mesh;

typedef struct	s_object {
	t_vector3	rotat;
	t_vector3	coord;
	t_v3float	scale;
	t_mesh		*mesh;
}				t_object;

typedef struct	s_material {
	rgba		color;
}				t_material;

rgba	new_rgba(value r, value g, value b, value a);
rgb		new_rgb(value r, value g, value b);
rgba	str_to_rgba(char *str);
rgb		str_to_rgb(char *str);

#endif
