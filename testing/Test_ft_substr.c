/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:13:38 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/28 16:12:03 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n - 1;
	while (n-- && (dest != NULL || src != NULL))
	{
		((char *)dest)[i - n] = (*(const char *)(src + (i - n)));
	}
	return (dest);
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

/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*st;

	if (!s)
		return (0);
	else if (s)
	{
		if (!(st = (char *)malloc(len + 1)))
			return (NULL);
		if (start <= ft_strlen(s))
		{
			ft_memcpy(st, &s[start], len);
			st[len] = 0;
		}
		else
			st[0] = 0;
		return ((char *)st);
	}
	else
		return (NULL);
} */

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*st;

	if (s)
	{
		st = malloc(sizeof(char) * len + 1);
		if (st)
		{
			ft_memset((void *)st, 0, len + 1);
			if (start < ft_strlen(s))
				ft_memcpy(st, &s[start], len);
			return ((char *)st);
		}
		else
			return (NULL);
	}
	return ((char *)s);
}

/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*st;

	if (s)
	{
		st = malloc(sizeof(char) * len + 1);
		if (st)
		{
			ft_memset((void *)st, 0, ft_strlen(s));
			if (start < ft_strlen(s))
				ft_memcpy(st, &s[start], ft_strlen(s));
			st[len] = 0;
			return ((char *)st);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
} */

/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*st;

	if (s)
	{
		st = malloc(sizeof(char) * len + 1);
		if (st)
		{
			ft_memset((void *)st, 0, len + 1);
			if (start < ft_strlen(s))
			{
				ft_memcpy(st, &s[start], ft_strlen(s));
				st[len] = 0;
			}
			return ((char *)st);
		}
		else
			return (NULL);
	}
	return ((char *)s);
} */

void check(bool succes)
{
	if (succes)
		write (1, "OK", 2);
	else
		write (1, "KO", 2);
}

void mcheck(void * p, size_t required_size)
{
	void * p2 = malloc(required_size); 
	if (malloc_size(p) == malloc_size(p2))
		write (1, "OK", 2);
	else
		write (1, "KO", 2);
	free(p2);
}

int	main(void)
{
	char * s = ft_substr("tripouille", 0, 42000);
	s = ft_substr("tripouille", 100, 1);
	
	/* 7 */ check(!strcmp(s, ""));
	printf("%s\n", s);
	/* 8 */ mcheck(s, 1);
	
	printf("%d\n", (unsigned)(-6));
	free(s);
	return (0);
}

