/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:18:13 by user              #+#    #+#             */
/*   Updated: 2023/07/21 19:05:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HandlingString.hpp"
#include "../include/InterpretLocationconf.hpp"
#include "../include/InterpretServerconf.hpp"
#include "../include/LocationConf.hpp"
#include "../include/SameportConf.hpp"
#include "../include/AllConf.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "x" << std::endl;
		return (1);
	}

	AllConf allconf(argv[1]);
	if (allconf.get_confready() == false)
	{
		std::cout << "x" << std::endl;
		return (1);
	}
}