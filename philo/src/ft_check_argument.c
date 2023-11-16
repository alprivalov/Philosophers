/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 01:29:22 by alprival          #+#    #+#             */
/*   Updated: 2022/09/26 01:29:23 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_int_check(char **av, t_data *vars)
{
	int	i;
	int	x;

	x = 0;
	while (av[++x])
	{
		i = -1;
		while (av[x][++i])
		{
			if (av[x][i] == '-')
			{
				write(2, "Error\nPhilo_argument_neg_int\n", 28);
				vars->error++;
				return ;
			}
			else if (av[x][i] < '0' || av[x][i] > '9')
			{
				write(2, "Error\nPhilo_argument_no_int\n", 28);
				vars->error++;
				return ;
			}
		}
	}
}

void	ft_check_argument(int ac, char **av, t_data *vars)
{
	if (ac < 5 || ac > 6)
	{
		write(2, "Error\nWrong_number_argument\n", 28);
		vars->error++;
		return ;
	}
	ft_int_check(av, vars);
}
