/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:07:36 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/24 12:33:45 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_TPP__
#define __EASYFIND_TPP__

#include "easyfind.hpp"

template <typename T>
typename T::iterator::difference_type easyfind(T sequence, int value) { return (std::distance(sequence.begin(), std::find(sequence.begin(), sequence.end(), value))); }

#endif
