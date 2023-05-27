/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:54:30 by kylian            #+#    #+#             */
/*   Updated: 2023/05/27 03:48:56 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

void ft_print_error(char *src)
{
    int i = -1;

    while (src[++i])
        write(2, &src[i], 1);
}

int print_error(int error_code)
{
    if (error_code == ERRCODE_MALLOC_FAIL)
        ft_print_error("Error :\nMalloc failed to allocate memory.\n");
    else if (error_code == ERRCODE_INIT_WIN)
        ft_print_error("Error :\nInit window failed\n");
    else if (error_code == ERRCODE_CREATE_WIN)
        ft_print_error("Error :\nFailed to create window\n");
    else if (error_code == ERRCODE_ARG)
        ft_print_error("Error :\nYou got your argument wrong\n");
    else if (error_code == ERRCODE_FILE_NUMBER)
        ft_print_error("Error :\nonly the characters '0' or '1' are accepted in the map\n");
    else if (error_code == ERRCODE_OPEN)
        ft_print_error("Error :\nOpen did not work, check if the file passed in parameter is good\n");
    return (0);
}