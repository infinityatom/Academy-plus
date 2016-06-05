
#ifndef NODE_H
# define NODE_H

# include "vector3.h"

typedef struct	s_node {
	vector3		coord;
	vector3		rotation;
	v3float		scale;
}				node;

#endif
