/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 01:27:52 by alprival          #+#    #+#             */
/*   Updated: 2022/09/26 01:27:53 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_thinking(t_data *vars, t_philo *philo)
{
	struct timeval	end;

	pthread_mutex_lock(&vars->printf);
	gettimeofday(&end, NULL);
	if (vars->death == 0)
		printf("%s%ld %d is thinking\n", KYEL,
			((end.tv_sec * 1000000 + end.tv_usec)
				- vars->start_timer) / 1000, philo->num_philo);
	pthread_mutex_unlock(&vars->printf);
}

void	ft_sleeping(t_data *vars, t_philo *philo)
{
	struct timeval	end;

	pthread_mutex_lock(&vars->printf);
	gettimeofday(&end, NULL);
	if (vars->death == 0)
		printf("%s%ld %d is sleeping\n", KBLU,
			((end.tv_sec * 1000000 + end.tv_usec)
				- vars->start_timer) / 1000, philo->num_philo);
	pthread_mutex_unlock(&vars->printf);
	usleep(vars->time_to_sleep * 1000);
}

void	ft_eating(t_data *vars, t_philo *philo)
{	
	pthread_mutex_lock(&vars->eat);
	gettimeofday(&philo->timer, NULL);
	pthread_mutex_unlock(&vars->eat);
	pthread_mutex_lock(&vars->printf);
	if (vars->death == 0)
		printf("%s%ld %d is eating\n", KGRN,
			((philo->timer.tv_sec * 1000000 + philo->timer.tv_usec)
				- vars->start_timer) / 1000, philo->num_philo);
	pthread_mutex_unlock(&vars->printf);
	usleep(vars->time_to_eat * 1000);
	pthread_mutex_lock(&vars->eat);
	if (philo->number_of_times_philosopher_eat > 0)
		philo->number_of_times_philosopher_eat--;
	else if (philo->number_of_times_philosopher_eat == 0)
	{
		philo->number_of_times_philosopher_eat--;
		vars->end++;
	}
	pthread_mutex_unlock(&vars->eat);
}
