/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:01:08 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/17 19:40:58 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv)
{
	Sed fr;

	if (argc != 4) {
		std::cerr << "Invalid number of arguments" << std::endl;
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	if (argv[1][0] == '\0' || argv[2][0] == '\0') {
		std::cout << "Error: empty argument" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	fr.fileReplace();
	return 0;
}

// __attribute__((destructor)) void end(void)
// {
// 	system("leaks -q replace");
// }