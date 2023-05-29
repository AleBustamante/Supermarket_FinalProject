#include "Test_DataProvider.h"

void Test_DataProvider::Test_DataProviderloadDatafirstelement(DataProvider data)
{
	data.loadData();
	if (data.getsupermarker()->products[0] == nullptr)
	{
		cout << "no se pudo cargar correctamente el primer producto";
	}
	if (data.getsupermarker()->workers[0] == nullptr)
	{
		cout << "no se pudo cargar correctamente el primer trabajador";
	}
	if(data.getsupermarker()->clients[0] == nullptr)
	{
		cout << "no se pudo cargar correctamente el primer cliente";
	}
	if (data.getsupermarker()->sales[0] == nullptr)
	{
		cout << "no se pudo cargar correctamente la primera venta";
	}
}
