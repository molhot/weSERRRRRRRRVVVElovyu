/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:18:13 by user              #+#    #+#             */
/*   Updated: 2023/07/20 00:37:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AllConf.hpp"
#include "../include/HandlingString.hpp"
#include "../include/InterpretLocationconf.hpp"
#include "../include/InterpretSeverconf.hpp"
#include "../include/LocationConf.hpp"
#include "../include/SameportConf.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "x" << std::endl;
		return ;
	}

	AllConf allconf(argv[1]);
}