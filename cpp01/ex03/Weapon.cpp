/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:42:58 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/21 14:08:27 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const &type) : type(type)
{
	return;
}

Weapon::~Weapon(void)
{
	return;
}

std::string const &Weapon::getType(void) const
{
	return this->type;
}

void Weapon::setType(std::string const &type)
{
	this->type = type;

	return;
}
