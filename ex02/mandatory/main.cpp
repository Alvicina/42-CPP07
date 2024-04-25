/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:24:55 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/25 17:21:40 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

#define MAX_VAL 15

/////////////////////////////ARRAY DE INTS/////////////////////////////////////////

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


/////////////////////////////ARRAY DE CHARS/////////////////////////////////////////

/*
int main(void)
{
    Array<char> chars(MAX_VAL);
    char    *mirror = new char[MAX_VAL];

    std::cout << "-------------- comprobacion  ----------------------" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        chars[i] =  'c';
        mirror[i] = 'c';
        std::cout << "template : " << chars[i] << " mirror : " << mirror[i] << std::endl;
    }
    
    //SCOPE
    {
        std::cout << "-------------- comprobacion copia profunda ----------------------" << std::endl;
        Array<char> tmp = chars;
        Array<char> test(tmp);
        for (int i = 0; i < MAX_VAL; i++)
			std::cout << "tmp : " << tmp[i] << " test : " << test[i] << std::endl;
        std::cout << "-----------------------------------------------------------------" << std::endl;
		test[10] = 'A';
		for (int i = 0; i < MAX_VAL; i++)
			std::cout << "tmp : " << tmp[i] << " test : " << test[i] << std::endl; 
    }
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        if(mirror[i] != chars[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }         
    }

    try
    {
        chars[-2] = 'a';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        chars[39] = 'p';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete [] mirror;//
	system ("leaks Array");
    return 0;  
}*/

/////////////////////////////ARRAY DE STRINGS/////////////////////////////////////////
/*
int main(void)
{
    Array<std::string>  strings(MAX_VAL);
    std::string *mirror = new std::string[MAX_VAL];

    std::cout << "-------------- comprobacion  ----------------------" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        strings[i] =  "Alejandro";
        mirror[i] = "Alejandro";
        std::cout << "template : " << strings[i] << " mirror : " << mirror[i] << std::endl;
    }

      //SCOPE
    {
        std::cout << "-------------- comprobacion copia profunda ----------------------" << std::endl;
        Array<std::string> tmp = strings;
        Array<std::string> test(tmp);
        for (int i = 0; i < MAX_VAL; i++)
			std::cout << "tmp : " << tmp[i] << " test : " << test[i] << std::endl;
        std::cout << "-----------------------------------------------------------------" << std::endl;
		test[10] = "Mauro";
		for (int i = 0; i < MAX_VAL; i++)
			std::cout << "tmp : " << tmp[i] << " test : " << test[i] << std::endl; 
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if(mirror[i] != strings[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }         
    }

    try
    {
        strings[-2] = "Pepe";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        strings[39] = "Pepe";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete [] mirror;//
	system ("leaks Array");
    return 0; 
}*/

/////////////////////////////ARRAY DE CLASE/////////////////////////////////////////
/*
int main(void)
{
    Array<prueba> clase(MAX_VAL);
    prueba  *mirror = new prueba[MAX_VAL];
    srand(time(NULL));

    std::cout << "-------------- comprobacion  ----------------------" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        clase[i].setAge(value);
        mirror[i].setAge(value);
        std::cout << "clase age : " << clase[i].getAge() << " mirror age : " << clase[i].getAge() << std::endl;
    }

    //SCOPE
    std::cout << "-------------- comprobacion copia profunda ----------------------" << std::endl;
    {
        Array<prueba> tmp = clase;
        Array<prueba> test(tmp);
        for (int i = 0; i < MAX_VAL; i++)
             std::cout << "clase age : " << tmp[i].getAge() << " mirror age : " << test[i].getAge() << std::endl;
        test[2].setAge(0);
        for (int i = 0; i < MAX_VAL; i++)
             std::cout << "clase age : " << tmp[i].getAge() << " mirror age : " << test[i].getAge() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if(mirror[i].getAge() != clase[i].getAge())
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }         
    }

    try
    {
        clase[-2].setAge(2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        clase[39].setAge(4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete [] mirror;//
	system ("leaks Array");
    return 0; 

    
}*/
