/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:47:21 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/07 00:23:39 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* GradeTooHighException */

Form::GradeTooHighException::GradeTooHighException(void) throw() : std::logic_error("Form::GradeTooHighException") { return; }

Form::GradeTooHighException::GradeTooHighException(std::string const &what_arg) throw() : std::logic_error(what_arg) { return; }

/* GradeTooLowException */

Form::GradeTooLowException::GradeTooLowException(void) throw() : std::logic_error("Form::GradeTooLowException") { return; }

Form::GradeTooLowException::GradeTooLowException(std::string const &what_arg) throw() : std::logic_error(what_arg) { return; }

/* Form */

Form::Form(void) throw() : name(), signGrade(), execGrade(), mSigned() { return; }

Form::Form(Form const &src) throw() : name(src.name), signGrade(src.signGrade), execGrade(src.execGrade), mSigned(src.mSigned) { return; }

Form::Form(std::string const &name, int const signGrade, int const execGrade) throw(Form::GradeTooHighException, Form::GradeTooLowException) : name(name), signGrade(signGrade), execGrade(execGrade), mSigned(false)
{
	std::ostringstream o;

	if (this->signGrade < 1)
	{
		o << "Form::GradeTooHighException: Form::Form: " << *this << ": Sign grade is too high (smaller than 1)";

		throw Form::GradeTooHighException(o.str());
	}

	if (this->signGrade > 150)
	{
		o << "Form::GradeTooLowException: Form::Form: " << *this << ": Sign grade is too low (greater than 150)";

		throw Form::GradeTooLowException(o.str());
	}

	if (this->execGrade < 1)
	{
		o << "Form::GradeTooHighException: Form::Form: " << *this << ": Exec grade is too high (smaller than 1)";

		throw Form::GradeTooHighException(o.str());
	}

	if (this->execGrade > 150)
	{
		o << "Form::GradeTooLowException: Form::Form: " << *this << ": Exec grade is too low (greater than 150)";

		throw Form::GradeTooLowException(o.str());
	}

	return;
}

Form::~Form(void) throw() { return; }

Form &Form::operator=(Form const &rhs) throw()
{
	if (this != &rhs)
	{
		const_cast<std::string &>(this->name) = rhs.name;
		const_cast<int &>(this->signGrade) = rhs.signGrade;
		const_cast<int &>(this->execGrade) = rhs.execGrade;
		this->mSigned = rhs.mSigned;
	}

	return (*this);
}

std::string const &Form::getName(void) const throw() { return (this->name); }

int Form::getSignGrade(void) const throw() { return (this->signGrade); }

int Form::getExecGrade(void) const throw() { return (this->execGrade); }

bool Form::isSigned(void) const throw() { return (this->mSigned); }

void Form::beSigned(Bureaucrat const &signatory) throw(Form::GradeTooLowException)
{
	std::ostringstream o;

	if (signatory.getGrade() > this->signGrade)
	{
		o << "Form::GradeTooLowException: Form::beSigned: " << *this << ": Bureaucrat grade is not higher or equal to form sign grade (" << signatory << ')';

		throw Form::GradeTooLowException(o.str());
	}

	this->mSigned = true;

	return;
}

std::ostream &operator<<(std::ostream &o, Form const &i) { return (o << i.getName() << ", form sign grade " << i.getSignGrade() << ", form exec grade " << i.getExecGrade() << ", form signed " << std::boolalpha << i.isSigned()); }
