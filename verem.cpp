#include <iostream>
#include <string>
#include <locale>

typedef struct verem {
	char betu;
	struct verem* kov;
} Verem;

Verem* elore_beszur(Verem* eleje, char betu);
Verem* kivesz_torol(Verem* eleje);
bool uresVerem(Verem* verem);
void kilistaz(Verem* verem);

int main()
{
	setlocale(LC_ALL, "hun");
	Verem* lista = NULL;
	bool exit = false;
	std::string muvelet;
	std::string karakter = "";
	do
	{
		std::cout << "Betenni szeretnél a verembe, vagy kivenni belõle? (b/k/kilépés az Enter gomb megnyomásával)" << std::endl;		
		std::getline(std::cin,muvelet);

		if (muvelet == "b")
		{
			std::cout << "Add meg a karaktert!" << std::endl;
			std::getline(std::cin, karakter);
			lista = elore_beszur(lista, karakter[0]);
		}
		else if (muvelet == "k") {
			if (!uresVerem(lista))
				lista = kivesz_torol(lista);
			else
				std::cout << "A verem üres, sajnos nem tudsz már kiszedni belõle semmit." << std::endl;
		}
		else if (muvelet == "")
			exit = true;
		
		std::cout << std::endl;
		std::cout << "A verem tartalma: " << std::endl << std::endl;
		if (lista == NULL)
			std::cout << "A verem még/már üres." << std::endl;		
		else
			kilistaz(lista);		
		std::cout << std::endl;

	} while (!exit);
	
}

Verem* elore_beszur(Verem* eleje, char betu) {
	Verem* uj = new Verem;
	uj->betu = betu;
	uj->kov = eleje;
	return uj;
}

Verem* kivesz_torol(Verem* eleje) {
	std::cout << "Kivetted a legfelsõ elemet, ami a(z) " << eleje->betu << " betû" << std::endl;
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
		std::cout << it->betu << std::endl;	
}