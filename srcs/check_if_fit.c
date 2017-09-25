/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_fit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:51:39 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/12 10:22:13 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_update_position_back(t_coor coor, int y_decal, int x_decal)
{
	int			index;

	index = 0;
	while (index < coor.pc.cnt_stars)
	{
		coor.pc.stars_i[index] -= y_decal;
		coor.pc.stars_j[index] -= x_decal;
		index++;
	}
}

void		ft_update_position(t_coor coor, int y_decal, int x_decal)
{
	int			index;

	index = 0;
	while (index < coor.pc.cnt_stars)
	{
		coor.pc.stars_i[index] += y_decal;
		coor.pc.stars_j[index] += x_decal;
		index++;
	}
}

int			ft_checker_map(t_coor *coor)
{
	int			index;
	int			ovrlp;
	int			i;
	int			j;

	index = 0;
	ovrlp = 0;
	while (index < coor->pc.cnt_stars)
	{
		i = coor->pc.stars_i[index];
		j = coor->pc.stars_j[index];
		if (i < 0 || i >= coor->map_i || j < 0 || j >= coor->map_j)
			return (0);
		if (coor->map[i][j] == coor->id)
			ovrlp++;
		else if (coor->map[i][j] == (coor->id == 'X' ? 'O' : 'X') || ovrlp > 1)
			return (0);
		index++;
	}
	if (index == coor->pc.cnt_stars && ovrlp == 1)
		return (1);
	return (0);
}

int			ft_distance(t_coor coor, int gap, int stars, int gap_tmp)
{
	int			index;
	int			i;
	int			j;

	i = -1;
	while (coor.map[++i])
	{
		j = -1;
		while (coor.map[i][++j])
		{
			if (coor.map[i][j] != coor.id && coor.map[i][j] != '.')
			{
				index = -1;
				while (++index < stars)
				{
					gap_tmp = ft_abs(coor.pc.stars_i[index] - i) +\
					ft_abs(coor.pc.stars_j[index] - j);
					if (gap_tmp < gap && gap_tmp >= 0)
						gap = gap_tmp;
				}
			}
		}
	}
	return (gap);
}

int			ft_checker(t_coor *coor, int i, int j, int count)
{
	int			x_decal;
	int			y_decal;
	int			ret;
	int			t_gap;

	t_gap = 0;
	x_decal = j - coor->pc.stars_j[count];
	y_decal = i - coor->pc.stars_i[count];
	ft_update_position(*coor, y_decal, x_decal);
	if ((ret = ft_checker_map(coor)))
		coor->gap = ft_distance(*coor, coor->gap, coor->pc.cnt_stars, t_gap);
	ft_update_position_back(*coor, y_decal, x_decal);
	if (ret == 1)
		return (1);
	return (0);
}
