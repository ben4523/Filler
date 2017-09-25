/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:52:35 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/12 10:25:08 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	check_position(t_coor *coor)
{
	int				i;
	int				j;
	int				me;
	int				him;

	i = -1;
	me = 0;
	him = 0;
	while (coor->map[++i])
	{
		j = -1;
		while (coor->map[i][++j])
		{
			if (coor->map[i][j] == (coor->id == 'X' ? 'O' : 'X'))
				him = i;
			if (coor->map[i][j] == coor->id)
				me = i;
		}
	}
	coor->strat.is_below = (me > him ? 1 : 0);
}

int		filled_on_top(t_coor *coor)
{
	int				i;
	int				j;

	i = -1;
	while (coor->map[++i])
	{
		j = -1;
		while (coor->map[i][++j])
		{
			if (coor->map[i][j] == coor->id)
			{
				if (i == 0)
					return (1);
				else
					return (0);
			}
		}
	}
	return (0);
}

void	check_if_you_can_go_up(t_coor *coor)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (coor->map[++i])
	{
		j = -1;
		while (coor->map[i][++j])
		{
			if (coor->map[i][j] == coor->id)
			{
				while (coor->map[i][j++] == coor->id)
					;
				if (i - 1 > 0 && j - 1 > 0 && j < coor->map_j)
				{
					if (coor->map[i - 1][j - 1] != '.' ||\
					coor->map[i - 1][j] != '.')
						coor->strat.can_up = 1;
				}
				return ;
			}
		}
	}
}

void	ft_solve(t_coor *coor)
{
	static int		count_turns = 0;
	int				i;
	int				j;
	int				count;

	i = -1;
	j = -1;
	count = -1;
	count_turns++;
	if (coor->strat.can_up == 0)
		check_if_you_can_go_up(coor);
	if (count_turns == 1)
		check_position(coor);
	if (!filled_on_top(coor) && coor->strat.is_below && !coor->strat.can_up)
	{
		ft_fill_on_top(coor);
		if (coor->x == 0 && coor->y == 0)
			ft_fill_on_top_as_possible(coor);
	}
	else
		ft_surround_him(coor, i, j, count);
	ft_printf("%d %d\n", coor->x, coor->y);
	coor->x = 0;
	coor->y = 0;
	coor->done = 0;
}
