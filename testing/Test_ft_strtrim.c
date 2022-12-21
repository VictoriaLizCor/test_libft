/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:13:38 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/22 15:04:30 by lilizarr         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{	
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((*s == '\0') && (c == '\0'))
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{	
	size_t	counter;

	counter = ft_strlen(s);
	while (counter > 0)
	{
		if (*(s + counter) == (char)c || c == '\0')
			return ((char *)(s + counter));
		counter --;
	}
	if (counter == 0 && (char)c == *s)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*st;
	size_t	s_st;
	size_t	e_st;

	if (!*set || !*s1)
		return ((char *)s1);
	s_st = 0;
	e_st = ft_strlen(s1) - 1;
	printf("%zu\n", e_st);
	while (s1[s_st] && ft_strchr((set), s1[s_st]) != NULL)
	{
		printf("\t| %c | %zu\n", s1[s_st], s_st);
		s_st++;
	}
	printf("%zu\n", s_st);
	while (e_st > s_st && ft_strrchr((set), s1[e_st]) != NULL)
	{
		printf("\t| %c | %zu\n", s1[e_st], e_st);
		e_st--;
	}
	printf("%zu\n", e_st);
	st = (char *)malloc(e_st - s_st + 2);
	if (st)
	{
		ft_memcpy(st, s1 + s_st, e_st - s_st + 1);
		printf("%zu | %zu\n", e_st - s_st + 1,ft_strlen(st));
		st[e_st - s_st + 1] = 0;
		return (st);
	}
	else
		return (NULL);
}

int	main(void)
{
	printf("%s\n", ft_strtrim("lorem ipsum dolor sit amet", "te"));
	printf("%s\n", ft_strtrim("   xxxtripouille   xxx", " x"));
	printf("%s\n", ft_strtrim("   xxxtripouille", " x"));
	printf("%s\n", ft_strtrim("", "123"));
	return (0);
}

