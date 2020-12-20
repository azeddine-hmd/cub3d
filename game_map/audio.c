/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 03:56:18 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/20 04:06:29 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	play_audio(int id)
{
	char command[128];

	ft_bzero(command);
	if (game()->is_audio_running)
		stop_audio();
	sprintf(command, "afplay soundtracks/%d.mp3 &", id);
	system(command);
	game()->is_audio_running = TRUE;
}

void	stop_audio(void)
{
	system("killall afplay");
}
