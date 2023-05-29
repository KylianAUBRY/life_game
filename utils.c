/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:02:46 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/29 01:11:06 by kylian           ###   ########.fr       */
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

int	count_nb(int n)
{
	int	t;

	t = 0;
	if (n <= 0)
		t++;
	while (n != 0)
	{
		n /= 10;
		t++;
	}
	return (t);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;
	long	nb;

	i = count_nb(n) - 1;
	nb = n;
	dest = malloc(sizeof(char) * (count_nb(n) + 1));
	if (!dest)
		return (NULL);
	if (nb < 0)
	{
		dest[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		dest[0] = '0';
	while (nb != 0)
	{
		dest[i] = (nb % 10) + '0';
		i--;
		nb /= 10;
	}
	dest[count_nb(n)] = '\0';
	return (dest);
}
