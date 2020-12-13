/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:39:01 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/11 18:32:49 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*make_bmp_header(t_bitmapheader *header)
{
	char	*buf;

	buf = ft_calloc(54, 1);
	header->bit_count = 24;
	header->width_in_bytes = ((map()->win_width * header->bit_count + 31)
	/ 32) * 4;
	header->image_size = header->width_in_bytes * map()->win_height;
	header->size = 54 + header->image_size;
	header->off_bits = 54;
	header->info_size = 40;
	header->planes = 1;
	header->width = map()->win_width;
	header->height = map()->win_height;
	ft_memcpy(buf, "BM", 2);
	ft_memcpy(buf + 2, &(header->size), 4);
	ft_memcpy(buf + 10, &(header->off_bits), 4);
	ft_memcpy(buf + 14, &(header->info_size), 4);
	ft_memcpy(buf + 18, &(header->width), 4);
	ft_memcpy(buf + 22, &(header->height), 4);
	ft_memcpy(buf + 26, &(header->planes), 2);
	ft_memcpy(buf + 28, &(header->bit_count), 2);
	ft_memcpy(buf + 34, &(header->image_size), 4);
	return (buf);
}

int		*get_colors(int color)
{
	int *colors;

	colors = malloc(3 * sizeof(int));
	colors[0] = ((color >> 16) & 0xFF);
	colors[1] = ((color >> 8) & 0xFF);
	colors[2] = ((color) & 0xFF);
	return (colors);
}

char	*make_img_buff(t_bitmapheader *header)
{
	char	*buf;
	int		i;
	int		j;
	int		*colors;

	buf = malloc(header->image_size);
	i = header->height - 1;
	while (i > 0)
	{
		j = 0;
		while (j < header->width)
		{
			colors = get_colors(get_window_color(
				j,
				(map()->win_height - i)
			));
			buf[i * header->width_in_bytes + j * 3 + 2] = colors[0];
			buf[i * header->width_in_bytes + j * 3 + 1] = colors[1];
			buf[i * header->width_in_bytes + j * 3 + 0] = colors[2];
			free(colors);
			j++;
		}
		i--;
	}
	return (buf);
}

void	take_screenshot(void)
{
	t_bitmapheader	header;
	char			*header_str;
	char			*img_buf;

	header.fd = open("./screenshot.bmp", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	game_loop();
	header_str = make_bmp_header(&header);
	img_buf = make_img_buff(&header);
	write(header.fd, header_str, 54);
	write(header.fd, img_buf, header.image_size);
	free(header_str);
	free(img_buf);
	game_exit(0);
}
