/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <kiroussa@oss@xtrm.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:58:15 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/21 13:37:44 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN__
# define __SPAN__

# include <iostream>
# include <iterator>
# include <algorithm>
# include <vector>

class Span
{
	public:
		Span(unsigned int n);
		~Span(void);
		Span(Span &copy);
		Span& operator=(const Span& x);

		void addNumber(int n);
		template <typename T>
		void addNumbers(const typename T::const_iterator begin, const typename T::const_iterator end);

		int shortestSpan(void);
		int longestSpan(void);

		std::vector<int> const& getNumbers(void) const;
		unsigned int getFilled(void) const;
	private:
		Span(void);
		std::vector<int> numbers;
		unsigned int size;
		unsigned int filled;
};

std::ostream& operator<<(std::ostream& os, const Span& s);

#endif
