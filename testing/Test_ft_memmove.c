/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/28 12:33:22 by lilizarr         ###   ########.fr       */
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


/*  Copies "numBytes" bytes from address "src" to address "dest"; */
/* void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*aux;
	
	if ((ft_strlen(src) > ft_strlen(dest)))
	{
		write(1, "\n\tMemory overflow, dest must be bigger than src\n", 48);
		write(1, "\tft_memmove(void *dest, const void *src, size_t n)\n", 50);
		return (0);
	}
	 for (i=0; i<ft_strlen(src); i++)
	{
		printf("\nThe ascii value of buffer[%zu] = %c \n", i, (*(const char*)(src + i)));
	} 
	else
	{	
		aux = (char *)src;
		return (ft_memcpy(dest, aux, n));
	}
}
 */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		write(1, "--------\n", 9);
		write(1, dest + i, 1);
		write(1, "-", 1);
		write(1, src + i, 1);
		write(1,"\n", 1);
		//((char *)dest)[i] = (*(const char *)(src + (i)));
		write(1, "----\n", 5);
		write(1, dest + i, 1);
		write(1, "-", 1);
		write(1, src + i, 1);
		write(1, "\n", 1);
		i++;
	}
	write(1,"\n---\n", 5);
	write(1, dest, 22);
	write(1,"\n---\n", 5);
	return ((char *)dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*pd;
	char	*ps;
	int		cnt;
	pd = (char *)dest;
	ps = (char *)src;
	printf("\t------%zu ----- \n\n", n);
	printf("\n SRC Address = %p \n", src);
	printf("\n DEST Address = %p \n", dest);
	printf("--- %d--\n", (src < dest));
	write(1, src, ft_strlen(src));
	write(1, "|*|", 3);
	write(1, dest, ft_strlen(dest));
	write(1, "\n", 1);
	cnt = 0;
	if (dest != src && n)
	{
		if (src < dest)
		{
			while (n--)
			{
				write(1, ps + n, 1);
				write(1, "|", 1);
				*(pd + n) = *(ps + n);
				write(1, pd + n, 1);
				write(1, "\n", 1);
			}
		}
		else
		{
			write(1, "*------\n", 8);
			while (n--)
			{
				write(1, ps, 1);
				write(1, "|", 1);
				*pd++ = *ps++;
				write(1, pd -1, 1);
				write(1, "\n", 1);
				cnt++;
			}
			write(1, "\n", 1);
		}
	}
	write(1, dest, ft_strlen(dest));
	write(1, "||\n", 3);
	return (dest);
}

int	main()
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;

	dest = src + 1;
	printf ("\n SRC content: \n\t%s - Address = %p \n\n", (char *)src, src);
	printf ("\n DEST content: \n\t%s - Address = %p \n\n", (char *)dest, dest);
	ft_memmove(dest, src, 8);
	write(1, "\n--\n", 4);
	write(1, dest, 27);
	printf ("\n SRC content: \n\t%s - Address = %p \n\n", (char *)src, src);
	printf ("\n DEST content:\n\t %s - Address = %p \n\n", (char *)dest, dest);

	char	src1[] = "lorem ipsum dolor sit amet";
	char	*dest1;
	
	dest1 = src1 + 1;
	printf ("\n\n SRC content:\n\t %s - Address = %p \n\n", (char *)src1, src1);
	printf ("\n DEST content: \n\t%s - Address = %p \n\n", (char *)dest1, dest1);
	memmove(dest1, src1, 8);
	write(1, "\n-*-\n", 5);
	write(1, dest1, 27);
	printf ("\n\n SRC content:\n\t %s - Address = %p \n\n", (char *)src1, src1);
	printf ("\n DEST content:\n\t %s - Address = %p \n\n", (char *)dest1, dest1);

	char s0[] = {65, 66, 67, 68, 69, 0, 45};
	char d0[] = { 0,  0,  0,  0,  0,  0, 0};
	char s1[] = {65, 66, 67, 68, 69, 0, 45};
	char d1[] = { 0,  0,  0,  0,  0,  0, 0};
	char s2[] = {65, 66, 67, 68, 69, 0, 45};
	char d2[] = { 0,  0,  0,  0,  0,  0, 0};
	char s3[] = {65, 66, 67, 68, 69, 0, 45};
	char d3[] = { 0,  0,  0,  0,  0,  0, 0};
	/* 1 */ 
	write(1, "\n-****-\n", 8);
	write(1, s0, 7);
	write(1, "\n--\n", 4);
	write(1, d0, 7);
	write(1, "|", 1);
	write(1, "\n-****-\n", 8);
	write(1, s1, 7);
	write(1, "\n--\n", 4);
	write(1, d1, 7);
	write(1, "|", 1);
	write(1, "\n", 2);
	write(1, ft_memmove(d0, s0, 7), ft_strlen(d0));
	write(1, "|", 1);
	write(1, memmove(d1, s1, 7), ft_strlen(d1));
	/* 3 */ 
	write(1, "\n--\n", 4);
	write(1, s2, 7);
	write(1, "\n--\n", 4);
	write(1, s2, 7);
	write(1, "|", 1);
	write(1, "\n--\n", 4);
	write(1, s3, 7);
	write(1, "\n--\n", 4);
	write(1, s3, 7);
	write(1, "\n", 1);
	write(1, ft_memmove(s2, s2 + 2, 2), ft_strlen(s2));
	write(1, "|", 1);
	write(1, memmove(s3, s3 + 2, 2), ft_strlen(s3));
	return (0);
}

/* int	main()
{
	
	char	buffer[26];
	char	test[] = "lorem ipsum dolor sit amet";
	char	ft_buffer[26];
	char	ft_test[] = "lorem ipsum dolor sit amet";
	int	k;

	int num = 8;
	int knum = 26;
	//lorem ipum dolor sit a
	for (k=0; k<knum; k++)
	{
		printf("The ascii value of buffer[%d] %c \n", k, *(ft_buffer + k));
	} 
	//ft_memmove(ft_test, ft_buffer,  2);
	ft_memmove(ft_buffer, "lorem ipsum dolor sit amet", num);
	for (k=0; k<knum; k++)
	{
		printf("The ascii value of buffer[%d] %c \n", k, *(ft_buffer + k));
	} 
	printf ("\n size buffer %lu \n content: %s\n\n",sizeof(ft_buffer),  ft_buffer);
	printf("\n----main-----\n");
	for (k=0; k<knum; k++)
	{
		printf("The ascii value of buffer[%d] %c \n", k, *(buffer + k));
	}
	memmove(buffer, "lorem ipsum dolor sit amet", num);
	for (k=0; k<knum; k++)
	{
		printf("The ascii value of buffer[%d] %c \n", k, *(buffer + k));
	}
	printf ("\n size buffer %lu \n content: %s\n\n",sizeof(buffer),  buffer);
	
	return 0;
} */


/*
    char *pDest = (char *)dest;
    const char *pSrc =( const char*)src;
    //allocate memory for tmp array
    char *tmp  = (char *)malloc(sizeof(char ) * n);
    if(NULL == tmp)
    {
        return NULL;
    }
    else
    {
        unsigned int i = 0;
        // copy src to tmp array
        for(i =0; i < n ; ++i)
        {
            *(tmp + i) = *(pSrc + i);
        }
        //copy tmp to dest
        for(i =0 ; i < n ; ++i)
        {
            *(pDest + i) = *(tmp + i);
        }
        free(tmp); //free allocated memory
    }
    return dest;
	*/