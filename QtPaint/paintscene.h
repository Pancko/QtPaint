#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

enum Tools {Pencil, Brush, Text, Eraser};
enum Figures {Line, Curve, Ellipsoid, Square, Polygon};

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PaintScene(QObject *parent = nullptr);

    ~PaintScene();
public:

    void changeToolColor (QColor color);
    void changeToolSize  (int size);
    void changeTextTool  (QString text);
    void changeTool      (Tools tool);
    void changeFigure    (Figures figure);
    void setIsFigure     (bool flag);

private:
    QPointF currentPoint;
    QPointF currentCurvePoint;
    QPointF startingPoint;
    QGraphicsItem* processingFigure;
    QGraphicsTextItem* processingText;

    QColor  currentColor;
    Tools   currentTool;
    Figures currentFigure;
    QString currentText;
    int     brushSize = 1;
    bool    isFigure  = false;
    bool    isDrawing = false;
    bool    isPolygon = true;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // PAINTSCENE_H
