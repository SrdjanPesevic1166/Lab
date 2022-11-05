#include "PriorityQueue.h"
#include <iostream>



int main()
{
	int value;
	PriorityQueue obj(5);
	obj.enqueue(&obj,22);
	obj.enqueue(&obj,12);
	obj.enqueue(&obj,18);
	obj.enqueue(&obj,11);
	obj.enqueue(&obj,3);
	obj.enqueue(&obj,5);
	obj.ispis(&obj);


	/*if (obj.Obrisi_Najveci(&obj, &value))
	{
		std::cout << "\nObrisan broj:" << value;
		std::cout << "\nPrikaz reda nakon brisanja:";
		obj.ispis(&obj);
	}
	else
		std::cout << "Red je prazan!";
		*/

	obj.Obrisi_Najveci(&obj);
	std::cout << "\n";
	obj.ispis(&obj);
	
	obj.enqueue(&obj, 38);
	std::cout << "\n";
	obj.ispis(&obj);
	obj.Obrisi_Na_Poziciji(3);
	std::cout << "\n";
	obj.ispis(&obj);

	obj.Obrisi_Najveci(&obj);
	std::cout << "\n";
	obj.ispis(&obj);

	obj.Obrisi_Na_Poziciji(2);
	std::cout << "\n";
	obj.ispis(&obj);

	obj.Obrisi_Na_Poziciji(1);
	std::cout << "\n";
	obj.ispis(&obj);

	obj.enqueue(&obj, 40);
	std::cout << "\n";
	obj.ispis(&obj);

	obj.enqueue(&obj,1);
	std::cout << "\n";
	obj.ispis(&obj);


}