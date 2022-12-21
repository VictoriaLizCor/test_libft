/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:12:56 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/07 12:48:01 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>

void	check(bool succes)
{
	if (succes)
		write(1, "Yes\n", 4);
	else
		write(1, "*NO\n", 4);
}

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

void	ft_putstr_fd(char *s, int fd)
{
	//write(1, s, ft_strlen(s));
	write(fd, s, ft_strlen(s));
	/* int i;
	
	i = 0; 
	while (s[i])
	{
		write(fd, &s[i], 1);
		write(1, &s[i], 1);
		i++;
	} */
}

 int main(void)
 {
	int fd = open("tripouille", O_RDWR | O_CREAT);
	ft_putstr_fd("Hola, como estas", fd);
	lseek(fd, SEEK_SET, 0);
	char s[20] = {0}; 
	read(fd, s, 20);
	printf("%s\n", s);
	/* 1 */ check(!strcmp(s, "Hola, como estas"));
	close(fd);
	//unlink("./tripouille");
	write(1, "\n", 1);
	return (0);
 }
 