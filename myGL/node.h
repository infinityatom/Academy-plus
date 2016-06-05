
#ifndef NODE_H
# define NODE_H

# include "vector3.h"

typedef struct	s_intvector3 {
	v3float		x;
	v3float		y;
	v3float		z;
}				intvector3;

typedef struct	s_node {
	vector3		coord;
	vector3		rotation;
	v3float		scale;
}				node;

typedef struct	s_camera {
	node		*node;
}				camera;

typedef struct	s_mesh {
	node		*node;
	vector3		*vertices;
	intvector3	*poligons;
}				mesh;

#endif
