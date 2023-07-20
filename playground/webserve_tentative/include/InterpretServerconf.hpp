/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InterpretServerconf.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:36:37 by user              #+#    #+#             */
/*   Updated: 2023/07/20 12:05:16 by user             ###   ########.fr       */
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

	public:
		static bool serverkeyword_ch(const std::string& word);
};

#endif