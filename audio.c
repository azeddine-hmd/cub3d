/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 06:22:58 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/13 20:21:24 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	play_song(int id)
{
	char command[128];

	system("killall afplay >/dev/null 2>/dev/null");
	ft_bzero(command, 128);
	sprintf(
			command,
			"afplay </dev/null >/dev/null 2&>1 soundtracks/%d.mp3 &",
			id);
	system(command);
}
