/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:59:09 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/24 12:47:55 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

void pout(int const value)
{
	std::cout << ", " << value;

	return;
}

int main(void)
{
	int const myints[] = {6, 3, 17, 9, 11};
	std::deque<int> mydeque(myints, myints + 5);
	std::list<int> mylist(myints, myints + 5);
	std::list<int>::iterator it;
	std::vector<int> myvector(myints, myints + 5);

	std::cout << "\033[1;32mInfo: \033[0;34mstd::deque<int>: \033[0m[ " << mydeque.front();
	std::for_each(mydeque.begin() + 1, mydeque.end(), ::pout);
	std::cout << " ]" << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::deque<int>, 6): \033[0m" << *(mydeque.begin() + ::easyfind(mydeque, 6)) << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::deque<int>, 3): \033[0m" << *(mydeque.begin() + ::easyfind(mydeque, 3)) << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::deque<int>, 17): \033[0m" << *(mydeque.begin() + ::easyfind(mydeque, 17)) << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::deque<int>, 9): \033[0m" << *(mydeque.begin() + ::easyfind(mydeque, 9)) << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::deque<int>, 11): \033[0m" << *(mydeque.begin() + ::easyfind(mydeque, 11)) << std::endl;

	if ((mydeque.begin() + ::easyfind(mydeque, 0)) == mydeque.end())
		std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::deque<int>, 0): \033[0mnot found" << std::endl;

	std::cout << "\033[1;32mInfo: \033[0;34mstd::list<int>: \033[0m[ " << mylist.front();
	std::for_each(++mylist.begin(), mylist.end(), ::pout);
	std::cout << " ]" << std::endl;

	it = mylist.begin();

	for (std::ptrdiff_t i = ::easyfind(mylist, 6); i > 0; --i)
		++it;

	std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::list<int>, 6): \033[0m" << *it << std::endl;

	it = mylist.begin();

	for (std::ptrdiff_t i = ::easyfind(mylist, 3); i > 0; --i)
		++it;

	std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::list<int>, 3): \033[0m" << *it << std::endl;

	it = mylist.begin();

	for (std::ptrdiff_t i = ::easyfind(mylist, 17); i > 0; --i)
		++it;

	std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::list<int>, 17): \033[0m" << *it << std::endl;

	it = mylist.begin();

	for (std::ptrdiff_t i = ::easyfind(mylist, 9); i > 0; --i)
		++it;

	std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::list<int>, 9): \033[0m" << *it << std::endl;

	it = mylist.begin();

	for (std::ptrdiff_t i = ::easyfind(mylist, 11); i > 0; --i)
		++it;

	std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::list<int>, 11): \033[0m" << *it << std::endl;

	it = mylist.begin();

	for (std::ptrdiff_t i = ::easyfind(mylist, 0); i > 0; --i)
		++it;

	if (it == mylist.end())
		std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::list<int>, 0): \033[0mnot found" << std::endl;

	std::cout << "\033[1;32mInfo: \033[0;34mstd::vector<int>: \033[0m[ " << myvector.front();
	std::for_each(myvector.begin() + 1, myvector.end(), ::pout);
	std::cout << " ]" << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::vector<int>, 6): \033[0m" << *(myvector.begin() + ::easyfind(myvector, 6)) << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::vector<int>, 3): \033[0m" << *(myvector.begin() + ::easyfind(myvector, 3)) << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::vector<int>, 17): \033[0m" << *(myvector.begin() + ::easyfind(myvector, 17)) << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::vector<int>, 9): \033[0m" << *(myvector.begin() + ::easyfind(myvector, 9)) << std::endl;
	std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::vector<int>, 11): \033[0m" << *(myvector.begin() + ::easyfind(myvector, 11)) << std::endl;

	if ((myvector.begin() + ::easyfind(myvector, 0)) == myvector.end())
		std::cout << "\033[1;32mInfo: \033[0;34m::easyfind(std::vector<int>, 0): \033[0mnot found" << std::endl;

	return (0);
}
