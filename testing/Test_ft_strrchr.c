/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/07 12:04:16 by lilizarr         ###   ########.fr       */
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
	size_t	counter;
	char	*ptr;

	counter = 0;
	ptr = NULL;
	while (counter <= ft_strlen(s))
	{
		if (s[counter] == c || (s[counter] == '\0' && (c == '\0')))
		{
			ptr = (char *)(s + counter);
			return (ptr);
		}
		counter++;
	}
	return (ptr);
} */

char	*ft_strrchr(const char *s, int c)
{	
	size_t	counter;

	counter = ft_strlen(s);
	while (counter > 0)
	{
		write(1, s + counter, 1);
		write(1, "\n---\n",5);
		if (*(s + counter) == c || c== '\0')
		{
			write(1, "\nif-\n",5);
			return ((char *)(s + counter));
		}
		counter --;
	}
	if (counter == 0 && c == *s)
		return ((char *)s);
	else
		return (NULL);
}

int	main()
{
	char	chr1 = 'o'; // '\0' // 's'
	char	str2[50] = "bonjour";
	char	*ptr_chr;

	ptr_chr = ft_strrchr(str2, chr1);

	write(1, "\n---\n",5);
	printf("%c in %s string  is: %s \n", chr1, str2, ptr_chr);
	printf("\n\n-------\n%c in %s string  is: %s ", chr1, str2, strrchr(str2, chr1));
	return (0);
}
