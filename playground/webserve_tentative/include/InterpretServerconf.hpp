/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InterpretSeverconf.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:36:37 by user              #+#    #+#             */
/*   Updated: 2023/07/20 11:04:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef InterpretServerconf_HPP
#define InterpretServerconf_HPP

#include <iostream>
#include <string>
#include <set>

class InterpretServerconf
{
	private:
		static const std::set<std::string> server_keyset;

	public:
		static bool serverkeyword_ch(const std::string& word);
};

#endif