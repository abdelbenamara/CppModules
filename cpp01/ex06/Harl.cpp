/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:20:20 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/21 14:51:01 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string const Harl::mood[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(void)
{
	return;
}

Harl::~Harl(void)
{
	return;
}

void Harl::complain(std::string const &level) const
{
	std::size_t i;

	i = 0;
	while (i < 4 && mood[i] != level)
		++i;

	switch (i)
	{
	case 0:
		this->debug();
		std::cout << std::endl;

		/* FALLTHROUGH */

	case 1:
		this->info();
		std::cout << std::endl;

		/* FALLTHROUGH */

	case 2:
		this->warning();
		std::cout << std::endl;

		/* FALLTHROUGH */

	case 3:
		this->error();

		break;

	default:
		std::cout << "\033[0:37m";
		std::cout << "[ Probably complaining about insignificant problems ]";
		std::cout << "\033[0m" << std::endl;

		break;
	}

	return;
}

void Harl::debug(void) const
{
	std::cout << "\033[0:37m";
	std::cout << "[ DEBUG ]";
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[0;36m";
	std::cout << "I love having extra onion rings for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. ";
	std::cout << "I really do!";
	std::cout << "\033[0m" << std::endl;

	return;
}

void Harl::info(void) const
{
	std::cout << "\033[0:37m";
	std::cout << "[ INFO ]";
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[0;32m";
	std::cout << "I cannot believe adding extra onion rings costs more money. ";
	std::cout << "You didn't put enough onion rings in my burger! ";
	std::cout << "If you did, I wouldn't be asking for more!";
	std::cout << "\033[0m" << std::endl;

	return;
}

void Harl::warning(void) const
{
	std::cout << "\033[0:37m";
	std::cout << "[ WARNING ]";
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[1;33m";
	std::cout << "I think I deserve to have some extra onion rings for free. ";
	std::cout << "I've been coming for years ";
	std::cout << "whereas you started working here since last month.";
	std::cout << "\033[0m" << std::endl;

	return;
}

void Harl::error(void) const
{
	std::cout << "\033[0:37m";
	std::cout << "[ ERROR ]";
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[1;31m";
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << "\033[0m" << std::endl;

	return;
}
