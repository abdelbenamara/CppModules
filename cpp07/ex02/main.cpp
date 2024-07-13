/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:09:39 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/14 01:31:38 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
	int *a = new int();
	Array<int> array1;
	Array<int> array2(10);
	Array<int> array3(array2);

	std::cout << "Info: new int(): a: " << *a << std::endl;

	delete a;

	std::cout << "Info: Array<int> default constructor: array1: " << array1 << std::endl;
	std::cout << "Info: Array<int> parameterized constructor: array2: " << array2 << std::endl;
	std::cout << "Info: Array<int> copy constructor: array3: " << array3 << std::endl;

	for (std::size_t i = 0; i < array2.size(); ++i)
		array2[i] = i;

	std::cout << "Info: array2 modified: " << array2 << std::endl;
	std::cout << "Info: array3: " << array3 << std::endl;

	Array<int> const array4(array2);

	std::cout << "Info: Array<int> copy constructor: array4 const: " << array4 << std::endl;

	array3 = array2;

	std::cout << "Info: Array<int> assignement operator: array3: " << array3 << std::endl;

	for (std::size_t i = 0; i < array3.size(); ++i)
		array3[i] *= array4[i];

	std::cout << "Info: array3 modified: " << array3 << std::endl;
	std::cout << "Info: array2: " << array2 << std::endl;
	std::cout << "Info: array4: " << array4 << std::endl;

	try
	{
		array4[array4.size()];
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: array4[array4.size()]: const operator[]: " << e.what() << std::endl;
	}

	Array<std::string> array5(3);

	std::cout << "Info: Array<std::string> parameterized constructor: array5: " << array5 << std::endl;

	array5[0] = "Hello";
	array5[1] = "World";
	array5[2] = "!";

	std::cout << "Info: array5: " << array5 << std::endl;

	try
	{
		array5[array5.size()];
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: array5[array5.size()]: operator[]: " << e.what() << std::endl;
	}

	return (0);
}
