/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_napi_create_object.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:33:03 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/13 13:30:47 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libnapi.h"

napi_value ft_napi_create_object(void) {
	napi_status status;
	napi_value Object;

	status = napi_create_object(ft_napi_env(NULL), &Object);
	if (status != napi_ok)
		napi_throw_error(ft_napi_env(NULL), NULL,
						 "Unable to create Object value");
	return Object;
}