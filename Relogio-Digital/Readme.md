# Relogio Digital com display LCD

Projeto em arduino de um relogio digital que mostra as horas em 24 horas. Com possibilidade de alterar o seu horario com os seguintes botões presentes. E mostra o horario em um display LCD. Possui função despertador com botão soneca.

![](https://github.com/Roalli/Projetos-de-arduino/blob/main/Relogio-Digital/Copy%20of%20Relogio%20Digital.png)

## Materiais

* Arduino Uno R3
* LCD 16 x 2
* 220 Ω Resistor
* 1 kΩ Resistor
* 4 Botão
* Interruptor deslizante
* Piezo

## O seu uso

Com os seus 4 botões conectados ao arduino, sendo eles o de horas, minutos, segundos e um para entrar na configuração do despertador.

### Horario

Para alterar o horario, é apenas clicar em um dos 3 primeiros botões, que ira ajustar o horario conforme o usuario pretender. Caso queira diminuir o horario é só ativar o botão deslizante, que ao clicar um dos 3 botões, ao inves de aumentar ele diminui o horario.

### Despertador

Ao clicar no ultimo botão, ele entra na configuração do despertador, neste modo a contagem do tempo ainda continua. Ao clicar um dos 3 botão de ajuste de horario, ira alterar o horario do despertador.
Quando o horario configurado do despertador atingir, o relogio desperta, podendo o usuario clicar o soneca para parar o alarme e ira tocar após 10 segundos, que no caso o botão soneca é o mesmo do de horas. E para parar, o botão é o de minuto, e após 10 segundos sem clicar em nenhum botão, ele para de despertar.

## Codigo 

O codigo fonte está presente neste repositorio em formato .ino para ser usado no arduino.
