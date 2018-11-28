#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "secondwindow.h"


class Projectile:public secondwindow
{
public:
    Projectile(double v, double w, double x, double y, double z);


   double angle_rad;
   double ang_din,mass_din,cd_din,diameter_din,velocity_init_din;
   double time;
};

#endif // PROJECTILE_H
