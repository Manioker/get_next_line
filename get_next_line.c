/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avacca <avacca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:33:50 by avacca            #+#    #+#             */
/*   Updated: 2023/11/23 15:15:08 by avacca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	str_len(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	int		a;

	i = str_len(s1) + str_len(s2);
	new = (char *)malloc(i + 1);
	a = 0;
	if (new == NULL)
		return (NULL);
	if (!s1)
		s1 = s2;
	while (i > 1)
	{
		while (*s1 != '\0')
		{
			new[a] = *s1;
			s1++;
			a++;
			i--;
		}
		s1 = s2;
	}
	new[a] = '\0';
	return (new);
}

int	check_n(char *temp)
{
	int	i;

	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*save(char *temp, char *buf, int a)
{
	int	i;
	int	b;

	b = 0;
	i = str_len(temp);
    buf = malloc(a);
	while (i - a < i)
    {
		buf[b] = temp[i - a]
        b++;
        a--;
    }
    return (buf);
}

char *cut(char *temp, int a, int n)
{
    while (a++ < n)
        temp[a] = '\0';
    return (temp);
}

char	*read_nl(char *temp, int fd)
{
	int			n;
	int			i;
	int			a;
	static char	*buf = NULL;

	i = 0;
	a = 0;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	n = read(fd, temp + i, BUFFER_SIZE - i);
	if (n == -1)
		return (NULL);
	temp[n] = '\0';
	a = check_n(temp);
	if (a < n)
    {
		buf = save(temp, buf, (n - a));
        while (a < n)
            temp[a++] = '\0';
    }
    return (temp);
}

char	*get_next_line(int fd)
{
	char	*temp;
	char	*buf;
	int		i;

	buf = NULL;
	i = 0;
	while (1)
	{
		temp = read_nl(temp, fd);
		if (*temp == '\0')
			return (buf);
		buf = ft_strjoin(buf, temp);
		free(temp);
		if (check_n(buf) < str_len(buf))
			return (buf);
	}
	return (NULL);
}
int	main(void)
{
	int fd;
	fd = open("file.txt", O_RDONLY);
	printf("i am one %s", get_next_line(fd));
	printf("i am two %s", get_next_line(fd));
	printf("i am three %s", get_next_line(fd));
	printf("i am four %s", get_next_line(fd));
	printf("i am five %s", get_next_line(fd));
	printf("i am six %s", get_next_line(fd));
	close(fd);
	return (0);
}