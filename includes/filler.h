/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:33:28 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/12 10:29:46 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/ft_printf.h"

typedef struct			s_pc
{
	char				**shape;
	int					pc_i;
	int					pc_j;
	int					*stars_i;
	int					*stars_j;
	int					cnt_stars;
}						t_pc;

typedef struct			s_strat
{
	int					is_below;
	int					can_up;
}						t_strat;

typedef struct			s_coor
{
	char				id;
	int					map_i;
	int					map_j;
	char				**map;
	int					gap;
	int					x;
	int					y;
	int					done;
	t_pc				pc;
	t_strat				strat;
}						t_coor;

void					ft_get_map_coor(t_coor *coor, char *line);
void					ft_get_pc_coor(t_coor *coor, char *line);
char					*ft_get_map(char *line, char *map);
char					*ft_get_pc(char *line, char *pc);
void					ft_check_line(t_coor *coor, char *line, char **pc,\
						char **map);

void					ft_get_coor_stars(t_coor *coor);
int						ft_count_stars(t_coor *coor);
void					ft_update_position_back(t_coor coor, int y_decal,\
						int x_decal);
void					ft_update_position(t_coor coor, int y_decal,\
						int x_decal);

int						ft_checker_map(t_coor *coor);
int						ft_checker(t_coor *coor, int i, int j, int count);

void					ft_solve(t_coor *coor);
void					ft_surround_him(t_coor *coor, int i, int j, int count);
void					ft_fill_on_top(t_coor *coor);
void					ft_fill_on_top_as_possible(t_coor *coor);

#endif
