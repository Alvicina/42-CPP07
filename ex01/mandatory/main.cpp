/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:35:00 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/24 17:31:47 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"


int main(void)
{
	int			intArray[5] = {1, 2, 3, 4, 5};
	double		doubleArray[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string	stringArray[5] = {"H", "Adios", "Hasta luego", "Agur", "Bye"};
	char		charArray[5] = {'A', 'B', 'C', 'D', 'E'};
	
	std::cout << "printing intArray: " << std::endl;
	iter(intArray, 5, printElement);

	std::cout << "printing doubleArray: " << std::endl;
	iter(doubleArray, 5, printElement);

	std::cout << "printing stringArray: " << std::endl;
	iter(stringArray, 5, printElement);

	std::cout << "printing charArray: " << std::endl;
	iter(charArray, 5, printElement);

	return (EXIT_SUCCESS);
	
}