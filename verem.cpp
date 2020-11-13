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
			throw "A verem �res, sajnos nem tudsz m�r kiszedni bel�le semmit.";
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
		std::cout << "Betenni szeretn�l a verembe, vagy kivenni bel�le? (b/k/kil�p�s az Enter gomb megnyom�s�val)" << std::endl;
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
				std::cout << "Kivetted a legfels� elemet, ami a(z) " << kivett << " bet�" << std::endl;
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
			std::cout << "A verem m�g/m�r �res." << std::endl;
		else
			verem.kilistaz();
		std::cout << std::endl;

	} while (!exit);

	if (exit)
		std::cout << "Program v�ge." << std::endl;

	return 0;
}

