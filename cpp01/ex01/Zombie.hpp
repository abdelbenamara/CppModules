/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:47:29 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/21 14:01:49 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>
#include <string>

class Zombie
{
public:
	Zombie(void);
	~Zombie(void);

	void setName(std::string const &name);
	void announce(void) const;

private:
	std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif
