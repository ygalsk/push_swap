/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:00:06 by dkremer           #+#    #+#             */
/*   Updated: 2024/06/02 11:51:52 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atol(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
	{
		i++;
		if (!num[i])
			return (0);
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_validate_args(int argc, char **args, char **sub_args, int i)
{
	int		j;
	long	tmp;

	j = 0;
	while (sub_args[j])
	{
		tmp = ft_atol(sub_args[j]);
		if (!ft_isnum(sub_args[j]) || ft_contains(tmp, args, i) || \
				tmp < -2147483648 || tmp > 2147483647)
		{
			free_list(sub_args);
			check_error(argc, args);
		}
		j++;
	}
	free_list(sub_args);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	char	**args;
	char	**sub_args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		sub_args = ft_split(args[i], ' ');
		if (!sub_args)
			check_error(argc, sub_args);
		else
			ft_validate_args(argc, args, sub_args, i);
		i++;
	}
	if (argc == 2)
		free_list(args);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sgn;
	long	res;

	i = 0;
	sgn = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sgn);
}
