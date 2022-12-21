/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_putendl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:12:56 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/07 12:53:13 by lilizarr         ###   ########.fr       */
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

void	ft_putendl_fd(char *s, int fd)
{
	//write(1, s, ft_strlen(s));
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

 int main(void)
 {
	int fd = open("tripouille", O_RDWR | O_CREAT);
	ft_putendl_fd((char*)"42", fd);
	lseek(fd, SEEK_SET, 0);
	char s[20] = {0}; 
	read(fd, s, 20);
	printf("%s\n", s);
	/* 1 */ check(!strcmp(s, "42\n"));
	unlink("./tripouille");
	write(1, "\n", 1);
	return (0);
 }
 