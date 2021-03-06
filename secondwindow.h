#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSlider>
#include <string>
#include <sstream>
#include <math.h>
double const PI=3.1416;// constante PI
double const g=9.8;// gravedad como constante con valor 9.8
double const rho=1.225;// densidad del aire
namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();



    double on_Release_angle_sliderReleased();

    double on_Enter_Mass_sliderReleased();

    double on_Enter_Velocity_Initial_sliderReleased();

    double on_Enter_cd_sliderReleased();

    double on_Enter_Diameter_sliderReleased();

    double set_Xpos(double v, double w, double x, double y, double z);
    double set_Ypos(double v, double w, double x, double y, double z);
    double get_Release_angle(){return ang_din;}
    double get_Mass(){return mass_din;}
    double get_Velocity_initial(){return velocity_init_din;}
    double get_cd(){ return cd_din;}
    double get_diameter(){return diameter_din;}
    double get_Rest_k();
    double get_Xpos(){return Xpos;}
    double get_Ypos(){return Ypos;}

private slots:
    void on_Out_K_textChanged();

private:
    Ui::secondwindow *ui;
   QGraphicsScene *scene=nullptr;
   QGraphicsEllipseItem *ellipse=nullptr;
   QGraphicsRectItem *rectangle=nullptr;
    QSlider *slider1=nullptr;
    QSlider *slider2=nullptr;
    QSlider *slider3=nullptr;
    QSlider *slider4=nullptr;
    QSlider *slider5=nullptr;
    double ang_din;
    double mass_din;
    double velocity_init_din;
     double cd_din;
     double diameter_din;
     double Xpos, Ypos;
     double rest_k;

};
#endif // SECONDWINDOW_H
