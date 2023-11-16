/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 01:51:39 by alprival          #+#    #+#             */
/*   Updated: 2022/09/26 01:51:41 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mi_sleep(int time)
{
	struct timeval	get_end;
	struct timeval	get_start;
	int				start;
	int				end;

	gettimeofday(&get_start, NULL);
	gettimeofday(&get_end, NULL);
	start = (get_start.tv_sec * 1000000 + get_start.tv_usec) / 1000;
	end = (get_end.tv_sec * 1000000 + get_end.tv_usec) / 1000;
	while (end - start < time)
	{
		gettimeofday(&get_end, NULL);
		end = (get_end.tv_sec * 1000000 + get_end.tv_usec) / 1000;
		usleep(50);
	}
}
