/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:48:08 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/14 01:24:24 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long long	ll;
	char		length[10];
	int			i;

	ll = n;
	i = 0;
	if (ll == 0)
		ft_putchar_fd('0', fd);
	if (ll < 0)
	{
		ft_putchar_fd('-', fd);
		ll *= -1;
	}
	while (ll)
	{
		length[i++] = ll % 10 + '0';
		ll /= 10;
	}
	while (i)
		ft_putchar_fd(length[--i], fd);
}
