/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:49:47 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/06 21:11:39 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM__HPP__
#define __ROBOTOMYREQUESTFORM__HPP__

#include <cstdlib>
#include <ctime>
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(std::string const &target) throw();
	RobotomyRequestForm(RobotomyRequestForm const &src) throw();
	virtual ~RobotomyRequestForm(void) throw();

	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs) throw();

	virtual void beExecuted(void) const throw();

protected:
	RobotomyRequestForm(void) throw();
};

#endif
