/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllConf.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:18:13 by user              #+#    #+#             */
/*   Updated: 2023/07/18 22:13:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AllConf_HPP
#define AllConf_HPP

#include <iostream>
#include <map>
#include <vector>
#include "SameportConf.hpp"

class AllConf
{
	private:
		std::map<std::string, std::vector <SameportConf> >	all_conf;//port(listen) その中の各情報（ポートに紐づく情報は一つと限らない）
		bool												_confready;
		void												conf_check();
	public:
		AllConf(std::string const &config_file);
		~AllConf();
};

#endif
