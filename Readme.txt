Este programa es una prueba funcional del accionamiento de un motor a pasos nema 23, durante un tiempo asignado;
 una vez que se acaba el tiempo, el motor queda inhabilitado hasta volver a presionar un boton. 

Esta prueba asigna un tiempo de 10 segundos cada vez que se presiona el boton asignado al pin 8, conocido como 
"ACTIONPIN". Despues se habilita el timer mediante la libreria "TimerOne.h", y se ejecuta un ciclo do while que mantendra
el motor girando hasta que la cuenta regresiva llegue a 0. 

PIN DE TIMER 1

el pin 7 

conocido como "Led" parpadea cada vez que se ejecuta la interrupcion para indicar o poder ver que el timer 
esta corriendo a un segundo. 

PINES DE CONTROL DEL MOTOR 

Pin 10 "ENAPIN"
pin 11 "DIRPIN"
pin 12 "STEPPIN"

