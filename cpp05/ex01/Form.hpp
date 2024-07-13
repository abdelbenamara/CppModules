/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:45:11 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/06 23:17:44 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Form
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

	/* Form */

	Form(Form const &src) throw();
	Form(std::string const &name, int const signGrade, int const execGrade) throw(Form::GradeTooHighException, Form::GradeTooLowException);
	virtual ~Form(void) throw();

	Form &operator=(Form const &rhs) throw();

	std::string const &getName(void) const throw();
	int getSignGrade(void) const throw();
	int getExecGrade(void) const throw();
	bool isSigned(void) const throw();
	void beSigned(Bureaucrat const &signatory) throw(Form::GradeTooLowException);

protected:
	Form(void) throw();

private:
	std::string const name;
	int const signGrade;
	int const execGrade;
	bool mSigned;
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif
