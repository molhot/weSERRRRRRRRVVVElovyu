/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:41:08 by user              #+#    #+#             */
/*   Updated: 2023/07/22 15:53:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Socket.hpp"

Socket::Socket(std::string const &port)
{
	this->_status = makesocket(port);	
}

Socket::~Socket()
{

}

int Socket::makeAddressInfo(std::string const &port, struct addrinfo **res)
{
	struct addrinfo	hints;
	int				errcode;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;//TCPとか
	hints.ai_socktype = SOCK_STREAM;//安定生のある通信
	hints.ai_flags = AI_PASSIVE;//bindするのに最適

	if ((errcode = getaddrinfo(NULL, port.c_str(), &hints, res)) != 0)
	{
		perror("getaddrinfo");
		return (-1);
	}
	return (0);
}

int	Socket::makesocket(std::string const &port)
{
	struct addrinfo *addr_inf = NULL;

	if (makeAddressInfo(port, &addr_inf) == -1)
		return (-1);
	_socketFD = socket(addr_inf->ai_family, addr_inf->ai_socktype, addr_inf->ai_protocol);
}