/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:40:16 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/07 00:23:56 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat b1("Alice", 1);
	Bureaucrat b2("Bob", 150);

	std::cout << "\033[1;32mInfo: \033[0;34mBureaucrat parameterized constructor: b1: \033[0m" << b1 << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mBureaucrat parameterized constructor: b2: \033[0m" << b2 << std::endl;

	/* Parameterized constructor */

	Form f1("maggot example", 100, 50);

	std::cout << "\033[1;32mInfo: \033[0;34mForm parameterized constructor: f1: \033[0m" << f1 << std::endl;

	/* Copy constructor */

	Form f2(f1);

	std::cout << "\033[1;32mInfo: \033[0;34mForm copy constructor: f2: \033[0m" << f2 << std::endl;

	/* Getters */

	std::cout << "\033[1;32mInfo: \033[0;34mf2.getName(): \033[0m" << f2.getName() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf2.getSignGrade(): \033[0m" << f2.getSignGrade() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf2.getExecGrade(): \033[0m" << f2.getExecGrade() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf2.isSigned(): \033[0m" << f2.isSigned() << std::endl;

	/* GradeTooHighException */

	try
	{
		throw Form::GradeTooHighException();
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mdefault throw: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		throw Form::GradeTooHighException("Grade is too high");
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mparameterized throw: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		Form("GTH", 0, 75);
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mForm constructor: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		Form("GTH", 75, 0);
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mForm constructor: e.what(): \033[0m" << e.what() << std::endl;
	}

	/* GradeTooLowException */

	try
	{
		throw Form::GradeTooLowException();
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mdefault throw: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		throw Form::GradeTooLowException("Grade is too low");
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mparameterized throw: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		Form("GTL", 151, 75);
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mForm constructor: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		Form("GTL", 75, 151);
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mForm constructor: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		f2.beSigned(b2);
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mForm beSigned: e.what(): \033[0m" << e.what() << std::endl;
	}

	std::cout << "\033[1;32mInfo: \033[0;34mb1.signForm(f2): \033[0m";
	b1.signForm(f2);
	std::cout << "\033[1;32mInfo: \033[0;34mb2.signForm(f2): \033[0m";
	b2.signForm(f2);

	return (0);
}
