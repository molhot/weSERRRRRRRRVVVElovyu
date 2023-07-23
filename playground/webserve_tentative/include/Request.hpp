/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:26:15 by user              #+#    #+#             */
/*   Updated: 2023/07/23 13:13:30 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//UserRequestの例
//
// POST /search.html HTTP/1.1\r\n
// Host: wa3.i-3-i.info\r\n
// Connection: keep-alive\r\n
// Content-Length: 38\r\n
// Cache-Control: max-age=0\r\n
// Origin: http://wa3.i-3-i.info\r\n
// Upgrade-Insecure-Requests: 1\r\n
// User-Agent: うんちゃら\r\n
// Content-Type: application/x-www-form-urlencoded\r\n
// Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\n
// Referer: http://wa3.i-3-i.info/index.html\r\n
// Accept-Encoding: gzip, deflate\r\n
// Accept-Language: ja,en-US;q=0.8,en;q=0.6\r\n
// \r\n
// q=test&submitSearch=%E6%A4%9C%E7%B4%A2

#ifndef Request_HPP
#define Request_HPP

#include <string>

//　userから送られるメッセージは事前にエラーチェックがされているはずなので
//　ここにerrorcheckは必要ない

class Request
{
	private:
		std::string	_method;
		std::string	_contentlength;

	public:
	
};

#endif