#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "secondwindow.h"


class Projectile:public secondwindow
{
public:
    Projectile(double v, double w, double x, double y, double z);

    double set_Xpos(double v, double w, double x, double y, double z);
    double set_Ypos(double v, double w, double x, double y, double z);
    double set_Rest_k(double a);
    double set_Angle_rad(double a);
    double get_Xpos(){return Xpos;}
    double get_Ypos(){return Ypos;}

private:
   double Xpos, Ypos;
   double rest_k;
   double angle_rad;
};

#endif // PROJECTILE_H
