/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/28 13:31:08 by lilizarr         ###   ########.fr       */
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

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = (*(const char *)(src + (i)));
		i++;
	}
	return ((char *)dest);
}

/*  Copies "numBytes" bytes from address "src" to address "dest"
void * memmove(void *to, const void *from, size_t numBytes); */
/* size_t	ft_strlcpy(char * restrict dest, const char * restrict src, size_t n)
{
	size_t	i;
	
	write(1, "\n----inside-----\n)", 17);
	printf("size src: %lu\n",sizeof((*(const char*)(src + 0))));
	printf("size dest: %lu\n", ft_strlen(src));
	printf("content dest: %c\n", (*(const char*)(src + 0)));
	printf("size_t n: %lu\n", n);
	
	if (ft_strlen(src) < n)
	{
		write(1, "\n\tMemory overflow, dest must be bigger than src\n", 48);
		return (0);
		write(1, "\n----End inside-----\n)", 17);
		return (0);
	}
	else
	{	
		i = 0;
		while (i < (n-1))
		{
			dest[i] = src[i];
			printf("String[%lu][%p]:%c \n",i, dest + i, *(const char*)(dest + i));
			i++;
		}
		dest[n-1] = '\0';
		printf("String[%lu][%p]:%c \n",i, dest + (n-1), *(const char*)(dest + (n-1)));
		write(1, "\n----End inside-----\n)", 17);
		return (i);
	}
} */

void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
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

size_t	ft_strlcpy(char * restrict dest, const char * restrict src, size_t n)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < n)
	{
		ft_memcpy(dest, src, src_len+1);
	}
	else if (n != 0)
	{	
		ft_memcpy(dest, src, n-1);
		dest[n - 1] = '\0';
	}
	return (src_len);
}

int	main()
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
	memset(dest, 0, 15);
	printf ("\n DEST content: %s - Address = %p \n\n", (char *)dest, src);
	write(1, "\n--\n", 4);
	memset(dest, 'r', 6);
	printf ("\n DEST content: %s - Address = %p \n\n", (char *)dest, src);
	write(1, "\n--\n", 4);
	ft_print_result(ft_strlcpy(dest, "lorem ipsum dolor sit amet", 10));
	write(1, "\n", 1);
	write(1, dest, 15);	
	write(1, "\n--------\n", 10);
	ft_print_result(strlcpy(dest, "lorem ipsum dolor sit amet", 0));
	write(1, "\n", 1);
	write(1, dest, 15);
	return (0);
}

/* int	main()
{
	char	ft_buffer[10] = "Hello!";
	char	ft_empty[10] = "Many";
	char	buffer2[10] = "Hello!";
	char	empty[7] = "MANY";

	size_t k;

	printf("\n----test ft_function-----\n");
	for (k=0; k < (int)(sizeof(ft_buffer)); k++)
	{
		printf("The ascii value of buffer[%zu] [%p]: %c \n", k, (ft_buffer + k), *(ft_buffer + k));
	}
	
	ft_strlcpy( ft_empty, ft_buffer, 7 );

	printf("\n----after ft_function-----\n");
	for (k=0; k < sizeof(ft_empty); k++)
	{
		printf("The ascii value of empty[%zu] [%p]: %c \n", k, (ft_empty + k), *(ft_empty + k));
	} 
	printf("\n----original function-----\n");
	for (k=0; k < (int)(sizeof(buffer2)); k++)
	{
		printf("The ascii value of buffer[%zu] [%p]: %c \n", k, (buffer2 + k), *(buffer2 + k));
	}
	printf ("\n size test %lu \n content: %s\n\n",sizeof(empty), empty);
	strlcpy(empty, buffer2, 7);
	
	printf ("\n size buffer %lu \n content: %s\n\n",sizeof(buffer2), buffer2);	

	for (k=0; k < (int)(sizeof(empty)); k++)
	{
		printf("The ascii value of buffer[%zu] [%p]: %c \n", k, (empty + k), *(empty + k)); 
	}
}
 */