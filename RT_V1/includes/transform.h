#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "rt.h"

/*
** transform_00.c
*/

t_pos		transform(t_base a, t_base b, t_pos pos);
t_pos		transform_rev(t_base b, t_pos pos);
void		test_transform(void); //Debug

#endif
