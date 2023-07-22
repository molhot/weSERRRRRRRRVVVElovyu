/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:26:28 by user              #+#    #+#             */
/*   Updated: 2023/07/23 01:20:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef Socket_HPP
# define Socket_HPP

# include <string>
# include <map>
# include <unistd.h>

# include <sys/param.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <sys/wait.h>

# include <arpa/inet.h>
# include <netinet/in.h>
# include <netdb.h>

# include <fcntl.h>

# include "SameportConf.hpp"

class Socket
{
	private:
		int			_socketFD;
		int			_status;

		int			makesocket(std::string const &port);
		int			makeAddressInfo(std::string const &port, struct addrinfo **res);

	public:
		Socket(std::string const &port);
		~Socket();

		int			get_socketFD(void) const;
};

# endif