/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeSockets.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:58:43 by user              #+#    #+#             */
/*   Updated: 2023/07/23 12:43:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/AllConf.hpp"

void	AllConf::makeServersockets()
{
	std::vector<std::string>						handled_port;
	std::map<std::string, int>						fd_with_port;
	std::map<std::string, SameportConf>::iterator	it = all_conf.begin();
	it++;
	while (it != all_conf.end())
	{
		std::cout << "=====" << std::endl;
		std::cout << it->first << std::endl;
		std::cout << it->second.get_port() << std::endl;
		std::vector<std::string>::iterator			it_ch = std::find(handled_port.begin(), handled_port.end(), it->second.get_port());
		if (it_ch == handled_port.end())
		{
			Socket	new_sock(it->second.get_port());
			fd_with_port[it->second.get_port()] = new_sock.get_socketFD();
			handled_port.push_back(it->second.get_port());
			this->_sockets[new_sock.get_socketFD()].push_back(it->second);
			this->_allaccseptFD = new_sock.get_socketFD();
		}
		else
			this->_sockets[fd_with_port[it->first]].push_back(it->second);
		it++;
	}
}