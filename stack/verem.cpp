#include <iostream>
#include <string>

#include "verem.hpp"
#include "CannotPopFromStackException.hpp"

using namespace std;

void Verem::push(char c) {
	list.push_front(c);
}

void Verem::pop(char c) {
	list.pop_front();
}

void Verem::pop(std::string str) {
	if (list.empty())
		throw "Exception: A verem üres.";

	if (checkString(str)) {
		for (int i = 0; i < str.size(); i++)
			pop(str[i]);
	}

	else
		throw CannotPopFromStackException{"Exception: A verembõl nem lehet kivenni ezt a stringet."};
}

bool Verem::checkString(std::string str) {
	
	if (str.length() == 1 && str[0] == list.front())
		return true;	
	else
	{
		int i = 0;
		for (auto it = list.begin(); it != list.end() && i < str.length(); ++it)
		{
			if (*it == str[i])
				i++;
			else
				return false;			
			if (i == str.size())
				return true;
		}
		return false;
	}	
}

void Verem::printList() {
	for (auto it = list.begin(); it != list.end(); it++)
		std::cout << *it << ' ';
}