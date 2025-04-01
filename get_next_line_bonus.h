/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:31:44 by avacca            #+#    #+#             */
/*   Updated: 2024/05/21 11:26:26 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(char *content);
char				*create_list(int fd);
int					find(char *buf);
char				*get_next_line(int fd);
char				*copychar(char *buf, int i, int a);
char				*copyleft(char *buf);
int					tofree(t_list **list, t_list **firstnode, char *leftover,
						int fd);
char				*leftoverchecker(char **leftover, int fd);
void				freelist(t_list **list);

#endif
