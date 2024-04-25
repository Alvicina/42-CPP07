/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:30:29 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/25 12:38:40 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T				*_arrayPtr;
		unsigned int	_size;
	public:
		Array()
		{
			_size = 0;
			_arrayPtr = new T[0];
		}
		
		Array(unsigned int n)
		{
			_size = n;
			_arrayPtr = new T[_size];
		}

		~Array()
		{
			delete [] _arrayPtr;
		}
		
		Array(Array const & a)
		{
			_arrayPtr = new T[a._size];
			this->_size = a._size;
			unsigned int	i = 0;
			while (i < a._size)
			{
				_arrayPtr[i] = a[i];
				i++;
			}
		}
		
		Array& operator=(Array const & a)
		{
			if (this != &a)
			{
				delete [] _arrayPtr;
				_arrayPtr = new T[a._size];
				this->_size = a._size;
				unsigned int	i = 0;
				while (i < a._size)
				{
					_arrayPtr[i] = a[i];
					i++;
				}
			}
			return (*this);
		}

		T&	operator[](unsigned int i) const
		{
			if (i >= _size)
				throw outOfBoundsException();
			else
				return (_arrayPtr[i]);
		}
		
		unsigned int	size(void) const
		{
			return (_size);
		}

		class outOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Index is out of bounds");
				}
		};
};

template < typename T > 
std::ostream& operator<<(std::ostream &o, Array <T> const &a)
{
	unsigned int i = 0;
	while (i < a._size)
	{
		o << a._arrayPtr[i] << std::endl;
		i++;
	}
	return (o);
}

#endif