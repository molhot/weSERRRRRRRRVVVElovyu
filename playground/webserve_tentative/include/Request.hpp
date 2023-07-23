/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:26:15 by user              #+#    #+#             */
/*   Updated: 2023/07/23 20:38:40 by user             ###   ########.fr       */
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
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

//　userから送られるメッセージは事前にエラーチェックがされているはずなので
//　ここにerrorcheckは必要ない

class Request
{
	private:
		//request line
		std::string							_method;
		std::string							_version;
		std::string							_port;
		std::string							_servername;
		std::string							_allpath;
		std::string							_path;
		std::string							_querypath;
		std::map<std::string, std::string>	query_combi;
		std::string							_file_ext;
		bool								_is_redirect;

		//general header 一般ヘッダー
		std::string							_transfer_encoding;

		//request header　リクエストヘッダー
		std::string							_authorization;
		std::string							_accept_type;
		std::string							_accept_mimetype;
		std::string							_accept_mime_subtype;
		std::string							_accept_encoding;
		std::string							_accept_language;
		std::string							_except_status;

		//entyty header　エンティティヘッダー
		bool								_is_content;
		std::string							_content_type;
		std::string							_content_encoding;
		std::string							_content_lang;
		std::string							_content_location;
		std::string							_contentlength;

		//request body　ボディー
		std::string							_requestbody;

		void								split_path(void);

	public:
		Request(std::string const &message);
		~Request();
};

#endif