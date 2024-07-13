/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:54:36 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/07 00:26:16 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) throw() : AForm() { return; }

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) throw() : AForm("robotomy request", target, 72, 45) { return; }

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) throw() : AForm(src) { return; }

RobotomyRequestForm::~RobotomyRequestForm(void) throw() { return; }

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) throw()
{
	AForm::operator=(rhs);

	return (*this);
}

void RobotomyRequestForm::beExecuted(void) const throw()
{
	std::cout << "* SOME DRILLING NOISES * ... ";

	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully !" << std::endl;
	else
		std::cout << this->getTarget() << " robotomy failed." << std::endl;

	return;
}
