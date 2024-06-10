/********************************************************************************
** Form generated from reading UI file 'learning_view.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNING_VIEW_H
#define UI_LEARNING_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "./view/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_LearningView
{
public:
    QWidget *centralwidget;
    QWidget *widget_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *hiddenLayers;
    QLabel *label_2;
    QGridLayout *gridLayout_2;
    QRadioButton *matrixMethod;
    QRadioButton *graphMethod;
    QLabel *realization;
    QCheckBox *randomWeights;
    QVBoxLayout *verticalLayout;
    QCheckBox *crossValid;
    QCheckBox *checkGraph;
    QLabel *label_3;
    QSpinBox *countEpochs;
    QSpinBox *countGroups;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QPushButton *startTraining;
    QPushButton *downloadTrain;
    QPushButton *downloadLearnWeight;
    QPushButton *saveWeight;
    QPushButton *reset;
    QLabel *learnTitle;
    QTextEdit *learnInfo;
    QCustomPlot *CustomPlot;
    QPushButton *startTesting;

    void setupUi(QMainWindow *LearningView)
    {
        if (LearningView->objectName().isEmpty())
            LearningView->setObjectName("LearningView");
        LearningView->setEnabled(true);
        LearningView->resize(932, 664);
        LearningView->setStyleSheet(QString::fromUtf8("background-color: white;"));
        centralwidget = new QWidget(LearningView);
        centralwidget->setObjectName("centralwidget");
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(30, 40, 471, 581));
        widget_2->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"color: black;\n"
"background-color: rgba(239, 240, 242, 0.8);\n"
"/*background-color: rgba(221, 222, 222, 0.2);*/"));
        gridLayoutWidget = new QWidget(widget_2);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(30, 30, 420, 286));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        hiddenLayers = new QSpinBox(gridLayoutWidget);
        hiddenLayers->setObjectName("hiddenLayers");
        hiddenLayers->setEnabled(true);
        hiddenLayers->setMinimumSize(QSize(70, 35));
        hiddenLayers->setMaximumSize(QSize(70, 35));
        QFont font;
        font.setPointSize(16);
        hiddenLayers->setFont(font);
        hiddenLayers->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 227, 231);\n"
"border-radius: 5px;"));
        hiddenLayers->setAlignment(Qt::AlignCenter);
        hiddenLayers->setMinimum(2);
        hiddenLayers->setMaximum(5);

        gridLayout->addWidget(hiddenLayers, 1, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(31, 31));
        label_2->setMaximumSize(QSize(16777215, 50));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_2->setVerticalSpacing(6);
        matrixMethod = new QRadioButton(gridLayoutWidget);
        matrixMethod->setObjectName("matrixMethod");
        matrixMethod->setEnabled(true);
        matrixMethod->setFont(font1);
        matrixMethod->setCursor(QCursor(Qt::PointingHandCursor));
        matrixMethod->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        matrixMethod->setChecked(true);

        gridLayout_2->addWidget(matrixMethod, 1, 0, 1, 1);

        graphMethod = new QRadioButton(gridLayoutWidget);
        graphMethod->setObjectName("graphMethod");
        graphMethod->setEnabled(true);
        graphMethod->setFont(font1);
        graphMethod->setCursor(QCursor(Qt::PointingHandCursor));
        graphMethod->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout_2->addWidget(graphMethod, 1, 1, 1, 1);

        realization = new QLabel(gridLayoutWidget);
        realization->setObjectName("realization");
        realization->setMaximumSize(QSize(350, 31));
        realization->setFont(font1);
        realization->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout_2->addWidget(realization, 0, 0, 1, 2);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 2);

        randomWeights = new QCheckBox(gridLayoutWidget);
        randomWeights->setObjectName("randomWeights");
        randomWeights->setMinimumSize(QSize(0, 30));
        randomWeights->setFont(font1);
        randomWeights->setCursor(QCursor(Qt::PointingHandCursor));
        randomWeights->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        randomWeights->setCheckable(true);
        randomWeights->setChecked(true);

        gridLayout->addWidget(randomWeights, 7, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        crossValid = new QCheckBox(gridLayoutWidget);
        crossValid->setObjectName("crossValid");
        crossValid->setEnabled(true);
        crossValid->setMinimumSize(QSize(0, 0));
        crossValid->setMaximumSize(QSize(380, 30));
        crossValid->setFont(font1);
        crossValid->setCursor(QCursor(Qt::PointingHandCursor));
        crossValid->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        verticalLayout->addWidget(crossValid);


        gridLayout->addLayout(verticalLayout, 3, 0, 1, 1);

        checkGraph = new QCheckBox(gridLayoutWidget);
        checkGraph->setObjectName("checkGraph");
        checkGraph->setEnabled(true);
        checkGraph->setMinimumSize(QSize(381, 30));
        checkGraph->setMaximumSize(QSize(381, 30));
        checkGraph->setFont(font1);
        checkGraph->setCursor(QCursor(Qt::PointingHandCursor));
        checkGraph->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(checkGraph, 4, 0, 1, 2);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setEnabled(true);
        label_3->setMaximumSize(QSize(16777215, 31));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        countEpochs = new QSpinBox(gridLayoutWidget);
        countEpochs->setObjectName("countEpochs");
        countEpochs->setEnabled(true);
        countEpochs->setMinimumSize(QSize(70, 35));
        countEpochs->setMaximumSize(QSize(70, 35));
        countEpochs->setFont(font);
        countEpochs->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 227, 231);\n"
