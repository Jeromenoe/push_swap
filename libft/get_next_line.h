/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:56:06 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/03 18:07:28 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 1

typedef struct		s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}					t_list;

int					ft_realloc(char *str, char **line, int i);

int					check_endline(const int fd, char **str, char **line);

int					ft_strpart(char **str, int i);

char				**makelst(t_list **lst, int fd);

int					get_next_line(const int fd, char **line);

#endif
