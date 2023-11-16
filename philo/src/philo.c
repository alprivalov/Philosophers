/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:30:20 by alprival          #+#    #+#             */
/*   Updated: 2022/08/30 08:30:31 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	static t_data	vars;
	int				i;

	vars.end = 0;
	ft_check_argument(ac, av, &vars);
	if (vars.error == 0)
		ft_init_argument(&vars, av, ac);
	if (vars.error != 0 || vars.number_of_times_each_philosopher_must_eat == 0)
		return (0);
	ft_init_vars(&vars);
	i = -1;
	while (++i < vars.number_of_philosophers)
	{
		pthread_create(&vars.philo[i].thread,
			NULL, &ft_create_thread, &vars.philo[i]);
	}
	ft_init_timer(&vars);
	pthread_create(&vars.death_timer_thread, NULL, &ft_death_thread, &vars);
	i = -1;
	while (++i < vars.number_of_philosophers)
		pthread_join(vars.philo[i].thread, NULL);
	pthread_join(vars.death_timer_thread, NULL);
}
