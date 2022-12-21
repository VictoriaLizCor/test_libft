/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/27 17:34:49 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

/* #define type_name(expr) \ 
    (_Generic((expr), \ 
              char: "char", unsigned char: "unsigned char", signed char: "signed char", \ 
              short: "short", unsigned short: "unsigned short", \ 
              int: "int", unsigned int: "unsigned int", \ 
              long: "long", unsigned long: "unsigned long", \ 
              long long: "long long", unsigned long long: "unsigned long long", \ 
              float: "float", \ 
              double: "double", \ 
              long double: "long double", \ 
              void*: "void*", \ 
              default: "?"))  */

void	check(bool succes)
{
	if (succes)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{	
	size_t				i;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	i = 0;
	if (n > 0)
	{
		write(1, "if\n", 3);
		while (--n > 0 && ptr1[i] == ptr2[i])
		{
			printf("i = %zu\n", i);
			i++;
		}
		printf("i = %zu\n", i);
		write(1, ptr1 + i, 1);
		write(1, "|", 1);
		write(1, ptr2 + i, 1);
		write(1, "\n", 1);
		if (ptr1[i] - ptr2[i] > 0)
			return (ptr1[i] - ptr2[i]);
		else if (ptr1[i] - ptr2[i] < 0)
			return (ptr1[i] - ptr2[i]);
		else
			return (0);
	}
	else
		return (0);
}

/* int	ft_memcmp(const void *s1, const void *s2, size_t n)
{	
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;

	i = 0;
	if (n > 0)
	{
		while (i +1 < n &&  ptr1[i] &&  ptr1[i] &&  ptr1[i] ==  ptr2[i])
		{
			write(1, ptr1 + i, 1);
			write(1, "|", 1);
			write(1, ptr2 + i, 1);
			write(1, "\n", 1);
			i++;
			
		}
		write(1, "*", 1);
		write(1, ptr1 + i, 1);
		write(1, "|", 1);
		write(1, ptr2 + i, 1);
		write(1, "\n", 1);
		printf("i = %zu\n", i);
		printf("*%d|%d = %d\n", ptr1[i], ptr2[i], ptr1[i] - ptr2[i]); 
		printf("*%d|%d = %d\n", ((unsigned char *)s1)[i], ((unsigned char *)s2)[i], ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]); 
		
		if (ptr1[i] - ptr2[i] > 0)
			return (1);
		else if (ptr1[i] - ptr2[i] < 0)
			return (-1);
		else
			return (0);
		 if (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i] > 0)
			return (1);
		else if (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i] < 0)
			return (-1);
		else
			return (0); 
	}
	 else
		return (0); 
} */

int main(int argc, const char *argv[])
{
	/*char		string1[] = "V";
	const void	*str = string1;
	size_t	i = 0;
	//write(1, str + 1, 1);
	printf("%d \n", *(const char *)(str + i));
	printf("%d \n", ((unsigned char *)str)[i]); */
	//printf("%s \n", type_name(str));

	/* char		string1[] = "Victoria";
	char		c = '\200';
	unsigned char uc = (unsigned char *)c;
	unsigned char	*str = (unsigned char *)string1;
	size_t	i = 0;
	printf("%d \n", str[i]);
	printf("%d \n", uc); */
	
	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
	
	check(memcmp(s2, s3, 4) != 0);
	printf ("**%d\n", (memcmp(s2, s3, 4)));
	check(ft_memcmp(s2, s3, 4) != 0);
	printf ("%d", (ft_memcmp(s2, s3, 4)));
	
	 
	/* printf("--------\n");
	printf ("1 = %d\n", ft_memcmp("salut", "salut", 5)); 
	printf ("2 = %d\n", ft_memcmp("t\200", "t\0", 2)); 
	printf ("3 = %d\n", ft_memcmp("testss", "test", 5)); 
	
	printf ("4 = %d\n", ft_memcmp("test", "tEst", 4)); 
	printf ("5 = %d\n", ft_memcmp("", "test", 4)); 
	printf ("6 = %d\n", ft_memcmp("test", "", 4));
	printf ("7 = %d\n", ft_memcmp("abcdefghij", "abcdefgxyz", 7)); 
	printf ("8 = %d\n", ft_memcmp("abcdefgh", "abcdwxyz", 6)); 
	printf ("9 = %d\n", ft_memcmp("zyxbcdefgh", "abcdwxyz", 0)); 
	printf ("10 = %d\n", ft_memcmp("abcdefgh", "", 0));  

	printf("--------\n");
	printf ("1 = %d\n", memcmp("salut", "salut", 5)); //0
	printf ("2 = %d\n",memcmp("t\200", "t\0", 2)); //1
	printf ("3 = %d\n",memcmp("testss", "test", 5)); //1
	printf ("4 = %d\n",memcmp("test", "tEst", 4)); //1
	printf ("5 = %d\n",memcmp("", "test", 4)); //-1
	printf ("6 = %d\n",memcmp("test", "", 4)); //1
	printf ("7 = %d\n",memcmp("abcdefghij", "abcdefgxyz", 7)); // 0
	printf ("8 = %d\n",memcmp("abcdefgh", "abcdwxyz", 6)); // -1
	printf ("9 = %d\n",memcmp("zyxbcdefgh", "abcdwxyz", 0)); // 0
	printf ("10 = %d\n",memcmp("abcdefgh", "", 0)); // 0 */
	
	return (0);
}
