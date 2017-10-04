/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:08:28 by dmoureu-          #+#    #+#             */
/*   Updated: 2017/10/04 11:04:01 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int cmd_out(char *line, t_client *client)
{
   char **cmd;

   if (ft_strnstr(line, "/connect ", 9))
   {
	  cmd = ft_strsplit(line, ' ');
	  ft_printf("connect to : %s ...\n", cmd[1]);
	  ft_printf("HERE?");
	  if (connect_host(cmd[1], cmd[2], client))
		client->connect = 1;
   } else {
		if (client->connect) {
			write_server(client->socket, line);
		}
   }
   return (0);
}

int cmd_in(t_client *client)
{
	char **tab;
	char **cmds;
	int i;
	int n;
	char *cmd;

	cmd = read_server(client->socket, &n);
	if (n == 0 || cmd == NULL)
	{
		ft_printf("server disconnected");
		return (0);
	}
	ft_printf("cmd in BUFFER:[%s][%d]\n", cmd, ft_strlen(cmd));
	i = 0;
	cmds = ft_strsplit(cmd, '\n');
	while (cmds[i] != '\0')
	{
		if (cmds[i][0] == '/') {
			tab = ft_strsplit(cmds[i], ' ');
			if (ft_strnstr(cmds[i], "/nick ", 6))
			{
				ft_strcpy(client->name, tab[1]);
			}
			if (ft_strnstr(cmds[i], "/join ", 9))
			{
				ft_strcpy(client->channel, tab[1]);
			}
			if (ft_strnstr(cmds[i], "/newmsg ", 8))
			{
				ft_printf("\n%s\n", &cmd[8]);
				client->msg = addmsg(&client->msg, newmsg(&cmds[i][8], client));
			}
			ft_tabfree(tab);
		}
		i++;
	}
	free(cmd);
	cmd = NULL;
	ft_tabfree(cmds);
	return (0);
}
