/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:38:10 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/13 18:49:22 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

template <typename T>
void swap(T &lhs, T &rhs)
{
	T tmp(lhs);

	lhs = rhs;
	rhs = tmp;

	return;
}

template <typename T>
T const &min(T const &lhs, T const &rhs)
{
	if (lhs < rhs)
		return (lhs);

	return (rhs);
}

template <typename T>
T const &max(T const &lhs, T const &rhs)
{
	if (lhs > rhs)
		return (lhs);

	return (rhs);
}

#endif
