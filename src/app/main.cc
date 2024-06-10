#include <QApplication>

#include "view/learning_view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  s21::ModelFacade model;
  s21::Controller controller(&model);
  s21::TestingView testing_window(nullptr, &controller);
  s21::LearningView w(nullptr, &controller, &testing_window);
  w.show();
  return a.exec();
}
