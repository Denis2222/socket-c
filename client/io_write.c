/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:56:43 by dmoureu-          #+#    #+#             */
/*   Updated: 2017/10/04 17:15:06 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int sendall(int s, void *buf, size_t *len)
{
    size_t total = 0;        // how many bytes we've sent
    size_t bytesleft = *len; // how many we have left to send
    size_t n;

    while(total < *len) {
        n = send(s, buf+total, bytesleft, 0);
        if (n == -1)
		{
			break;
		}
        total += n;
        bytesleft -= n;
    }
    *len = total;
    if (n == -1)
		return (-1);
	return (0);
}

void write_server(int sock, char *buffer)
{
	int nb;
	size_t i;

	ft_printf("OK");
	i = ft_strlen(buffer);
	if (i > 0)
	{
		sendall(sock, buffer, &i);
	}
}
