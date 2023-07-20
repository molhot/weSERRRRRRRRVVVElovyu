/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HandlingString.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:21:15 by user              #+#    #+#             */
/*   Updated: 2023/07/20 12:21:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/HandlingString.hpp"

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
	else if (False_wd == sub_wd)
		return (false);
	return (false);
}

std::string HandringString::skipping_emptywd(std::string const &word)
{
	std::string src = "";
	size_t		pos = 0;

	while (word[pos] != '\0')
	{
		if (word[pos] != ' ' && word[pos] != '\t')
			src = src + word[pos];
		pos++;
	}
	return (src);
}