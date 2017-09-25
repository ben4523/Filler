/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_coor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:52:02 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/12 10:22:34 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_check_line(t_coor *coor, char *line, char **pc, char **map)
{
	static int		compt = 0;

	if (line[0] == '$' && line[1] == '$' && ft_strlen(line) > 10)
		coor->id = ((ft_atoi(&line[10]) == 1) ? 'O' : 'X');
	else if (line[0] == 'P' && line[1] == 'l' && ft_strlen(line) > 13)
		ft_get_map_coor(coor, line);
	else if (line[0] == 'P' && line[1] == 'i' && ft_strlen(line) > 9)
		ft_get_pc_coor(coor, line);
	else if (ft_isdigit(line[0]) == 1 && ft_strlen(line) > 4)
		*map = ft_get_map(line, *map);
	else if (line[0] == '.' || line[0] == '*')
	{
		compt++;
		*pc = ft_get_pc(line, *pc);
		if (compt == coor->pc.pc_i)
		{
			coor->done = 1;
			compt = 0;
		}
	}
}

void		ft_get_map_coor(t_coor *coor, char *line)
{
	coor->map_i = ft_atoi(&line[7]);
	line = ft_strchr(&line[8], ' ');
	if (line != NULL)
		coor->map_j = ft_atoi(&line[0]);
}

void		ft_get_pc_coor(t_coor *coor, char *line)
{
	coor->pc.pc_i = ft_atoi(&line[5]);
	line = ft_strchr(&line[6], ' ');
	if (line != NULL)
		coor->pc.pc_j = ft_atoi(&line[0]);
}

char		*ft_get_map(char *line, char *map)
{
	char	*tmp;

	tmp = map;
	map = ft_strnjoin(3, tmp, &line[4], "\n");
	ft_memdel((void **)&tmp);
	return (map);
}

char		*ft_get_pc(char *line, char *pc)
{
	char	*tmp;

	tmp = pc;
	pc = ft_strnjoin(3, tmp, line, "\n");
	ft_memdel((void **)&tmp);
	return (pc);
}
