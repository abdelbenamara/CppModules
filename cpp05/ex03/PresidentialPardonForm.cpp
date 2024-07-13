/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:54:36 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/07 00:26:20 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) throw() : AForm() { return; }

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) throw() : AForm("presidential pardon", target, 25, 5) { return; }

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) throw() : AForm(src) { return; }

PresidentialPardonForm::~PresidentialPardonForm(void) throw() { return; }

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) throw()
{
	AForm::operator=(rhs);

	return (*this);
}

void PresidentialPardonForm::beExecuted(void) const throw()
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;

	return;
}
