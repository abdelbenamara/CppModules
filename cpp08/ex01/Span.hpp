/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:01:26 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/24 13:15:41 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <algorithm>
#include <iterator>
#include <new>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <vector>

class Span
{
public:
	Span(void) throw(std::bad_alloc);
	Span(unsigned int const size) throw(std::range_error, std::bad_alloc);
	Span(Span const &src) throw(std::bad_alloc);
	virtual ~Span(void) throw();

	Span &operator=(Span const &rhs) throw(std::bad_alloc);

	unsigned int const &getSize(void) const throw();
	void addNumber(int const value) throw(std::range_error);
	unsigned int shortestSpan(void) throw(std::range_error, std::bad_alloc);
	unsigned int longestSpan(void) throw(std::range_error);

	template <typename InputIterator>
	void addNumbers(InputIterator first, InputIterator last) throw(std::range_error)
	{
		typename std::iterator_traits<InputIterator>::difference_type n = std::distance(first, last);

		if (this->storage.size() + n > this->size)
		{
			std::stringstream o;

			o << "Span::addNumbers: std::range_error: Not all numbers can be added: " << n << " numbers received when " << this->storage.size() << " numbers stored, but a maximum amount of " << this->size << " numbers can be stored";

			throw std::range_error(o.str());
		}

		this->storage.insert(this->storage.end(), first, last);

		return;
	}

private:
	unsigned int const size;
	std::vector<int> storage;
};

#endif
