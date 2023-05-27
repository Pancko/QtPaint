#include "resizewindow.h"
#include <QtWidgets>
#include <QRegularExpressionValidator>

ResizeWindow::ResizeWindow()
{
    this->setStyleSheet("background-color: rgb(245, 238, 255);");

    setHeight= new QLineEdit;
    setWidth = new QLineEdit;

    setHeight->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{4}")));
    setWidth->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{4}")));

    QLabel* plblHeight = new QLabel("&Height");
    QLabel* plblWidth = new QLabel("&Width");

    plblHeight ->setBuddy(setHeight);
    plblWidth ->setBuddy(setWidth);

    QPushButton* pcmdOk = new QPushButton("&Ok");
    QPushButton* pcmdCancel = new QPushButton("&Cancel");

    connect(pcmdOk, SIGNAL(clicked()), this, SLOT(accept()));
    connect(pcmdCancel, SIGNAL(clicked()),this,  SLOT(reject()));

    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(plblWidth, 0, 0);
    ptopLayout->addWidget(plblHeight, 1, 0);
    ptopLayout->addWidget(setWidth, 0, 1);
    ptopLayout->addWidget(setHeight, 1, 1);
    ptopLayout->addWidget(pcmdOk, 2, 0);
    ptopLayout->addWidget(pcmdCancel, 2, 1);
    setLayout(ptopLayout);
}

QString ResizeWindow::height() const
{
    return setHeight->text();
}

QString ResizeWindow::width() const
{
    return setWidth->text();
}
