/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HandlingString.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:05:40 by user              #+#    #+#             */
/*   Updated: 2023/07/19 23:44:03 by user             ###   ########.fr       */
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
		static std::vector<std::string> inputargtomap_withoutfirst(std::string const &words);
		static bool						return_matchpattern(std::string True_wd, std::string False_wd, std::string sub_wd);
};

std::vector<std::string> HandringString::inputargtomap_withoutfirst(std::string const &words)
{
	std::string					word;
	std::istringstream			splited_words(words);
	std::vector<std::string>	ans;

	splited_words >> word;
	while (splited_words >> word)
		ans.push_back(word);
	return (ans);
}

bool HandringString::return_matchpattern(std::string True_wd, std::string False_wd, std::string sub_wd)
{
	if (True_wd == sub_wd)
		return (true);
	else
		return (false);
}
#endif