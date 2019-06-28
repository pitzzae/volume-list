/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_napi_set_object_number.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:33:03 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/28 16:05:26 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libnapi.h"

napi_value ft_napi_set_object_number(unsigned long value) {
	napi_status status;
	napi_value Number;

	status = napi_create_double(ft_napi_env(NULL), (double) value, &Number);
	if (status != napi_ok)
		napi_throw_error(ft_napi_env(NULL), NULL,
						 "Unable to create size number value");
	return Number;
}