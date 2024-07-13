/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:49:47 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/06 19:52:41 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM__HPP__
#define __SHRUBBERYCREATIONFORM__HPP__

#include <fstream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(std::string const &target) throw();
	ShrubberyCreationForm(ShrubberyCreationForm const &src) throw();
	virtual ~ShrubberyCreationForm(void) throw();

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs) throw();

	virtual void beExecuted(void) const throw();

protected:
	ShrubberyCreationForm(void) throw();
};

#endif
