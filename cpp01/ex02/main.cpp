/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:28:33 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/14 13:11:08 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address of the string variable: ";
	std::cout << &str << std::endl;
	std::cout << "     The memory address held by stringPTR: ";
	std::cout << stringPTR << std::endl;
	std::cout << "     The memory address held by stringREF: ";
	std::cout << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "         The value of the string variable: ";
	std::cout << str << std::endl;
	std::cout << "        The value pointed to by stringPTR: ";
	std::cout << *stringPTR << std::endl;
	std::cout << "        The value pointed to by stringREF: ";
	std::cout << stringREF << std::endl;

	return 0;
}
