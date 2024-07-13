/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:40:16 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/07 00:19:10 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	/* Parameterized constructor */

	Bureaucrat b1("Alice", 1);

	std::cout << "\033[1;32mInfo: \033[0;34mparameterized constructor: b1: \033[0m" << b1 << std::endl;

	/* Copy constructor */

	Bureaucrat b2(b1);

	std::cout << "\033[1;32mInfo: \033[0;34mcopy constructor: b2: \033[0m" << b2 << std::endl;

	/* Getters */

	std::cout << "\033[1;32mInfo: \033[0;34mb2.getName(): \033[0m" << b2.getName() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mb2.getGrade(): \033[0m" << b2.getGrade() << std::endl;

	/* GradeTooHighException */

	try
	{
		throw Bureaucrat::GradeTooHighException();
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mdefault throw: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		throw Bureaucrat::GradeTooHighException("Grade is too high");
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mparameterized throw: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		Bureaucrat("GTH", 0);
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mBureaucrat constructor: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		b2.incrementGrade();
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mBureaucrat incrementGrade: e.what(): \033[0m" << e.what() << std::endl;
	}

	/* GradeTooLowException */

	try
	{
		throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mdefault throw: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		throw Bureaucrat::GradeTooLowException("Grade is too low");
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mparameterized throw: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		Bureaucrat("GTL", 151);
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mBureaucrat constructor: e.what(): \033[0m" << e.what() << std::endl;
	}

	Bureaucrat b3("Bob", 150);

	std::cout << "\033[1;32mInfo: \033[0;34mparameterized constructor: b3: \033[0m" << b3 << std::endl;

	try
	{
		b3.decrementGrade();
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mBureaucrat decrementGrade: e.what(): \033[0m" << e.what() << std::endl;
	}

	return (0);
}
