#include "paint.h"
#include "ui_paint.h"

Paint::Paint(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Paint)
{
    ui->setupUi(this);

    paintScene = new PaintScene();
    ui->graphicsView->setScene(paintScene);
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Paint::slotTimer);
    timer->start(100);

    // Первичная настройка цветов
    ui->m_pB_Color2->setStyleSheet("background-color:rgb(253, 253, 253); border-style:inset; border-width: 2px;");
    ui->m_pB_Color1->setStyleSheet("background-color:rgb(27, 27, 27); border-style:inset; border-width: 2px;");
    Color1Style = ui->m_pB_Color1->styleSheet();
    Color2Style = ui->m_pB_Color2->styleSheet();
    ui->m_pB_Color1->setStyleSheet(Color1Style + "border-color: blue; outset;border-width: 5px;");
    ActiveColor = 1;

    // Первичная настройка сцены
    paintScene->setIsFigure(false);
    paintScene->changeTool((Tools)0);
    paintScene->changeToolSize(0);
    ui->m_label_CurrentTool->setText("Инструмент: карандаш");
    ui->m_TextToolLineEdit->setVisible(false);
    QRect rectScene(0,0,1024,1024);
    paintScene->setSceneRect(rectScene);
    ui->graphicsView->setMaximumSize(paintScene->width(),paintScene->height());
}

Paint::~Paint()
{   delete ui->m_comboBox_Tools->view();
    delete ui->m_comboBox_Figures->view();
    delete ui->m_comboBox_Width->view();
    delete own_palette;
    delete paintScene;
    delete timer;
    delete ui;
}

// Выбор цвета
void Paint::on_m_pB_Color1_clicked()
{
    ui->m_pB_Color2->setStyleSheet(Color2Style+"border-color: white;");
    ui->m_pB_Color1->setStyleSheet(Color1Style+"border-color: blue; outset;border-width: 5px;");
    paintScene->changeToolColor(mainColor);
    ActiveColor = 1;
}

void Paint::on_m_pB_Color2_clicked()
{
    ui->m_pB_Color2->setStyleSheet(Color2Style+"border-color: blue; outset;border-width: 5px;");
    ui->m_pB_Color1->setStyleSheet(Color1Style+"border-color: white;");
    paintScene->changeToolColor(secondaryColor);
    ActiveColor = 2;
}

// Палитра
void Paint::on_m_pB_ColorPalette_clicked()
{
    own_palette = new QColorDialog();
    own_palette->setCurrentColor(QColor(0,0,255));
    own_palette->exec();
    if (ActiveColor == 1)
    {
        Color1Style = "background-color:" + own_palette->selectedColor().name() + "; border-style:inset; border-width: 2px;";
        ui->m_pB_Color1->setStyleSheet(Color1Style + "border-color: blue; outset;border-width: 5px;");
        mainColor = own_palette->selectedColor();
        paintScene->changeToolColor(mainColor);
    }
    else
    {
        Color2Style = "background-color:" + own_palette->selectedColor().name() + "; border-style:inset; border-width: 2px;";
        ui->m_pB_Color2->setStyleSheet(Color2Style + "border-color: blue; outset;border-width: 5px;");
        secondaryColor = own_palette->selectedColor();
        paintScene->changeToolColor(secondaryColor);
    }
}

// Выбор размера кисти/фигуры
void Paint::on_m_comboBox_Width_currentIndexChanged(int index)
{
    ui->m_TextToolLineEdit->setVisible(false);
    paintScene->changeToolSize(index);
}

// Выбор инструмента
void Paint::on_m_comboBox_Tools_activated(int index)
{
    paintScene->setIsFigure(false);
    paintScene->changeTool((Tools)index);
    ui->m_TextToolLineEdit->setVisible(false);
    switch(index)
    {
    case(0):
    {
        ui->m_label_CurrentTool->setText("Инструмент: карандаш");
        break;
    }
    case(1):
    {
        ui->m_label_CurrentTool->setText("Инструмент: кисть");
        break;
    }
    case(2):
    {
        ui->m_label_CurrentTool->setText("Инструмент: текст");
        ui->m_TextToolLineEdit->setVisible(true);
        break;
    }
    case(3):
    {
        ui->m_label_CurrentTool->setText("Инструмент: ластик");
        break;
    }

    }
}

