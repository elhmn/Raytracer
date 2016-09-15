#include "rt.h"
#include "object.h"
#include "libft.h"
#include "check_errors.h"
#include "put_var.h"
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
** Solve that camera rotation issue later
*/

void	rot_camera(t_camera *cam, t_pos r)
{
	t_pos	*o;
	t_pos	*u;
	t_pos	*v;
	t_pos	*w;

	(void)r;
	(void)cam;
	(void)o;
	if (cam)
	{
		o = &cam->spPos;
		u = &cam->u;
		v = &cam->v;
		w = &cam->w;
		pos_rot_xyz(o, get_pos(0, 0, 0), r);
		pos_rot_xyz(w, get_pos(0, 0, 0), r);
		pos_rot_xyz(u, get_pos(0, 0, 0), r);
		pos_rot_xyz(v, get_pos(0, 0, 0), r);
//		copy_pos(v, pos_cross_product(*w, cam->v_up));
//		copy_pos(u, pos_cross_product(*v, *w));
		put_var_dbl("w", pos_norme(*w));
		put_var_dbl("u", pos_norme(*u));
		put_var_dbl("v", pos_norme(*v));
		*u = pos_normalize(*u);
		*v = pos_normalize(*v);
		*w = pos_normalize(*w);
		put_var_dbl("w", pos_norme(*w));
		put_var_dbl("u", pos_norme(*u));
		put_var_dbl("v", pos_norme(*v));
	}
}
