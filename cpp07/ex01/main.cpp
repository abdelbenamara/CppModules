/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:57:45 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/13 18:49:58 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void pout(T &item)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << ", " << item;

	return;
}

template <typename T>
void incr(T &item)
{
	item += 49;

	return;
}

int main(void)
{
	char characters[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int integers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	float floatings[] = {0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F};
	std::string strings[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

	std::cout << "\033[1;32mInfo: \033[0;34miter<char>: pout\033[0m";
	::iter<char>(characters, 10, &::pout);
	std::cout << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;35miter<char>: incr: +49\033[0m" << std::endl;
	::iter<char>(characters, 10, &::incr);
	std::cout << "\033[1;32mInfo: \033[0;34miter<char>: pout\033[0m";
	::iter<char>(characters, 10, &::pout);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34miter<int>: pout\033[0m";
	::iter<int>(integers, 10, &::pout);
	std::cout << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;35miter<int>: incr: +49\033[0m" << std::endl;
	::iter<int>(integers, 10, &::incr);
	std::cout << "\033[1;32mInfo: \033[0;34miter<int>: pout\033[0m";
	::iter<int>(integers, 10, &::pout);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34miter<float>: pout\033[0m";
	::iter<float>(floatings, 10, &::pout);
	std::cout << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;35miter<float>: incr: +49\033[0m" << std::endl;
	::iter<float>(floatings, 10, &::incr);
	std::cout << "\033[1;32mInfo: \033[0;34miter<float>: pout\033[0m";
	::iter<float>(floatings, 10, &::pout);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34miter<std::string>: pout\033[0m";
	::iter<std::string>(strings, 10, &::pout);
	std::cout << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;35miter<std::string>: incr: +49\033[0m" << std::endl;
	::iter<std::string>(strings, 10, &::incr);
	std::cout << "\033[1;32mInfo: \033[0;34miter<std::string>: pout\033[0m";
	::iter<std::string>(strings, 10, &::pout);
	std::cout << std::endl;

	return (0);
}
