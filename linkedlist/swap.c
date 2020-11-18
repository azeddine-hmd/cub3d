/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:19:06 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/18 12:22:24 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void	swap(t_data* this, t_data* other)
{
	void	*tmp;

	tmp = this->data;
	this->data = other->data;
	other->data = tmp;
}