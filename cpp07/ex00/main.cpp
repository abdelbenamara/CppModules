/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:49:37 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/13 18:49:53 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "swap(a, b)" << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::cout << "swap<int>(a, b)" << std::endl;
	::swap<int>(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min<int>( a, b ) = " << ::min<int>(a, b) << std::endl;
	std::cout << "max<int>( a, b ) = " << ::max<int>(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "swap(c, d)" << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	std::cout << "swap<std::string>(c, d)" << std::endl;
	::swap<std::string>(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min<std::string>( c, d ) = " << ::min<std::string>(c, d) << std::endl;
	std::cout << "max<std::string>( c, d ) = " << ::max<std::string>(c, d) << std::endl;

	return (0);
}
