/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:18:13 by user              #+#    #+#             */
/*   Updated: 2023/07/22 14:46:26 by user             ###   ########.fr       */
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

	// std::cout << "test" << std::endl;
	// std::map<std::string, SameportConf >	test = allconf.get_all_conf();
	// int										rank = test.size();
	// int										pos = 1;
	// int										location_pos = 1;
	// while (pos != rank)
	// {
	// 	SameportConf	portconf = test[allconf.get_conf_rank()[pos]];
	// 	std::cout << "---------" << std::endl;
	// 	std::cout << allconf.get_conf_rank()[pos] << std::endl;
	// 	std::cout << portconf.get_port() << std::endl;
	// 	std::cout << std::endl;
	// 	int				location_count = portconf.get_locations().size();
	// 	while (location_pos != location_count + 1)
	// 	{
	// 		LocationConf	locationconf = portconf.get_locations()[portconf.get_location_rank()[location_pos]];
	// 		std::cout << "~~~~~~~" << std::endl;
	// 		std::cout << portconf.get_location_rank()[location_pos] << std::endl;
	// 		locationconf.show_locationconfinf();
	// 		location_pos++;
	// 	}
	// 	pos++;
	// 	location_pos = 1;
	// }

	allconf.makeServersockets();
}