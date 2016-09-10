#ifndef PUT_VAR_H
# define PUT_VAR_H

# include "rt.h"
# include "object.h"

/*
** put_var_00.c
*/

void			put_pos(t_pos pos);
void			put_base(t_base base);
void			put_camera(t_camera camera);
void			put_space(t_space space);
void			put_screen(t_screen screen);

/*
** put_var_01.c
*/

void			put_ray(t_ray ray);
void			put_dataSphere(t_dataSphere *data);
void			put_type(int type);
void			put_obj(void *obj);
void			put_dataPlane(t_dataPlane *data);

#endif
