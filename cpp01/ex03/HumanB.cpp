/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:57:16 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/21 14:12:04 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string const &name) : name(name), weapon(NULL)
{
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;

	return;
}

void HumanB::attack(void) const
{
	std::cout << this->name << " attacks with their ";

	if (this->weapon != NULL)
		std::cout << this->weapon->getType();
	else
		std::cout << "bare hands";

	std::cout << std::endl;

	return;
}
