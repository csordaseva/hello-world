#include <iostream>
#include "dfa.hpp"


int main()
{
	Dfa dfa;

	dfa.hozzaadCsucs("q0", 'a',"q1");
	dfa.hozzaadCsucs("q0", 'b', "q2");
	dfa.hozzaadCsucs("q1", 'b', "q3");
	dfa.hozzaadCsucs("q2", 'b', "q3");
	dfa.hozzaadCsucs("q3", 'a', "q4");
	dfa.hozzaadCsucs("q3", 'b', "q5");
	dfa.hozzaadCsucs("q4", 'b', "q5");

	dfa.kiir();


	return 0;
}
