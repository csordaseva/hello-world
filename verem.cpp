#include <iostream>
#include <string>
#include <locale>
#include <list>
#include <exception>

class Verem {

public:
	std::list<char> lista;

public:

	void push(char c) {
		lista.push_front(c);
	}

	char pop() {
		if (lista.empty())
		{
			throw "A verem üres, sajnos nem tudsz már kiszedni belõle semmit.";
		}
		char out;
		out = lista.front();
		lista.pop_front();
		return out;
	}

	bool isEmpty() {
		if (lista.size() == 0)
			return true;
		else
			return false;
	}

	void kilistaz() {
		for (std::list<char>::iterator it = lista.begin(); it != lista.end(); it++)
			std::cout << *it << ' ' << std::endl;
	}
};

int main()
{
	setlocale(LC_ALL, "hun");
	Verem verem;
	bool exit = false;
	std::string muvelet;
	std::string karakter = "";
	char kivett;
	do
	{
		std::cout << "Betenni szeretnél a verembe, vagy kivenni belõle? (b/k/kilépés az Enter gomb megnyomásával)" << std::endl;
		std::getline(std::cin, muvelet);

		if (muvelet == "b")
		{
			std::cout << "Add meg a karaktert!" << std::endl;
			std::getline(std::cin, karakter);
			verem.push(karakter[0]);
		}
		else if (muvelet == "k") {
			try{
				kivett = verem.pop();
				std::cout << "Kivetted a legfelsõ elemet, ami a(z) " << kivett << " betû" << std::endl;
			}
			catch (const char* msg){
			std::cerr << msg << std::endl;
			}
		}
		else if (muvelet == "")
			exit = true;

		std::cout << std::endl;
		std::cout << "A verem tartalma: " << std::endl << std::endl;
		if (verem.isEmpty())
			std::cout << "A verem még/már üres." << std::endl;
		else
			verem.kilistaz();
		std::cout << std::endl;

	} while (!exit);

	if (exit)
		std::cout << "Program vége." << std::endl;

	return 0;
}

