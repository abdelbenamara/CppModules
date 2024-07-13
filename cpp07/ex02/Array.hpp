/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:36:27 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/14 01:17:49 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>

template <typename T>
class Array
{
public:
	Array(void);
	Array(unsigned int const n);
	Array(Array<T> const &src);
	virtual ~Array(void);

	Array<T> &operator=(Array<T> const &rhs);
	T &operator[](std::size_t const idx) throw(std::out_of_range);
	T const &operator[](std::size_t const idx) const throw(std::out_of_range);

	std::size_t size(void) const throw();

private:
	std::size_t mSize;
	T *mArray;

	T &get(std::size_t const idx) const throw(std::out_of_range);
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &i);

#include "Array.tpp"

#endif
