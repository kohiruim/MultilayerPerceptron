#ifndef CPP7_MLP_SRC_VIEW_LEARNINGVIEW_H_
#define CPP7_MLP_SRC_VIEW_LEARNINGVIEW_H_

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>

#include "../controller/controller.h"
#include "testing_view.h"
#include "ui_learning_view.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LearningView;
}
QT_END_NAMESPACE

namespace s21 {
class LearningView : public QMainWindow {
  Q_OBJECT
 public:
  LearningView(QWidget *parent = nullptr, s21::Controller *controller = nullptr,
               s21::TestingView *testing_window = nullptr);
  ~LearningView();
 private slots:
  void onRandomWeightsToggled();
  void onDownloadTrainClicked();
  void onDownloadWeightClicked();
  void onSaveWeightClicked();
  void onStartTrainingClicked();
  void onStartTestingClicked();
  void onResetClicked();

 private:
  Ui::LearningView *ui_;
  TestingView *testingWindow_;
  Controller *controller_;
  std::vector<Trainer::TrainerInfo> training_info_ = {};
  void printInfo(std::vector<Trainer::TrainerInfo> training_info);
  void printGraph(std::vector<Trainer::TrainerInfo> training_info);
  void makeActiveMenuButton(QPushButton *button);
  void makePassiveMenuButton(QPushButton *button);
  void makePassiveTestButton();
  void makeActiveTestButton();
  void makeEnabledMenu();
  void makeNotEnabledMenu();
};
}  // namespace s21

#endif  // CPP7_MLP_SRC_VIEW_LEARNINGVIEW_H_
