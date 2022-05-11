# Simulación de la carrera de la libre y la tortuga
La liebre y la tortuga: En este problema, recreará la carrera clásica de la tortuga
y la liebre, se valdrá de la generación de números aleatorios para desarrollar la
simulación de este memorable evento.
Nuestros contendientes comienzan la carrera en el “cuadro 1” de una serie de
70 cuadros, cada cuadro representa una posición posible en la ruta de la carrera. La línea de meta está en el cuadro 70. El primer contendiente que llegue
o pase el cuadro 70 obtiene como recompensa un cubo de zanahorias y lechuga frescas. La ruta sube serpenteando por la ladera de una montaña resbalosa, por lo que ocasionalmente los contendientes pierden terreno.
Hay un reloj que pulsa una vez por segundo. Con cada pulso del reloj, el programa deberá ajustar la posición de los animales, de acuerdo con las siguientes
reglas:
![image](https://user-images.githubusercontent.com/63917946/167915202-30100c74-c800-4fe8-bc8f-6f434c95ba86.png)
Utilice variables para llevar el registro de las posiciones de los animales (Las posiciones son de la 1 a la 70) Cada animal debe comenzar en la posición 1 (es
decir, la “puerta de salida”). Si un animal resbala hacia la izquierda, quedando
antes del cuadro 1, devuélvalo al cuadro 1.
Genere los porcentajes de la tabla previa produciendo un entero aleatorio, i,
que esté en el rango 1 <= i <= 10. Para la tortuga, efectúe un “paso veloz”
cuando 1 <= i <= 5, un “resbalón” cuando 6 <= i <= 7 y un “paso lento” cuando
8 <= i <= 10. Utilice una técnica similar para mover a la liebre.
Comience la carrera imprimiendo:
¡BANG!
¡Y ARRANCAN!
Por cada pulso del reloj (Es decir, cada repetición del ciclo) imprima una línea
de 70 posiciones que muestre la posición de la tortuga mediante la letra T y la
de la liebre mediante la letra H. Ocasionalmente los contendientes caerán en
el mismo cuadro. En
este caso, la tortuga morderá a la liebre y el programa deberá imprimir: ¡OUCH!
en tal posición. Todas las posiciones de impresión que no sean T, H ni ¡OUCH”
(En caso de empate), deben estar en blanco.
Después de la impresión de cada línea, pruebe si alguno de los animales ha
llegado o pasado el cuadro 70. De ser así imprima el ganador y termine la simulación. Si la tortuga gana imprima ¡LA TORTUGA GANA! ¡BRAVO! Si la liebre
gana, imprima “La liebre gana. Ni hablar” si ambos animales llegan a la meta
con el mismo pulso de reloj, tal vez usted quiera favorecer a la tortuga o imprimir
“Es un empate” si ninguno de los animales gana, vuelva a efectuar el ciclo,
simulando el siguiente pulso de reloj. Cuando esté listo para ejecutar su programa.
Desarrollo de la Solución
Utilice un vector, apuntadores a posiciones para los animales, vectores
para los porcentajes de los movimientos descritos en la tabla.
