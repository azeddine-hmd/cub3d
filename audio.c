/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 03:56:18 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/22 23:12:15 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	play_audio(int id)
{
	char command[128];

	ft_bzero(command, 128);
	if (g_pref.is_audio_running)
		stop_audio();
	sprintf(command, "afplay soundtracks/%d.mp3 &", id);
	system(command);
	g_pref.is_audio_running = TRUE;
}

void	stop_audio(void)
{
	if (g_pref.is_audio_running)
	{
		system("killall afplay");
		g_pref.is_audio_running = FALSE;
	}
}

void	audio_binding(int key)
{
	if (key == KEY_0)
		stop_audio();
	else if (key == KEY_1)
		play_audio(1);
	else if (key == KEY_2)
		play_audio(2);
	else if (key == KEY_3)
		play_audio(3);
	else if (key == KEY_4)
		play_audio(4);
	else if (key == KEY_5)
		play_audio(5);
	else if (key == KEY_6)
		play_audio(6);
	else if (key == KEY_7)
		play_audio(7);
	else if (key == KEY_8)
		play_audio(8);
	else if (key == KEY_9)
		play_audio(9);
}
