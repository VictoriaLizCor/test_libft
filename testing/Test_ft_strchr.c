/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/08/30 14:49:56 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>


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

void	check(bool succes)
{
	if (succes)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

/* char	*ft_strchr(const char *s, int c)
{	
	while (*s)
	{
		//write(1, (char *)&c, 1);
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
} */

char	*ft_strchr(const char *s, int c)
{	
	size_t	counter;
	char	*ptr;

	counter = 0;
	ptr = NULL;
	while (counter <= ft_strlen(s))
	{
		if (s[counter] == (char)c || (s[counter] == '\0' && (c == '\0')))
		{
			ptr = (char *)(s + counter);
			return (ptr);
		}
		counter++;
	}
	return (ptr);
}

int	main(void)
{
	/* char	chr1 = 'c'; // '\0' // 's'
	char	str2[50] = "consectetur";
	char	*ptr_chr;
	const char *haystack = "lorem ipsum dolor sit lorem ipsum dolor";


	ptr_chr = ft_strchr(haystack, str2[0]);

	printf("%c in %s string  is: %s \n", chr1, str2, ptr_chr);
	printf("\n\n-------\n%c in %s string  is: %s ", chr1, str2, strchr(str2, chr1)); */
	
	char s[] = "tripouille";
	/*check(ft_strchr(s, 't') == s);
	check(ft_strchr(s, 'l') == s + 7);
	check(ft_strchr(s, 'z') == 0);
	check(ft_strchr(s, 0) == s + ft_strlen(s));*/
	check(ft_strchr(s, 't' + 256) == s); 
	printf ("%s\n", ft_strchr(s, 't' + 256)); 
	check(strchr(s, 't' + 256) == s); 
	printf ("%s\n", strchr(s, 't' + 256));
	printf ("%i %c\n", 't' + 256, 't' + 256);
	printf ("%i %c\n", 256, 256);
	printf ("%i\n", 't');
	return (0);
}
