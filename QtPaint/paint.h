#ifndef PAINT_H
#define PAINT_H

#include <QMainWindow>
#include <QListView>
#include <QGraphicsScene>
#include <QMenu>
#include <QColor>
#include <QString>
#include <QRgb>
#include <QColorDialog>
#include <QImage>
#include <QTimer>
#include <QRectF>
#include <QResizeEvent>
#include <QScrollBar>
#include <QSize>
#include <QPainter>
#include <QFileDialog>
#include "paintscene.h"
#include "resizewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Paint; }
QT_END_NAMESPACE

class Paint : public QMainWindow
{
    Q_OBJECT

public:
    Paint(QWidget *parent = nullptr);
    ~Paint();

private:
    Ui::Paint *ui;
private slots:

    void on_m_pB_Color1_clicked();

    void on_m_pB_Color2_clicked();

    void on_m_pB_ColorPalette_clicked();

    void on_m_comboBox_Width_currentIndexChanged(int index);

    void on_m_comboBox_Tools_activated(int index);

    void on_m_comboBox_Figures_activated(int index);

    void on_m_comboBox_Width_activated(int index);

    void slotTimer();

    void on_m_TextToolLineEdit_textChanged(const QString &arg1);

    void on_m_pB_minus_clicked();

    void on_m_pB_plus_clicked();

    void on_actionSave_triggered();

    void on_actionOpen_file_triggered();

    void on_actionCreate_new_file_triggered();



private:
    QColorDialog *own_palette;
    //

    QString Color1Style;
    QString Color2Style;
    QColor mainColor;
    QColor secondaryColor;
    int ActiveColor;
    PaintScene* paintScene;
    QTimer* timer;
    void resizeEvent(QResizeEvent * event);
    void resizeWorkspace();
};
#endif // PAINT_H
