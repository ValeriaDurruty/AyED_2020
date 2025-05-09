// Estrategia de abordaje:
// * Estructuras a utilizar:
	// - Vector de tamaño 3 con nros. reales: en el primer lugar tarifa por hora auto, en el 2do tarifa por hora camioneta, en el 3ro tarifa por hora moto.
	// - Lista de Ingreso cuyo registro tiene los sig. datos: patente y tipo. (LI)
	// - Lista Final de Cobro cuyo registro tiene los sig. datos: patente, tipo, horas y monto total. (LF)
// * Operatoria del día:
	// - Al comienzo del día se cargan los importes por hora para cada tipo de vehículo.
	// - Cuando abre el estacionamiento:
		// a. Por c/auto que ingresa: agrego un nuevo nodo en Lista de Ingreso y le cargo patente y tipo.
		// b. Por c/auto que egresa: lo busco por patente en la Lista de Ingreso, copio la patente y el tipo del nodo en una variable auxiliar y procedo a borrar
			// el nodo, luego agrego un nuevo nodo en la Lista de Cobro y le cargo patente, tipo, pido que se ingresen la cant. de horas y calculo el monto total.
	// - Al finalizar el día, recorro la Lista de Ingreso de manera recursiva y cuento el total de nodos para saber cuántos vehículos ingresaron en el día.


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

float tarifas[3];

struct vehic
{	char patente[7];
	int tipo;
};
struct lIngreso
{	struct vehic dato;
	struct lIngreso *psig;
};

struct cobro
{	char patente[7];
	int tipo;
	int horas;
	float mTotal;
};
struct lFinal
{	struct cobro dato;
	struct lFinal * psig;
};

void cargartarifas (float *montos);
void crearlistas (struct lIngreso **L1, struct lFinal **L2);
void insertar (struct lIngreso **L1, struct vehic reg);
void borrarAuto (struct lIngreso **L1, struct cobro *reg);
void InsertarCobro (struct lFinal **L2, struct cobro reg);
int contarnodos1 (struct lIngreso **L1);
int contarnodos2 (struct lFinal **L2);



int main()
{
	struct vehic regAuto;
	struct lIngreso *LI;
	struct cobro regMonto;
	struct lFinal *LF;
	int dia;
	int op;
	int nodosLI;
	int nodosLF;
	int totalvehic;
	
	
	
	//Cargo las tarifas por hora para los distintos tipos de vehículo
	cargartarifas (&tarifas[3]);
	//Creo las listas de ingreso y la final
	crearlistas (&LI, &LF);
	
	dia=1;
	
	while (dia==1)
	{	
		printf ("Si el vehículo ingresa presione 1, si egresa presione 0.");
		scanf ("%d", &op);

		if (op==1)
		{	printf ("Ingrese patente.");
			scanf ("%s", regAuto.patente);
			printf ("Ingrese tipo de vehículo: 1. auto, 2. camioneta, 3. moto.");
			scanf ("%d", &regAuto.tipo);
			//Cargo el auto que ingreso en la lista
			insertar (&LI, regAuto);
		}
			else
			{	printf ("Ingrese patente del vehículo que se retira.");
				scanf ("%s", regMonto.patente);
				//Busco el vehículo que egresa por patente y lo borro
				borrarAuto (&LI, &regMonto);
				if (regMonto.tipo!=0)
				{	printf ("Ingrese las horas a facturar.");
					scanf ("%d", &regMonto.horas);
					//calculo el monto a cobrar
					regMonto.mTotal=tarifas[regMonto.tipo]*regMonto.horas;
					//Ingreso el auto que se retiro en la lista de cobro
					InsertarCobro(&LF, regMonto);
				}
		printf ("Finalizó el día laboral? No: presione 1, Si: presione 0");
		scanf ("%d", &dia);
	}
	nodosLI=contarnodos1 (LI);
	nodosLF=contarnodos2 (LF);
	//calculo total de vehículos ingresados en el día
	totalvehic=nodosLI+nodosLF;
	
	return 0;
};


void cargartarifas (float *montos[3])
{	int i;

	for (int i=1; i<4; i++)
	{	printf ("Siendo 1. auto, 2. camioneta y 3. moto ingrese la tarifa por hora del vehículo: %d", i);
		Scanf ("%.xf", &montos[i]);
	};
}

void crearlistas (struct lIngreso **L1, struct lFinal **L2)
{	*L1=0;
	*L2=0;
}

void insertar (struct lIngreso **L1, struct vehic reg)
{
    struct lIngreso *nuevo=malloc (sizeof(struct lIngreso));
    nuevo ->dato=reg;
    nuevo->psig=*L1;
    *L1=nuevo;
}

void borrarAuto (struct lIngreso **L1,  struct cobro *reg)
{	struct lIngreso *act;
	struct lIngreso *ant;			
	if(*L1!=0)
	{	ant=0;
		act=*L1;
		while ((act!=0) && (act->dato.patente!=reg.patente))
		{	ant=act;
			act=act->psig;
		}
		if (act==0)
		{	//no se encontró la patente
			printf ("Patente inexistente.");
			reg.tipo=0;
		}
		else
		{	//se encontró la patente
			reg.tipo=act->dato.tipo;
			if (ant==0)
			{	*L1=act->psig;
				free(act);
			}
			else
			{	ant->psig=act->psig;
				free(act);
			}
	}
	else
	{	printf ("La lista esta vacía.");
		reg.tipo=0;
	}
}

void InsertarCobro (struct lFinal **L2, struct cobro reg)
{	struct lFinal *nuevo=malloc (sizeof(struct lFinal));
	nuevo->dato=reg;
	nuevo->psig=*L2;
	*L2=nuevo;
}

int contarnodos1 (struct lIngreso **L1)
{	if (L1!=0)
	{	return contarnodos (L1->psig)+1;
	}
	else
	{return 0;
	}
}
	
int contarnodos2 (struct lFinal **L2)
{	if (L2!=0)
	{	return contarnodos (L2->psig)+1;
	}
	else
	{return 0;
	}
}