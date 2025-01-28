/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:11:48 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/03 11:26:09 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	error_message(char **av, int ac)
{
	if (ac == 2)
	{
		ft_free(av);
	}
	write(2, "Error\n", 6);
	exit(1);
}

static int	ft_digit(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
	{
		i++;
		if (av[i] < '0' || av[i] > '9')
			return (0);
	}
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check(char **av, int n, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == n)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_error_av2(char **av, int i, int ac)
{
	long	n;

	while (av[i])
	{
		if (ft_digit(av[i]) == 0)
			error_message(av, ac);
		n = ft_atoi(av[i]);
		if (n < -2147483648 || n > 2147483647)
			error_message(av, ac);
		if (ft_strlen(av[i]) > 15)
			error_message(av, ac);
		if (ft_check(av, n, i) == 1)
			error_message(av, ac);
		i++;
	}
}

void	ft_error_av(int ac, char **av)
{
	int		i;
	char	*str;

	i = 0;
	if (ac == 2)
	{
		str = ft_strtrim(av[1], " ");
		if (str[i] == '\0')
		{
			free(str);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(str);
		av = ft_split(av[1], ' ');
		if (av == NULL)
			error_message(av, ac);
	}
	else
		i = 1;
	ft_error_av2(av, i, ac);
	if (ac == 2)
		ft_free(av);
}
