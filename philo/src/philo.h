/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 01:34:17 by alprival          #+#    #+#             */
/*   Updated: 2022/09/26 01:41:19 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>	
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# include <pthread.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	fork;
	struct timeval	timer;
	int				num_philo;
	int				number_of_times_philosopher_eat;
	struct s_data	*vars;
}t_philo;

typedef struct s_data
{
	pthread_t		death_timer_thread;
	pthread_mutex_t	printf;
	pthread_mutex_t	eat;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				end;
	int				death;
	long int		start_timer;
	int				number_of_times_each_philosopher_must_eat;
	int				error;
	t_philo			philo[4096];
}t_data;

//          function        //

int		ft_atoi(const char *nptr, t_data *vars);
void	ft_int_check(char **av, t_data *vars);
void	ft_check_argument(int ac, char **av, t_data *vars);
void	ft_init_argument(t_data *vars, char **av, int ac);
void	ft_mi_sleep(int time);
void	*ft_create_thread(void *arg);
void	*ft_death_thread(void *arg);

//          mutex           //

void	ft_unlock_mutex_zero(t_philo *philo, t_data *vars);
void	ft_unlock_mutex(t_philo *philo, t_data *vars);
void	ft_lock_mutex_zero(t_philo *philo, t_data *vars);
void	ft_lock_mutex(t_philo *philo, t_data *vars);

//          init            //

void	ft_init_vars(t_data *vars);
void	ft_init_timer(t_data *vars);
void	ft_init_tab(t_data *vars);

//          actions         //

void	ft_thinking(t_data *vars, t_philo *philo);
void	ft_sleeping(t_data *vars, t_philo *philo);
void	ft_eating(t_data *vars, t_philo *philo);

#endif
