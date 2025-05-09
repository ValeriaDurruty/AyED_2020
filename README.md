# AyED_2020
Este repositorio contiene la solución en C para problemáticas planteadas en la materia Algoritmos y Estructuras de Datos, cursada en 2020.

##   Contenido

* `paqueteria.c`: Solución al problema de gestión de envíos de paquetes de un correo.
* `estacionamiento.c`: Simulación de la gestión de un estacionamiento.

##   `paqueteria.c`

Este programa gestiona información sobre envíos de paquetes de un correo durante un día. Los datos de cada paquete incluyen número de guía, DNI del destinatario, número de ciudad de origen, número de ciudad de destino y número de vehículo. Los paquetes se cargan en una pila a medida que llegan a la base de operaciones.

El programa realiza las siguientes operaciones:

1.  Ordena los paquetes por número de vehículo y determina cuántos paquetes ha entregado cada vehículo (usando recursión).
2.  Calcula el total de paquetes entregados en la ciudad de destino 1900 (usando recursión).
3.  Calcula el porcentaje de paquetes entregados en la ciudad 1900 respecto al total de paquetes entregados.

La solución implementa una pila para la carga inicial de datos, una lista enlazada ordenada para la organización por vehículo, y funciones recursivas para los cálculos.

##   `estacionamiento.c`

Este programa simula la gestión de un estacionamiento. Permite registrar el ingreso y egreso de vehículos, y calcular los cobros correspondientes.

Las funcionalidades principales incluyen:

* Carga de tarifas por tipo de vehículo (auto, camioneta, moto).
* Registro de ingresos de vehículos con patente y tipo.
* Registro de egresos de vehículos, calculando el monto a cobrar según el tiempo de estadía y el tipo de vehículo.
* Cálculo del total de vehículos que ingresaron al estacionamiento en un día.

El programa utiliza estructuras de datos para almacenar la información de los vehículos y las tarifas.

##   Compilación y Ejecución

Para compilar los programas, puedes usar un compilador de C como GCC. Los comandos típicos serían:

```bash
gcc paqueteria.c -o paqueteria
gcc estacionamiento.c -o estacionamiento
./paqueteria
./estacionamiento
```

## Autor

Valeria E. Durruty
