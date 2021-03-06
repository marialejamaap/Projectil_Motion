#include "secondwindow.h"
#include "ui_secondwindow.h"


secondwindow::secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);


   scene= new QGraphicsScene(this);
 ui->graphicsView->setScene(scene);
 QBrush redBrush(Qt::red);
 QBrush blueBrush(Qt::blue);
 QBrush greenBrush(Qt::green);
 QPen blackpen(Qt::black);
 blackpen.setWidth(6);
 ellipse=scene->addEllipse(0, 0, 10, 10, blackpen, greenBrush);


}

secondwindow::~secondwindow()
{
    delete ui;
    delete scene;
    delete ellipse;
    delete rectangle;
    delete slider1;
    delete slider2;
    delete slider3;
    delete slider4;
    delete slider5;
}




double secondwindow::on_Release_angle_sliderReleased()
{

   slider1=new QSlider(this);
   ang_din=slider1->value();
   ang_din=ang_din*(PI/180);
   return ang_din;
}

double secondwindow::on_Enter_Mass_sliderReleased()
{

    slider2=new QSlider(this);
    mass_din=slider2->value();
    return mass_din;
}


double secondwindow::on_Enter_cd_sliderReleased()
{

    slider3=new QSlider(this);
    cd_din=slider3->value();
    return cd_din;
}

double secondwindow::on_Enter_Diameter_sliderReleased()
{

    slider4=new QSlider(this);
    diameter_din=slider4->value();
    return diameter_din;

}

double secondwindow::get_Rest_k()
{
   double a=cd_din;
   double b=diameter_din;
   double k,Area,radius;
       radius=b/2;
       Area=4*PI*radius*radius; // Area de la esfera es igual a: 4*PI*radio al cuadrado
       k=0.5*rho*a*Area;
       return k;
}

double secondwindow::on_Enter_Velocity_Initial_sliderReleased()
{

    slider5=new QSlider(this);
    velocity_init_din=slider5->value();
    return velocity_init_din;
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
void secondwindow::on_Out_K_textChanged()
{
    double st;
 QString str;
 st=get_Rest_k();
 str=static_cast<ostringstream*>(&(ostringstream() << st))->str();
}
