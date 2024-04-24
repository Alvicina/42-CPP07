/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:35:04 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/24 17:37:02 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T* array, size_t length, void (*func)(T const & element))
{
	size_t	i = 0;
	while (i < length)
	{
		func(array[i]);
		i++;
	}
}

template <typename T>
void	printElement(T const & element)
{
	std::cout << element << std::endl;
}

#endif