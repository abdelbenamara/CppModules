/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:47:21 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/07 00:24:44 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* GradeTooHighException */

AForm::GradeTooHighException::GradeTooHighException(void) throw() : std::logic_error("AForm::GradeTooHighException") { return; }

AForm::GradeTooHighException::GradeTooHighException(std::string const &what_arg) throw() : std::logic_error(what_arg) { return; }

/* GradeTooLowException */

AForm::GradeTooLowException::GradeTooLowException(void) throw() : std::logic_error("AForm::GradeTooLowException") { return; }

AForm::GradeTooLowException::GradeTooLowException(std::string const &what_arg) throw() : std::logic_error(what_arg) { return; }

/* SignatureException */

AForm::SignatureException::SignatureException(void) throw() : std::logic_error("AForm::SignatureException") { return; }

AForm::SignatureException::SignatureException(std::string const &what_arg) throw() : std::logic_error(what_arg) { return; }

/* AForm */

AForm::AForm(void) throw() : name(), target(), signGrade(), execGrade(), mSigned() { return; }

AForm::AForm(AForm const &src) throw() : name(src.name), target(src.target), signGrade(src.signGrade), execGrade(src.execGrade), mSigned(src.mSigned) { return; }

AForm::AForm(std::string const &name, std::string const &target, int const signGrade, int const execGrade) throw(AForm::GradeTooHighException, AForm::GradeTooLowException) : name(name), target(target), signGrade(signGrade), execGrade(execGrade), mSigned(false)
{
	std::ostringstream o;

	if (this->signGrade < 1)
	{
		o << "AForm::GradeTooHighException: AForm::AForm: " << *this << ": Sign grade is too high (smaller than 1)";

		throw AForm::GradeTooHighException(o.str());
	}

	if (this->signGrade > 150)
	{
		o << "AForm::GradeTooLowException: AForm::AForm: " << *this << ": Sign grade is too low (greater than 150)";

		throw AForm::GradeTooLowException(o.str());
	}

	if (this->execGrade < 1)
	{
		o << "AForm::GradeTooHighException: " << *this << ": Exec grade is too high (smaller than 1)";

		throw AForm::GradeTooHighException(o.str());
	}

	if (this->execGrade > 150)
	{
		o << "AForm::GradeTooLowException: AForm::AForm: " << *this << ": Exec grade is too low (greater than 150)";

		throw AForm::GradeTooLowException(o.str());
	}

	return;
}

AForm::~AForm(void) throw() { return; }

AForm &AForm::operator=(AForm const &rhs) throw()
{
	if (this != &rhs)
	{
		const_cast<std::string &>(this->name) = rhs.name;
		const_cast<std::string &>(this->target) = rhs.target;
		const_cast<int &>(this->signGrade) = rhs.signGrade;
		const_cast<int &>(this->execGrade) = rhs.execGrade;
		this->mSigned = rhs.mSigned;
	}

	return (*this);
}

std::string const &AForm::getName(void) const throw() { return (this->name); }

std::string const &AForm::getTarget(void) const throw() { return (this->target); }

int AForm::getSignGrade(void) const throw() { return (this->signGrade); }

int AForm::getExecGrade(void) const throw() { return (this->execGrade); }

bool AForm::isSigned(void) const throw() { return (this->mSigned); }

void AForm::beSigned(Bureaucrat const &signatory) throw(AForm::GradeTooLowException)
{
	std::ostringstream o;

	if (signatory.getGrade() > this->signGrade)
	{
		o << "AForm::GradeTooLowException: AForm::beSigned: " << *this << ": Bureaucrat grade is not higher or equal to form sign grade (" << signatory << ')';

		throw AForm::GradeTooLowException(o.str());
	}

	this->mSigned = true;

	return;
}

void AForm::execute(Bureaucrat const &executor) const throw(AForm::SignatureException, AForm::GradeTooLowException)
{
	std::ostringstream o;

	if (!this->mSigned)
	{
		o << "AForm::SignatureException: AForm::execute: " << *this << ": Form is not signed";

		throw AForm::SignatureException(o.str());
	}

	if (executor.getGrade() > this->execGrade)
	{
		o << "AForm::GradeTooLowException: AForm::execute: " << *this << ": Bureaucrat grade is not higher or equal to form exec grade (" << executor << ')';

		throw AForm::GradeTooLowException(o.str());
	}

	this->beExecuted();

	return;
}

std::ostream &operator<<(std::ostream &o, AForm const &i) { return (o << i.getName() << ", target " << i.getTarget() << ", form sign grade " << i.getSignGrade() << ", form exec grade " << i.getExecGrade() << ", form signed " << std::boolalpha << i.isSigned()); }
