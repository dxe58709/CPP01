/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 02:04:16 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/17 18:22:23 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class Sed {
	private:
		std::string filename;
		std::string s1;
		std::string s2;

	public:
		void fileReplace();
};
#endif