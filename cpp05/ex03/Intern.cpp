/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:24:18 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/07 01:06:22 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

std::string const Intern::FORMS[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

Intern::Intern(void) throw() { return; }

Intern::Intern(Intern const &) throw() { return; }

Intern::~Intern(void) throw() { return; }

Intern &Intern::operator=(Intern const &) throw()
{
	return (*this);
}

AForm *Intern::makeForm(std::string const &name, std::string const &target) const throw()
{
	static AForm *(Intern::*newForm[])(std::string const &) const =
		{&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
	std::size_t i;
	AForm *form;

	i = 0;
	while (i < 3 && FORMS[i] != name)
		++i;

	if (i == 3)
	{
		std::cerr << "Error: Intern::makeForm: Form name `" << name << "' is unknown" << std::endl;

		return (NULL);
	}

	form = (this->*newForm[i])(target);

	std::cout << "Intern creates " << *form << std::endl;

	return (form);
}

AForm *Intern::makeShrubberyCreationForm(std::string const &target) const throw()
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string const &target) const throw()
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(std::string const &target) const throw()
{
	return new PresidentialPardonForm(target);
}
