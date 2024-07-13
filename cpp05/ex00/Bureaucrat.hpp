/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:39:54 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/06 23:17:29 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class Bureaucrat
{
public:
	/* GradeTooHighException */

	class GradeTooHighException : public std::logic_error
	{
	public:
		GradeTooHighException(void) throw();
		explicit GradeTooHighException(std::string const &what_arg) throw();
	};

	/* GradeTooLowException */

	class GradeTooLowException : public std::logic_error
	{
	public:
		GradeTooLowException(void) throw();
		explicit GradeTooLowException(std::string const &what_arg) throw();
	};

	/* Bureaucrat */

	Bureaucrat(std::string const &name, int const grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
	Bureaucrat(Bureaucrat const &src) throw();
	virtual ~Bureaucrat(void) throw();

	Bureaucrat &operator=(Bureaucrat const &rhs) throw();

	std::string const &getName(void) const throw();
	int getGrade(void) const throw();
	void incrementGrade(void) throw(Bureaucrat::GradeTooHighException);
	void decrementGrade(void) throw(Bureaucrat::GradeTooLowException);

protected:
	Bureaucrat(void) throw();

private:
	std::string const name;
	int grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif
