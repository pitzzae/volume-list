/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_napi_set_object_property.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:33:03 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/13 13:30:47 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libnapi.h"

void
ft_napi_set_object_property(napi_value Object, char *name, napi_value Value) {
	napi_status status;

	status = napi_set_named_property(ft_napi_env(NULL), Object, name, Value);
	if (status != napi_ok)
		napi_throw_error(ft_napi_env(NULL), NULL, "Unable to set size value");
}