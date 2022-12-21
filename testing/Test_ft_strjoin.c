/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:13:38 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/14 14:52:44 by lilizarr         ###   ########.fr       */
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

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		cnt;
	size_t		dlen;

	d = dest;
	s = src;
	cnt = n;
	while (cnt-- != 0 && *d)
	{
		write(1, "|", 1);
		write(1, d, 1);
		d++;
	}
	dlen = d - dest;
	cnt = n - dlen;
	printf("\n n = %lu \tdlen = %lu \tcnt = %lu\n", n, dlen, cnt);
	printf("\n d = %lu \tdest = %lu", d, dest);
	if (cnt == 0)
	{	
		write(1, dest, 15);
		return (dlen + ft_strlen(s));
	}
	while (*s)
	{
		if (cnt != 1)
		{
			*d++ = *s;
			cnt--;
			write(1, "|", 1);
			write(1, d, 1);
		}
		write(1, "|", 1);
		write(1, s, 1);
		s++;
	}
	*d = '\0';
	write(1, dest, 15);
	return (dlen + (s - src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	size_t	lens1s2;

	lens1s2 = ft_strlen(s1) + ft_strlen(s2);
	sj = (char *)malloc(lens1s2 + 1);
	if (!sj)
	{
		ft_memcpy(sj, s1, ft_strlen(s1));
		ft_memcpy(sj + ft_strlen(s1) , s2, ft_strlen(s2) + 1);
		return (sj);
	}
	else
		return (NULL);
}

int	main(void)
{
	char	dest[30];
	char	*src = "AAAAAAAAA";

	memset(dest, 0, 30);
	dest[0] = 'B';

	printf("%s\n", ft_strlcat(dest, src, 1));
	printf("%s\n", strlcat(dest, src, 1));
	return (0);
}

