/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:13:38 by lilizarr          #+#    #+#             */
/*   Updated: 2022/10/08 18:50:04 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
//#include <stddef.h>
#include <stdint.h>

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*st;

	if (s)
	{
		st = ft_calloc(sizeof(char), len + 1);
		if (st)
		{
			if (start < ft_strlen(s))
				ft_memcpy(st, &s[start], len);
		}
		return (st);
	}
	return ((char *)s);
}

char	**ft_split(char const *s, char c)
{
	char	**sp;
	int		a_size;
	int		a_cnt;
	size_t	s_s;
	size_t	s_e;

	a_size = 0;
	a_cnt = 1;
	s_e = 0;
	s_s = 0;
	printf("\n\t\t\t\tbeg|  %p | %s | %zu\n", s, s, ft_strlen(s));
	while (s[s_e])
	{
		//printf("-%c | %c- | %d\n", s[s_e], s[s_e + 1], a_size);
		if (s[s_e] != c && (s[s_e + 1] == c || s[s_e + 1] == 0))
			a_size++;
		s_e++;
	}
	printf("\t\t\t\t---%zu	\t|%d	\n", s_e, a_size);
	s_e = 0;
	printf("%p | %s	\t| %zu\n", &s[s_e], &s[s_e], ft_strlen(s));
	sp = ft_calloc(a_size, sizeof(char *));
	sp[a_size] = NULL;
	while (s[s_e])
	{
		printf("%d	\t| %p | %c\n", a_cnt, &s[s_e], s[s_e]);
		if (s[s_e] != c)
			s_s++;
		if (s[s_e] != c && (s[s_e + 1] == c || s[s_e + 1] == 0))
		{
			printf("\t\t\t\t| %p | %c | %p | %c |\t %zu| \t %zu\n", &s[s_e] , s[s_e], &s[s_e - s_s + 1] , s[s_e- s_s + 1 ], s_s, s_e);
			//scpy = ft_substr(s, s_e - s_s, s_s + 1);
			//printf("\t\t\t\t| %p | %s | \t%zu | \t%zu|%d\n", scpy, scpy, ft_strlen(scpy), s_s, a_cnt);
			sp[a_cnt] = ft_substr(s, s_e - s_s + 1, s_s);
			printf("----///\t\t\t\t| %p | %s | \t%zu | \t%zu|%d\n", sp[a_cnt], sp[a_cnt], ft_strlen(sp[a_cnt]), s_s, a_cnt);
			s_s = 0;
			printf("\t%p | %d\n", sp[a_cnt], a_cnt);
			a_cnt++;
		}
		s_e++;
	}
	return (sp);
}

// static char	**array_size(const char *s, char c)
// {
// 	char	**sp;
// 	int		a_size;
// 	size_t	s_e;

// 	if (!s)
// 		return (NULL);
// 	s_e = 0;
// 	a_size = 1;
// 	while (s[s_e])
// 	{
// 		if (s[s_e] != c && (s[s_e + 1] == c || s[s_e + 1] == 0))
// 			a_size++;
// 		s_e++;
// 	}
// 	sp = ft_calloc((a_size), sizeof(char *));
// 	if (!sp)
// 		return (NULL);
// 	sp[a_size] = NULL;
// 	return (sp);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**sp;
// 	int		a_cnt;
// 	size_t	s_l;
// 	size_t	s_e;

// 	sp = array_size(s, c);
// 	if (!sp || !s)
// 		return (NULL);
// 	a_cnt = 0;
// 	s_l = 0;
// 	s_e = 0;
// 	while (s[s_e])
// 	{
// 		if (s[s_e] != c)
// 			s_l++;
// 		if (s[s_e] != c && (s[s_e + 1] == c || s[s_e + 1] == 0))
// 		{
// 			sp[a_cnt] = ft_substr(s, s_e - s_l + 1, s_l);
// 			s_l = 0;
// 			a_cnt++;
// 		}
// 		s_e++;
// 	}
// 	return (sp);
// }

int	main(void)
{
	char	**result1;
	int		idx;
	//char **result = ft_split(s, ' ');
	///char	**expected = ((char*[6]){"split", "this", "for", "me", "!", NULL});
	//char **result = ft_split(string, ' ');

	result1 = ft_split("    split     this for   me  !     ", ' ');
	idx = -1;
	printf("%d ", idx);
	while (result1[++idx])
	{
		printf("%d ", idx);
		printf("%s | %p\n", result1[idx], result1[idx]);
	}
	printf("%d ", idx);
	printf("%s | %p\n", result1[idx], result1[idx]);
	free(result1);
	return (0);
}
