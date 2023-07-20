/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HandlingString.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:05:40 by user              #+#    #+#             */
/*   Updated: 2023/07/20 12:21:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HandlingString_HPP
#define HandlingString_HPP

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class HandringString
{
	private:

	public:
		static	std::vector<std::string> 	inputargtomap_withoutfirst(std::string const &words);
		static	bool						return_matchpattern(std::string True_wd, std::string False_wd, std::string sub_wd);
		static	std::string					skipping_emptywd(std::string const &word);
};

#endif