/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-faya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:15:09 by ral-faya          #+#    #+#             */
/*   Updated: 2024/08/08 15:02:58 by ral-faya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_atoi(char *str)
{
	size_t	nbr_conv;

	nbr_conv = 0;
	while (*str)
	{
		nbr_conv = (nbr_conv * 10) + (*str - '0');
		str++;
	}
	return (nbr_conv);
}

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static t_bool	is_nbr(char *string)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (!ft_isdigit(string[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	is_valid_input(int argc, char **argv)
{
	size_t	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (FALSE);
	while (i < (size_t)argc)
	{
		if (!is_nbr(argv[i]))
			return (FALSE);
		if ((i < 5 && *argv[i] == '0')
			|| (argc == 6 && i == 5 && *argv[i] == '0'))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
