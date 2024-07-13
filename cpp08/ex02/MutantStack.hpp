/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:36:37 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/25 00:32:12 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <deque>
#include <iterator>
#include <stack>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack(void);
	MutantStack(MutantStack const &src);
	virtual ~MutantStack(void);

	MutantStack &operator=(MutantStack const &rhs);

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;
	typedef typename Container::difference_type difference_type;

	iterator begin(void);
	const_iterator begin(void) const;
	iterator end(void);
	const_iterator end(void) const;
	reverse_iterator rbegin(void);
	const_reverse_iterator rbegin(void) const;
	reverse_iterator rend(void);
	const_reverse_iterator rend(void) const;
};

#include "MutantStack.tpp"

#endif
