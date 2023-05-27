/********************************************************************************
** Form generated from reading UI file 'paint.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINT_H
#define UI_PAINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Paint
{
public:
    QAction *actionClose;
    QAction *actionCreate_new_file;
    QAction *actionOpen_file;
    QAction *actionSave;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QComboBox *m_comboBox_Tools;
    QComboBox *m_comboBox_Width;
    QComboBox *m_comboBox_Figures;
    QPushButton *m_pB_ColorPalette;
    QPushButton *m_pB_Color1;
    QLineEdit *m_TextToolLineEdit;
    QPushButton *m_pB_plus;
    QPushButton *m_pB_Color2;
    QPushButton *m_pB_minus;
    QLabel *m_label_CurrentTool;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Paint)
    {
        if (Paint->objectName().isEmpty())
            Paint->setObjectName("Paint");
        Paint->resize(800, 600);
        actionClose = new QAction(Paint);
        actionClose->setObjectName("actionClose");
        actionCreate_new_file = new QAction(Paint);
        actionCreate_new_file->setObjectName("actionCreate_new_file");
        actionOpen_file = new QAction(Paint);
        actionOpen_file->setObjectName("actionOpen_file");
        actionSave = new QAction(Paint);
        actionSave->setObjectName("actionSave");
        centralwidget = new QWidget(Paint);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(0, 90));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName("gridLayout");
        m_comboBox_Tools = new QComboBox(frame);
        m_comboBox_Tools->addItem(QString());
        m_comboBox_Tools->addItem(QString());
        m_comboBox_Tools->addItem(QString());
        m_comboBox_Tools->addItem(QString());
        m_comboBox_Tools->setObjectName("m_comboBox_Tools");

        gridLayout->addWidget(m_comboBox_Tools, 1, 0, 1, 1);

        m_comboBox_Width = new QComboBox(frame);
        m_comboBox_Width->addItem(QString());
        m_comboBox_Width->addItem(QString());
        m_comboBox_Width->addItem(QString());
        m_comboBox_Width->addItem(QString());
        m_comboBox_Width->setObjectName("m_comboBox_Width");

        gridLayout->addWidget(m_comboBox_Width, 1, 1, 1, 1);

        m_comboBox_Figures = new QComboBox(frame);
        m_comboBox_Figures->addItem(QString());
        m_comboBox_Figures->addItem(QString());
        m_comboBox_Figures->addItem(QString());
        m_comboBox_Figures->addItem(QString());
        m_comboBox_Figures->addItem(QString());
        m_comboBox_Figures->setObjectName("m_comboBox_Figures");

        gridLayout->addWidget(m_comboBox_Figures, 3, 1, 1, 1);

        m_pB_ColorPalette = new QPushButton(frame);
        m_pB_ColorPalette->setObjectName("m_pB_ColorPalette");

        gridLayout->addWidget(m_pB_ColorPalette, 3, 5, 1, 1);

        m_pB_Color1 = new QPushButton(frame);
        m_pB_Color1->setObjectName("m_pB_Color1");

        gridLayout->addWidget(m_pB_Color1, 1, 4, 1, 1);

        m_TextToolLineEdit = new QLineEdit(frame);
        m_TextToolLineEdit->setObjectName("m_TextToolLineEdit");
        m_TextToolLineEdit->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(m_TextToolLineEdit, 3, 0, 1, 1);

        m_pB_plus = new QPushButton(frame);
        m_pB_plus->setObjectName("m_pB_plus");

        gridLayout->addWidget(m_pB_plus, 1, 2, 1, 1);

        m_pB_Color2 = new QPushButton(frame);
        m_pB_Color2->setObjectName("m_pB_Color2");

        gridLayout->addWidget(m_pB_Color2, 1, 5, 1, 1);

        m_pB_minus = new QPushButton(frame);
        m_pB_minus->setObjectName("m_pB_minus");

        gridLayout->addWidget(m_pB_minus, 1, 3, 1, 1);

        m_label_CurrentTool = new QLabel(frame);
        m_label_CurrentTool->setObjectName("m_label_CurrentTool");
        QFont font;
        font.setBold(true);
        m_label_CurrentTool->setFont(font);
        m_label_CurrentTool->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(m_label_CurrentTool, 3, 2, 1, 2);


        verticalLayout->addWidget(frame);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        verticalLayout->addWidget(graphicsView);

        Paint->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Paint);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        Paint->setMenuBar(menubar);
        statusbar = new QStatusBar(Paint);
        statusbar->setObjectName("statusbar");
        Paint->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionClose);
        menuMenu->addAction(actionCreate_new_file);
        menuMenu->addAction(actionOpen_file);
        menuMenu->addAction(actionSave);

        retranslateUi(Paint);

        QMetaObject::connectSlotsByName(Paint);
    } // setupUi

    void retranslateUi(QMainWindow *Paint)
    {
        Paint->setWindowTitle(QCoreApplication::translate("Paint", "Paint", nullptr));
        actionClose->setText(QCoreApplication::translate("Paint", "Close", nullptr));
        actionCreate_new_file->setText(QCoreApplication::translate("Paint", "Create new file", nullptr));
        actionOpen_file->setText(QCoreApplication::translate("Paint", "Open file", nullptr));
        actionSave->setText(QCoreApplication::translate("Paint", "Save", nullptr));
        m_comboBox_Tools->setItemText(0, QCoreApplication::translate("Paint", "Pencil", nullptr));
        m_comboBox_Tools->setItemText(1, QCoreApplication::translate("Paint", "Brush", nullptr));
        m_comboBox_Tools->setItemText(2, QCoreApplication::translate("Paint", "Text", nullptr));
        m_comboBox_Tools->setItemText(3, QCoreApplication::translate("Paint", "Eraser", nullptr));

        m_comboBox_Width->setItemText(0, QCoreApplication::translate("Paint", "4 px", nullptr));
        m_comboBox_Width->setItemText(1, QCoreApplication::translate("Paint", "8 px", nullptr));
        m_comboBox_Width->setItemText(2, QCoreApplication::translate("Paint", "16 px", nullptr));
        m_comboBox_Width->setItemText(3, QCoreApplication::translate("Paint", "32 px", nullptr));

        m_comboBox_Figures->setItemText(0, QCoreApplication::translate("Paint", "Line", nullptr));
        m_comboBox_Figures->setItemText(1, QCoreApplication::translate("Paint", "Curve", nullptr));
        m_comboBox_Figures->setItemText(2, QCoreApplication::translate("Paint", "Ellipsoid", nullptr));
        m_comboBox_Figures->setItemText(3, QCoreApplication::translate("Paint", "Square", nullptr));
        m_comboBox_Figures->setItemText(4, QCoreApplication::translate("Paint", "Polygon", nullptr));

        m_pB_ColorPalette->setText(QCoreApplication::translate("Paint", "Palette", nullptr));
        m_pB_Color1->setText(QString());
        m_pB_plus->setText(QCoreApplication::translate("Paint", "\320\237\321\200\320\270\320\261\320\273\320\270\320\267\320\270\321\202\321\214", nullptr));
        m_pB_Color2->setText(QString());
        m_pB_minus->setText(QCoreApplication::translate("Paint", "\320\236\321\202\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        m_label_CurrentTool->setText(QCoreApplication::translate("Paint", "TextLabel", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("Paint", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Paint: public Ui_Paint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINT_H