// Выбор фигуры
void Paint::on_m_comboBox_Figures_activated(int index)
{
    paintScene->setIsFigure(true);
    paintScene->changeFigure((Figures)index);
    ui->m_TextToolLineEdit->setVisible(false);
    switch(index)
    {
    case(0):
    {
        ui->m_label_CurrentTool->setText("Инструмент: линия");
        break;
    }
    case(1):
    {
        ui->m_label_CurrentTool->setText("Инструмент: кривая (Используйте ПКМ чтобы завершить рисование)");
        break;
    }
    case(2):
    {
        ui->m_label_CurrentTool->setText("Инструмент: эллипс");
        break;
    }
    case(3):
    {
        ui->m_label_CurrentTool->setText("Инструмент: квадрат");
        break;
    }
    case(4):
    {
        ui->m_label_CurrentTool->setText("Инструмент: многоугольник (Используйте ПКМ чтобы завершить рисование)");
        break;
    }
    }
}

// Изменение размера инструментов
void Paint::on_m_comboBox_Width_activated(int index)
{
    ui->m_TextToolLineEdit->setVisible(false);
    paintScene->changeToolSize(index);
}

// Таймер
void Paint::slotTimer()
{
    timer->stop();
    paintScene->setSceneRect(0,0, ui->graphicsView->width() + 200 , ui->graphicsView->height() + 200 );
}

// Изменение текста для инструмента текст
void Paint::on_m_TextToolLineEdit_textChanged(const QString &arg1)
{
    paintScene->changeTextTool(ui->m_TextToolLineEdit->text());
}

// Приближение
void Paint::on_m_pB_minus_clicked()
{
    ui->graphicsView->scale(0.8,0.8);
}

// Отдаление
void Paint::on_m_pB_plus_clicked()
{
    ui->graphicsView->scale(1.25,1.25);
}

// Сохранение
void Paint::on_actionSave_triggered()
{
    QString savingPath = QFileDialog::getSaveFileName(0, "Save File", "", "*.png *.jpg *.jpeg");
    QPixmap image = ui->graphicsView->grab();
    image.save(savingPath);
}

// Загрузка
void Paint::on_actionOpen_file_triggered()
{
    QString pathToPic = QFileDialog::getOpenFileName(0, "Open File", "", "*.png *.jpg *.jpeg");
    QPixmap picture(pathToPic);

    if(( picture.size().rheight() > ui->graphicsView->size().rheight() ) || ( picture.size().rwidth() > ui->graphicsView->size().rwidth() ))
    {
        QSize pixSize = picture.size();
        pixSize.scale(ui->graphicsView->size(), Qt::KeepAspectRatio);
        QPixmap scaledPic = picture.scaled(pixSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        paintScene->addPixmap(scaledPic);
    }
    else
    {  paintScene->addPixmap(picture);
    }
}

// Изменение размера рабочей области
void Paint::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
    ui->graphicsView->fitInView(paintScene->sceneRect());
}

void Paint::resizeWorkspace()
{
    ResizeWindow* pSizeDialog = new ResizeWindow;
    pSizeDialog->setWindowIcon(QIcon(":res/res/paint-palette"));
    pSizeDialog->setWindowTitle("Size dialog");
    pSizeDialog->setStyleSheet(" color: rgb(245, 238, 255);");
    if(pSizeDialog->exec() == QDialog::Accepted)
    {
        QString new_width = pSizeDialog->width();
        QString new_height = pSizeDialog->height();
        ui->graphicsView->scene()->clear();
        ui->graphicsView->resize(new_width.toInt(), new_height.toInt());
        QRect rectScene = ui->graphicsView->rect();
        rectScene.setHeight(rectScene.height()-20);
        rectScene.setWidth(rectScene.width()-20);
        ui->graphicsView->scene()->setSceneRect(rectScene);
    }
    delete pSizeDialog;
}

// Новый файл
void Paint::on_actionCreate_new_file_triggered()
{
    resizeWorkspace();
}

