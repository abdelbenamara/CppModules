/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:17:11 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/07 01:09:10 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	AForm *form;

	std::cout << "\033[1;32mInfo: \033[0;34msomeRandomIntern.makeForm: \033[0m";
	form = someRandomIntern.makeForm("shrubbery creation", "testSC");
	std::cout << "\033[1;32mInfo: \033[0;34mIntern::makeForm: *form: \033[0m" << *form << std::endl;

	delete form;

	std::cout << "\033[1;32mInfo: \033[0;34msomeRandomIntern.makeForm: \033[0m";
	form = someRandomIntern.makeForm("robotomy request", "testRR");
	std::cout << "\033[1;32mInfo: \033[0;34mIntern::makeForm: *form: \033[0m" << *form << std::endl;

	delete form;

	std::cout << "\033[1;32mInfo: \033[0;34msomeRandomIntern.makeForm: \033[0m";
	form = someRandomIntern.makeForm("presidential pardon", "testPP");
	std::cout << "\033[1;32mInfo: \033[0;34mIntern::makeForm: *form: \033[0m" << *form << std::endl;

	delete form;

	std::cout << "\033[1;32mInfo: \033[0;34msomeRandomIntern.makeForm: \033[0m";
	form = someRandomIntern.makeForm("bla bla bla", "testBBB");
	std::cout << "\033[1;32mInfo: \033[0;34mIntern::makeForm: form: \033[0m";

	if (form)
		std::cout << form;
	else
		std::cout << "NULL";

	std::cout << std::endl;

	return (0);
}
