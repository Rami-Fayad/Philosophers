/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:12:47 by ral-faya          #+#    #+#             */
/*   Updated: 2024/08/08 13:12:49 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_dinner(t_status *status, t_philosopher *philos)
{
	pthread_t	*seat;
	pthread_t	manager;
	size_t		i;

	seat = malloc(status->total_philo * sizeof(pthread_t));
	i = -1;
	while (++i < status->total_philo)
		pthread_create(seat + i, NULL, start_dinner, &philos[i]);
	pthread_create(&manager, NULL, thread_manager, philos);
	i = -1;
	while (++i < philos->status->total_philo)
		pthread_join(seat[i], NULL);
	pthread_join(manager, NULL);
	free(seat);
}

void	*start_dinner(void *philo_sits_down)
{
	t_philosopher	*philo;

	philo = philo_sits_down;
	if (philo->status->total_philo == 1)
	{
		print_status(philo, TAKING_FORK);
		usleep(philo->status->time_of_death * 1000);
		return (NULL);
	}
	while (!stop_dinner(philo->status))
	{
		eating(philo);
		if (philo->eat_again == philo->status->meals_to_eat)
		{
			pthread_mutex_lock(&philo->status->m_meals_repeated);
			philo->status->meals_repeated += 1;
			pthread_mutex_unlock(&philo->status->m_meals_repeated);
			return (NULL);
		}
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

t_bool	stop_dinner(t_status *philo_status)
{
	pthread_mutex_lock(&philo_status->m_stop_dinner);
	if (philo_status->stop_dinner == TRUE)
	{
		pthread_mutex_unlock(&philo_status->m_stop_dinner);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo_status->m_stop_dinner);
	return (FALSE);
}

size_t	print_status(t_philosopher *philo, t_action action)
{
	size_t	current_time;
	size_t	time_spent;

	current_time = get_current_time();
	time_spent = current_time - philo->status->start_time;
	pthread_mutex_lock(&philo->status->m_print_status);
	if (action == TAKING_FORK)
		printf(FORK_LOG, time_spent, philo->philo_name);
	else if (action == EATING)
		printf(FORK_LOG FORK_LOG EAT_LOG, time_spent, \
					philo->philo_name, time_spent, philo->philo_name, \
					time_spent, philo->philo_name);
	else if (action == SLEEPING)
		printf(SLEEP_LOG, time_spent, philo->philo_name);
	else if (action == DEAD)
		printf(DEATH_LOG, time_spent, philo->philo_name);
	else if (action == THINKING)
		printf(THINK_LOG, time_spent, philo->philo_name);
	pthread_mutex_unlock(&philo->status->m_print_status);
	return (current_time);
}
