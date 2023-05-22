/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:33:55 by neves             #+#    #+#             */
/*   Updated: 2023/05/22 19:34:32 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s2[++i] != '\0')
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}