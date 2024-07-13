/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:39:47 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/14 01:19:03 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_TPP__
#define __ARRAY_TPP__

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : mSize(0), mArray(new T[this->mSize]) { return; }

template <typename T>
Array<T>::Array(unsigned int const n) : mSize(n), mArray(new T[this->mSize])
{
	for (std::size_t i = 0; i < this->mSize; ++i)
		this->mArray[i] = T();

	return;
}

template <typename T>
Array<T>::Array(Array<T> const &src) : mSize(src.mSize), mArray(new T[this->mSize])
{
	for (std::size_t i = 0; i < this->mSize; ++i)
		this->mArray[i] = src.mArray[i];

	return;
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] this->mArray;

	return;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	if (this != &rhs)
	{
		delete[] this->mArray;

		this->mSize = rhs.mSize;
		this->mArray = new T[this->mSize];

		for (std::size_t i = 0; i < this->mSize; ++i)
			this->mArray[i] = rhs.mArray[i];
	}

	return (*this);
}

template <typename T>
T &Array<T>::operator[](std::size_t const idx) throw(std::out_of_range) { return (this->get(idx)); }

template <typename T>
T const &Array<T>::operator[](std::size_t const idx) const throw(std::out_of_range) { return (this->get(idx)); }

template <typename T>
std::size_t Array<T>::size(void) const throw() { return (this->mSize); }

template <typename T>
T &Array<T>::get(std::size_t const idx) const throw(std::out_of_range)
{
	std::stringstream o;

	if (idx >= this->mSize)
	{
		o << "Array<T>::operator[]: std::out_of_range: " << idx << " is out of bounds";

		throw std::out_of_range(o.str());
	}

	return (this->mArray[idx]);
}

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &i)
{
	o << '[';

	for (std::size_t n = 0; n < i.size(); ++n)
	{
		o << ' ' << i[n];

		if (n + 1 < i.size())
			o << ',';
	}

	return (o << " ]");
}

#endif
