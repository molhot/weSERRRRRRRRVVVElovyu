/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:18:14 by user              #+#    #+#             */
/*   Updated: 2023/07/23 20:38:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/AllConf.hpp"

#define BUFSIZE 1024
struct timeval AllConf::_timeout = {0, 200};

#define ERROR		-1
#define	NO_MESSAGE	0

void	AllConf::set_allrecvfds(fd_set *allfd)
{
	std::map<int, std::vector<SameportConf> > ::iterator	it = _sockets.begin();

	while (it != _sockets.end())
	{
		FD_SET(it->first, allfd);
		it++;
	}
}

void	AllConf::run()
{
	std::cout << "ok" << std::endl;

	fd_set						all_recvfds;
	fd_set						all_sendfds;
	fd_set						socket_recvfds;
	fd_set						socket_sendfds;
	std::map<int, std::string>	strage;
	int 						fd = 0;

	FD_ZERO(&all_recvfds);
	FD_ZERO(&all_sendfds);
	set_allrecvfds(&all_recvfds);
	std::cout << "this->_allaccseptFD" << this->_allaccseptFD << std::endl;
	
	while (true)
	{
		memcpy(&socket_recvfds, &all_recvfds, sizeof(all_recvfds));
		memcpy(&socket_sendfds, &all_sendfds, sizeof(all_sendfds));

		switch (select(this->_allaccseptFD + 1, &socket_recvfds, &socket_sendfds, NULL, &_timeout))
		{
			case ERROR:
				std::cout << "select missed" << std::endl;
				return ;
			
			case NO_MESSAGE:
				// std::cout << "waiting now" << std::endl;
				break;
			
			default:
				std::cout << "in the accept func" << std::endl;
				std::cout << "this->_allaccseptFD" << this->_allaccseptFD << std::endl;
				while (fd < this->_allaccseptFD + 1)
				{
					if (FD_ISSET(fd, &socket_recvfds))
					{
						if (_sockets.find(fd) != _sockets.end())
							connect_server_requester(fd, &all_recvfds);
						else
							accept_requestmessage(fd, &all_recvfds, &all_sendfds, strage);
					}
					fd++;
				}
				fd = 0;
		}
	}
}

void	AllConf::connect_server_requester(int fd, fd_set *all_recvfds)
{
	int	accept_fd;

	accept_fd = accept(fd, NULL, NULL);
	if (accept_fd == -1)
	{
		std::cout << "missed accept" << std::endl;
		return ;
	}
	this->_connnected_sockets[accept_fd] = fd;
	fcntl(accept_fd, F_SETFL, O_NONBLOCK);
	FD_SET(accept_fd, all_recvfds);
	if (this->_allaccseptFD < accept_fd)
		this->_allaccseptFD = accept_fd;
}

void	AllConf::accept_requestmessage(int fd, fd_set *all_recvfds, fd_set *all_sendfds, std::map<int, std::string> &strage)
{
	char	buffer[BUFSIZE + 1];
	int		len;
	static	std::map<int, int> checkedSize;

	len = recv(fd, buffer, BUFSIZE, 0);
	buffer[len] = '\0';
	strage[fd] = strage[fd] + buffer;
	if (strage[fd].find("\r\n\r\n") == std::string::npos)
		return ;
	
	Request user_request(strage[fd]);
	(void)all_recvfds;
	(void)all_sendfds;
}