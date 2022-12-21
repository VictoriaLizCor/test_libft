/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/28 11:16:45 by lilizarr         ###   ########.fr       */
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
	//size_t len_dest;

	//len_dest = ft_strlen(dest);
	//rintf("\n---%lu----", len_dest);
	//write(1, dest, len_dest);
	//printf("\t---%c----", ((char *)dest)[len_dest]);
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
	while (n-- && dest != NULL && (char *)dest && (const char *)src)
	{
		printf("\n%lu",n);
		printf("\t%lu",i-n);
		((char *)dest)[i - n] = (*(const char *)(src + (i - n)));
	}
	//((char *)dest)[len_dest] = '\0';
	return (dest);
}
/* void * ft_memcpy(void *dest, const void *src, size_t len)
{
	char	*d = dest;
	const char *s = src;
	while (len--)
	{
		printf("%lu size src: %c\n",len,(*(const char*)(src)));
		printf("%lu size d: %c\n",len,(d[len]));
		printf("%lu size s: %c\n",len,(*(const char*)(s++)));
		*d++ = *s++;

		printf("%lu size d: %c\n",len,(d[len]));
		printf("%lu size s: %c\n",len,(*(const char*)(s++)));
	}
	return dest;
} */

int	main()
{
	void	*mem;
	void *c = 0;
	if (!(mem = malloc(sizeof(void) * 30)))
		return (0);
	memset(mem, 'j', 30);

	memcpy(((void *)c), ((void *)c), 3);
	write(1, "-\n", 2);
	write(1, ((void *)c), 30);
	ft_memcpy(((void *)c), ((void *)c), 3);
	write(1, "-\n", 2);
	write(1, ((void *)c), 30);
	ft_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba",  14);
	write(1, "\n", 1);
	write(1, mem, 30);
	memset(mem, 'j', 30);
	ft_memcpy(mem, "zyxwvutst", 0);
	write(1, "\n", 1);
	write(1, mem, 30);
	memset(mem, 'j', 30);
	ft_memcpy(mem, "zy\0xw\0vu\0\0tsr", 11);
	write(1, "\n", 1);
	write(1, mem, 30);
	write(1, "\n", 1);
	
	memset(mem, 'j', 30);
	memcpy(mem, "zyxwvutsrqponmlkjihgfedcba",  14);
	write(1, "\n", 1);
	write(1, mem, 30);
	memset(mem, 'j', 30);
	memcpy(mem, "zyxwvutst", 0);
	write(1, "\n", 1);
	write(1, mem, 30);
	memset(mem, 'j', 30);
	memcpy(mem, "zy\0xw\0vu\0\0tsr", 11);
	write(1, "\n", 1);
	write(1, mem, 30);
	

	/* for (k=0; k<num; k++)
	{
		printf("\nThe ascii value of empty[%d] [%p]: %c \n", k, (test + k), *(test + k));
	}  */	
	/* memcpy(test, buffer,  6);
	printf ("\n size test %lu \n content: %s\n\n",sizeof(test),  test);
	memcpy(buffer, empty, 10);
	printf ("\n size buffer %lu \n content: %s\n\n",sizeof(buffer),  buffer);
	memcpy(ft_buffer, ft_test,10);	
	printf ("\n size test %lu \n content: %s\n\n",sizeof(ft_buffer),  ft_buffer);

	for (k=0; k<2; k++)
	{
		printf("\nThe ascii value of empty[%d] [%p]: %c \n", k, (buffer + k), *(buffer + k));
	}  */
	
	
}

