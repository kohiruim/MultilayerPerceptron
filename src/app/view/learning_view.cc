#include "learning_view.h"

namespace s21 {
LearningView::LearningView(QWidget *parent, s21::Controller *controller,
                           s21::TestingView *testing_window)
    : QMainWindow(parent),
      ui_(new Ui::LearningView),
      testingWindow_(testing_window),
      controller_(controller) {
  ui_->setupUi(this);

  connect(ui_->randomWeights, SIGNAL(toggled(bool)), this,
          SLOT(onRandomWeightsToggled()));
  connect(ui_->downloadTrain, SIGNAL(clicked()), this,
          SLOT(onDownloadTrainClicked()));
  connect(ui_->downloadLearnWeight, SIGNAL(clicked()), this,
          SLOT(onDownloadWeightClicked()));
  connect(ui_->startTraining, SIGNAL(clicked()), this,
          SLOT(onStartTrainingClicked()));
  connect(ui_->saveWeight, SIGNAL(clicked()), this,
          SLOT(onSaveWeightClicked()));
  connect(ui_->startTesting, SIGNAL(clicked()), this,
          SLOT(onStartTestingClicked()));
  connect(ui_->reset, SIGNAL(clicked()), this, SLOT(onResetClicked()));
}

LearningView::~LearningView() { delete ui_; }

void LearningView::makeActiveMenuButton(QPushButton *button) {
  button->setEnabled(true);
  button->setStyleSheet(
      "QPushButton {background-color: white; color: black; margin: 10px 0; "
      "border-radius: 10px;}"
      "QPushButton:hover {background-color: black; color: white;}");
}

void LearningView::makePassiveMenuButton(QPushButton *button) {
  button->setEnabled(false);
  button->setStyleSheet(
      "background-color: rgba(222, 227, 231, 0.5); color: white; margin: 10px "
      "0; border-radius: 10px;");
}

void LearningView::makePassiveTestButton() {
  ui_->startTesting->setEnabled(false);
  ui_->randomWeights->setEnabled(true);
  ui_->startTesting->setStyleSheet(
      "background-color: rgba(222, 227, 231, 0.5); color: white;"
      "border-radius: 10px;");
}

void LearningView::makeActiveTestButton() {
  ui_->startTesting->setEnabled(true);
  ui_->randomWeights->setEnabled(false);
  ui_->startTesting->setStyleSheet(
      "QPushButton {background-color: rgb(255, 55, 57); color: white; "
      "border-radius: 10px;}"
      "QPushButton:hover {background-color: rgba(255, 55, 57, .5); }");
}

void LearningView::makeEnabledMenu() {
  ui_->matrixMethod->setEnabled(true);
  ui_->graphMethod->setEnabled(true);
  ui_->hiddenLayers->setEnabled(true);
  ui_->countEpochs->setEnabled(true);
  ui_->crossValid->setEnabled(true);
  ui_->countEpochs->setEnabled(true);
  ui_->checkGraph->setEnabled(true);
  ui_->countGroups->setEnabled(true);
  ui_->realization->setEnabled(true);
  ui_->label_2->setEnabled(true);
  ui_->label_3->setEnabled(true);
  ui_->randomWeights->setChecked(true);
}

void LearningView::makeNotEnabledMenu() {
  ui_->matrixMethod->setEnabled(false);
  ui_->graphMethod->setEnabled(false);
  ui_->hiddenLayers->setEnabled(false);
  ui_->countEpochs->setEnabled(false);
  ui_->crossValid->setEnabled(false);
  ui_->countEpochs->setEnabled(false);
  ui_->checkGraph->setEnabled(false);
  ui_->countGroups->setEnabled(false);
  ui_->realization->setEnabled(false);
  ui_->label_2->setEnabled(false);
  ui_->label_3->setEnabled(false);
  ui_->randomWeights->setChecked(false);
}

void LearningView::onRandomWeightsToggled() {
  if (ui_->randomWeights->isChecked()) {
    makeActiveMenuButton(ui_->downloadTrain);
    makePassiveMenuButton(ui_->downloadLearnWeight);
    makePassiveMenuButton(ui_->saveWeight);
    makePassiveMenuButton(ui_->startTraining);
    makeEnabledMenu();
  } else {
    makePassiveMenuButton(ui_->downloadTrain);
    makeActiveMenuButton(ui_->downloadLearnWeight);
    makePassiveMenuButton(ui_->startTraining);
    makePassiveMenuButton(ui_->saveWeight);
    makePassiveTestButton();
    makeNotEnabledMenu();
  }
}

void LearningView::onDownloadTrainClicked() {
  QString fileName =
      QFileDialog::getOpenFileName(this, "Выберете файл", "", "*.csv");
  QMessageBox msgBox;
  bool error = controller_->ParseData(fileName.toStdString());
  if (error) {
    makePassiveMenuButton(ui_->startTraining);
    msgBox.setText("train.csv не загрузился или файл пустой");
    msgBox.exec();
  } else if (!controller_->DataIsEmpty()) {
    makeActiveMenuButton(ui_->startTraining);
    makePassiveMenuButton(ui_->downloadTrain);
  }
}

void LearningView::onDownloadWeightClicked() {
  QMessageBox msgBox;
  QString fileName =
      QFileDialog::getOpenFileName(this, tr("Выберете файл"), "", tr("*.txt"));
  bool error = controller_->ParseWeights(ui_->matrixMethod->isChecked(),
                                         fileName.toStdString());
  if (error) {
    makePassiveTestButton();
    msgBox.setText("веса.txt не загрузились или файл пустой");
    msgBox.exec();
  } else if (!controller_->WeightsIsEmpty()) {
    makeActiveTestButton();
    makePassiveMenuButton(ui_->downloadLearnWeight);
  }
}

void LearningView::onSaveWeightClicked() {
  QMessageBox msgBox;
  QString fileName =
      QFileDialog::getSaveFileName(this, tr("Выберете файл"), "", tr("*.txt"));
  controller_->SaveWeights(fileName.toStdString());
  msgBox.setText("Веса сохранены, проверяй!");
  msgBox.exec();
}

void LearningView::onStartTrainingClicked() {
  makePassiveMenuButton(ui_->startTraining);
  makePassiveMenuButton(ui_->downloadTrain);
  makeActiveMenuButton(ui_->saveWeight);

  int type = ui_->matrixMethod->isChecked();
  if (ui_->randomWeights->isChecked()) {
    controller_->CreateNetwork(type, ui_->hiddenLayers->value(),
                               ui_->randomWeights->isChecked());
  }
  if (ui_->crossValid->isChecked()) {
    training_info_ = controller_->Training(ui_->countEpochs->value(),
                                           ui_->countGroups->value());
  } else {
    training_info_ = controller_->Training(ui_->countEpochs->value(), 0);
  }
  makeActiveTestButton();
  printInfo(training_info_);
  if (ui_->checkGraph->isChecked()) printGraph(training_info_);
}

void LearningView::printInfo(std::vector<Trainer::TrainerInfo> training_info) {
  for (size_t i = 0; i != training_info.size(); ++i) {
    if (training_info.size() > 1)
      ui_->learnInfo->insertPlainText("Epoch " + QString::number(i + 1) + "\n");
    ui_->learnInfo->insertPlainText(
        "Ошибка - " + QString::number(training_info[i].error) + "\n");
    ui_->learnInfo->insertPlainText(
        "Точность - " + QString::number(training_info[i].accuracy) + "\n");
    ui_->learnInfo->insertPlainText(
        "Время - " + QString::number(training_info[i].time) + "\n");
  }
}

void LearningView::printGraph(std::vector<Trainer::TrainerInfo> training_info) {
  ui_->CustomPlot->clearGraphs();
  double x_begin = 0.5;
  double x_end = training_info.size() + 0.5;
  double y_begin = training_info.front().error + 0.1;
  double y_end = training_info.back().error - 0.1;
  ui_->CustomPlot->xAxis->setRange(x_begin, x_end);
  ui_->CustomPlot->yAxis->setRange(y_begin, y_end);
  QVector<double> x{x_begin};
  QVector<double> y{y_begin};
  for (size_t i = 0; i < training_info.size(); ++i) {
    x.push_back(i + 1);
    y.push_back(training_info[i].error);
  }
  ui_->CustomPlot->addGraph();
  ui_->CustomPlot->graph(0)->setPen(QPen(Qt::red, 2));
  ui_->CustomPlot->graph(0)->setData(x, y);
  ui_->CustomPlot->replot();
}

void LearningView::onStartTestingClicked() { testingWindow_->show(); }

void LearningView::onResetClicked() {
  makeEnabledMenu();
  ui_->matrixMethod->setChecked(true);
  ui_->hiddenLayers->setValue(2);
  ui_->countEpochs->setValue(1);
  ui_->countGroups->setValue(2);
  ui_->crossValid->setChecked(false);
  ui_->checkGraph->setChecked(false);
  makeActiveMenuButton(ui_->downloadTrain);
  makePassiveMenuButton(ui_->saveWeight);
  makePassiveMenuButton(ui_->startTraining);
  makePassiveMenuButton(ui_->downloadLearnWeight);
  makePassiveTestButton();
  controller_->Clear();
  ui_->CustomPlot->clearGraphs();
  ui_->CustomPlot->replot();
  ui_->learnInfo->clear();
  if (testingWindow_->isVisible()) testingWindow_->hide();
}

}  // namespace s21
