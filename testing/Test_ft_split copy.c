/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:13:38 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/23 13:16:33 by lilizarr         ###   ########.fr       */
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

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	j;
	size_t	i;

	if (!*nd)
		return ((char *)hs);
	if (len > 0 && ft_strchr(hs, nd[0]) != NULL)
	{
		j = 0;
		i = -1;
		while (nd[++i] && len > 0)
		{
			if (nd[i] != hs[j + i])
			{
				j++;
				i = -1;
			}
		}
		if (i == ft_strlen(nd) && i + j <= len)
			return ((char *)hs + j);
		else
			return (NULL);
	}
	else
		return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*st;
	size_t	s_st;
	size_t	e_st;

	if (set && s1)
	{
		s_st = 0;
		e_st = ft_strlen(s1) - 1;
		while (s1[s_st] && ft_strchr((set), s1[s_st]) && *set)
			s_st++;
		while (e_st > s_st && ft_strrchr((set), s1[e_st]) && *set && *s1)
			e_st--;
		st = (char *)malloc(e_st - s_st + 2);
		if (st)
		{
			ft_memcpy(st, s1 + s_st, e_st - s_st + 1);
			st[e_st - s_st + 1] = 0;
			return ((char *)st);
		}
		else
			return (NULL);
	}
	else
		return ((char *)s1);
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

/* char	**ft_split(char const *s, char c)
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
} */

static char	**array_size(const char *s, char c)
{
	char	**sp;
	int		a_size;
	size_t	s_e;

	s_e = 0;
	a_size = 1;
	while (s[s_e])
	{
		if (s[s_e] != c && (s[s_e + 1] == c || s[s_e + 1] == 0))
			a_size++;
		s_e++;
	}
	sp = malloc((a_size) * sizeof(char *));
	if (sp)
	{
		sp[a_size] = NULL;
		return (sp);
	}
	else
		return (NULL);
}

static char	**fill_array(char	***sp, char const *s, char c)
{
	int		a_cnt;
	size_t	s_s;
	size_t	s_e;

	a_cnt = 0;
	s_s = 0;
	s_e = 0;
	while (s[s_e])
	{
		if (s[s_e] != c)
			s_s++;
		if (s[s_e] != c && (s[s_e + 1] == c || s[s_e + 1] == 0))
		{
			*sp[a_cnt] = ft_substr(s, s_e - s_s + 1, s_s);
			s_s = 0;
			a_cnt++;
		}
		s_e++;
	}
	return (*sp);
}

char	**ft_split(char const *s, char c)
{
	char	**sp;

	if (s)
	{
		sp = array_size(s, c);
		printf("%s", sp);
		if (sp)
		{
			sp = fill_array((&sp), s, c);
		}
		return (sp);
	}
	else
		return (NULL);
}

int	main(void)
{
	//char *s = "      split       this for   me  !       ";
	//char **result = ft_split(s, ' ');
	///char	**expected = ((char*[6]){"split", "this", "for", "me", "!", NULL});
	//char **result = ft_split(string, ' ');
	char *s = "      split       this for   me  !";
	char **result1 = ft_split(s, ' ');
	char *s1 = "                  olol";
	char **result2 = ft_split(s1, ' ');
	//printf("%s", result[0]);
	//printf("%s", result[5]);
	//printf("%s", result[6]);
	//printf("%s", result[7]);
	ft_split("  tripouille  42  ", ' ');
	//ft_split("tripouille   42 65  ", ' ');
	//ft_split("tripouille", 0);
	//ft_split("     ", ' ');
	//ft_split("chinimala", ' ');
	return (0);
}

