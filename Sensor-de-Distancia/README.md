# Sensor de Distancia
É um sensor de distancia com 3 sensores, possuindo um motor de vibração para cada sensor. Assim sabendo em qual posição está se aproximando o obstaculo.
Possui também um modo para saber se os sensores está sendo movimentado reto ou não em um corredor.

![](https://github.com/Roalli/Projetos-de-arduino/blob/main/Sensor-de-Distancia/sensor%20de%20distancia.png)

## Materiais

* Arduino Uno R3
* 3 Sensor de distancia Ultrasonico
* 3 Motor de vibração
* 3 1kΩ Resistor
* 3 Transistor NPN (BJT)
* 1 Interruptor deslizante

## O seu uso

Ao ligar o arduino, ele ja começa a detectar a distancia com os sensores, se a distancia de lgum obstaculo for maior que 1 metro, os motores de vibração estara parado, mas caso a distancia for menor que um metro mas maior que 50cm, o motor de vibração correspondente ao sensor, ira vibrar com baixa intensidade. Caso a distancia for menor que 50 cm e maior que 25cm, ira vibrar com mais intensidade, e se for menor que 25cm ele não vibra pelo motivo de ter sido planejado em ser usado na cintura, para não vibrar com gestos do usuario.

## Codigo

O codigo fonte está presente neste repositorio em .ino para já ser usado no arduino.
