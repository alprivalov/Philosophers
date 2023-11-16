/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 01:54:57 by alprival          #+#    #+#             */
/*   Updated: 2022/09/26 01:54:59 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_if_death(t_data *vars, struct timeval end, int i)
{	
	pthread_mutex_lock(&vars->eat);
	if (vars->philo[i].number_of_times_philosopher_eat != 0)
	{
		pthread_mutex_unlock(&vars->eat);
		pthread_mutex_lock(&vars->printf);
		vars->death++;
		usleep(50);
		printf("%s%ld %d died\n", KRED,
			((end.tv_sec * 1000000 + end.tv_usec)
				- vars->start_timer) / 1000, i + 1);
		pthread_mutex_unlock(&vars->printf);
		return (1);
	}
	pthread_mutex_unlock(&vars->eat);
	return (0);
}

int	ft_init_value_time(t_data *vars, struct timeval end, int i)
{
	int	time;

	pthread_mutex_lock(&vars->eat);
	time = ((end.tv_sec * 1000000) + end.tv_usec)
		- ((vars->philo[i].timer.tv_sec * 1000000)
			+ vars->philo[i].timer.tv_usec);
	pthread_mutex_unlock(&vars->eat);
	return (time);
}

void	*ft_death_thread(void *arg)
{
	t_data			*vars;
	struct timeval	end;
	long int		time;
	int				i;

	vars = (t_data *)arg;
	i = 0;
	while (1)
	{
		usleep(50);
		gettimeofday(&end, NULL);
		time = ft_init_value_time(vars, end, i);
		if ((time / 1000) > vars->time_to_die)
		{
			if (vars->end >= vars->number_of_philosophers)
				return (NULL);
			if (ft_if_death(vars, end, i))
				return (NULL);
		}
		i++;
		if (i >= vars->number_of_philosophers)
			i = 0;
	}
	return (NULL);
}
