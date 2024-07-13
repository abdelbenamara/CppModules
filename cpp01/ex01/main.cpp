/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:06:52 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/27 20:40:57 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombies;

	zombies = zombieHorde(7, "Baz");

	for (int i = 0; i < 7; ++i)
		zombies[i].announce();

	delete[] zombies;

	return 0;
}
