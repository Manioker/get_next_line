/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:14:31 by andi              #+#    #+#             */
/*   Updated: 2024/05/21 11:05:28 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (content == NULL)
	{
		free (new);
		return (NULL);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}

int	find(char *buf)
{
	int	i;

	i = 0;
	if (*buf == '\0')
		return (1);
	if (buf == NULL)
		return (1);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*copychar(char *buf, int i, int a)
{
	char	*leftover;
	int		b;

	b = 0;
	if (i == a)
		return (NULL);
	leftover = malloc(((i - a) + 1) * sizeof(char));
	if (!leftover)
		return (NULL);
	while (a < i)
	{
		leftover[b] = buf[a];
		a++;
		b++;
	}
	leftover[b] = '\0';
	return (leftover);
}

char	*copyleft(char *buf)
{
	int		i;
	int		a;
	char	*leftover;

	i = 0;
	a = 0;
	if (buf[i] == '\0' || !buf)
		return (NULL);
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			i++;
			a = i;
			while (buf[i])
				i++;
			leftover = copychar(buf, i, a);
			return (leftover);
		}
		i++;
	}
	return (NULL);
}

int	tofree(t_list **list, t_list **firstnode, char *leftover, int fd)
{
	while (!find((*list)->content))
	{
		(*list)->next = ft_lstnew(leftoverchecker(&leftover, fd));
		if ((*list)->next == NULL)
		{
			freelist(firstnode);
			return (0);
		}
		*list = (*list)->next;
	}
	return (1);
}
