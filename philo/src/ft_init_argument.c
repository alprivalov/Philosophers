/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 01:30:37 by alprival          #+#    #+#             */
/*   Updated: 2022/09/26 01:30:38 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_argument(t_data *vars, char **av, int ac)
{
	vars->number_of_philosophers = ft_atoi(av[1], vars);
	vars->time_to_die = ft_atoi(av[2], vars);
	vars->time_to_eat = ft_atoi(av[3], vars);
	vars->time_to_sleep = ft_atoi(av[4], vars);
	if (vars->number_of_philosophers < 1)
	{
		vars->error++;
		write(2, "Error\nLess then 1 philosopher\n", 30);
	}
	if (vars->number_of_philosophers == 1)
	{
		printf("%s%d has taken a fork\n", KWHT, 1);
		printf("%s%d %d is thinking\n", KYEL, 0, 1);
		usleep(vars->time_to_die * 1000);
		printf("%s%d %d died\n", KRED, vars->time_to_die + 1, 1);
		vars->error++;
	}
	if (vars->time_to_die < 60 || vars->time_to_eat < 60
		|| vars->time_to_sleep < 60 || vars->number_of_philosophers > 200)
		vars->error++;
	if (ac == 6)
		vars->number_of_times_each_philosopher_must_eat = ft_atoi(av[5], vars);
	else
		vars->number_of_times_each_philosopher_must_eat = -1;
}
