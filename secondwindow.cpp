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
}




double secondwindow::on_Release_angle_sliderReleased()
{
   double ang_din;
   slider1=new QSlider(this);
   ang_din=slider1->value();
   ang_din=ang_din*(PI/180);
   return ang_din;
}

double secondwindow::on_Enter_Mass_sliderReleased()
{
    double mass_din;
    slider2=new QSlider(this);
    mass_din=slider2->value();
    return mass_din;
}


double secondwindow::on_Enter_cd_sliderReleased()
{
    double cd_din;
    slider3=new QSlider(this);
    cd_din=slider3->value();
    return cd_din;
}

double secondwindow::on_Enter_Diameter_sliderReleased()
{
    double diameter_din;
    slider4=new QSlider(this);
    diameter_din=slider4->value();
    return diameter_din;

}

double secondwindow::on_Enter_Velocity_Initial_sliderReleased()
{
    double velocity_init_din;
    slider5=new QSlider(this);
    velocity_init_din=slider5->value();
    return velocity_init_din;
}
