/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:58:22 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/25 12:46:16 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main(void)
{
	{
		MutantStack<int> mtmp;
		MutantStack<int> mstack;

		std::cout << "Info: MutantStack<int>: default constructor" << std::endl;

		mtmp.push(6);

		std::cout << "Info: MutantStack<int>::push(6)" << std::endl;

		mtmp.push(5);

		std::cout << "Info: MutantStack<int>::push(5)" << std::endl;

		mstack = mtmp;

		std::cout << "Info: MutantStack<int>: assignement operator" << std::endl;
		std::cout << "Info: MutantStack<int>::size(): " << mstack.size() << std::endl;
		std::cout << "Info: MutantStack<int>::top(): " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Info: MutantStack<int>::pop()" << std::endl;
		std::cout << "Info: MutantStack<int>::size(): " << mstack.size() << std::endl;

		mstack.push(3);

		std::cout << "Info: MutantStack<int>::push(3)" << std::endl;

		mstack.push(17);

		std::cout << "Info: MutantStack<int>::push(17)" << std::endl;

		mstack.push(9);

		std::cout << "Info: MutantStack<int>::push(9)" << std::endl;

		mstack.push(11);

		std::cout << "Info: MutantStack<int>::push(11)" << std::endl;
		std::cout << "Info: MutantStack<int>::size(): " << mstack.size() << std::endl;

		MutantStack<int>::iterator it = mstack.begin();

		std::cout << "Info: MutantStack<int>::iterator: [ " << *it++;

		--it;
		++it;

		for (; it != mstack.end(); ++it)
			std::cout << ", " << *it;

		std::cout << " ]" << std::endl;

		MutantStack<int> const cmstack(mstack);

		std::cout << "Info: MutantStack<int>: copy constructor" << std::endl;

		MutantStack<int>::const_iterator cit = cmstack.begin();

		std::cout << "Info: MutantStack<int>::const_iterator: [ " << *cit++;

		--cit;
		++cit;

		for (; cit != cmstack.end(); ++cit)
			std::cout << ", " << *cit;

		std::cout << " ]" << std::endl;

		MutantStack<int>::reverse_iterator rit = mstack.rbegin();

		std::cout << "Info: MutantStack<int>::reverse_iterator: [ " << *rit++;

		--rit;
		++rit;

		for (; rit != mstack.rend(); ++rit)
			std::cout << ", " << *rit;

		std::cout << " ]" << std::endl;

		MutantStack<int>::const_reverse_iterator crit = cmstack.rbegin();

		std::cout << "Info: MutantStack<int>::const_reverse_iterator: [ " << *crit++;

		--crit;
		++crit;

		for (; crit != cmstack.rend(); ++crit)
			std::cout << ", " << *crit;

		std::cout << " ]" << std::endl;

		std::stack<int> s(mstack);

		std::cout << "Info: std::stack<int>: copy constructor" << std::endl;
		std::cout << "Info: std::stack<int>::size(): " << s.size() << std::endl;
		std::cout << "Info: std::stack<int>::top(): " << s.top() << std::endl;
	}

	{
		std::list<int> tmp;
		std::list<int> l;

		std::cout << "------------------------------------------" << std::endl;
		std::cout << "Info: std::list<int>: default constructor" << std::endl;

		tmp.push_back(6);

		std::cout << "Info: std::list<int>::push_back(6)" << std::endl;

		tmp.push_back(5);

		std::cout << "Info: std::list<int>::push_back(5)" << std::endl;

		l = tmp;

		std::cout << "Info: std::list<int>: assignement operator" << std::endl;
		std::cout << "Info: std::list<int>::size(): " << l.size() << std::endl;
		std::cout << "Info: std::list<int>::back(): " << l.back() << std::endl;

		l.pop_back();

		std::cout << "Info: std::list<int>::pop_back()" << std::endl;
		std::cout << "Info: std::list<int>::size(): " << l.size() << std::endl;

		l.push_back(3);

		std::cout << "Info: std::list<int>::push_back(3)" << std::endl;

		l.push_back(17);

		std::cout << "Info: std::list<int>::push_back(17)" << std::endl;

		l.push_back(9);

		std::cout << "Info: std::list<int>::push_back(9)" << std::endl;

		l.push_back(11);

		std::cout << "Info: std::list<int>::push_back(11)" << std::endl;
		std::cout << "Info: std::list<int>::size(): " << l.size() << std::endl;

		std::list<int>::iterator it = l.begin();

		std::cout << "Info: std::list<int>::iterator: [ " << *it++;

		--it;
		++it;

		for (; it != l.end(); ++it)
			std::cout << ", " << *it;

		std::cout << " ]" << std::endl;

		std::list<int> const cl(l);

		std::cout << "Info: std::list<int>: copy constructor" << std::endl;

		std::list<int>::const_iterator cit = cl.begin();

		std::cout << "Info: std::list<int>::const_iterator: [ " << *cit++;

		--cit;
		++cit;

		for (; cit != cl.end(); ++cit)
			std::cout << ", " << *cit;

		std::cout << " ]" << std::endl;

		std::list<int>::reverse_iterator rit = l.rbegin();

		std::cout << "Info: std::list<int>::reverse_iterator: [ " << *rit++;

		--rit;
		++rit;

		for (; rit != l.rend(); ++rit)
			std::cout << ", " << *rit;

		std::cout << " ]" << std::endl;

		std::list<int>::const_reverse_iterator crit = cl.rbegin();

		std::cout << "Info: std::list<int>::const_reverse_iterator: [ " << *crit++;

		--crit;
		++crit;

		for (; crit != cl.rend(); ++crit)
			std::cout << ", " << *crit;

		std::cout << " ]" << std::endl;
	}

	return (0);
}
