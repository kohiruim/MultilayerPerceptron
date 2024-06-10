#ifndef CPP7_MLP_SRC_VIEW_TESTINGVIEW_H_
#define CPP7_MLP_SRC_VIEW_TESTINGVIEW_H_

#include <QFileDialog>
#include <QMessageBox>
#include <QWidget>

#include "../controller/controller.h"
#include "paintscene.h"

namespace Ui {
class TestingView;
}

namespace s21 {
class TestingView : public QWidget {
  Q_OBJECT

 public:
  explicit TestingView(QWidget *parent = nullptr,
                       s21::Controller *controller = nullptr);
  ~TestingView();

 private slots:
  void onDownloadTestClicked();
  void onStartTestClicked();
  void onCleanPaintClicked();
  void onDownloadImgClicked();
  void onStartTestIMGClicked();
  void onResetClicked();
  void onExperimentClicked();

 private:
  Ui::TestingView *ui_;
  s21::Controller *controller_;
  PaintScene *scene_;
  std::vector<float> WeightIMG(const QImage &img);
  void makeActiveButton(QPushButton *button);
  void makePassiveButton(QPushButton *button);
  void setDefaultValue();
};
}  // namespace s21

#endif  // CPP7_MLP_SRC_VIEW_TESTINGVIEW_H_
