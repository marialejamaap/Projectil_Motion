#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSlider>
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

private slots:

    double on_Release_angle_sliderReleased();

    double on_Enter_Mass_sliderReleased();

    double on_Enter_Velocity_Initial_sliderReleased();

    double on_Enter_cd_sliderReleased();

    double on_Enter_Diameter_sliderReleased();

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
};
#endif // SECONDWINDOW_H
