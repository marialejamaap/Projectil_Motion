#include <iostream> //Librería para datos de entrada y salida
#include <math.h> // Librería para utilizar operaciones como cos(angulo) y sen(angulo)
#include <conio.h> // Librería para getch()
#include <windows.h> // Librería para el tiempo
#include <iomanip> // Librería para el tiempo
using namespace std;

double const PI=3.1416;// constante PI
double const g=9.8;// gravedad como constante con valor 9.8
double const rho=1.225;// densidad del aire
double resistance_k (double a, double b); // función para hallar la k que determina la fricción que se presenta en el proyectil
double Position_X(double v, double w, double x, double y, double z);// Función para determinar la posición en X en cierto tiempo t
 double Position_Y(double v, double w, double x, double y, double z);// Función para determinar la posición en Y en cierto tiempo t

 double angle_1(double a);// función para pasar el angulo a radianes

int main()
{

   double angle1,angle, mass, cd,diameter,velocity_init, Xpos,Ypos, rest_k;// Declaración de variables
   /* angle1= el ángulo en radianes
      angle= ángulo que ingresa el usuario
      mass= La masa del proyectil
      cd= coeficiente de arrastre que posee el proyectil, este depende del proyectil que se utilice
por eso queda a decisión del usuario(por lo general es 0.5 para las esferas)
      diameter= diametro del proyectil para hallar su Àrea
      velocity_init=velocidad inicial
      Xpos= Posición en X del proyectil en cierto tiempo
      Ypos= Posición en Y del proyectil en cierto tiempo
      rest_k= es la variable k que define la fuerza de fricción ejercida en el proyectil
*/
    cout << "\t\t\t Projectile motion\n\n\n\n";// Título del programa
    cout <<" Enter the Initial speed: ";cin>>velocity_init;cout<<endl;// Pide al usuario la velocidad inicial
    cout << " Enter the Angle:  "; cin>>angle;cout<<endl; // Pide al usuario el ángulo, posteriormente se debe hacer su conversión
                                                          // a radianes
    cout <<" Enter the mass of projectile: "; cin>>mass;cout<<endl;// La masa de la esfera o proyectil
    cout<< " Enter the drag coeficient: "; cin>>cd;cout<<endl; // drag coeficient
    cout <<" Enter projectile diameter: ";cin>>diameter;cout<<endl;// Diámetro de la esfera
    rest_k=resistance_k(cd,diameter);// rest_k toma el valor que retorna la función resistance_k
    angle1=angle_1(angle);// El ángulo ya en radianes
    cout<<"The value of K is:"<< rest_k<<endl; // Imprimir el valor de k para comparar con los resultados escritos

    for (int t=0;t<60;t++){
   Xpos= Position_X(rest_k,mass,velocity_init,angle1,t);// Se asigna a la variable Xpos el valor que retorna la función Position_X
                                                        // El valor que retorna es la posición en X del proyectil
   Ypos=Position_Y(rest_k,mass,velocity_init,angle1,t); // Se asigna a la variable Ypos el valor que retorna la función Position_X
                                                        // El valor que retorna es la posición en Y del proyectil
   cout << Xpos<<"\t"<<Ypos<<endl; // Imprimir la posición en x y en y en cierto tiempo t, observar que caada variable
                                    // solo queda dependiendo del tiempo

    }



    getch();// Presionar para continuar
    return 0; // Retorna un cero a función main, que retorna un entero -> Indica que el programa a finalizado correctamente
}
double angle_1(double a){ // Función que convierte el ángulo ingresado por el usuario a un ángulo en rad para poder ser operado
                           // por las posteriores funciones,
return (a*PI/180);  // Fórmula para pasar angúlo a radianes (Recibe como argumento el ángulo del usuario)
}
 double resistance_k (double a, double b){ //Función para hallar la variable k, definida por k=1/2*densidad_del_aire*drag_coeficient*Area
    double k,Area,radius;
    radius=b/2;
    Area=4*PI*radius*radius; // Area de la esfera es igual a: 4*PI*radio al cuadrado
    k=0.5*rho*a*Area;
    return k; // retorna K, variable tipo doble
}


 //Función que define la posición en X, sus argumentos son: (k,masa,velocidad inicial, angulo, tiempo)
double Position_X(double v, double w, double x, double y, double z){
double X,b;
b=((-1)*(v/w));
X=(w/v)*(x)*(cos(y))*((1-(exp(b*z)))); // Fórmula para hallar la posición en x con resistencia en el aire
return X;
}

//Función que define la posición en Y, sus argumentos son: (k,masa,velocidad inicial, angulo, tiempo)
double Position_Y(double v, double w, double x, double y, double z){
double Y,b,c;
b=((-1)*(v/w));
c=(w/v);
Y=(c)*(x*(sin(y))+(c*g))*(1-(exp(b*z)))-(c*g*z);//Fórmula para hallar posición en Y con resistencia en el aire
return Y;
}

