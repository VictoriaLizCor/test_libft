/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:12:56 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/07 11:53:11 by lilizarr         ###   ########.fr       */
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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

 int main(void)
 {
	int fd = open("tripouille", O_RDWR | O_CREAT);
	ft_putchar_fd('a', fd);
	lseek(fd, SEEK_SET, 0);
	char s[10] = {0}; 
	read(fd, s, 2);
	printf("%s\n", s);
	/* 1 */ check(!strcmp(s, "a"));
	close(fd);
	//unlink("./tripouille");
	write(1, "\n", 1);
	return (0);
 }
 