/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:13:27 by alrobert          #+#    #+#             */
/*   Updated: 2023/05/29 17:26:48 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

void	test(int condition, char *str)
{
	if (condition)
	{
		ft_printf("\033[92m[ OK ]\033[0m : %s\033[0m\n", str);
	}
	else
	{
		ft_printf("\033[91m[ KO ] : %s\033[0m\n", str);
	}
}
