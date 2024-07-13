/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:45:11 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/06 23:17:51 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class AForm
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

	/* SignatureException */

	class SignatureException : public std::logic_error
	{
	public:
		SignatureException(void) throw();
		explicit SignatureException(std::string const &what_arg) throw();
	};

	/* AForm */

	AForm(AForm const &src) throw();
	AForm(std::string const &name, std::string const &target, int const signGrade, int const execGrade) throw(AForm::GradeTooHighException, AForm::GradeTooLowException);
	virtual ~AForm(void) throw();

	AForm &operator=(AForm const &rhs) throw();

	std::string const &getName(void) const throw();
	std::string const &getTarget(void) const throw();
	int getSignGrade(void) const throw();
	int getExecGrade(void) const throw();
	bool isSigned(void) const throw();
	void beSigned(Bureaucrat const &signatory) throw(AForm::GradeTooLowException);
	virtual void beExecuted(void) const throw() = 0;
	void execute(Bureaucrat const &executor) const throw(AForm::SignatureException, AForm::GradeTooLowException);

protected:
	AForm(void) throw();

private:
	std::string const name;
	std::string const target;
	int const signGrade;
	int const execGrade;
	bool mSigned;
};

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif
