/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 01:54:43 by alprival          #+#    #+#             */
/*   Updated: 2022/09/26 01:54:43 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_vars(t_data *vars)
{
	pthread_mutex_lock(&vars->eat);
	if (vars->end >= vars->number_of_philosophers)
	{
		pthread_mutex_unlock(&vars->eat);
		return (1);
	}
	pthread_mutex_unlock(&vars->eat);
	pthread_mutex_lock(&vars->printf);
	if (vars->death == 1)
	{
		pthread_mutex_unlock(&vars->printf);
		return (1);
	}
	pthread_mutex_unlock(&vars->printf);
	return (0);
}

void	*ft_create_thread(void *arg)
{
	t_philo			*philo;
	t_data			*vars;

	philo = (t_philo *)arg;
	vars = philo->vars;
	if (philo->num_philo % 2)
		usleep(5000);
	while (1)
	{
		if (ft_check_vars(vars))
			return (NULL);
		if (philo->num_philo != vars->number_of_philosophers)
			ft_lock_mutex(philo, vars);
		else
			ft_lock_mutex_zero(philo, vars);
		ft_eating(vars, philo);
		if (philo->num_philo != vars->number_of_philosophers)
			ft_unlock_mutex(philo, vars);
		else
			ft_unlock_mutex_zero(philo, vars);
		ft_sleeping(vars, philo);
		ft_thinking(vars, philo);
	}
	return (NULL);
}
