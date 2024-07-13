/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:48:38 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/21 13:57:23 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string const &name) : name(name)
{
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie \"" << this->name;
	std::cout << "\" has been destroyed !" << std::endl;

	return;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;

	return;
}
