#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Planar.h"

class Planar : public QMainWindow
{
    Q_OBJECT

public:
    Planar(QWidget *parent = nullptr);
    ~Planar();

public slots:
    void displaySelected();

private:
    Ui::PlanarClass ui;
};