"border-radius: 5px;"));
        countEpochs->setAlignment(Qt::AlignCenter);
        countEpochs->setMinimum(1);

        gridLayout->addWidget(countEpochs, 2, 1, 1, 1);

        countGroups = new QSpinBox(gridLayoutWidget);
        countGroups->setObjectName("countGroups");
        countGroups->setEnabled(true);
        countGroups->setMinimumSize(QSize(70, 35));
        countGroups->setMaximumSize(QSize(70, 35));
        countGroups->setFont(font);
        countGroups->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 227, 231);\n"
"border-radius: 5px;"));
        countGroups->setAlignment(Qt::AlignCenter);
        countGroups->setMinimum(2);
        countGroups->setMaximum(100);

        gridLayout->addWidget(countGroups, 3, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(widget_2);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(30, 330, 421, 138));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        startTraining = new QPushButton(gridLayoutWidget_2);
        startTraining->setObjectName("startTraining");
        startTraining->setEnabled(false);
        startTraining->setMinimumSize(QSize(200, 61));
        startTraining->setMaximumSize(QSize(190, 61));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        startTraining->setFont(font2);
        startTraining->setCursor(QCursor(Qt::PointingHandCursor));
        startTraining->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgba(222, 227, 231, 0.5);\n"
"color: white;\n"
"margin: 10px 0;"));

        gridLayout_3->addWidget(startTraining, 0, 1, 1, 1);

        downloadTrain = new QPushButton(gridLayoutWidget_2);
        downloadTrain->setObjectName("downloadTrain");
        downloadTrain->setMinimumSize(QSize(180, 61));
        downloadTrain->setMaximumSize(QSize(190, 61));
        downloadTrain->setFont(font2);
        downloadTrain->setCursor(QCursor(Qt::PointingHandCursor));
        downloadTrain->setFocusPolicy(Qt::NoFocus);
        downloadTrain->setAcceptDrops(false);
        downloadTrain->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 10px;\n"
"background-color: white;\n"
"color: black;\n"
"margin: 10px 0;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: black;\n"
"color: white;\n"
"}"));

        gridLayout_3->addWidget(downloadTrain, 0, 0, 1, 1);

        downloadLearnWeight = new QPushButton(gridLayoutWidget_2);
        downloadLearnWeight->setObjectName("downloadLearnWeight");
        downloadLearnWeight->setEnabled(false);
        downloadLearnWeight->setMinimumSize(QSize(171, 61));
        downloadLearnWeight->setMaximumSize(QSize(190, 61));
        downloadLearnWeight->setFont(font2);
        downloadLearnWeight->setCursor(QCursor(Qt::PointingHandCursor));
        downloadLearnWeight->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgba(222, 227, 231, 0.5);\n"
"color: white;\n"
"margin: 10px 0;"));

        gridLayout_3->addWidget(downloadLearnWeight, 1, 0, 1, 1);

        saveWeight = new QPushButton(gridLayoutWidget_2);
        saveWeight->setObjectName("saveWeight");
        saveWeight->setEnabled(false);
        saveWeight->setMinimumSize(QSize(200, 61));
        saveWeight->setMaximumSize(QSize(190, 61));
        saveWeight->setFont(font2);
        saveWeight->setCursor(QCursor(Qt::PointingHandCursor));
        saveWeight->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgba(222, 227, 231, 0.5);\n"
"color: white;\n"
"margin: 10px 0;"));

        gridLayout_3->addWidget(saveWeight, 1, 1, 1, 1);

        reset = new QPushButton(widget_2);
        reset->setObjectName("reset");
        reset->setEnabled(true);
        reset->setGeometry(QRect(30, 490, 421, 60));
        reset->setMinimumSize(QSize(100, 40));
        reset->setMaximumSize(QSize(500, 60));
        reset->setFont(font2);
        reset->setCursor(QCursor(Qt::PointingHandCursor));
        reset->setFocusPolicy(Qt::NoFocus);
        reset->setAcceptDrops(false);
        reset->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 10px;\n"
