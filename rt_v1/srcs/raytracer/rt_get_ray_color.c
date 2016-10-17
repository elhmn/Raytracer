/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_ray_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 20:09:44 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 20:11:06 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static void	rt_get_ray_color(t_ray *r, t_list *o, t_rt *rt)
{
	t_list	*list;
	t_obj	*obj;
	t_obj	*tmp;
	double	ret;
	double	d;

	list = o;
	d = MAX_DBL;
	if (!rt || !r)
		check_errors(NUL, "raytracer.c", "rt && r");
	tmp = NULL;
	while (list != NULL)
	{
		obj = (t_obj*)list->content;
		if (obj && d > (ret = get_distance(r, obj, rt))
			&& ret >= 0)
		{
			tmp = obj;
			d = ret;
		}
		list = list->next;
	}
	if (!tmp)
		return ;
	r->col = tmp->col;
	if (tmp && tmp->material)
		rt_get_color(r, tmp, rt,
				get_point(rt->camera->sp.o, r->rd, d));
}
