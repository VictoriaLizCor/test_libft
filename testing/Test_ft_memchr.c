/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/08/30 13:25:48 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

/* void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;

	src = s;

	while (--n > 0)
	{
		if (*src++ == (unsigned char)c)
			return ((void *)(src - 1));
		src++;
	}
	return (NULL);
} */

void	*ft_memchr(const void *src, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = src;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (*(ptr + i) == ((unsigned char)c))
			return ((void *)(ptr + i));
		i++;
	}
	if ((*(ptr + i) == '\0') && (c == 0))
		return ((void *)ptr);
	else
		return (NULL);
}

void	check(bool succes)
{
	if (succes)
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
}

int	main(void)
{
	char	*ptr;
	int 	tab[7] = {0, 49, 1, -1, 0, -2, 2};
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	int c = 258;
	
	/* printf("%s\n", (char *)ft_memchr(s, 0, 0));
	write(1 , "|\n", 2);
	printf("%s\n", (char *)memchr(s, 0, 0));
	write(1 , "|\n", 2); */
	//*printf("%s\n", (char *)ft_memchr(s, 2 + 256, 3));
	write(1 , "|\n", 2);
	printf("%s\n", (char *)memchr(s,2 + 256, 3));
	write(1, &c, 2);
	write(1, s +2, 10);
	check(ft_memchr(s, 2 + 256, 3) == s + 2);
/* 	printf("\n----- Memchar code\n");
	ptr = ft_memchr("bonjour", 'b', 4);
	printf("String[4] after b is - |%s|\n", ptr);
	ptr = ft_memchr("bonjour", 'o', 7);
	printf("String[7] after o is - |%s|\n", ptr);
	ptr = ft_memchr("bonjourno", 'n', 2);
	printf("String[2] after n is - |%s|\n", ptr);
	ptr = ft_memchr("bonjour", 'j', 6);
	printf("String[6] after j is - |%s|\n", ptr);
	ptr = ft_memchr("bonjour", 's', 7);
	printf("String[7] after s is - |%s|\n", ptr);
	printf("%s\n", (char *)ft_memchr(tab, -1, 7));
	
	printf("\n----- Memchar code\n");
	ptr = memchr("bonjour", 'b', 4);
	printf("String[4] after b is - |%s|\n", ptr);
	ptr = memchr("bonjour", 'o', 7);
	printf("String[7] after o is - |%s|\n", ptr);
	ptr = memchr("bonjourno", 'n', 2);
	printf("String[2] after n is - |%s|\n", ptr);
	ptr = memchr("bonjour", 'j', 6);
	printf("String[6] after j is - |%s|\n", ptr);
	ptr = memchr("bonjour", 's', 7);
	printf("String[7] after s is - |%s|\n", ptr);
	printf("%s", (char *)memchr(tab, -1, 7)); */
	return (0);
}
