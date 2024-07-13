/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:16:14 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/21 14:48:52 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <iostream>
#include <string>

class Harl
{
public:
	Harl(void);
	~Harl(void);

	void complain(std::string level);

private:
	static const std::string mood[];

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif
