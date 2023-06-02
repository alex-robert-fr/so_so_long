/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:48:11 by alrobert          #+#    #+#             */
/*   Updated: 2023/06/02 11:23:33 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"
#include "map.h"

void	test_check_path(char *str)
{
	header(str);
	test(check_path("./main.c") == 0, "Exist file		:	\033[96m./main.c\033[0m");
	test(check_path("./pablo.c") == 1, "Not exist file		:	\033[96m./pablo.c\033[0m");
	test(check_path("./test/") == 1, "Directory		: 	\033[96m./test/\033[0m");
}

void	test_check_map(char *str)
{
	header(str);
	test(check_map("./main.c") == 0, "Random file		:	\033[96m./main.c\033[0m");
	test(check_map("./map/random.ber") == 0, "Random file		:	\033[96m./map/random.ber\033[0m");
	test(check_map("./map/small_ok.ber.ber") != 0, "Random file		:	\033[96m./map/small_ok.ber\033[0m");
}
