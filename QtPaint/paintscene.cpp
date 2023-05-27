#include "paintscene.h"

PaintScene::PaintScene(QObject *parent)
    : QGraphicsScene{parent}
{
    processingText=new QGraphicsTextItem();
    processingFigure=nullptr;
    processingFigure = addEllipse(0,0,0,0);
    setBackgroundBrush(QColor(253,253,253));
}

PaintScene::~PaintScene()
{
    delete processingText;
    delete processingFigure;
    clear();
}

// Смена цвета кисти/фигур
void PaintScene::changeToolColor (QColor color)
{
    currentColor = color;
}

// Смена размера кисти/фигур
void PaintScene::changeToolSize (int size)
{
    switch(size)
    {
    case 0:
    {
        brushSize = 4;
        break;
    }
    case 1:
    {
        brushSize = 8;
        break;
    }
    case 2:
    {
        brushSize = 16;
        break;
    }
    case 3:
    {
        brushSize = 32;
        break;
    }
    }
}

// Смена активного инструмента
void PaintScene::changeTool (Tools tool)
{
    isFigure = false;
    switch (tool)
    {
    case(0):
    {
        currentTool = Tools::Pencil;
        break;
    }
    case(1):
    {
        currentTool = Tools::Brush;
        break;
    }
    case(2):
    {
        currentTool = Tools::Text;
        break;
    }
    case(3):
    {
        currentTool = Tools::Eraser;
        break;
    }
    }
}

// Смена активной фигуры
void PaintScene::changeFigure (Figures figure)
{
    switch (figure)
    {
    case(0):
    {
        currentFigure = Figures::Line;
        break;
    }
    case(1):
    {
        currentFigure = Figures::Curve;
        break;
    }
    case(2):
    {
        currentFigure = Figures::Ellipsoid;
        break;
    }
    case(3):
    {   currentFigure = Figures::Square;
        break;
    }
    case(4):
    {   currentFigure = Figures::Polygon;
        break;
    }
    }
}

// Флаг о смене фигуры/остальных инструментов
void PaintScene::setIsFigure(bool flag)
{
    isFigure = flag;
}

// Смена текста для инструмента текст
void PaintScene::changeTextTool (QString text)
{
    currentText = text;
}

// Рисование по нажатию мыши
void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    // Вычисление смещения точки относительно центра
    int offset = 0;
    switch(brushSize)
    {
    case(4):
    {
        offset = 2;
        break;
    }
    case(8):
    {
        offset = 4;
        break;
    }
    case(16):
    {
        offset = 8;
        break;
    }
    case(32):
    {
        offset = 16;
        break;
    }
    }

    if (event->button() == Qt::MouseButton::LeftButton)
    {
        // Рисование обычными инструментами
        if (!isFigure)
        {
            switch(currentTool)
            {
            case Pencil:
            {
                addEllipse(event->scenePos().x(),
                           event->scenePos().y(),
                           2,
                           2,
                           QPen(Qt::NoPen),
                           QBrush(currentColor));
                currentPoint = event->scenePos();
                break;
            }

            case Brush:
            {
                addEllipse(event->scenePos().x() - offset,
                           event->scenePos().y() - offset,
                           brushSize,
                           brushSize,
                           QPen(Qt::NoPen),
                           QBrush(currentColor));
                currentPoint = event->scenePos();
                break;
            }

            case Eraser:
            {
                addEllipse(event->scenePos().x() - offset,
                           event->scenePos().y() - offset,
                           brushSize,
                           brushSize,
                           QPen(Qt::NoPen),
                           QBrush(QBrush(QColor(253,253,253))));
                currentPoint = event->scenePos();
                break;
            }

            case Text:
            {
                processingText->setHtml(currentText);
                processingText->setPos(event->scenePos().x(),event->scenePos().y());
                addItem(processingText);
                processingText = new QGraphicsTextItem();
                break;
            }

            default:
                break;
            }
        }
        // Рисование фигур
        else
        {
            switch(currentFigure)
            {

            case Line:
            {
                if (!isDrawing)
                {
                    isDrawing = true;
                    currentPoint = event->scenePos();
                }
                break;
            }

            case Curve:
            {
                if (!isDrawing)
                {
                    isDrawing = true;
                    currentPoint = event->scenePos();
                }
                break;
            }

            case Ellipsoid:
            {
                if (!isDrawing)
                {
                    isDrawing = true;
                    startingPoint = event->scenePos();
                }
                break;
            }

            case Square:
            {
                if (!isDrawing)
                {
                    isDrawing = true;
                    startingPoint = event->scenePos();
                }
                break;
            }

            case Polygon:
            {
                if (!isDrawing)
                {
                    if (isPolygon)
                    {
                        startingPoint = event->scenePos();
                        isPolygon = false;
                        currentPoint = event->scenePos();
                    }
                    isDrawing = true;
                }
                break;
            }
            }
        }}
    // Нажата ПКМ, прекращение рисования линии, ломаной, многоугольника
    else
    {
        switch(currentFigure)
        {
        case Line:
        {
            if (isDrawing)
            {
                isDrawing = false;
                removeItem(processingFigure);
                delete processingFigure;
                processingFigure = nullptr;
                currentPoint=event->scenePos();
            }
            break;
        }
        case Curve:
        {
            if (isDrawing)
            {
                isDrawing = false;
                removeItem(processingFigure);
                delete processingFigure;
                processingFigure = nullptr;
                currentPoint=event->scenePos();
            }
            break;
        }
        case Polygon:
        {
            if (isDrawing)
            {
                isDrawing = false;
                addLine(currentPoint.x(),
                        currentPoint.y(),
                        startingPoint.x(),
                        startingPoint.y(),
                        QPen(currentColor,
                             brushSize,
                             Qt::SolidLine,
                             Qt::RoundCap,
                             Qt::RoundJoin));

                processingFigure = nullptr;
                isPolygon = true;
                break;
            }
        }
        default:
            break;
        }
    }
}


