/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:48:05 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/14 00:38:27 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <cstddef>

template <typename T>
void iter(T array[], std::size_t const size, void (*f)(T &))
{
	for (std::size_t i = 0; i < size; ++i)
		f(array[i]);

	return;
}

#endif
