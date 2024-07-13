/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:44:46 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/07 00:22:17 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* GradeTooHighException */

Bureaucrat::GradeTooHighException::GradeTooHighException(void) throw() : std::logic_error("Bureaucrat::GradeTooHighException") { return; }

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string const &what_arg) throw() : std::logic_error(what_arg) { return; }

/* GradeTooLowException */

Bureaucrat::GradeTooLowException::GradeTooLowException(void) throw() : std::logic_error("Bureaucrat::GradeTooLowException") { return; }

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string const &what_arg) throw() : std::logic_error(what_arg) { return; }

/* Bureaucrat */

Bureaucrat::Bureaucrat(void) throw() : name(), grade() { return; }

Bureaucrat::Bureaucrat(std::string const &name, int const grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException) : name(name), grade(grade)
{
	std::ostringstream o;

	if (this->grade < 1)
	{
		o << "Bureaucrat::GradeTooHighException: Bureaucrat::Bureaucrat: " << *this << ": Grade is too high (smaller than 1)";

		throw Bureaucrat::GradeTooHighException(o.str());
	}

	if (this->grade > 150)
	{
		o << "Bureaucrat::GradeTooLowException: Bureaucrat::Bureaucrat: " << *this << ": Grade is too low (greater than 150)";

		throw Bureaucrat::GradeTooLowException(o.str());
	}

	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) throw() : name(src.name), grade(src.grade) { return; }

Bureaucrat::~Bureaucrat(void) throw() { return; }

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) throw()
{
	if (this != &rhs)
	{
		const_cast<std::string &>(this->name) = rhs.name;
		this->grade = rhs.grade;
	}

	return (*this);
}

std::string const &Bureaucrat::getName(void) const throw() { return (this->name); }

int Bureaucrat::getGrade(void) const throw() { return (this->grade); }

void Bureaucrat::incrementGrade(void) throw(Bureaucrat::GradeTooHighException)
{
	std::ostringstream o;

	--this->grade;

	if (this->grade < 1)
	{
		o << "Bureaucrat::GradeTooHighException: Bureaucrat::incrementGrade: " << *this << ": Grade is too high (smaller than 1)";

		++this->grade;

		throw Bureaucrat::GradeTooHighException(o.str());
	}

	return;
}

void Bureaucrat::decrementGrade(void) throw(Bureaucrat::GradeTooLowException)
{
	std::ostringstream o;

	++this->grade;

	if (this->grade > 150)
	{
		o << "Bureaucrat::GradeTooLowException: Bureaucrat::decrementGrade: " << *this << ": Grade is too low (greater than 150)";

		--this->grade;

		throw Bureaucrat::GradeTooLowException(o.str());
	}

	return;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i) { return (o << i.getName() << ", bureaucrat grade " << i.getGrade()); }
