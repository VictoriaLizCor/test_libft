/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/10/11 10:23:10 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/* RETURN VALUE
** If needle is an empty string, haystack is returned; if needle occurs
** nowhere in haystack, NULL is returned; otherwise a pointer to the
** first character of the first occurrence of needle is returned.

** EXAMPLES
** The following sets the pointer ptr to the "Bar Baz" portion of largestring:

           const char *largestring = "Foo Bar Baz";
           const char *smallstring = "Bar";
           char *ptr;

           ptr = strstr(largestring, smallstring);

     The following sets the pointer ptr to NULL, because only the first 4 characters of largestring are searched:

           const char *largestring = "Foo Bar Baz";
           const char *smallstring = "Bar";
           char *ptr;

           ptr = strnstr(largestring, smallstring, 4);
*/
void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
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

void	check(bool succes)
{
	if (succes)
		write(1, "Yes\n", 4);
	else
		write(1, "*NO\n", 4);
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

/* char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	diff;
	size_t i, j;
	char	*ptr;

	ptr = ft_strchr(haystack, needle[0]);
	printf("\n\t-%s-", ptr);
	if (len > 0 && ptr != NULL)
	{
		diff = ft_strlen(haystack) - ft_strlen(ptr);
		printf("\t|%zu", diff);
		i = 0;
		j = len;
		while (needle[i] == haystack[i + diff] && i < len && i < ft_strlen(needle))
		{
			printf("\t|%zu|%zu|%zu|", j, i, i+ diff);	
			printf("- %c/%c", needle[i], haystack[i + diff]);
			j--;
			i++;
		}
		printf("\n\t|%zu|%zu|%zu|", j, i, i+ diff);	
		printf("- %c/%c", needle[i], haystack[i + diff]);
		if ((i == ft_strlen(needle) && i + diff <= len) || !needle[0])
			return (ptr);
		else
		{
			printf("\n-|2e|-");
			return (NULL);
		}
	}
	else
	{
		printf("-1e");
		return (NULL);
	}
}*/

/* char * ft_strnstr(const char * s, const char * find, size_t slen)
{
	char c, sc;
	size_t	len;

	if ((c = *find++) != '\0')
	{
		len = strlen(find);
		do {
			do {
				if ((sc = *s++) == '\0' || slen-- < 1)
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
} */

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	j;
	size_t	i;

	printf("\n\t| %s | %zu |%s | %zu |\n", hs, ft_strlen(hs), nd,ft_strlen(nd));
	if (!*nd)
		return ((char *)hs);
	if (len > 0 && nd[0] != '\0' && ft_strchr(hs, nd[0]) != NULL)
	{
		printf("\n\t -| %s | %zu |-\n", ft_strchr(hs, '\0'), ft_strlen(ft_strchr(hs, '\0')));
		j = 0;
		i = -1;
		while (nd[++i] && len > 0 && i + j <= ft_strlen(hs))
		{
			printf("\n\t -| %s | %zu |-\n", ft_strchr(hs, nd[i]), ft_strlen(ft_strchr(hs, nd[i])));
			printf("\t i = %zu | j = %zu | len = %zu | ndLen = %zu", i, j, len, ft_strlen(nd) - 1);
		printf("\t\t| %c|%c |%s | i + j = %lu\n", nd[i], hs[j + i], hs + j, i + j);
			if (nd[i] != hs[j + i])
			{
				j++;
				i = -1;
			}
		}
		//printf("\t| %s \n", ft_strchr(hs + j, *nd));
		if (i == ft_strlen(nd) && i + j <= len)
		{
			printf("\t| %s \n", (char *)hs + j);
			return ((char *)hs + j);
		}
	}
	return (NULL);
}


/* char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	printf("\n\t%s | %s\n", hs, nd);
	if (len < 1)
		return ((char *)hs);
	while (nd[++i])
	{
		printf("\t i = %zu | j = %zu | len = %zu | ndLen = %zu", i, j, len, ft_strlen(nd) - 1);
		printf("\t| %c|%c |%s |%zu", nd[i], hs[j + i], hs + j, len);
		if (nd[i] != hs[j + i])
		{
			if (i == ft_strlen(nd) - 1)
				return (NULL);
			j++;
			i = -1;
		}
		printf("\t| %s \n", ft_strchr(hs + j, *nd));
		if ((ft_strchr(hs + j, *nd) == NULL || len-- < 1))
		{
			if (ft_strchr(hs + j, *nd) != NULL && nd[i] != hs[j + i] && nd[i])
				return ((char *)ft_strchr(hs + j, *nd));
			else
				return (NULL);
		}
	}
	return ((char *)hs + j);
} */

