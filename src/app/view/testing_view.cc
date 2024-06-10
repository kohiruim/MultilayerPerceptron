#include "testing_view.h"

#include "ui_testing_view.h"

namespace s21 {
TestingView::TestingView(QWidget *parent, s21::Controller *controller)
    : QWidget(parent), ui_(new Ui::TestingView), controller_(controller) {
  ui_->setupUi(this);
  connect(ui_->downloadTest, SIGNAL(clicked()), this,
          SLOT(onDownloadTestClicked()));
  connect(ui_->startTest, SIGNAL(clicked()), this, SLOT(onStartTestClicked()));
  connect(ui_->cleanPaint, SIGNAL(clicked()), this,
          SLOT(onCleanPaintClicked()));
  connect(ui_->downloadImg, SIGNAL(clicked()), this,
          SLOT(onDownloadImgClicked()));
  connect(ui_->startTestIMG, SIGNAL(clicked()), this,
          SLOT(onStartTestIMGClicked()));
  connect(ui_->reset, SIGNAL(clicked()), this, SLOT(onResetClicked()));
  connect(ui_->experiment, SIGNAL(clicked()), this,
          SLOT(onExperimentClicked()));
  scene_ = new PaintScene();  // Инициализируем графическую сцену
  ui_->paint->setScene(scene_);  // Устанавливаем графическую сцену
  scene_->setSceneRect(0, 0, 200, 200);
  onResetClicked();
}

TestingView::~TestingView() {
  delete ui_;
  delete scene_;
}

void TestingView::makeActiveButton(QPushButton *button) {
  button->setEnabled(true);
  button->setStyleSheet(
      "QPushButton {background-color: white; color: black; margin: 10px 0 0 0; "
      "border-radius: 10px;}"
      "QPushButton:hover {background-color: black; color: black;}");
}

void TestingView::makePassiveButton(QPushButton *button) {
  button->setEnabled(false);
  button->setStyleSheet(
      "background-color: rgba(222, 227, 231, 0.5); color: white; margin: 10px "
      "0; border-radius: 10px;");
}

void TestingView::setDefaultValue() {
  ui_->valueAccuracy->setText("0.00");
  ui_->valuePrecision->setText("0.00");
  ui_->valueRecall->setText("0.00");
  ui_->valueFMeasure->setText("0.00");
  ui_->valueTime->setText("0.00");
}

void TestingView::onDownloadTestClicked() {
  QString fileName =
      QFileDialog::getOpenFileName(this, "Выберете файл", "", "*.csv");
  QMessageBox msgBox;
  bool error = controller_->ParseData(fileName.toStdString());
  if (error) {
    makePassiveButton(ui_->startTest);
    msgBox.setText("test.csv не загрузился");
    msgBox.exec();
  } else if (!controller_->DataIsEmpty()) {
    makeActiveButton(ui_->startTest);
    makeActiveButton(ui_->experiment);
  }
}

void TestingView::onStartTestClicked() {
  makePassiveButton(ui_->downloadTest);
  setDefaultValue();
  Tester::TestingInfo info = controller_->Testing(ui_->partTest->value());
  ui_->valueAccuracy->setText(QString::number(info.accuracy));
  ui_->valuePrecision->setText(QString::number(info.precision));
  ui_->valueRecall->setText(QString::number(info.recall));
  ui_->valueFMeasure->setText(QString::number(info.f_measure));
  ui_->valueTime->setText(QString::number(info.time));
}

void TestingView::onCleanPaintClicked() {
  ui_->result->clear();
  scene_->clear();
}

void TestingView::onDownloadImgClicked() {
  QMessageBox msgBox;
  QString fileName =
      QFileDialog::getOpenFileName(this, tr("Выберете файл"), "", tr("*.bmp"));
  scene_->clear();
  QPixmap img = QPixmap(fileName);
  if (img.isNull() || img.width() > 512 || img.height() > 512) {
    msgBox.setText("Или картинка большая, или путь неверный");
    msgBox.exec();
  } else {
    img = img.scaled(200, 200, Qt::KeepAspectRatio);
    scene_->addPixmap(img);
    ui_->paint->setScene(scene_);
    ui_->paint->setEnabled(false);
  }
}

void TestingView::onStartTestIMGClicked() {
  if (ui_->valueTime->text() == "0.0") {
    QMessageBox msgBox;
    msgBox.setText("Сначала запусти тестирование с файлом выше");
    msgBox.exec();
  } else {
    QPixmap pixmap2 = ui_->paint->grab(ui_->paint->sceneRect().toRect());
    QImage img = pixmap2.scaled(28, 28).toImage();
    std::vector<float> weight = WeightIMG(img);
    scene_->addPixmap(pixmap2);
    ui_->paint->setScene(scene_);
    int res = controller_->TestIMG(weight);
    QString resultSymbol =
        QString((char)(64 + res)) + QString((char)(96 + res));
    ui_->result->setText(resultSymbol);
  }
}

std::vector<float> TestingView::WeightIMG(const QImage &img) {
  std::vector<float> weight = {0};
  for (int i = 0; i < 28; i++) {
    for (int j = 0; j < 28; j++) {
      QColor current_color = img.pixel(i, j);
      int red, green, black;
      current_color.getRgb(&red, &green, &black);
      float result = (red + green + black) / 3.0;
      weight.push_back(result);
    }
  }
  return weight;
}

void TestingView::onResetClicked() {
  makeActiveButton(ui_->downloadTest);
  makePassiveButton(ui_->startTest);
  makePassiveButton(ui_->experiment);
  ui_->partTest->setValue(0.1);
  setDefaultValue();
  onCleanPaintClicked();
}

void TestingView::onExperimentClicked() {
  makePassiveButton(ui_->downloadTest);
  setDefaultValue();
  double time = controller_->Experiment(ui_->numberExperiments->value());
  ui_->valueTime->setText(QString::number(time));
}

}  // namespace s21
