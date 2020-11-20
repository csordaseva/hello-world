#ifndef VEREM_HPP
#define VEREM_HPP

#include<list>

class Verem {

private:
	std::list<char> list;

public:

	std::list<char> getList() { return list; }
	void push(char c);
	void pop(char c);
	void pop(std::string str);
	bool checkString(std::string str);
	void printList();
};

#endif
