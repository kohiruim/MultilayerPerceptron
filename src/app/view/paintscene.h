#ifndef CPP7_MLP_SRC_VIEW_PAINTSCENE_H_
#define CPP7_MLP_SRC_VIEW_PAINTSCENE_H_

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>

class PaintScene : public QGraphicsScene {
  Q_OBJECT
 public:
  explicit PaintScene(QObject *parent = 0);
  ~PaintScene();

 private:
  QPointF previousPoint;  // Координаты предыдущей точки
  // события мыши для рисования
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif  // CPP7_MLP_SRC_VIEW_PAINTSCENE_H_
