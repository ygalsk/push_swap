/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:49:10 by dkremer           #+#    #+#             */
/*   Updated: 2024/06/02 11:50:33 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	free_and_error(char **str)
{
	free_list(str);
	error();
}

void	check_error(int argc, char **str)
{
	if (argc > 2)
		error();
	free_and_error(str);
}
