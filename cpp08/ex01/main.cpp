/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:00:31 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/24 13:17:44 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
#include "Span.hpp"

static int number = -5000;

static int uniqueNumber() { return (++number); }

int main(void)
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		try
		{
			sp.addNumber(0);
		}
		catch (std::exception const &e)
		{
			std::cerr << "\033[1;31mError: \033[0m" << e.what() << '\n';
		}

		std::cout << "\033[1;32mInfo: \033[0;34mSpan::shortestSpan: \033[0m" << sp.shortestSpan() << std::endl;
		std::cout << "\033[1;32mInfo: \033[0;34mSpan::longestSpan: \033[0m" << sp.longestSpan() << std::endl;
	}

	{
		int const myints[] = {6, 3, 17, 9, 11};
		Span sp = Span(5);

		sp.addNumbers(myints, myints + 5);

		try
		{
			sp.addNumbers(myints, myints + 3);
		}
		catch (std::exception const &e)
		{
			std::cerr << "\033[1;31mError: \033[0m" << e.what() << '\n';
		}

		std::cout << "\033[1;32mInfo: \033[0;34mSpan::shortestSpan: \033[0m" << sp.shortestSpan() << std::endl;
		std::cout << "\033[1;32mInfo: \033[0;34mSpan::longestSpan: \033[0m" << sp.longestSpan() << std::endl;
	}

	{
		Span sp = Span();
		std::vector<int> myvector(sp.getSize());

		std::generate(myvector.begin(), myvector.end(), ::uniqueNumber);

		try
		{
			sp.shortestSpan();
		}
		catch (std::exception const &e)
		{
			std::cerr << "\033[1;31mError: \033[0m" << e.what() << '\n';
		}

		try
		{
			sp.longestSpan();
		}
		catch (std::exception const &e)
		{
			std::cerr << "\033[1;31mError: \033[0m" << e.what() << '\n';
		}

		sp.addNumber(myvector.front());

		try
		{
			sp.shortestSpan();
		}
		catch (std::exception const &e)
		{
			std::cerr << "\033[1;31mError: \033[0m" << e.what() << '\n';
		}

		try
		{
			sp.longestSpan();
		}
		catch (std::exception const &e)
		{
			std::cerr << "\033[1;31mError: \033[0m" << e.what() << '\n';
		}

		sp.addNumbers(myvector.begin() + 1, myvector.end());

		std::cout << "\033[1;32mInfo: \033[0;34mSpan::shortestSpan: \033[0m" << sp.shortestSpan() << std::endl;
		std::cout << "\033[1;32mInfo: \033[0;34mSpan::longestSpan: \033[0m" << sp.longestSpan() << std::endl;
	}

	return (0);
}
