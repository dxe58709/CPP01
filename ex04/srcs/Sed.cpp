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

Sed::Sed(const std::string &filename, const std::string &s1, const std::string &s2) : filename(filename), s1(s1), s2(s2)
{
}

bool Sed::replaceContent(){
	std::ifstream inputFile(filename);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open the input file." << std::endl;
		return (false);
	}
	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename);
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not open the output file." << std::endl;
		return (false);
	}
	std::string line;
	if (s1.empty())
	{
		std::cerr << "Error: Empty string to search for." << std::endl;
		return false;
	}
	while (std::getline(inputFile, line))
	{
		outputFile << replaceInLine(line) << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return (true);
}

std::string Sed::replaceInLine(const std::string &line)
{
	std::string result = line; // 引数の line をコピーして result に保存
	size_t pos = 0;            // 置き換えを開始する位置を 0 に初期化
	while ((pos = result.find(s1, pos)) != std::string::npos) // s1 を見つけた位置を pos に設定、見つからなければ終了
	{
		result = result.substr(0, pos) + s2 + result.substr(pos + s1.length()); // s1 を s2 に置き換える
		pos += s2.length(); // 検索位置を進める
	}
	return result; // 置き換えた結果を返す
}