/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/08/12 16:02:35 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
// C program to demonstrate working of memset()
#include <stdio.h>
#include <string.h>
/*The memset() function fills the first n bytes of the 
memory area pointed to by s with the constant byte c.
*/
/*RETURN VALUE
The memset() function returns a pointer to the memory area1\ s. */
/*Windows: Shift + Alt + A
Windows: Ctrl + /s
*/

/* void *ptr(arg1, arg2) => priority in arguments
and that the pointer is a function
void (*ptr)(arg1, arg2) => priority in the pointer and 
is possible to call any function with this prototype
*/

/* calloc allocates the requested memory and returns
 a pointer to it. It also sets allocated memory to zero.

In case you are planning to use your string as empty
 string all the time:

char *string = NULL;
string = (char*)calloc(1, sizeof(char));

In case you are planning to store some value in your string later:

char *string = NULL;
int numberOfChars = 50; // you can use as many as you need
string = (char*)calloc(numberOfChars + 1, sizeof(char));
 */

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	i = 0;

	printf("valor de C = %i\n", c);
	printf("valor de C = %c\n",  (unsigned char)c);
	while (i < n)
	{

		((char *)s)[i] = c;
		i++;
	}
	return s;
}

int main()
{
    char str1[50] = "";
	char str2[50] = "Linda Victoria Lizarraga 342345.³¤€³¤€½";
	if (str1[0] == 0)
	{
		printf("Str1 is empty\n");
		printf("Str1 %d \n", str1[1]);
	}
	// void *s1, s2;
	// printf("(char)s +1 = %c\n", ((char *)s)[1]);
	/* int c;
	size_t n;

	
	c = 1;
	n = 2; */
    // Fill 8 characters starting from str[13] with '.'
	printf("-----Memset code\n");
    ft_memset(str1 + 13, 46546, 8*sizeof(char));
	printf("After ft_memset():  %s\n", str1);
	ft_memset(str1 + 13, '/', 8*sizeof(char));
	printf("After ft_memset():  %s\n", str1);
	printf("-----\n");
	memset(str2 + 13, 46546, 8*sizeof(char));
	printf("After memset():  %s\n", str2);
	memset(str2 + 13, 'n', 8*sizeof(char));
	printf("After memset():  %s\n", str2);
/* 	printf("i = %i\n", c);
	printf("n = %ld\n", n);
	printf("s = %p\n", s);
	printf("s+1 = %p\n", (s+1));
	printf("&s = %p\n", &s)
	printf("(char *)s = %s\n", (char *)(s));
	printf("(char *)s +1 = %s\n", (char *)(s+1)); */

	// printf("(char)s +1 = %c\n", ((char *)s)[0]);
	
	//printf("(char)c) = %d, %i\n", (char)c, c);
	
    return 0;
}
