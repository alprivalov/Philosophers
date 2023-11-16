/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 01:30:55 by alprival          #+#    #+#             */
/*   Updated: 2022/09/26 19:40:57 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lock_mutex(t_philo *philo, t_data *vars)
{
	struct timeval	end;

	pthread_mutex_lock(&philo->fork);
	gettimeofday(&end, NULL);
	pthread_mutex_lock(&vars->printf);
	if (vars->death == 0)
		printf("%s%ld %d has taken a fork\n", KWHT,
			((end.tv_sec * 1000000 + end.tv_usec)
				- vars->start_timer) / 1000, philo->num_philo);
	pthread_mutex_unlock(&vars->printf);
	pthread_mutex_lock(&vars->philo[philo->num_philo].fork);
	gettimeofday(&end, NULL);
	pthread_mutex_lock(&vars->printf);
	if (vars->death == 0)
		printf("%s%ld %d has taken a fork\n", KWHT,
			((end.tv_sec * 1000000 + end.tv_usec)
				- vars->start_timer) / 1000, philo->num_philo);
	pthread_mutex_unlock(&vars->printf);
}

void	ft_lock_mutex_zero(t_philo *philo, t_data *vars)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&vars->printf);
	if (vars->death == 0)
		printf("%s%ld %d has taken a fork\n", KWHT,
			((end.tv_sec * 1000000 + end.tv_usec)
				- vars->start_timer) / 1000, philo->num_philo);
	pthread_mutex_unlock(&vars->printf);
	pthread_mutex_lock(&vars->philo[0].fork);
	gettimeofday(&end, NULL);
	pthread_mutex_lock(&vars->printf);
	if (vars->death == 0)
		printf("%s%ld %d has taken a fork\n", KWHT,
			((end.tv_sec * 1000000 + end.tv_usec)
				- vars->start_timer) / 1000, philo->num_philo);
	pthread_mutex_unlock(&vars->printf);
}

void	ft_unlock_mutex(t_philo *philo, t_data *vars)
{
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&vars->philo[philo->num_philo].fork);
}

void	ft_unlock_mutex_zero(t_philo *philo, t_data *vars)
{
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&vars->philo[0].fork);
}
