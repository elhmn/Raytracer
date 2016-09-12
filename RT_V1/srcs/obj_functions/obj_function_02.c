#include "rt.h"
#include "object.h"
#include "libft.h"
#include "check_errors.h"
#include <stdlib.h>

/*
** Plane rotation function
*/

void	rot_plane(t_obj *plane, t_pos r)
{
	t_dataPlane	*data;

	data = NULL;
	if (plane)
	{
		if (!(data = (t_dataPlane*)plane->data))
			check_errors(NUL, "plane->data", "obj->function_02.c");
		pos_rot_xyz(&(data->v_normal), plane->spPos, r);
	}
}

/*
** I will work on the camera rotation that later
*/

void	rot_camera(t_camera *cam, t_pos r)
{
	t_base	*b;

	b = NULL;
	if (cam)
	{
		b = &cam->space;
		pos_rot_xyz(&(b->i), b->o, r);
		pos_rot_xyz(&(b->j), b->o, r);
		pos_rot_xyz(&(b->k), b->o, r);
	}
}
