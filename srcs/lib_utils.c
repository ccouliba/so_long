/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:50:41 by ccouliba          #+#    #+#             */
/*   Updated: 2021/12/13 14:05:36 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		++i;
	return (i);
}

int	ft_strcmp(char *a_s1, char *a_s2)
{
	int	i;

	i = 0;
	while (a_s1[i] && a_s2[i] && a_s1[i] == a_s2[i])
		++i;
	return (a_s1[i] - a_s2[i]);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	a;

	a = n;
	if (a < 0)
	{
		ft_putchar_fd('-', fd);
		a = -a;
	}
	if (a > 9)
	{
		ft_putnbr_fd((a / 10), fd);
		ft_putnbr_fd((a % 10), fd);
	}
	else
		ft_putchar_fd((a + '0'), fd);
}
