# ProyectoProgIV

Proyecto ProgIV- Reserva de Hoteles: Proyecto final de la asignatua de ProgIV cursada en 2º de carrera. 

> Miembros del equipo: Unai mendiondo, Mireya Quintana, Haizea Rodriguez


Programa que permite a un usuario realizar una reserva de hotel. El usuario podrá seleccionar el lugar en el que desea hospedarse seleccionando entre las distintas localidades donde se encuentra la cadena de hotel. Su siguiente paso será marcar la fecha en la que quiere acudir y el número de acompañantes. En este apartado se indicará si son niños o adultos (considerando niños menores de 17 años). También se puede dar la opción de cuna o no cuna en el caso de marcar la casilla de niño. 

Se le ofrecerá al cliente una lista de opciones (media pensión, pensión completa, luxury). La decisión tomada en este punto nos dará el precio por noche que conjunto a los datos anteriores nos permitirá mostrar al usuario su precio final. 

Se permite otra opción de contratación de parking. Esto supondrá un cargo extra. 

A continuación, comenzará el proceso de reserva. El cliente deberá insertar una serie de datos para realizar la reserva, así como el nombre y el teléfono de contacto. Seguidamente se pedirán los datos de compra (titular de la tarjeta, número de tarjeta, fecha de caducidad y código de seguridad). También tendrá la opción de introducir la dirección de correo electrónico donde le gustaría recibir la confirmación.



Este programa permite si se selecciona la opción 1 entrar como administrador y realizar las funciones pertinentes o si selecciona la opción 2 realizar una compra. 

#OO

Para la parte de OO de nuestro proyecto hemos decidido utilizar la siguiente herencia:

> La herencia se constituye de las clases “Usuario”, “Cliente” y “Admin”, siendo “Usuario” la clase padre y las restantes las clases hijas. De esta manera tanto a clientes como administradores pese a tener diferentes funcionalidades los dos son tipos de usuarios que comparten los atributos y métodos básicos.


#BD

En nuestro programa utilizamos una BD para gestionar toda la información.  La BD y sus tablas se crea la primera vez que se ejecuta el programa y se insertan ciertos valores por defecto, como los tres hoteles con sus correspondientes administradores y los tipos de pensión. 


