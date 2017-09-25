/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:27:16 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/08 21:16:56 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 9
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_fd
{
	int				fd;
	char			*stat;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(const int fd, char **line);
#endif
