/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:23:33 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/07 01:02:46 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN__HPP__
#define __INTERN__HPP__

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern(void) throw();
	Intern(Intern const &src) throw();
	virtual ~Intern(void) throw();

	Intern &operator=(Intern const &rhs) throw();

	AForm *makeForm(std::string const &name, std::string const &target) const throw();

private:
	static std::string const FORMS[];

	AForm *makeShrubberyCreationForm(std::string const &target) const throw();
	AForm *makeRobotomyRequestForm(std::string const &target) const throw();
	AForm *makePresidentialPardonForm(std::string const &target) const throw();
};

#endif
