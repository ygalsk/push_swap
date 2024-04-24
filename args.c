/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:00:06 by dkremer           #+#    #+#             */
/*   Updated: 2024/04/24 15:00:06 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  ft_contains(int num, char **argv, int i)
{
    i++;
    while (argv[i])
    {
        if (ft_atoi(argv[i]) == num)
            return (1);
        i++;
    }
    return (0);
}

static int  ft_isnum(char *num)
{
    int i;

    i = 0;
    if (num[0] == '-')
        i++;
    while (num[i])
    {
        if (!ft_isdigit(num[i]))
            return (0);
        i++;
    }
    return(1);
}

void    ft_check_args(int argc, char **argv)
{
    int i;
    long    tmp;
    char    **args;

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
        tmp = ft_atoi(args[i]);
        if (!ft_isnum(args[i]))
            error();
        if (ft_contains(tmp, args, i))
            error();
        if (tmp < -2147483648 || tmp > 2147483647)
            error();
        i++;
    }
 if (argc == 2)
    free_list(args);   
}