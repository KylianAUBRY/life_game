/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:02:46 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/27 15:03:37 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

int ft_strlen(char *src)
{
	int i;

	i = 0;
	if (!src)
		return (i);
	while (src[i])
		i++;
	return (i);
}