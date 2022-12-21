/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:51:31 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/26 15:25:07 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <time.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*data;

	if (size == SIZE_MAX || count == SIZE_MAX)
		return (NULL);
	data = malloc(count * size);
	if (data)
		ft_bzero(data, count * size);
	else
		return (NULL);
	return (data);
}

size_t	ft_strlen(const char *str)
{	
	size_t	counter;

	counter = 0;
	while (str[counter])
	{
		counter++;
	}
	return (counter);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int			idx;
	char		*str;

	idx = 0;
	if (s)
	{
		str = ft_calloc(sizeof(char), ft_strlen(s) + 1);
		if (str)
		{
			while (s[idx])
			{
				str[idx] = (*f)(idx, s[idx]);
				printf("%c | ", str[idx]);
				idx++;
			}
		}
		return (str);
	}
	return ((char *)s);
}

char	add_one(unsigned int i, char c)
{
	return (i + c);
}

int	main(void)
{
	char * s = ft_strmapi("1234", add_one);

	printf("\n %s\n" ,s );
	return (0);
}