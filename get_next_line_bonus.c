/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:33:50 by avacca            #+#    #+#             */
/*   Updated: 2024/05/21 11:26:04 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*leftoverchecker(char **leftover, int fd)
{
	char	*buf;
	int		n;

	if (*leftover)
		return (*leftover);
	n = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = read(fd, buf, BUFFER_SIZE);
	if (n == -1)
	{
		free(buf);
		return (NULL);
	}
	buf[n] = '\0';
	return (buf);
}

int	countletters(t_list *list)
{
	int	i;
	int	a;

	a = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				a = a + 1;
				return (a);
			}
			i++;
			a = a + i;
		}
		list = list->next;
	}
	return (a);
}

char	*lastfunction(t_list *list)
{
	int		i;
	int		k;
	char	*str;

	str = malloc((countletters(list) + 1) * sizeof(char));
	if (list == NULL || !str)
		return (NULL);
	k = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return (str);
			}
			str[k++] = list->content[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
	return (str);
}

void	freelist(t_list **list)
{
	t_list	*tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
}

char	*get_next_line(int fd)
{
	t_list		*list;
	t_list		*firstnode;
	char		*string;
	static char	*leftover = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	list = ft_lstnew(leftoverchecker(&leftover, fd));
	leftover = NULL;
	if (!list)
		return (NULL);
	if (list->content[0] == '\0')
	{
		freelist(&list);
		return (NULL);
	}
	firstnode = list;
	if (!tofree(&list, &firstnode, leftover, fd))
		return (NULL);
	leftover = copyleft(list->content);
	string = lastfunction(firstnode);
	freelist(&firstnode);
	return (string);
}

// int	main(void)
// {
// 	int fd;
// 	fd = open("file.txt", O_RDONLY);
// 	printf("i am one %s", get_next_line(fd));
// 	printf("i am two %s", get_next_line(fd));
// 	printf("i am three %s", get_next_line(fd));
// 	printf("i am four %s", get_next_line(fd));
// 	printf("i am five %s", get_next_line(fd));
// 	printf("i am six %s", get_next_line(fd));
// 	printf("i am 7 %s", get_next_line(fd));
// 	printf("i am 8 %s", get_next_line(fd));
// 	printf("i am 9 %s", get_next_line(fd));
// 	printf("i am 10 %s", get_next_line(fd));
// 	printf("i am 11 %s", get_next_line(fd));
// 	printf("i am 12 %s", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
