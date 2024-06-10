#include "paintscene.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent) {}
PaintScene::~PaintScene() {}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  addEllipse(event->scenePos().x() - 5, event->scenePos().y() - 5, 20, 20,
             QPen(Qt::NoPen), QBrush(Qt::white));
  // Сохраняем координаты точки нажатия
  previousPoint = event->scenePos();
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  // Отрисовываем линии с использованием предыдущей координаты
  addLine(previousPoint.x(), previousPoint.y(), event->scenePos().x(),
          event->scenePos().y(),
          QPen(Qt::white, 20, Qt::SolidLine, Qt::RoundCap));
  // Обновляем данные о предыдущей координате
  previousPoint = event->scenePos();
}
