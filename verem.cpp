#include <iostream>
#include <string>
#include <locale>

typedef struct verem {
	std::string szin;
	struct verem* kov;
} Verem;

Verem* elore_beszur(Verem* eleje, std::string szin);
Verem* kivesz_torol(Verem* eleje);
bool uresVerem(Verem* verem);
void kilistaz(Verem* verem);

int main()
{
	setlocale(LC_ALL, "hun");
	Verem* lista = NULL;
	bool exit = false;
	std::string kar;
	std::string szin = "";
	do
	{
		std::cout << "Le akarsz tenni a polcra egy pólót vagy elvenni onnan? (l/e/kilépés az Enter gomb megnyomásával)" << std::endl;		
		std::getline(std::cin,kar);

		if (kar == "l")
		{
			std::cout << "Milyen színû pólót akarsz letenni?" << std::endl;
			std::getline(std::cin, szin);
			lista = elore_beszur(lista, szin);
		}
		else if (kar == "e") {
			if (!uresVerem(lista))
				lista = kivesz_torol(lista);
			else
				std::cout << "A polc üres, sajnos nem tudsz már levenni róla semmit." << std::endl;
		}
		else if (kar == "")
			exit = true;
		else
			std::cout << "Hibás karakter." << std::endl;
		
		std::cout << std::endl;
		kilistaz(lista);
		std::cout << std::endl;

	} while (!exit);
	
}

Verem* elore_beszur(Verem* eleje, std::string szin) {
	Verem* uj = new Verem;
	uj->szin = szin;
	uj->kov = eleje;
	return uj;
}

Verem* kivesz_torol(Verem* eleje) {
	std::cout << "Kivetted a legfelsõ pólót, aminek a színe: " << eleje->szin << std::endl;
	eleje = eleje->kov;
	return eleje;
}

bool uresVerem(Verem* verem) {
	if (verem == NULL)
		return true;
	else
		return false;
}

void kilistaz(Verem* verem) {
	Verem* it;
	for (it = verem; it != NULL; it = it->kov)
		std::cout << it->szin << std::endl;	
}