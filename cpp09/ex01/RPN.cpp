/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:03:00 by abenamar          #+#    #+#             */
/*   Updated: 2024/07/02 20:48:00 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) { return; }

RPN::RPN(RPN const & /* src */) { return; }

RPN::~RPN(void) { return; }

RPN RPN::operator=(RPN const & /* rhs */) { return (*this); }

int RPN::process(std::string const &expression) throw(std::invalid_argument, std::overflow_error, std::underflow_error)
{
	std::string const tokens("0123456789+-/*");
	std::stringstream sstream(expression);
	std::string str;
	std::stack<int, std::list<int> > stack;
	int item;

	while (sstream >> str)
	{
		if (str.length() > 1 || tokens.find(str.at(0)) == std::string::npos)
			throw std::invalid_argument("Error: invalid expression");
		else if (tokens.find(str.at(0), 10) != std::string::npos)
		{
			if (stack.empty())
				throw std::invalid_argument("Error: invalid expression");

			item = stack.top();

			stack.pop();

			if (stack.empty())
				throw std::invalid_argument("Error: invalid expression");

			switch (str.at(0))
			{
			case '+':
				if (item > 0 && stack.top() > std::numeric_limits<int>::max() - item)
					throw std::overflow_error("Error: overflow");
				else if (item < 0 && stack.top() < std::numeric_limits<int>::min() - item)
					throw std::underflow_error("Error: underflow");

				item = stack.top() + item;

				break;

			case '-':
				if (item < 0 && stack.top() > std::numeric_limits<int>::max() + item)
					throw std::overflow_error("Error: overflow");
				else if (item > 0 && stack.top() < std::numeric_limits<int>::min() + item)
					throw std::underflow_error("Error: underflow");

				item = stack.top() - item;

				break;

			case '/':
				if (item == 0)
					throw std::invalid_argument("Error: division by zero");
				else if (stack.top() == std::numeric_limits<int>::min() && item == -1)
					throw std::overflow_error("Error: overflow");

				item = stack.top() / item;

				break;

			// case '*':
			default:
				if ((stack.top() == -1 && item == std::numeric_limits<int>::min()) || (item == -1 && stack.top() == std::numeric_limits<int>::min()))
					throw std::overflow_error("Error: overflow");
				else if (stack.top() > 0)
				{
					if (item > 0 && stack.top() > std::numeric_limits<int>::max() / item)
						throw std::overflow_error("Error: overflow");
					else if (item < -1 && stack.top() > std::numeric_limits<int>::min() / item)
						throw std::underflow_error("Error: underflow");
				}
				else if (stack.top() < 0)
				{
					if (item < 0 && stack.top() < std::numeric_limits<int>::max() / item)
						throw std::overflow_error("Error: overflow");
					else if (item > 0 && stack.top() < std::numeric_limits<int>::min() / item)
						throw std::underflow_error("Error: underflow");
				}

				item = stack.top() * item;

				break;
			}

			stack.pop();
			stack.push(item);
		}
		else
			stack.push(str.at(0) - '0');
	}

	if (stack.empty())
		throw std::invalid_argument("Error: invalid expression");

	item = stack.top();

	stack.pop();

	if (!stack.empty())
		throw std::invalid_argument("Error: invalid expression");

	return (item);
}
