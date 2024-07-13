/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:47:29 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/21 13:56:03 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>
#include <string>

class Zombie
{
public:
	Zombie(std::string const &name);
	~Zombie(void);

	void announce(void);

private:
	std::string name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
