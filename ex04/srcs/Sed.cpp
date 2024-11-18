/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:34:14 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/17 19:32:22 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void Sed::fileReplace() {
    std::ifstream ifs(filename);
    std::string line;
    std::string::size_type n;

    if (ifs.fail()) {
        std::cerr << "Failed to open file." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::ofstream ofs(filename + ".replace");
    if (ofs.fail()) {
        std::cerr << "Failed to create/overwrite file: " << filename + ".replace" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    while (1) {
        std::getline(ifs, line);
        while (1) {
            n = line.find(s1);
            if (n == std::string::npos) {
                break;
            }
            ofs << line.substr(0, n) << s2;
            line = line.substr(n + s1.length());
        }
        ofs << line;
        if (ifs.eof()) {
            break;
        }
        ofs << std::endl;
    }
}
