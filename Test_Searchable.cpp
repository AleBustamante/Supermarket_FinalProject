#include "Test_Searchable.h"

void Test_Searchable::Test_SearchableProduct()
{
	Product p(432, "chocolate");
	if (!p.isInIdentifier(432))
	{
		cout << "no funciona la funcion de buscar un producto por identificacion"<<endl;
	}
	if (!p.isInName("chocolate"))
	{
		cout << "no funciona la funcion de buscar un producto por nombre" << endl;
	}	
}

void Test_Searchable::Test_SearchableCliente()
{
	Client c("Dylan", "Calle", 345);
		if (!c.isInName("Dylan Calle"))
		{
			cout << "no funciona la funcion de buscar un clinete por nombre" << endl;
		}
		if (!c.isInIdentifier(345))
		{
			cout << "no funciona la funcion de buscar un clinete por identificacion" << endl;
		}
}

void Test_Searchable::Test_SearchableWorker()
{
	Worker w("Dylan", "Calle", 345);
	if (!w.isInName("Dylan Calle"))
	{
		cout << "no funciona la funcion de buscar un clinete por nombre" << endl;
	}
	if (!w.isInIdentifier(345))
	{
		cout << "no funciona la funcion de buscar un clinete por identificacion" << endl;
	}
}
