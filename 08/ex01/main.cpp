/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:57:53 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/21 13:43:48 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Span.tpp"
#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

int main(void) {
	srand(time(NULL) );
	{
		std::cout << "Creating a span with 5 numbers" << std::endl;
		Span sp(5);

		std::cout << "Adding 5 numbers" << std::endl;
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp << std::endl;

		try {
			std::cout << "Adding another number" << std::endl;
			sp.addNumber(12);
		} catch (std::length_error& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		std::list<int> list;
		std::cout << "Creating a list with 10 random numbers" << std::endl;
		for (int i = 0; i < 10; i++) {
			list.push_back(rand() % 100);
		}
		std::cout << "Creating a span with 10 numbers" << std::endl;
		Span sp(list.size());
		std::cout << "Adding everything from the list" << std::endl;
		sp.addNumbers<std::list<int> >(list.begin(), list.end());
		std::cout << sp << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "Creatinga span with 10.000 numbers" << std::endl;
		Span sp(10000);
		std::cout << "Adding 10.000 numbers" << std::endl;
		for (int i = 0; i < 10000; i++) {
			sp.addNumber(rand() % 10000);
		}
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	return 0;
}
