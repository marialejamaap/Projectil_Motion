#include "projectile.h"



Projectile::Projectile(double v, double w, double x, double y, double z)
{

}

double Projectile::set_Xpos(double v, double w, double x, double y, double z)
{
    double X,b;
    b=((-1)*(v/w));
   X=(w/v)*(x)*(cos(y))*((1-(exp(b*z)))); // Fórmula para hallar la posición en x con resistencia en el aire
   Xpos=X;
    return Xpos;
}

double Projectile::set_Ypos(double v, double w, double x, double y, double z)
{
    double Y,b,c;
    b=((-1)*(v/w));
    c=(w/v);
    Y=(c)*(x*(sin(y))+(c*g))*(1-(exp(b*z)))-(c*g*z);//Fórmula para hallar posición en Y con resistencia en el aire
    Ypos=Y;
    return Ypos;
}
