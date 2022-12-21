/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/08/23 13:25:47 by lilizarr         ###   ########.fr       */
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
	/* size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = (*(const char *)(src + (i)));
		i++;
	}
	return ((char *)dest); */
	size_t	i;

	i = n - 1;
	while (n--)
	{
		((char *)dest)[i-n] = (*(const char*)(src + (i - n)));
	}
	return (dest);
	
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*data;

	data = malloc(count * size);
	if (data)
		ft_bzero(data, count * size);
	return (data);
}

char	*ft_strdup(const char *s1)
{
	char	*aux;

	aux = malloc(sizeof(char) * (ft_strlen(s1)+1));
	if (aux == NULL)
		return (0);
	aux = ft_memcpy(aux, s1, ft_strlen(s1));
	return (aux);
}

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main()
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;
	
	dest = NULL;
	printf("%lu \t %lu ==== %p \t %p \n", sizeof(dest), sizeof(src), dest, src);
	if (!(dest = ft_strdup(src)))
		ft_print_result("NULL");
	else
	{
		printf("\n");
		ft_print_result(dest);
	}
	if (dest == src)
		ft_print_result("\nstr_dup's adress == str's adress");
	printf("\n%lu \t %lu ==== %p \t %p ", sizeof(dest), sizeof(src), dest, src);


/* 	printf ("\n DEST content: \n");
	write(1, dest, 26);
	write(1, src, 26);
 	printf ("\n - Address = %p \n", src);
	printf ("\n - Address = %p \n", dest);
	write(1, "\n--\n", 4);
	memset(src, 'r', 6);
	printf ("\n DEST content: \n");
	write(1, dest, 30);
 	printf ("\n - Address = %p \n", src);
	printf ("\n - Address = %p \n", dest);
	write(1, "\n--\n", 4);
	dest = ft_strdup(src);
	ft_print_result(dest);
	printf ("\n - Address = %p \n", src);
	printf ("\n - Address = %p \n", dest);
	write(1, dest,26);
	dest = NULL;
	printf ("\n DEST content: \n");
	write(1, dest, 26);
	write(1, src, 26);
 	printf ("\n - Address = %p \n", src);
	printf ("\n - Address = %p \n", dest);
	write(1, "\n--\n", 4);
	memset(src, 'r', 6);
	printf ("\n DEST content: \n");
	write(1, dest, 30);
 	printf ("\n - Address = %p \n", src);
	printf ("\n - Address = %p \n", dest);
	write(1, "\n--\n", 4);
	dest = strdup(src);
	ft_print_result(dest);
	printf ("\n - Address = %p \n", src);
	printf ("\n - Address = %p \n", dest);
	write(1, dest,30); */
/* 	ft_print_result(ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0));
	write(1, "\n", 1);
	write(1, dest, 15);	
	write(1, "\n--------\n", 10);
	ft_print_result(strlcpy(dest, "lorem ipsum dolor sit amet", 0));
	write(1, "\n", 1);
	write(1, dest, 15); */
	return (0);
}