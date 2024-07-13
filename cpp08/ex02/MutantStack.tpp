/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:50:18 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/25 12:45:07 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_TPP__
#define __MUTANTSTACK_TPP__

#include "MutantStack.hpp"

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>() { return; }

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(MutantStack const &src) : std::stack<T, Container>(src) { return; }

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack(void) { return; }

template <typename T, class Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(MutantStack const &rhs)
{
	if (this != &rhs)
		this->c = rhs.c;

	return (*this);
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(void) { return (this->c.begin()); }

template <typename T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin(void) const { return (this->c.begin()); }

template <typename T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(void) { return (this->c.end()); }

template <typename T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end(void) const { return (this->c.end()); }

template <typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin(void) { return (this->c.rbegin()); }

template <typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin(void) const { return (this->c.rbegin()); }

template <typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend(void) { return (this->c.rend()); }

template <typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend(void) const { return (this->c.rend()); }

#endif
