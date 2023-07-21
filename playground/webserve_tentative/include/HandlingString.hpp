/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HandlingString.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:05:40 by user              #+#    #+#             */
/*   Updated: 2023/07/21 12:04:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HandlingString_HPP
#define HandlingString_HPP

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

class HandringString
{
	private:

	public:
		static	bool						ch_lastword_semicoron(std::string const &word);
		static	std::string					skip_lastsemicoron(std::string const &word);
		static	std::vector<std::string> 	inputargtomap_withoutfirst(std::string const &words);
		static	bool						return_matchpattern(std::string True_wd, std::string False_wd, std::string sub_wd);
		static	std::string					skipping_emptywd(std::string const &word);
		static	bool						ch_under_intmax(std::string const &word);
		static	int							str_to_int(std::string const &word);
		static	void						error_show(std::string const &word, size_t const &pos);
};

#endif