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
		(void)b;
		(void)r;
		(void)cam;
		pos_rot_xyz(&(b->o), get_pos(0, 0, 0), r);
		pos_rot_xyz(&(b->k), get_pos(0, 0, 0), r);
//		pos_rot_xyz(&(b->k), b->o, r);
//		b->k = pos_normalize(b->k);
		copy_pos(&(b->j), pos_cross_product(b->k, cam->v_up));
//		b->j = pos_normalize(b->j);
		copy_pos(&(b->i), pos_cross_product(b->j, b->k));
///		b->i = pos_normalize(b->i);

//		pos_rot_xyz(&(b->j), b->o, r);
//		pos_rot_xyz(&(b->k), b->o, r);
	}
}
