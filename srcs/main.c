/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:52:43 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/12 10:22:47 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			free_tab(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void			free_filler(char **map, char **pc, t_coor **coor)
{
	ft_memdel((void **)map);
	ft_memdel((void **)pc);
	ft_memdel((void **)coor);
}

void			parsing_done(t_coor *coor, char **map, char **pc)
{
	coor->pc.shape = ft_strsplit(*pc, '\n');
	coor->map = ft_strsplit(*map, '\n');
	ft_get_coor_stars(coor);
	ft_solve(coor);
	ft_memdel((void**)map);
	ft_memdel((void**)pc);
	free_tab(coor->pc.shape);
	free_tab(coor->map);
	free(coor->pc.stars_i);
	free(coor->pc.stars_j);
}

int				main(void)
{
	char		*line;
	t_coor		*coor;
	char		*map;
	char		*pc;

	if (!(map = ft_strnew(0)))
		return (0);
	if (!(pc = ft_strnew(0)))
		return (0);
	if (!(coor = ft_memalloc(sizeof(t_coor))))
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		ft_check_line(coor, line, &pc, &map);
		if (coor->done == 1)
		{
			parsing_done(coor, &map, &pc);
			map = ft_strnew(0);
			pc = ft_strnew(0);
		}
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	free_filler(&map, &pc, &coor);
	return (0);
}
