/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/08/22 14:44:22 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	
	i = n - 1;
	/*
	if ((ft_strlen(src) > ft_strlen(dest)) && ((char *)dest)[0] != '\0')
	{
		write(1, "\n\tMemory overflow, dest must be bigger than src\n", 48);
		write(1, "\tft_memcpy(void *dest, const void *src, size_t n)\n", 49);
		return (0);
	}
	else
	{	
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = (*(const char*)(src + i));
			i++;
		}
		return (dest);
	} */

	while (n--)
	{
		printf("\n%lu",n);
		printf("\n%lu",i-n);
		((char *)dest)[i-n] = (*(const char*)(src + (i-n)));
	}
	return (dest);
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

int	main()
{
	char	*dest;

	if (!(dest = (char *)calloc(sizeof(*dest), 15)))
		return (0);
	
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	dest[11] = 'a';
	printf ("\n1 = %lu | %s \n",  ft_strlcat(dest, "lorem", 15),dest);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	dest[11] = 'a';
	printf ("\n2 = %lu | %s \n",ft_strlcat(dest, "", 15),dest);
	dest[0] = '\0';
	dest[11] = 'a';
	printf ("\n3 = %lu | %s \n",ft_strlcat(dest, "lorem ipsum", 15),dest);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	dest[14] = 'a';
	printf ("\n4 = %lu | %s \n",ft_strlcat(dest, "lorem ipsum dolor sit amet", 15),dest);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	dest[10] = 'a';
	printf ("\n5 = %lu | %s \n",ft_strlcat(dest, "lorem ipsum dolor sit amet", 0),dest);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	dest[10] = 'a';
	printf ("\n6 = %lu | %s \n",ft_strlcat(dest, "lorem ipsum dolor sit amet", 1),dest);
	memset(dest, 0, 15);
	memset(dest, 'r', 15);
	printf ("\n7 = %lu | %s \n",ft_strlcat(dest, "lorem ipsum dolor sit amet", 5),dest);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	dest[10] = 'a';
	printf ("\n8 = %lu | %s \n",ft_strlcat(dest, "lorem ipsum dolor sit amet", 6),dest);
	memset(dest, 'r', 14);
	printf ("\n9 = %lu | %s \n",ft_strlcat(dest, "lorem ipsum dolor sit amet", 15),dest);
	
	// original
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	dest[11] = 'a';
	printf ("1 = %lu | %s \n",  strlcat(dest, "lorem", 15),dest);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	dest[11] = 'a';
	printf ("2 = %lu | %s \n",strlcat(dest, "", 15),dest);
	dest[0] = '\0';
	dest[11] = 'a';
	printf ("3 = %lu | %s \n",strlcat(dest, "lorem ipsum", 15),dest);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	dest[14] = 'a';
	printf ("4 = %lu | %s \n",strlcat(dest, "lorem ipsum dolor sit amet", 15),dest);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	dest[10] = 'a';
	printf ("5 = %lu | %s \n",strlcat(dest, "lorem ipsum dolor sit amet", 0),dest);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	dest[10] = 'a';
	printf ("6 = %lu | %s \n",strlcat(dest, "lorem ipsum dolor sit amet", 1),dest);
	memset(dest, 0, 15);
	memset(dest, 'r', 15);
	printf ("7 = %lu | %s \n",strlcat(dest, "lorem ipsum dolor sit amet", 5),dest);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	dest[10] = 'a';
	printf ("8 = %lu | %s \n",strlcat(dest, "lorem ipsum dolor sit amet", 6),dest);
	memset(dest, 'r', 14);
	printf ("9 = %lu | %s \n",strlcat(dest, "lorem ipsum dolor sit amet", 15),dest);
}
