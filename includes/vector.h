/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:18:41 by alrobert          #+#    #+#             */
/*   Updated: 2023/05/29 19:19:37 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

t_vector	v_zero(void);
t_vector	v_init(int x, int y);

#endif