int	main(void)
{

	// char *s1 = "MZIRIBMZIRIBMZE123";
	// char *s2 = "MZIRIBMZE";
	// size_t max = strlen(s2);
	// char *i1 = strnstr(s1, s2, max);
	// char *i2 = ft_strnstr(s1, s2, max);

	// if (i1 == i2)
	// 	write(1, "OK\n", 3);
	// else
	// 	write(1, "KO\n", 3);
	// printf("\n%s\n", i1);
	// printf("%s\n", i2);
	
	// printf("%s\n",strnstr(((void *)0), "fake", 0));
	// printf("%s\n",ft_strnstr(((void *)0), "fake", 0));
	
	// if ((char *)strnstr(((void *)0), "fake", 0) == (char *)ft_strnstr(((void *)0), "fake", 0))
	// 	write(1, "OK\n", 3);
	// else
	// 	write(1, "KO\n", 3);
	
	printf ("\nW- %s\n", ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
	printf ("\nW- %s\n", strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
			
	char *s1 = "oh no not the empty string !";
	char *s2 = "";
	size_t max = 0;
	char *i1 = ft_strnstr(s1, s2, max);
	char *i2 = strnstr(s1, s2, max);
	
	printf("\n--%s\n", i1);
	printf("--%s\n", i2);
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	char * empty = (char*)"";
	const char *str;
	
	str = ft_strnstr("lorem ipsum dolor sit amet", "sit", 10);
	printf ("00- %s\n",str);
	printf ("00- %s\n",strnstr("lorem ipsum dolor sit amet", "sit", 10));
	str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 0);
	printf ("000- %s\n",str);
	printf ("000- %s\n",strnstr("lorem ipsum dolor sit amet", "dolor", 0));
	/* 1 */ //check(ft_strnstr(haystack, needle, 0) == 0);
	printf ("\n1- %s\n", ft_strnstr(haystack, needle, 0));
	printf ("\n1- %s\n", strnstr(haystack, needle, 0));
	/* 2 */ //check(ft_strnstr(haystack, needle, -1) == haystack + 1);
	printf ("\n2- %s\n", ft_strnstr(haystack, needle, -1));
	printf ("\n2- %s\n", strnstr(haystack, needle, -1));
	/* 3 */ //check(ft_strnstr(haystack, "a", -1) == haystack);
	printf ("\n3- %s\n", ft_strnstr(haystack, "a", -1));
	printf ("\n3- %s\n", strnstr(haystack, "a", -1));
	/* 4 */ //check(ft_strnstr(haystack, "c", -1) == haystack + 4);
	printf ("\n4- %s\n", ft_strnstr(haystack, "c", -1));
	printf ("\n4- %s\n", strnstr(haystack, "c", -1));
	/* 5 */ //check(ft_strnstr(empty, "", -1) == empty);
	printf ("\n5- %s\n", ft_strnstr(empty, "", -1));
	printf ("\n5- %s\n", strnstr(empty, "", -1));
	/* 6 */ //check(ft_strnstr(empty, "", 0) == empty);
	printf ("\n6- %s\n", ft_strnstr(empty, "", 0));
	printf ("\n6- %s\n", strnstr(empty, "", 0));
	/* 7 */ //check(ft_strnstr(empty, "coucou", -1) == 0);
	printf ("\n7- %s\n", ft_strnstr(empty, "coucou", -1));
	printf ("\n7- %s\n", strnstr(empty, "coucou", -1));
	/* 8 */ //check(ft_strnstr(haystack, "aaabc", 5) == haystack);
	printf ("\n8- %s\n", ft_strnstr(haystack, "aaabc", 5));
	printf ("\n8- %s\n", strnstr(haystack, "aaabc", 5));
	/* 9 */ //check(ft_strnstr(empty, "12345", 5) == 0);
	printf ("\n9- %s\n", ft_strnstr(empty, "12345", 5));
	printf ("\n9- %s\n", strnstr(empty, "12345", 5));
	/* 10 */ //check(ft_strnstr(haystack, "abcd", 9) == haystack + 5);
	printf ("\n10- %s\n", ft_strnstr(haystack, "abcd", 9));
	printf ("\n10- %s\n", strnstr(haystack, "abcd", 9));
	/* 11 */ //check(ft_strnstr(haystack, "cd", 8) == NULL);
	printf ("\n11- %s\n", ft_strnstr(haystack, "cd", 8));
	printf ("\n11- %s\n", strnstr(haystack, "cd", 8));
	/* 12 mbueno-g */ //check(ft_strnstr(haystack, "a", 1) == haystack);
	printf ("\n12- %s\n", ft_strnstr(haystack, "a", 1));
	printf ("\n12- %s\n", strnstr(haystack, "a", 1));
	/* 13 opsec-infosec */ //check(ft_strnstr("1", "a", 1) == NULL);
	printf ("\n13- %s\n", ft_strnstr("1", "a", 1));
	printf ("\n13- %s\n", strnstr("1", "a", 1));
	/* 14 opsec-infosec */ //check(ft_strnstr("22", "b", 2) == NULL);
	printf ("\n14- %s\n", ft_strnstr("22", "b", 2));
	printf ("\n14- %s\n", strnstr("22", "b", 2));
	write(1, "\n", 1);

	const char *str1;
	// TEST 5//
	printf ("\nWarMachine1- %s\n", ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
	printf ("\nWarMachine1- %s\n", strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
	write(1, "\n", 1);
	// TEST 4
	printf ("\nWarMachine2- %s\n",ft_strnstr("lorem ipsum dolor sit amet", "", 10));
	printf ("\nWarMachine2- %s\n",strnstr("lorem ipsum dolor sit amet", "", 10));
	//ft_print_result(str1);
	//write(1, str1, ft_strlen(str1));
	//write(1, "\n\n\n", 3);

	s1 = "oh no not the empty string !";
	s2 = "";
	printf(" - - %d - -\n", !s2[0]);
	printf ("\n16'ft- %s\n", ft_strnstr(s1, s2, 0));
	printf ("\n16'- %s\n", strnstr(s1, s2, 0));
	return (0);
}