"background-color: white;\n"
"color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: black;\n"
"color: white;\n"
"}"));
        learnTitle = new QLabel(centralwidget);
        learnTitle->setObjectName("learnTitle");
        learnTitle->setGeometry(QRect(530, 50, 371, 41));
        learnTitle->setMinimumSize(QSize(31, 31));
        learnTitle->setMaximumSize(QSize(16777215, 50));
        QFont font3;
        font3.setPointSize(22);
        learnTitle->setFont(font3);
        learnTitle->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: black;"));
        learnInfo = new QTextEdit(centralwidget);
        learnInfo->setObjectName("learnInfo");
        learnInfo->setGeometry(QRect(540, 100, 341, 201));
        learnInfo->setFont(font1);
        learnInfo->setStyleSheet(QString::fromUtf8("/*border: 1px solid rgb(128, 128, 128);*/\n"
"border-radius: 20px;\n"
"background-color: rgba(239, 240, 242, 0.8);\n"
"padding: 20px;"));
        learnInfo->setReadOnly(true);
        CustomPlot = new QCustomPlot(centralwidget);
        CustomPlot->setObjectName("CustomPlot");
        CustomPlot->setGeometry(QRect(540, 310, 341, 221));
        startTesting = new QPushButton(centralwidget);
        startTesting->setObjectName("startTesting");
        startTesting->setEnabled(false);
        startTesting->setGeometry(QRect(540, 540, 341, 60));
        startTesting->setMinimumSize(QSize(100, 60));
        startTesting->setMaximumSize(QSize(500, 60));
        startTesting->setFont(font2);
        startTesting->setCursor(QCursor(Qt::PointingHandCursor));
        startTesting->setFocusPolicy(Qt::NoFocus);
        startTesting->setAcceptDrops(false);
        startTesting->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"\n"
"background-color: rgba(222, 227, 231, 0.5);\n"
"color: white;"));
        LearningView->setCentralWidget(centralwidget);

        retranslateUi(LearningView);

        QMetaObject::connectSlotsByName(LearningView);
    } // setupUi

    void retranslateUi(QMainWindow *LearningView)
    {
        LearningView->setWindowTitle(QCoreApplication::translate("LearningView", "MLP", nullptr));
        label_2->setText(QCoreApplication::translate("LearningView", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\320\272\321\200\321\213\321\202\321\213\321\205 \321\201\320\273\320\276\320\265\320\262", nullptr));
        matrixMethod->setText(QCoreApplication::translate("LearningView", "\320\234\320\260\321\202\321\200\320\270\321\207\320\275\320\260\321\217", nullptr));
        graphMethod->setText(QCoreApplication::translate("LearningView", "\320\223\321\200\320\260\321\204\320\276\320\262\320\260\321\217", nullptr));
        realization->setText(QCoreApplication::translate("LearningView", "\320\241\320\277\320\276\321\201\320\276\320\261\321\213 \321\200\320\265\320\260\320\273\320\270\320\267\320\260\321\206\320\270\320\270 \320\277\320\265\321\200\321\206\320\265\320\277\321\202\321\200\320\276\320\275\320\260:", nullptr));
        randomWeights->setText(QCoreApplication::translate("LearningView", "\320\241\320\273\321\203\321\207\320\260\320\271\320\275\321\213\320\265 \320\262\320\265\321\201\320\260", nullptr));
        crossValid->setText(QCoreApplication::translate("LearningView", "\320\232\321\200\320\276\321\201\321\201-\320\262\320\260\320\273\320\270\320\264\320\260\321\206\320\270\321\217 \320\264\320\273\321\217 \321\207\320\270\321\201\320\273\320\260 \320\263\321\200\321\203\320\277\320\277 k  ", nullptr));
        checkGraph->setText(QCoreApplication::translate("LearningView", "\320\223\321\200\320\260\321\204\320\270\320\272", nullptr));
        label_3->setText(QCoreApplication::translate("LearningView", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\215\320\277\320\276\321\205", nullptr));
        startTraining->setText(QCoreApplication::translate("LearningView", "\320\241\321\202\320\260\321\200\321\202 \320\276\320\261\321\203\321\207\320\265\320\275\320\270\321\217", nullptr));
        downloadTrain->setText(QCoreApplication::translate("LearningView", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 train.\321\201sv ", nullptr));
        downloadLearnWeight->setText(QCoreApplication::translate("LearningView", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\262\320\265\321\201\320\260", nullptr));
        saveWeight->setText(QCoreApplication::translate("LearningView", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262\320\265\321\201\320\260", nullptr));
        reset->setText(QCoreApplication::translate("LearningView", "\320\241\320\261\321\200\320\276\321\201 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272 \320\276\320\261\321\203\321\207\320\265\320\275\320\270\321\217", nullptr));
        learnTitle->setText(QCoreApplication::translate("LearningView", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276\320\261 \320\276\320\261\321\203\321\207\320\265\320\275\320\270\320\270", nullptr));
        startTesting->setText(QCoreApplication::translate("LearningView", " \320\242\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265  >>>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LearningView: public Ui_LearningView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNING_VIEW_H
