/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:47:11 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/24 13:07:07 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

template <typename T>
void	swap(T& a, T& b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const &	min(T const & a, T const & b)
{
	if (a >= b)
		return (b);
	else 
		return (a);
}

template <typename T>
T const &	max(T const & a, T const & b)
{
	if (a > b)
		return (a);
	else
		return (b);
}


#endif