// Рисование по движению мыши
void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    // Рисование обычной кистью
    if (!isFigure)
    {
        switch (currentTool)
        {

        case Pencil:
        {
            addLine(currentPoint.x(),
                    currentPoint.y(),
                    event->scenePos().x(),
                    event->scenePos().y(),
                    QPen(currentColor,
                         2,
                         Qt::SolidLine,
                         Qt::RoundCap,
                         Qt::MiterJoin)
                    );
            currentPoint = event->scenePos();
            break;
        }

        case Brush:
        {
            addLine(currentPoint.x(),
                    currentPoint.y(),
                    event->scenePos().x(),
                    event->scenePos().y(),
                    QPen(currentColor,
                         brushSize,
                         Qt::SolidLine,
                         Qt::RoundCap,
                         Qt::RoundJoin)
                    );
            currentPoint = event->scenePos();
            break;
        }

        case Eraser:
        {
            addLine(currentPoint.x(),
                    currentPoint.y(),
                    event->scenePos().x(),
                    event->scenePos().y(),
                    QPen(QBrush(QColor(253,253,253)),
                         brushSize,
                         Qt::SolidLine,
                         Qt::RoundCap,
                         Qt::MiterJoin)
                    );
            currentPoint = event->scenePos();
            break;
        }

        default:
            break;
        }
    }
    // Рисование фигур
    else
    {
        if(processingFigure != nullptr)
        {
            removeItem(processingFigure);
        }

        switch(currentFigure)
        {

        case Line:
        {
            processingFigure = (QGraphicsItem*)(addLine(currentPoint.x(),
                                                       currentPoint.y(),
                                                       event->scenePos().x(),
                                                       event->scenePos().y(),
                                                       QPen(currentColor,brushSize,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin)));
            break;
        }

        case Curve:
        {
            processingFigure = (QGraphicsItem*)(addLine(currentPoint.x(),
                                                       currentPoint.y(),
                                                       event->scenePos().x(),
                                                       event->scenePos().y(),
                                                       QPen(currentColor,brushSize,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin)));
            currentCurvePoint = event->scenePos();
            break;
        }

        case Ellipsoid:
        {
            QPointF temp;
            temp.setY(qMin(event->scenePos().y(), startingPoint.y() ));
            temp.setX(qMin(startingPoint.x(), event->scenePos().x() ));
            QPointF tempMin;
            tempMin.setY(qMax(event->scenePos().y(), startingPoint.y() ));
            tempMin.setX(qMax(startingPoint.x(), event->scenePos().x() ));
            processingFigure = (QGraphicsItem*)addEllipse(QRectF(temp, tempMin), QPen(currentColor,brushSize,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
            break;
        }

        case Square:
        {
            QPointF temp;
            temp.setY(qMin(event->scenePos().y(), startingPoint.y() ));
            temp.setX(qMin(startingPoint.x(), event->scenePos().x() ));
            QPointF tempMin;
            tempMin.setY(qMax(event->scenePos().y(), startingPoint.y() ));
            tempMin.setX(qMax(startingPoint.x(), event->scenePos().x() ));
            processingFigure = (QGraphicsItem*)addRect(QRectF(temp, tempMin), QPen(currentColor,brushSize,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
            break;
        }

        case Polygon:
        {
            processingFigure = (QGraphicsItem*)(addLine(currentPoint.x(),
                                                       currentPoint.y(),
                                                       event->scenePos().x(),
                                                       event->scenePos().y(),
                                                       QPen(currentColor,brushSize,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin)));
            currentCurvePoint = event->scenePos();
            break;
        }
        default:
            break;
        }

    }
}

// Прекращение рисования
void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    if(event->button() != Qt::MouseButton::LeftButton) return;
    switch(currentFigure)
    {
    case Line:
    {
        if (isDrawing)
        {
            isDrawing = false;
            processingFigure = addEllipse(0,0,0,0);
        }
        break;
    }

    case Curve:
    {
        if (isDrawing)
        {
            currentPoint = currentCurvePoint;
            processingFigure = addEllipse(0,0,0,0);
        }
        break;
    }

    case Ellipsoid:
    {
        if (isDrawing)
        {
            processingFigure = addEllipse(0,0,0,0);
            isDrawing = false;
        }
        break;
    }

    case Square:
    {
        if (isDrawing)
        {
            processingFigure = addEllipse(0,0,0,0);
            isDrawing = false;
        }
        break;
    }

    case Polygon:
    {
        if (isDrawing)
        {
            currentPoint = currentCurvePoint;
            processingFigure = addEllipse(0,0,0,0);
            break;
        }
        break;
    }
    }
}



