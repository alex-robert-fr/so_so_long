/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:48:11 by alrobert          #+#    #+#             */
/*   Updated: 2023/05/29 19:08:23 by alrobert         ###   ########.fr       */
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
	test(check_path("./main.c") == 0, "Exist file		:	\033[96m./main.c\033[0m");
	test(check_path("./pablo.c") == 1, "Not exist file		:	\033[96m./pablo.c\033[0m");
	test(check_path("./test/") == 1, "Directory		: 	\033[96m./test/\033[0m");
}
