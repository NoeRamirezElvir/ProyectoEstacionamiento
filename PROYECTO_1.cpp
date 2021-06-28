#include <iostream>
#include <string>
#include <clocale>
#include <Windows.h>
#include <iomanip>
using namespace std;

const int TAM = 25;
struct parqueos {//estructura general del registro
	string cliente, tipo, modelo, placa;
}registro[TAM];
struct cobros {//estructura para manejar las descpciones y cobros que se acreditan a un ticket
	string descripcionCargo;
	double valorCargo;
}cargos[TAM][TAM];
void agregarCargos(int num, string descripcion, double valor) {//procedimiento para llenar cargos

	int temp = 0;
	for (int j = 0; j < TAM; j++)//columnas
	{
		if (cargos[num][j].descripcionCargo == "")//if para validar si un espacio esta vacio
		{
			break;
		}
		else
		{
			temp++;
		}
	}
	cargos[num][temp].descripcionCargo = descripcion;//llenado de tipo struct
	cargos[num][temp].valorCargo = valor;
}
void tipoDevehiculo(int i) {//funcion para seleccionar tipo de vehiculo, se llama en agregar y corregir
	char seleccion;
	boolean flag = false;
	cout << "Ingrese el Tipo de vehiculo: " << endl;
	do
	{
		cout << "1. Motocicleta" << endl << "2. Turismo" << endl << "3. Pick Up" << endl << "4. Camioneta" << endl << "5. Camion" << endl;
		cin >> seleccion;

		switch (seleccion)
		{
		case '1':
			registro[i].tipo = "Motocicleta";
			flag = true;
			break;
		case '2':
			registro[i].tipo = "Turismo";
			flag = true;
			break;
		case '3':
			registro[i].tipo = "Pick Up";
			flag = true;
			break;
		case '4':
			registro[i].tipo = "Camioneta";
			flag = true;
			break;
		case '5':
			registro[i].tipo = "Camion";
			flag = true;
			break;
		default:
			cout << "Opcion invalida" << endl;
			flag = !true;
			break;
		}
	} while (flag == !true);

}
void agregar(int i) {
	string tipo;
	cout << "Ingrese nombre del cliente" << endl;
	cin.ignore();
	getline(cin, registro[i].cliente);
	cout << endl;
	tipoDevehiculo(i);
	cout << "Ingrese el modelo del vehiculo: " << endl;
	cin.ignore();
	getline(cin, registro[i].modelo);
	cout << "Ingrese la identificacion vehicular (placa): " << endl;

	getline(cin, registro[i].placa);
	cout << endl << endl << "--------------------" << endl;
	cout << "Ticket: " << i + 1 << endl;
	if (registro[i].tipo == "Motocicleta")
	{
		tipo = " 7 Lps ";
	}
	else if (registro[i].tipo == "Camion")
	{
		tipo = " 18 Lps ";
	}
	else if (registro[i].tipo == "Pick Up")
	{
		tipo = " 12 Lps ";
	}
	else if (registro[i].tipo == "Camioneta")
	{
		tipo = " 15 Lps ";
	}
	else
	{
		tipo = "10 Lps";
	}
	cout << "NOTA: La tarifa por estadía es de: " << tipo << " por hora," << endl;
	cout << "No somos responsables a daños en su vehiculo o " << endl << "robo de articulos dejados en el interior del mismo" << endl;
	cout << "--------------------" << endl << endl;
}
void corregir(int i) {//funcion para corregir el registro, imprime nuevo ticket
	char op;
	string respuesta, tipo;
	int j, seleccion;
	try
	{
		cout << "Numero de ticket a corregir: ";
		cin >> j;
		if (j > i)
		{
			throw "Ticket no existe";
		}
		j = j - 1;
		do
		{
			cout << endl << "Elija una opcion a corregir" << endl;
			cout << "a. Nombre" << endl << "b. Tipo" << endl << "c. modelo" << endl << "d. Placa" << endl;
			cin >> op;
			switch (op)
			{
			case 'a':
				cout << "Nombre actual: " << registro[j].cliente << endl;
				cout << "Ingrese el nuevo nombre: " << endl;
				cin.ignore();
				getline(cin, registro[j].cliente);
				break;
			case 'b':
				cout << "Tipo de vehiculo actual: " << registro[j].tipo << endl;
				tipoDevehiculo(j);
				break;
			case 'c':
				cout << "Modelo actual: " << registro[j].modelo << endl;
				cout << "Ingrese el nuevo modelo del vehiculo: " << endl;
				cin.ignore();
				getline(cin, registro[j].modelo);
				break;
			case 'd':
				cout << "Placa actual: " << registro[j].placa << endl;
				cout << "Ingrese la nueva identificacion vehicular: " << endl;
				cin.ignore();
				getline(cin, registro[j].placa);
				break;
			default:
				cout << "Opcion a corregir invalida" << endl;
				break;
			}
			cout << "Si desea corregir otro campo presione 's' sino presione 'n' " << endl;
			cin >> respuesta;
		} while (respuesta == "s");

		cout << endl << endl << "--------------------" << endl;
		cout << "Ticket: " << j + 1 << endl;
		if (registro[j].tipo == "Motocicleta")
		{
			tipo = " 7 Lps ";
		}
		else if (registro[j].tipo == "Camion")
		{
			tipo = " 18 Lps ";
		}
		else if (registro[j].tipo == "Pick Up")
		{
			tipo = " 12 Lps ";
		}
		else if (registro[j].tipo == "Camioneta")
		{
			tipo = " 15 Lps ";
		}
		else
		{
			tipo = "10 Lps";
		}
		cout << "NOTA: La tarifa por estadía es de: " << tipo << " por hora," << endl;
		cout << "No somos responsables a daños en su vehiculo o " << endl << "robo de articulos dejados en el interior del mismo" << endl;
		cout << "--------------------" << endl << endl;
	}
	catch (const char* msg)
	{
		cerr << "Error: " << msg << endl << endl;
	}

}
double calculoDeLavado(int i) {
	const int SERVCOMPLETO = 350, SERVEXTERIOR = 160, SERVESPECIAL = 380;
	const int LIMPDEALFOMBRAS = 90, FRAGANCIA = 60, TOQUEDEBRILLO = 120;
	double total = 0;
	int  num;
	char opcion1, opcion2;
	string respuesta;
	cout << "Ingrese el numero de ticket al que desea agregar el servicio: ";
	try
	{
		cin >> num;
		if ((num <= 0) || (num > i))
		{
			throw "Numero de ticket invalido";
		}
		cout << endl << setw(10) << "Lavado de autos" << endl << setw(10) << "Seleccione los servicios que desea agregar" << endl;
		cout << "1. Lavado completo . . . . . .  Lps. 350" << endl;
		cout << "2. Lavado exterior . . . . . .  Lps. 160" << endl;
		cout << "3. Lavado especial . . . . . .  Lps. 380" << endl;
		cout << "4. Servicios extra" << endl;
		do
		{
			cout << endl << "Escriba el numero de la opcion: ";
			cin >> opcion1;

			switch (opcion1)
			{
			case '1':
				total += SERVCOMPLETO;
				cout << "Total:  Lps. " << total << endl << endl;
				agregarCargos(num - 1, "Lavado completo", SERVCOMPLETO);
				break;
			case '2':
				total += SERVEXTERIOR;
				cout << "Total:  Lps. " << total << endl << endl;
				agregarCargos(num - 1, "Lavado exterior", SERVEXTERIOR);
				break;
			case '3':
				total += SERVESPECIAL;
				cout << "Total:  Lps. " << total << endl << endl;
				agregarCargos(num - 1, "Lavado especial", SERVESPECIAL);
				break;
			case '4':
				cout << "Servicios extra" << endl << "1. Limpieza de alfombras . . .  Lps. 90" << endl << "2. Fragancia . . .  Lps. 60" << endl << "3. Toque de brillo . . . Lps. 120" << endl;
				cout << "Escriba el numero de la opcion: ";
				cin >> opcion2;
				switch (opcion2)
				{
				case '1':
					total += LIMPDEALFOMBRAS;
					cout << "Total:  Lps. " << total << endl << endl;
					agregarCargos(num - 1, "Limpieza de alfombras", LIMPDEALFOMBRAS);
					break;
				case '2':
					total += FRAGANCIA;
					cout << "Total:  Lps. " << total << endl << endl;
					agregarCargos(num - 1, "Fragancia", FRAGANCIA);
					break;
				case '3':
					total += TOQUEDEBRILLO;
					cout << "Total:  Lps. " << total << endl << endl;
					agregarCargos(num - 1, "Toque de brillo", TOQUEDEBRILLO);
					break;

				default:
					cout << "Opcion Invalida." << endl << endl;
					break;
				}
				break;

			default:
				cout << "Opcion Invalida." << endl << endl;
				break;
			}
			cout << "Para agregar otro servicio presione 's' sino 'n': ";
			cin >> respuesta;
		} while ((respuesta == "s") || (respuesta == "S"));
		return total;
	}
	catch (const char* msg)
	{
		cerr << "Error: " << msg;
	}
}
void extraviado() {
	string placa, respuesta;
	int k = 0, num, falso = 0;
	double subtotal = 0;
	cout << "Ingresar placa vehicular: " << endl;
	cin >> placa;
	try
	{
		boolean flag = false;
		for (int k = 0; k < 4; k++)
		{
			if (placa == registro[k].placa)
			{
				num = (k + 1);
				flag = true;
				cout << "Resultado:" << endl;
				cout << "--------------------" << endl;
				cout << "Ticket: " << num << endl;
				cout << "Cliente: " << registro[k].cliente << endl;
				cout << "Tipo de vehiculo: " << registro[k].tipo << endl;
				cout << "Modelo: " << registro[k].modelo << endl;
				cout << "--------------------" << endl << endl;
				cout << "Tip: Para confirmar mejor los datos solicite id del cliente." << endl;

			}
		}
		if (!flag)
		{
			throw "Placa no registrada";
		}
	}
	catch (const char msg)
	{
		cerr << "Error: " << msg << endl << endl;
	}
	cout << "Costo por extravío: 100" << endl << endl;
	cout << "si desea agregar el monto por extravío al ticket No. " << num << " presione 's' " << endl;
	cin >> respuesta;
	if (respuesta == "s")
	{
		subtotal = 100.00;
		agregarCargos(num - 1, "Costo por extravío", subtotal);
		cout << "Cargo agregado al ticket " << num << " : " << subtotal << endl << endl;
	}
	else
	{
		cout << "Cargo por extravio: " << subtotal << endl << endl;
	}
}
void buscarVehiculo(int i) {
	string res1;
	int numT, a, j;
	try
	{
		do
		{
			cout << "Ingrese el numero de Automovil: ";
			cin >> numT;
			if ((numT <= 0) || (numT > i))
			{
				throw "Numero de ticket invalido";

			}
			a = numT - 1;
			j = 0;
			string control = "f";
			while ((control == "f") && (j < i))
			{
				cout << "Cliente: " << registro[a].cliente << endl << "Tipo de automovil: " << registro[a].tipo << endl << "Modelo del automovil: " << registro[a].modelo << endl << "Placa: " << registro[a].placa << endl;
				control = "v";
				j++;
			}
			cout << endl << "Para buscar otro vehiculo escriba S: ";
			cin >> res1;
		} while ((res1 == "s") || (res1 == "S"));
	}
	catch (const char* msg)
	{
		cerr << "Error: " << msg << endl;
	}
}
void imprimirRegistro(int i) {
	string res;
	cin.ignore();
	cout << endl;
	cout << setw(20) << "Lista de automoviles" << endl;
	cout << "No. automovil" << setw(20) << "Placa" << endl;
	for (int j = 0; j < i; j++)
	{
		cout << "Vehiculo " << j + 1 << setw(22) << registro[j].placa << endl;
	}
	cout << endl << "Para ver mas informacion sobre un vehiculo escriba S" << endl;
	cin >> res;
	if ((res == "s") || (res == "S"))
	{
		buscarVehiculo(i);
	}
}
void listarCargos() {
	int numero;
	double subtotal = 0;
	try
	{
		cout << "Ingrese el numero de ticket: ";
		cin >> numero;
		if (numero <= 0)
		{
			throw "Numero de ticket invalido";

		}
		numero = numero - 1;
		cout << endl;
		cout << " Cargos" << "				" << "Valor cargo" << endl;
		for (int j = 0; j < tam; j++)
		{
			if (cargos[numero][j].descripcionCargo != "")
			{
				cout << cargos[numero][j].descripcionCargo << "		" << cargos[numero][j].valorCargo << endl;
				subtotal = subtotal + cargos[numero][j].valorCargo;
			}
		}
		cout << "Subtotal: " << "		" << subtotal << endl << endl;
	}
	catch (const char* msg)
	{
		cerr << "Error: " << msg << endl;
	}


}
double cobroEstacionamiento(int numero) {
	int hora;
	const double MOTO = 7, TURISMO = 10, CAMIONETA = 15, PICK_UP = 12, CAMION = 18;
	double subtotalEstadia, tiempo, min;
	cout << "	Ingrese cantidad de horas de estadia:   ";
	cin >> hora;
	cout << "	Ingrese cantidad de minutos de estadia: ";
	cin >> min;
	tiempo = ((min / 60) + hora);
	if (registro[numero].tipo == "Motocicleta")
	{
		subtotalEstadia = tiempo * MOTO;
	}
	else if (registro[numero].tipo == "Camion")
	{
		subtotalEstadia = tiempo * CAMION;
	}
	else if (registro[numero].tipo == "Pick Up")
	{
		subtotalEstadia = tiempo * PICK_UP;
	}
	else if (registro[numero].tipo == "Camioneta")
	{
		subtotalEstadia = tiempo * CAMIONETA;
	}
	else
	{
		subtotalEstadia = tiempo * TURISMO;
	}
	return subtotalEstadia;
}
double redondear(double valor, int CantidadDecimales) {
	const double multiplicador = pow(10.00, CantidadDecimales);
	return ceil(valor * multiplicador) / multiplicador;
}
void factura(int i, int estacionamiento[1][25], int* Libre) {
	int numero, fila = 0, columna = 0;
	double subtotal1, subtotalCargos = 0, total;
	bool salida;
	try
	{
		cout << "Ingrese el numero de ticket: ";
		cin >> numero;
		if ((numero <= 0) || (numero > i))
		{
			throw "Numero de ticket invalido";
		}
		numero = numero - 1;
		subtotal1 = cobroEstacionamiento(numero);
		cout << endl;
		cout << "------------------------------" << endl;
		cout << "|  PARQUEO LA BUENA ESTANCIA" << endl;
		cout << "|Cliente: " << registro[numero].cliente << endl;
		cout << "|Tipo de vehiculo: " << registro[numero].tipo << endl;
		cout << "|Modelo: " << registro[numero].modelo << endl;
		cout << "|Placa: " << registro[numero].placa << endl;
		cout << "|Cobro por estadía: " << "		" << fixed << setprecision(2) << redondear(subtotal1, 2) << endl;
		for (int j = 0; j < tam; j++)
		{
			if (cargos[numero][j].descripcionCargo != "")
			{
				cout << "|" << cargos[numero][j].descripcionCargo << ":" << "		" << fixed << setprecision(2) << redondear(cargos[numero][j].valorCargo, 2) << endl;
				subtotalCargos = subtotalCargos + cargos[numero][j].valorCargo;
			}
		}
		total = subtotalCargos + subtotal1;

		cout << "|Total: " << "			" << fixed << setprecision(2) << redondear(total, 2) << endl;
		cout << "|Nota:si uso uno de nuestros servicios del lavado" << endl;
		cout << "|el tiempo del mismo no suma a la tarifa." << endl;
		cout << "| !Estamos para servirles vuelva pronto!" << endl << endl;
		cout << "------------------------------" << endl;
		do {
			salida = false;
			if (estacionamiento[fila][columna] == 1) {
				estacionamiento[fila][columna] = 0;
				salida = true;
				(*Libre)++;
			}
			columna++;
		} while (salida == false);
	}
	catch (const char* msg)
	{
		cerr << "Error: " << msg << endl;
	}
}
void espacios(int estacionamiento[1][tam], int* Libre, int i) {
	bool estacionado;
	int fila = 0, columna = 0, numero, f = 0, c = 0;
	char seccion;
	cout << "----- Parqueo para Carros y Motocicletas  -----" << endl;
	if (*Libre > 0)
	{
		try
		{
			do {
				estacionado = false;
				cout << "Ingrese el numero de ticket: ";
				cin >> numero;
				if ((numero <= 0) || (numero > i))
				{
					estacionado = true;
					throw "Numero de ticket invalido";

				}
				numero = numero - 1;
				cout << endl;
				if ((estacionamiento[fila][columna] == 0) && (numero < i)) {
					estacionado = true;
					estacionamiento[fila][columna] = 1;
					(*Libre)--;
					cout << "----------------------------------------" << endl << endl;
					cout << " Vehículo estacionado correctamente " << endl;
					cout << "Cliente " << registro[numero].cliente << ": su ubicación es A" << fila << columna << endl << endl;
					cout << "----------------------------------------" << endl << endl;
				}
				columna++;
			} while (estacionado != true);
		}
		catch (const char* msg)
		{
			cerr << "Error: " << msg << endl;
		}
	}
	else {
		cout << "No quedan espacios libres" << endl;
	}
}
void estadoParqueo(int estacionamiento[1][25]) {
	const int NFILAS = 1, NCOLUMNAS = 25;
	cout << "	Estado del Parqueo" << endl;
	cout << "--------------------------------------" << endl;
	for (int fila = 0; fila < NFILAS; fila++)
		for (int columna = 0; columna < NCOLUMNAS; columna++)
			if (estacionamiento[fila][columna] == 1)
				cout << "	A" << fila << columna << "	Ocupado" << endl;
			else if (estacionamiento[fila][columna] == 0)
				cout << "	A" << fila << columna << "	Libre" << endl;
	cout << "--------------------------------------" << endl << endl;
}
int main() {
	char opcion;
	int  i = 0, c = 1, t = 0, Libre = 0;
	double totalDeLavado;
	string respuesta;
	setlocale(LC_ALL, "spanish");
	SetConsoleCP(1252);
	const int NFILAS = 1, NCOLUMNAS = 25;
	int estacionamiento[1][25] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
	for (int fila = 0; fila < NFILAS; fila++)
		for (int columna = 0; columna < NCOLUMNAS; columna++)
			if (estacionamiento[fila][columna] == 0)
				Libre++;
	do
	{
		try
		{
			cout << "PARQUEO LA BUENA ESTANCIA" << endl << endl;
			cout << "Elija una opcion: " << endl;
			cout << "1. Crear Tickets" << endl << "2. Corregir datos de un ticket" << endl << "3. Espacios " << endl << "4. Servicio de lavado " << endl;
			cout << "5. Ticket extraviado " << endl << "6. lista de clientes (del día)" << endl << "7. Listado de cargos" << endl << "8. Facturar " << endl << "9. Estado de Parqueos" << endl << "0. salir" << endl;
			cin >> opcion;
			switch (opcion)
			{
			case '1':
				agregar(i);
				i++;
				break;
			case '2':
				if (i == 0)
				{
					throw "No hay registros que corregir";
				}
				corregir(i);
				break;
			case '3':
				if (i == 0)
				{
					throw "No hay registros para aplicar Servicio";
				}
				espacios(estacionamiento, &Libre, i);
				break;
			case '4':
				if (i == 0)
				{
					throw "No hay registros para aplicar Servicio";
				}
				totalDeLavado = calculoDeLavado(i);
				break;
			case '5':
				if (i == 0)
				{
					throw "No hay registros para validar";
				}
				extraviado();
				break;
			case '6':
				if (i == 0)
				{
					throw "No hay registros que mostrar";
				}
				imprimirRegistro(i);
				break;
			case '7':
				if (i == 0)
				{
					throw "No hay registros para listar cargos";
				}
				listarCargos();
				break;
			case '8':
				if (i == 0)
				{
					throw "No hay registros que facturar";
				}
				factura(i, estacionamiento, &Libre);
				//tam = tam - 1;
				break;
			case '9':
				estadoParqueo(estacionamiento);
				break;
			case '0':
				c = 0;
				break;
			default:
				cout << "opcion invalida" << endl;
				break;
			}
		}
		catch (const char* msg)
		{
			cerr << "Error: " << msg << endl;
		}
	} while (c == 1);
	system("pause");
	return 0;
