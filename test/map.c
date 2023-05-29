/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:48:11 by alrobert          #+#    #+#             */
/*   Updated: 2023/05/29 17:28:23 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"
#include "map.h"

void	test_check_path(char *str)
{
	ft_printf("\n--------------------------------\n");
	ft_printf("%s\n", str);
	ft_printf("--------------------------------\n");
	test(check_path("./main.c") == 0, "Exist file");
	test(check_path("./mai.c") == 1, "Not exist file");
}
