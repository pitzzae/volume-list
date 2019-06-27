/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_napi_set_object_uint32.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:33:03 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/13 13:30:47 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libnapi.h"

napi_value ft_napi_set_object_uint32(unsigned long value) {
	napi_status status;
	napi_value Number;

	status = napi_create_uint32(ft_napi_env(NULL), (uint32_t) value, &Number);
	if (status != napi_ok)
		napi_throw_error(ft_napi_env(NULL), NULL,
						 "Unable to create size number value");
	return Number;
}