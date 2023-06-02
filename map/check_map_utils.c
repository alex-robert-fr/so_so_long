/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:58:54 by alex              #+#    #+#             */
/*   Updated: 2023/06/02 11:19:58 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"

int	check_line(char *str, int len)
{
	if (str)
	{
		if ((int)ft_strlen(str) != len)
			return (0);
	}
	return (1);
}