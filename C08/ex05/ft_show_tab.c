/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:29:47 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/16 17:09:41 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_setsign(long *i, int *n)
{
	if (*i < 0)
	{
		*i = -*i;
		*n = 1;
	}
}

void	ft_putnbr(int nb)
{
	int		is_negative;
	long	nbr;
	int		temp;
	long	factor;

	nbr = (long)nb;
	is_negative = 0;
	if (nbr == 0)
		ft_putchar('0');
	ft_setsign(&nbr, &is_negative);
	factor = 1;
	temp = nbr;
	while (temp)
	{
		temp = temp / 10;
		factor = factor * 10;
	}
	if (is_negative == 1)
		ft_putchar('-');
	while (factor > 1)
	{
		factor = factor / 10;
		ft_putchar((nbr / factor) + '0');
		nbr = nbr % factor;
	}
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != '\0')
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}
