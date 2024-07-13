/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:02:03 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/24 13:17:32 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) throw(std::bad_alloc) : size(10000), storage()
{
	this->storage.reserve(this->size);

	return;
}

Span::Span(unsigned int const size) throw(std::range_error, std::bad_alloc) : size(size), storage()
{
	if (this->size > this->storage.max_size())
	{
		std::stringstream o;

		o << "Span::Span: std::range_error: Maximum size exceeded: " << this->storage.max_size() << " is the maximum amount of numbers that can be stored";

		throw std::range_error(o.str());
	}

	this->storage.reserve(this->size);

	return;
}

Span::Span(Span const &src) throw(std::bad_alloc) : size(src.size), storage()
{
	this->storage.reserve(this->size);
	this->storage.insert(this->storage.begin(), src.storage.begin(), src.storage.end());

	return;
}

Span::~Span(void) throw() { return; }

Span &Span::operator=(Span const &rhs) throw(std::bad_alloc)
{
	if (this != &rhs)
	{
		const_cast<unsigned int &>(this->size) = rhs.size;

		std::vector<int>().swap(this->storage);

		this->storage.reserve(this->size);
		this->storage.insert(this->storage.begin(), rhs.storage.begin(), rhs.storage.end());
	}

	return (*this);
}

unsigned int const &Span::getSize(void) const throw() { return (this->size); }

void Span::addNumber(int const value) throw(std::range_error)
{
	if (this->storage.size() + 1 > this->size)
	{
		std::stringstream o;

		o << "Span::addNumber: std::range_error: No number can be added: " << this->size << " is the maximum amount of numbers that can be stored";

		throw std::range_error(o.str());
	}

	this->storage.push_back(value);

	return;
}

unsigned int Span::shortestSpan(void) throw(std::range_error, std::bad_alloc)
{
	std::vector<int> diff;

	if (this->storage.size() < 2)
	{
		std::stringstream o;

		o << "Span::shortestSpan: std::range_error: No shortest span can be found: " << this->storage.size() << " numbers stored, but at least 2 numbers are expected";

		throw std::range_error(o.str());
	}

	diff.reserve(this->storage.size());
	std::sort(this->storage.begin(), this->storage.end());
	std::adjacent_difference(this->storage.begin(), this->storage.end(), std::back_inserter(diff));

	return (*std::min_element(diff.begin() + 1, diff.end()));
}

unsigned int Span::longestSpan(void) throw(std::range_error)
{
	if (this->storage.size() < 2)
	{
		std::stringstream o;

		o << "Span::longestSpan: std::range_error: No longest span can be found: " << this->storage.size() << " numbers stored, but at least 2 numbers are expected";

		throw std::range_error(o.str());
	}

	std::sort(this->storage.begin(), this->storage.end());

	return (this->storage.back() - this->storage.front());
}
