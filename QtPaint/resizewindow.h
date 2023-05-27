#ifndef RESIZEWINDOW_H
#define RESIZEWINDOW_H

#include <QString>
#include <QDialog>
#include <QWidget>
#include <QLineEdit>

class ResizeWindow : public QDialog
{
public:
    ResizeWindow();
    QString height() const;
    QString width() const ;

private:
    QLineEdit* setHeight;
    QLineEdit* setWidth;
};

#endif // RESIZEWINDOW_H
