/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:14:31 by andi              #+#    #+#             */
/*   Updated: 2023/11/28 13:04:05 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

char	*create_list(int fd)
{
	char	*buf;
	int		n;

	n = 1;
	buf = malloc(BUFFER_SIZE + 1);
	n = read(fd, buf, BUFFER_SIZE);
	if (n == -1)
	{
		free (buf);
		return (NULL);
	}
	buf[n] = '\0';
	return (buf);
}

int	find(char *buf)
{
	int	i;

	i = 0;
	if (buf == NULL)
		return (-1);
	if (buf[i] == '\0')
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
	if (i - a <= 0)
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
	if (buf[i] == '\0')
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
