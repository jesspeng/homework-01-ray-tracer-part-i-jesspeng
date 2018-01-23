#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camera.h"
#include <QImage>
#include <QRgb>
#include <QLabel>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
Camera cam(0, 0, 10,
           0, 0, 0,
           0, 1, 0,
           45, 400, 400,
           0.1, 1000);
QRgb value;
QImage image(cam.width, cam.height, QImage::Format_RGB32);
for (int i = 0; i < cam.width; i++) {
    for (int j = 0; j < cam.height; j++) {
        Ray ray = cam.rayCast(i, j);
        glm::vec3 RGB = (ray.direction + glm::vec3(1, 1, 1)) * 0.5f;
        value = qRgb(RGB.x * 255, RGB.y * 255, RGB.z * 255);
        image.setPixel(i, j, value);
    }
}

ui->label->setPixmap(QPixmap::fromImage(image));
ui->label->show();
//myLabel.setPixmap(QPixmap::fromImage(image));

//myLabel.show();

}
