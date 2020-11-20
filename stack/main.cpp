#include <iostream>
#include <string>

#include "verem.hpp"
#include "CannotPopFromStackException.hpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "hun");
	Verem verem;
	bool exit = false;
	string muvelet;
	string karakter = "";
	do
	{
		cout << "Betenni szeretnél a verembe, vagy kivenni belõle? (b/k/kilépés az Enter gomb megnyomásával)" << endl;
		getline(cin, muvelet);

		if (muvelet == "b")
		{
			cout << "Add meg a karaktert!" << endl;
			getline(cin, karakter);
			verem.push(karakter[0]);
		}
		else if (muvelet == "k") {
			if (verem.getList().empty())
				cout << "A verem üres.\n" << endl;
			else
			{
				cout << "Adjon meg egy szót: ";
				string szo;
				getline(cin, szo);
				try {
					verem.pop(szo);
				}
				catch (CannotPopFromStackException e) {
					cout << e.message << endl;
				}
			}
		}
		else if (muvelet == "")
			exit = true;
		else
			cout << "Helytelen karakter." << endl;

		if (verem.getList().empty())
			cout << "(Ell.: A verem még/már üres.)\n" << endl;
		else {
			cout << "(Ell.: A verem tartalma:\n" << endl;
			verem.printList();
			cout << ")" << endl;
		}
	} while (!exit);

	if (exit)
		cout << "Program vége." << endl;
	return 0;
}