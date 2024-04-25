/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:24:55 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/25 12:56:17 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

#define MAX_VAL 15
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
	std::cout << "-------------- comprobacion  ----------------------" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
		std::cout << "template : " << numbers[i] << " mirror : " << mirror[i] << std::endl;
    }
    //SCOPE
    {
		std::cout << "-------------- comprobacion copia profunda ----------------------" << std::endl;
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		for (int i = 0; i < MAX_VAL; i++)
			std::cout << "tmp : " << tmp[i] << " test : " << test[i] << std::endl;
		std::cout << "-----------------------------------------------------------------" << std::endl;
		test[10] = 34;
		for (int i = 0; i < MAX_VAL; i++)
			std::cout << "tmp : " << tmp[i] << " test : " << test[i] << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[39] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	
    delete [] mirror;//
	system ("leaks Array");
    return 0;
}


