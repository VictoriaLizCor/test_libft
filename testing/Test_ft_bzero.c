/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/07/28 11:17:23 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
// C program to demonstrate working of memset()
#include <stdio.h>
#include <string.h>
/*The bzero() function erases the data in the n bytes of the memory
       starting at the location pointed to by s, by writing zeros (bytes
       containing '\0') to that area.

       The explicit_bzero() function performs the same task as bzero().
       It differs from bzero() in that it guarantees that compiler
       optimizations will not remove the erase operation if the compiler
       deduces that the operation is "unnecessary".
 \*/

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		//printf("ft_bzero(%zu):  %s\n", i,  (char *)s);
		((char *)s)[i] = 0;
		i++;
	}

	printf("After ft_bzero():  %s\n", (char *)s);

}

int main()
{
    char str1[50] = "Linda Victoria Lizarraga 342345.³¤€³¤€½";
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
    ft_bzero(str1, 8*sizeof(char));
	printf("After ft_bzero():  %s\n", str1);
	ft_bzero(str1 + 13, 8*sizeof(char));
	printf("After ft_bzero():  %s\n", str1);
	printf("-----\n");
	bzero(str2 + 13, 8*sizeof(char));
	printf("After bzero():  %s\n", str2);
	bzero(str2 + 13, 8*sizeof(char));
	printf("After bzero():  %s\n", str2);
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
