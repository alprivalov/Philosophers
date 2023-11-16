/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 01:30:46 by alprival          #+#    #+#             */
/*   Updated: 2022/09/26 01:30:46 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_timer(t_data *vars)
{
	int				i;
	struct timeval	end;

	i = -1;
	gettimeofday(&end, NULL);
	while (++i < vars->number_of_philosophers)
	{
		pthread_mutex_lock(&vars->eat);
		gettimeofday(&vars->philo[i].timer, NULL);
		pthread_mutex_unlock(&vars->eat);
	}
}

void	ft_init_vars(t_data *vars)
{
	struct timeval	start;
	int				i;

	i = 0;
	gettimeofday(&start, NULL);
	vars->start_timer = start.tv_sec * 1000000 + start.tv_usec;
	while (i < vars->number_of_philosophers)
	{
		pthread_mutex_init(&vars->philo[i].fork, NULL);
		vars->philo[i].num_philo = i + 1;
		vars->philo[i].number_of_times_philosopher_eat
			= vars->number_of_times_each_philosopher_must_eat;
		vars->philo[i].vars = vars;
		i++;
	}
	pthread_mutex_init(&vars->eat, NULL);
	pthread_mutex_init(&vars->printf, NULL);
}
