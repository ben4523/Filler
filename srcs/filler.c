/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:51:53 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/12 10:22:26 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				get_the_lowest_middle_stars(t_coor *coor)
{
	int				count;
	int				i_max;

	count = -1;
	i_max = 0;
	while (++count < coor->pc.cnt_stars)
	{
		if (coor->pc.stars_i[count] > i_max)
			i_max = coor->pc.stars_i[count];
	}
	count = coor->pc.cnt_stars - 1;
	while (coor->pc.stars_i[count] == i_max)
	{
		count--;
	}
	return (count + 1);
}

static int		ft_not_surrounded(int i, int j, t_coor *coor)
{
	if (i + 1 < coor->map_i)
		if (coor->map[i + 1][j] == '.')
			return (1);
	if (i - 1 >= 0)
		if (coor->map[i - 1][j] == '.')
			return (1);
	if (j + 1 >= 0)
		if (coor->map[i][j + 1] == '.')
			return (1);
	if (j - 1 >= 0)
		if (coor->map[i][j - 1] == '.')
			return (1);
	if (i + 1 < coor->map_i && j - 1 >= 0)
		if (coor->map[i + 1][j - 1] == '.')
			return (1);
	if (i + 1 < coor->map_i && j + 1 < coor->map_j)
		if (coor->map[i + 1][j + 1] == '.')
			return (1);
	if (i - 1 >= 0 && j - 1 >= 0)
		if (coor->map[i - 1][j - 1] == '.')
			return (1);
	if (i - 1 >= 0 && j + 1 < coor->map_j)
		if (coor->map[i - 1][j + 1] == '.')
			return (1);
	return (0);
}

void			ft_fill_on_top(t_coor *coor)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	while (coor->map[++i])
	{
		j = -1;
		while (coor->map[i][++j])
		{
			if (coor->map[i][j] == coor->id && ft_not_surrounded(i, j, coor))
			{
				count = get_the_lowest_middle_stars(coor);
				if (ft_checker(coor, i, j, count) == 1)
				{
					coor->x = i - coor->pc.stars_i[count];
					coor->y = j - coor->pc.stars_j[count];
				}
				return ;
			}
		}
	}
}

void			ft_fill_on_top_as_possible(t_coor *coor)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	while (coor->map[++i])
	{
		j = -1;
		while (coor->map[i][++j])
		{
			if (coor->map[i][j] == coor->id && ft_not_surrounded(i, j, coor))
			{
				count = coor->pc.cnt_stars;
				while (--count >= 0)
				{
					if (ft_checker(coor, i, j, count) == 1)
					{
						coor->x = i - coor->pc.stars_i[count];
						coor->y = j - coor->pc.stars_j[count];
						return ;
					}
				}
			}
		}
	}
}

void			ft_surround_him(t_coor *coor, int i, int j, int count)
{
	int		gap;

	gap = 300;
	while (coor->map[++i])
	{
		j = -1;
		while (coor->map[i][++j])
		{
			if (coor->map[i][j] == coor->id && ft_not_surrounded(i, j, coor))
			{
				coor->gap = 300;
				count = -1;
				while (++count < coor->pc.cnt_stars)
				{
					if (ft_checker(coor, i, j, count) == 1 && coor->gap <= gap)
					{
						coor->x = i - coor->pc.stars_i[count];
						coor->y = j - coor->pc.stars_j[count];
						gap = coor->gap;
					}
				}
			}
		}
	}
}
