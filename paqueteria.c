// Infomación sobre envíos de paquetes de un correo durante un día.
// Datos: nro-guía, DNI-destinatario, nro-ciudad-origen,
// nro-ciudad-destino, nro-vehículo.
// Se carga en una pila a medida que llegan a la base de operaciones.

// Ordenar por nro. de vehículo para obtener la info:
// - Cuántos paquetes ha entregado en total. (1)
// - Total de paquetes entregados por ciudad-destino=1900. (2)
// - Porcentaje de paquetes entregados en (1900) respecto al total de 
// paquetes.

// Operatoria:
// - Realizar la carga de la pila.
// - Descargar la pila e ir confeccionando una lista ordenada.
// - Sobre la lista determinar los puntos pedidos, tener en cuenta que 
// deberá usar recursión para dar la solución a 1 y 2.
// - Determinar el porcentaje solicitado.



// Estrategia de abordaje:
// - Comienza el día laboral, a medida que llegan los vehículos a la 
// base se apilan los paquetes que traen en la pila, con los datos:
// nro guía, dni destinatario, nro ciudad origen, nro ciudad destino 
// y nro de vehículo.
// - Cuando termina el día se desapilan los elementos de la pila 
// para pasarlos a una lista ordenada por nro de vehículo.
// - En base a esa lista se cuentan la cantidad de paquetes 
// entregados en total por todos los vehículos. Y los paquetes entregados 
// por ciudad destino (1900). Luego se saca el porcentaje de estos últimos.



#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct paquetes{
	int nro-guia;
	int DNI-destinatario;
	int nro-ciudad-origen;
	int nro-ciudad-destino;
	int nro-vehículo;
};

struct Pila{
	struct paquetes dato;
	struct Pila *ps;
};

struct Lista{
	struct paquetes dato;
	struct Lista *ps;
};

void cargadatos (struct paquetes *pq)
void apilarpaq (struct Pila **p, struct paquetes pq)
void desapilar(struct Pila **p, struct paquetes *pq)
void insertarOrd(struct Lista **l, struct paquetes pq)
int contarRec(struct Lista *l)
int contarlp(struct Lista *l)
	
int main(){
	struct paquetes paq;
	struct Pila *pil;
	struct Lista *lis;
	int resp;
	int pilavacia;
	int total;
	int paqlp;
	float porcentajelp;
	
	//inicializo la pila y la lista
	*pil=0;
	*lis=0;
	
	//comienza el día laboral
	resp=0;
	while (resp!=1){
		//comienzo a cargar los datos de los paquetes que ingresan
		cargadatos (&paq);
		apilarpaq (&pil, paq);
		printf("Terminó el día laboral? SI=1, NO=0");
		scanf("%d", &resp);
	}
	//termino el día, se pasan los datos a la lista
	pilavacia=0;
	while (pilavacia!=1){
		desapilar (&pil, &paq, &pilavacia);
		if (pilavacia!=1){
			insertarOrd (&lis, paq);
		}
	}
	//terminé de armar mi lista ordenada
	//cuento el total de paquetes del día
	total=contarRec (lis);
	printf("Se entregaron %d paquetes en el día.", total);
	//cuento el total de paquetes entregados en la ciudad 1900
	paqlp=contarlp (lis);
	printf("El total de paquetes entregados en la ciudad 1900 es : %d.", paqlp);
	//calculo el porcentaje de paquetes entregados en LP
	porcentajelp=(paqlp*100)/total;
	printf("El porcentaje de paquetes entregados en la ciudad 1900 es %f %", porcentajelp);

	return 0;
}

void cargadatos (struct paquetes *pq){
	printf("Ingrese nro. de guía del paquete.");
	scanf("%d", &pq->nro-guia);
	printf("Ingrese el DNI del destinatario del paquete.");
	scanf("%d", &pq->DNI-destinatario);
	printf("Ingrese nro. de ciudad de origen del paquete.");
	scanf("%d", &pq->nro-ciudad-origen);	
	printf("Ingrese nro. de ciuda de destino del paquete.");
	scanf("%d", &pq->nro-ciudad-destino);
	printf("Ingrese el nro. de vehículo en el que venía del paquete.");
	scanf("%d", &pq->nro-vehículo);
}

void apilarpaq (struct Pila **p, struct paquetes pq){
	struct Pila *nuevo = malloc (sizeof(struct Pila));
	nuevo->dato=pq;
	nuevo->ps=p;
	*p=nuevo;
}

void desapilar(struct Pila **p, struct paquetes *pq, int *marca){
	struct Pila *aux;
	
	aux=*p;
	if (aux==0){
		printf("Pila vacía.");
		marca=1;
	}
	else{
		*p=aux->ps;
		pq=aux->dato;
		free(aux);
	}
}

void insertarOrd(struct Lista **l, struct paquetes pq){
	struct Lista *ant;
	struct Lista *act;
 
    struct Lista *nuevo = malloc(sizeof(struct Lista));
	nuevo->dato=pq;
	
	if (*l==0){
		*l=nuevo;
		nuevo->ps=0;
	}
	else{
		ant=0;
		act=*l;
		while ((act!=0) && (act->dato.nro-vehículo<=nuevo->dato.nro-vehículo)){
			ant=act;
			act=act->ps;
		}
		if (ant==0){
			nuevo->ps=act;
			*l=nuevo;
		}
		else{
			nuevo->ps=act;
			ant->ps=nuevo;
		}
	}
}

int contarRec(struct Lista *l){
	struct Lista *aux;
	aux=*l;
	
	if(*aux!=0){
		return contarRec(aux->ps)+1;
	}
	else{
		return 0;
	}
}

int contarlp(struct Lista *l){
   struct Lista *aux;
   aux=*l;
   
   if (*aux!=0){
	   if (aux->dato.nro-ciudad-destino==1900){
		   return contarlp (aux->ps)+1;
	   }
	   else{
		   return contarlp (aux->ps)+0;
	   }
   }
   else{
	   return 0;
   }
}