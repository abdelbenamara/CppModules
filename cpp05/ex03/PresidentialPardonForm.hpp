/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:49:47 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/06 19:38:46 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM__HPP__
#define __PRESIDENTIALPARDONFORM__HPP__

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(std::string const &target) throw();
	PresidentialPardonForm(PresidentialPardonForm const &src) throw();
	virtual ~PresidentialPardonForm(void) throw();

	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs) throw();

	virtual void beExecuted(void) const throw();

protected:
	PresidentialPardonForm(void) throw();
};

#endif
