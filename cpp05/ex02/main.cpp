/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:40:16 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/07 00:19:27 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	srand(time(NULL));

	Bureaucrat b1("Alice", 1);
	Bureaucrat b2("Bob", 150);

	std::cout << "\033[1;32mInfo: \033[0;34mBureaucrat parameterized constructor: b1: \033[0m" << b1 << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mBureaucrat parameterized constructor: b2: \033[0m" << b2 << std::endl;

	/* Parameterized constructor */

	ShrubberyCreationForm s1("testSC");
	RobotomyRequestForm r1("testRR");
	PresidentialPardonForm p1("testPP");

	std::cout << "\033[1;32mInfo: \033[0;34mShrubberyCreationForm parameterized constructor: s: \033[0m" << s1 << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mRobotomyRequestForm parameterized constructor: r: \033[0m" << r1 << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mPresidentialPardonForm parameterized constructor: p: \033[0m" << p1 << std::endl;

	/* Copy constructor */

	AForm *f1 = new ShrubberyCreationForm(s1);
	AForm *f2 = new RobotomyRequestForm(r1);
	AForm *f3 = new PresidentialPardonForm(p1);

	std::cout << "\033[1;32mInfo: \033[0;34mShrubberyCreationForm copy constructor: f1: \033[0m" << *f1 << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mRobotomyRequestForm copy constructor: f2: \033[0m" << *f2 << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mPresidentialPardonForm copy constructor: f3: \033[0m" << *f3 << std::endl;

	/* Getters */

	std::cout << "\033[1;32mInfo: \033[0;34mf1.getName(): \033[0m" << f1->getName() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf1.getTarget(): \033[0m" << f1->getTarget() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf1.getSignGrade(): \033[0m" << f1->getSignGrade() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf1.getExecGrade(): \033[0m" << f1->getExecGrade() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf1.isSigned(): \033[0m" << f1->isSigned() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf2.getName(): \033[0m" << f2->getName() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf2.getTarget(): \033[0m" << f2->getTarget() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf2.getSignGrade(): \033[0m" << f2->getSignGrade() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf2.getExecGrade(): \033[0m" << f2->getExecGrade() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf2.isSigned(): \033[0m" << f2->isSigned() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf3.getName(): \033[0m" << f3->getName() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf3.getTarget(): \033[0m" << f3->getTarget() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf3.getSignGrade(): \033[0m" << f3->getSignGrade() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf3.getExecGrade(): \033[0m" << f3->getExecGrade() << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34mf3.isSigned(): \033[0m" << f3->isSigned() << std::endl;

	/* SignatureException */

	try
	{
		f1->execute(b1);
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mShrubberyCreationForm execute: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		f2->execute(b1);
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mRobotomyRequestForm execute: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		f3->execute(b1);
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mPresidentialPardonForm execute: e.what(): \033[0m" << e.what() << std::endl;
	}

	std::cout << "\033[1;32mInfo: \033[0;34mb1.signForm(*f1): \033[0m";
	b1.signForm(*f1);
	std::cout << "\033[1;32mInfo: \033[0;34mb2.signForm(*f1): \033[0m";
	b2.signForm(*f1);
	std::cout << "\033[1;32mInfo: \033[0;34mb1.signForm(*f2): \033[0m";
	b1.signForm(*f2);
	std::cout << "\033[1;32mInfo: \033[0;34mb2.signForm(*f2): \033[0m";
	b2.signForm(*f2);
	std::cout << "\033[1;32mInfo: \033[0;34mb1.signForm(*f3): \033[0m";
	b1.signForm(*f3);
	std::cout << "\033[1;32mInfo: \033[0;34mb2.signForm(*f3): \033[0m";
	b2.signForm(*f3);

	/* GradeTooLowException */

	try
	{
		f1->execute(b2);
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mShrubberyCreationForm execute: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		f2->execute(b2);
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mRobotomyRequestForm execute: e.what(): \033[0m" << e.what() << std::endl;
	}

	try
	{
		f3->execute(b2);
	}
	catch (std::exception const &e)
	{
		std::cerr << "\033[1;31mError: \033[0;34mPresidentialPardonForm execute: e.what(): \033[0m" << e.what() << std::endl;
	}

	std::cout << "\033[1;32mInfo: \033[0;34mb1.executeForm(*f1): \033[0m";
	b1.executeForm(*f1);
	std::cout << "\033[1;32mInfo: \033[0;34mb2.executeForm(*f1): \033[0m";
	b2.executeForm(*f1);
	std::cout << "\033[1;32mInfo: \033[0;34mb1.executeForm(*f2): \033[0m";
	b1.executeForm(*f2);
	std::cout << "\033[1;32mInfo: \033[0;34mb2.executeForm(*f2): \033[0m";
	b2.executeForm(*f2);
	std::cout << "\033[1;32mInfo: \033[0;34mb1.executeForm(*f3): \033[0m";
	b1.executeForm(*f3);
	std::cout << "\033[1;32mInfo: \033[0;34mb2.executeForm(*f3): \033[0m";
	b2.executeForm(*f3);

	delete f1;
	delete f2;
	delete f3;

	return (0);
}
