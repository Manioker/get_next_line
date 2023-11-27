/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:33:50 by avacca            #+#    #+#             */
/*   Updated: 2023/11/27 16:21:36 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*leftoverchecker(char *leftover, int fd)
{
	if (leftover == NULL)
		return (create_list(fd));
	return (leftover);
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
				a = a + 2;
				return (a);
			}
			a = a + i;
			i++;
		}
		list = list->next;
	}
	return(a);
}

char	*lastfunction(t_list *list)
{
	int		i;
	int		k;
	char	*str;

	if (NULL == list)
		return (NULL);
	str = malloc(countletters(list));
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

void freelist(t_list **list)
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
	list = ft_lstnew(leftoverchecker(leftover, fd));
	firstnode = list;
	while (!find(list->content))
	{
		list->next = ft_lstnew(create_list(fd));
		list = list->next;
	}
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
// 	close(fd);
// 	return (0);
// }