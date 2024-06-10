/********************************************************************************
** Form generated from reading UI file 'testing_view.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTING_VIEW_H
#define UI_TESTING_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestingView
{
public:
    QWidget *centralwidget;
    QLabel *testTitle;
    QWidget *widget_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QDoubleSpinBox *partTest;
    QPushButton *downloadTest;
    QPushButton *startTest;
    QPushButton *reset;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *experiment;
    QDoubleSpinBox *numberExperiments;
    QLabel *paintTitle;
    QWidget *widget_4;
    QLabel *resTitle;
    QGraphicsView *paint;
    QPushButton *cleanPaint;
    QPushButton *downloadImg;
    QPushButton *startTestIMG;
    QLabel *result;
    QWidget *widget;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_7;
    QLabel *fMeasure;
    QLabel *recall;
    QLabel *precision;
    QLabel *time;
    QLabel *accuracy;
    QLineEdit *valueAccuracy;
    QLineEdit *valuePrecision;
    QLineEdit *valueRecall;
    QLineEdit *valueFMeasure;
    QLineEdit *valueTime;

    void setupUi(QWidget *TestingView)
    {
        if (TestingView->objectName().isEmpty())
            TestingView->setObjectName("TestingView");
        TestingView->setEnabled(true);
        TestingView->resize(932, 771);
        TestingView->setStyleSheet(QString::fromUtf8("background-color: white;"));
        centralwidget = new QWidget(TestingView);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, -10, 951, 831));
        testTitle = new QLabel(centralwidget);
        testTitle->setObjectName("testTitle");
        testTitle->setGeometry(QRect(550, 10, 351, 41));
        testTitle->setMinimumSize(QSize(31, 31));
        testTitle->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(22);
        testTitle->setFont(font);
        testTitle->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(50, 60, 471, 371));
        widget_3->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"color: black;\n"
"background-color: rgba(239, 240, 242, 0.8);"));
        verticalLayoutWidget = new QWidget(widget_3);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 20, 411, 331));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName("label_8");
        label_8->setMinimumSize(QSize(0, 35));
        label_8->setMaximumSize(QSize(16777215, 35));
        QFont font1;
        font1.setPointSize(14);
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"padding-left: 25px;"));

        horizontalLayout->addWidget(label_8);

        partTest = new QDoubleSpinBox(verticalLayoutWidget);
        partTest->setObjectName("partTest");
        partTest->setMinimumSize(QSize(120, 35));
        partTest->setMaximumSize(QSize(120, 35));
        partTest->setFont(font1);
        partTest->setToolTipDuration(-1);
        partTest->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 227, 231);\n"
"border-radius: 5px;\n"
"margin-right: 25px;"));
        partTest->setAlignment(Qt::AlignCenter);
        partTest->setMinimum(0.100000000000000);
        partTest->setMaximum(1.000000000000000);
        partTest->setSingleStep(0.100000000000000);

        horizontalLayout->addWidget(partTest);


        verticalLayout_3->addLayout(horizontalLayout);

        downloadTest = new QPushButton(verticalLayoutWidget);
        downloadTest->setObjectName("downloadTest");
        downloadTest->setMinimumSize(QSize(190, 51));
        downloadTest->setMaximumSize(QSize(411, 51));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        downloadTest->setFont(font2);
        downloadTest->setCursor(QCursor(Qt::PointingHandCursor));
        downloadTest->setFocusPolicy(Qt::NoFocus);
        downloadTest->setAcceptDrops(false);
        downloadTest->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 10px;\n"
"background-color: white;\n"
"color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: black;\n"
"color: white;\n"
"}"));

        verticalLayout_3->addWidget(downloadTest);

        startTest = new QPushButton(verticalLayoutWidget);
        startTest->setObjectName("startTest");
        startTest->setEnabled(false);
        startTest->setMinimumSize(QSize(171, 61));
        startTest->setMaximumSize(QSize(411, 61));
        startTest->setFont(font2);
        startTest->setCursor(QCursor(Qt::PointingHandCursor));
        startTest->setFocusPolicy(Qt::NoFocus);
        startTest->setAcceptDrops(false);
        startTest->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgba(222, 227, 231, 0.5);\n"
"color: white;\n"
"margin: 10px 0 0 0;"));

        verticalLayout_3->addWidget(startTest);

        reset = new QPushButton(verticalLayoutWidget);
        reset->setObjectName("reset");
        reset->setEnabled(true);
        reset->setMinimumSize(QSize(100, 61));
        reset->setMaximumSize(QSize(411, 61));
        reset->setFont(font2);
        reset->setCursor(QCursor(Qt::PointingHandCursor));
        reset->setFocusPolicy(Qt::NoFocus);
        reset->setAcceptDrops(false);
        reset->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"margin: 10px 0 0 0;\n"
"border-radius: 10px;\n"
"background-color: white;\n"
"color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"margin: 10px 0 0 0;\n"
"background-color: black;\n"
"color: white;\n"
"}"));

        verticalLayout_3->addWidget(reset);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        experiment = new QPushButton(verticalLayoutWidget);
        experiment->setObjectName("experiment");
        experiment->setEnabled(false);
        experiment->setMinimumSize(QSize(100, 61));
        experiment->setMaximumSize(QSize(411, 61));
        experiment->setFont(font2);
        experiment->setCursor(QCursor(Qt::PointingHandCursor));
        experiment->setFocusPolicy(Qt::NoFocus);
        experiment->setAcceptDrops(false);
        experiment->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgba(222, 227, 231, 0.5);\n"
"color: white;\n"
"margin: 10px 0 0 0;"));

        horizontalLayout_2->addWidget(experiment);

        numberExperiments = new QDoubleSpinBox(verticalLayoutWidget);
        numberExperiments->setObjectName("numberExperiments");
        numberExperiments->setMinimumSize(QSize(120, 35));
        numberExperiments->setMaximumSize(QSize(120, 35));
        numberExperiments->setFont(font1);
        numberExperiments->setToolTipDuration(-1);
        numberExperiments->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 227, 231);\n"
"border-radius: 5px;\n"
"margin-right: 25px;"));
        numberExperiments->setAlignment(Qt::AlignCenter);
        numberExperiments->setDecimals(0);
        numberExperiments->setMinimum(-2.000000000000000);
        numberExperiments->setMaximum(3000.000000000000000);
        numberExperiments->setSingleStep(1.000000000000000);

        horizontalLayout_2->addWidget(numberExperiments);


        verticalLayout_3->addLayout(horizontalLayout_2);

        paintTitle = new QLabel(centralwidget);
        paintTitle->setObjectName("paintTitle");
        paintTitle->setGeometry(QRect(50, 430, 231, 41));
        paintTitle->setMinimumSize(QSize(31, 31));
        paintTitle->setMaximumSize(QSize(16777215, 50));
        QFont font3;
        font3.setPointSize(24);
        paintTitle->setFont(font3);
        paintTitle->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(50, 480, 851, 241));
        widget_4->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"color: black;\n"
"background-color: rgba(239, 240, 242, 0.8);\n"
"/*background-color: rgba(221, 222, 222, 0.2);*/"));
        resTitle = new QLabel(widget_4);
        resTitle->setObjectName("resTitle");
        resTitle->setGeometry(QRect(560, 30, 111, 31));
        resTitle->setMaximumSize(QSize(16777215, 31));
        QFont font4;
        font4.setPointSize(18);
        resTitle->setFont(font4);
        resTitle->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        paint = new QGraphicsView(widget_4);
        paint->setObjectName("paint");
        paint->setGeometry(QRect(40, 20, 200, 200));
        paint->setMinimumSize(QSize(200, 200));
        paint->setMaximumSize(QSize(250, 250));
        paint->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        paint->setStyleSheet(QString::fromUtf8("background-color: black;\n"
"border-radius: 20px;"));
        cleanPaint = new QPushButton(widget_4);
        cleanPaint->setObjectName("cleanPaint");
        cleanPaint->setGeometry(QRect(270, 20, 190, 61));
        cleanPaint->setMinimumSize(QSize(190, 61));
        cleanPaint->setMaximumSize(QSize(190, 61));
        cleanPaint->setFont(font2);
        cleanPaint->setCursor(QCursor(Qt::PointingHandCursor));
        cleanPaint->setFocusPolicy(Qt::NoFocus);
        cleanPaint->setAcceptDrops(false);
        cleanPaint->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 10px;\n"
"background-color: white;\n"
"/*background-color: rgb(245, 49, 49);\n"
"color: white;*/\n"
"color: black;\n"
"margin: 10px 0;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: black;\n"
"color: white;\n"
"}"));
        downloadImg = new QPushButton(widget_4);
        downloadImg->setObjectName("downloadImg");
        downloadImg->setGeometry(QRect(270, 80, 190, 61));
        downloadImg->setMinimumSize(QSize(190, 61));
        downloadImg->setMaximumSize(QSize(190, 61));
        downloadImg->setFont(font2);
        downloadImg->setCursor(QCursor(Qt::PointingHandCursor));
        downloadImg->setFocusPolicy(Qt::NoFocus);
        downloadImg->setAcceptDrops(false);
        downloadImg->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 10px;\n"
"background-color: white;\n"
"/*background-color: rgb(245, 49, 49);\n"
"color: white;*/\n"
"color: black;\n"
"margin: 10px 0;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: black;\n"
"color: white;\n"
"}"));
        startTestIMG = new QPushButton(widget_4);
        startTestIMG->setObjectName("startTestIMG");
        startTestIMG->setEnabled(true);
        startTestIMG->setGeometry(QRect(270, 140, 190, 61));
        startTestIMG->setMinimumSize(QSize(190, 61));
        startTestIMG->setMaximumSize(QSize(190, 61));
        startTestIMG->setFont(font2);
        startTestIMG->setCursor(QCursor(Qt::PointingHandCursor));
        startTestIMG->setFocusPolicy(Qt::NoFocus);
        startTestIMG->setAcceptDrops(false);
        startTestIMG->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 10px;\n"
"background-color: white;\n"
"/*background-color: rgb(245, 49, 49);\n"
"color: white;*/\n"
"color: black;\n"
"margin: 10px 0;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: black;\n"
"color: white;\n"
"}"));
        result = new QLabel(widget_4);
        result->setObjectName("result");
        result->setGeometry(QRect(540, 70, 231, 121));
        QFont font5;
        font5.setPointSize(36);
        result->setFont(font5);
        result->setStyleSheet(QString::fromUtf8(""));
        result->setAlignment(Qt::AlignCenter);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(550, 60, 351, 371));
        widget->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"color: black;\n"
"background-color: rgba(239, 240, 242, 0.8);\n"
"padding: 20px;"));
        gridLayoutWidget_5 = new QWidget(widget);
        gridLayoutWidget_5->setObjectName("gridLayoutWidget_5");
        gridLayoutWidget_5->setGeometry(QRect(30, 50, 293, 291));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setVerticalSpacing(6);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        fMeasure = new QLabel(gridLayoutWidget_5);
        fMeasure->setObjectName("fMeasure");
        fMeasure->setMinimumSize(QSize(31, 31));
        fMeasure->setMaximumSize(QSize(16777215, 50));
        fMeasure->setFont(font1);
        fMeasure->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"padding: 0;"));

        gridLayout_7->addWidget(fMeasure, 3, 0, 1, 1);

        recall = new QLabel(gridLayoutWidget_5);
        recall->setObjectName("recall");
        recall->setMinimumSize(QSize(31, 31));
        recall->setMaximumSize(QSize(16777215, 50));
        recall->setFont(font1);
        recall->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"background-color: transparent;"));

        gridLayout_7->addWidget(recall, 2, 0, 1, 1);

        precision = new QLabel(gridLayoutWidget_5);
        precision->setObjectName("precision");
        precision->setMinimumSize(QSize(31, 31));
        precision->setMaximumSize(QSize(16777215, 50));
        precision->setFont(font1);
        precision->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"background-color: transparent;"));

        gridLayout_7->addWidget(precision, 1, 0, 1, 1);

        time = new QLabel(gridLayoutWidget_5);
        time->setObjectName("time");
        time->setMinimumSize(QSize(27, 31));
        time->setMaximumSize(QSize(16777215, 50));
        time->setFont(font1);
        time->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"background-color: transparent;"));

        gridLayout_7->addWidget(time, 4, 0, 1, 1);

        accuracy = new QLabel(gridLayoutWidget_5);
        accuracy->setObjectName("accuracy");
        accuracy->setMinimumSize(QSize(188, 37));
        accuracy->setMaximumSize(QSize(188, 37));
        accuracy->setFont(font1);
        accuracy->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"padding: 0;"));

        gridLayout_7->addWidget(accuracy, 0, 0, 1, 1);

        valueAccuracy = new QLineEdit(gridLayoutWidget_5);
        valueAccuracy->setObjectName("valueAccuracy");
        valueAccuracy->setMinimumSize(QSize(95, 30));
        valueAccuracy->setMaximumSize(QSize(95, 30));
        valueAccuracy->setFont(font1);
        valueAccuracy->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"border: none;"));
        valueAccuracy->setAlignment(Qt::AlignCenter);
        valueAccuracy->setReadOnly(true);

        gridLayout_7->addWidget(valueAccuracy, 0, 1, 1, 1);

        valuePrecision = new QLineEdit(gridLayoutWidget_5);
        valuePrecision->setObjectName("valuePrecision");
        valuePrecision->setMinimumSize(QSize(95, 30));
        valuePrecision->setMaximumSize(QSize(95, 30));
        valuePrecision->setFont(font1);
        valuePrecision->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"border: none;"));
        valuePrecision->setAlignment(Qt::AlignCenter);
        valuePrecision->setReadOnly(true);

        gridLayout_7->addWidget(valuePrecision, 1, 1, 1, 1);

        valueRecall = new QLineEdit(gridLayoutWidget_5);
        valueRecall->setObjectName("valueRecall");
        valueRecall->setMinimumSize(QSize(95, 30));
        valueRecall->setMaximumSize(QSize(95, 30));
        valueRecall->setFont(font1);
        valueRecall->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"border: none;"));
        valueRecall->setAlignment(Qt::AlignCenter);
        valueRecall->setReadOnly(true);

        gridLayout_7->addWidget(valueRecall, 2, 1, 1, 1);

        valueFMeasure = new QLineEdit(gridLayoutWidget_5);
        valueFMeasure->setObjectName("valueFMeasure");
        valueFMeasure->setMinimumSize(QSize(95, 30));
        valueFMeasure->setMaximumSize(QSize(95, 30));
        valueFMeasure->setFont(font1);
        valueFMeasure->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"border: none;"));
        valueFMeasure->setAlignment(Qt::AlignCenter);
        valueFMeasure->setReadOnly(true);

        gridLayout_7->addWidget(valueFMeasure, 3, 1, 1, 1);

        valueTime = new QLineEdit(gridLayoutWidget_5);
        valueTime->setObjectName("valueTime");
        valueTime->setMinimumSize(QSize(95, 30));
        valueTime->setMaximumSize(QSize(95, 30));
        valueTime->setFont(font1);
        valueTime->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"border: none;"));
        valueTime->setAlignment(Qt::AlignCenter);
        valueTime->setReadOnly(true);

        gridLayout_7->addWidget(valueTime, 4, 1, 1, 1);


        retranslateUi(TestingView);

        QMetaObject::connectSlotsByName(TestingView);
    } // setupUi

    void retranslateUi(QWidget *TestingView)
    {
        TestingView->setWindowTitle(QCoreApplication::translate("TestingView", "View", nullptr));
        testTitle->setText(QCoreApplication::translate("TestingView", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_8->setText(QCoreApplication::translate("TestingView", "\320\247\320\260\321\201\321\202\321\214 \321\202\320\265\321\201\321\202\320\276\320\262\320\276\320\271 \320\262\321\213\320\261\320\276\321\200\320\272\320\270:", nullptr));
        downloadTest->setText(QCoreApplication::translate("TestingView", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 test.\321\201sv ", nullptr));
        startTest->setText(QCoreApplication::translate("TestingView", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        reset->setText(QCoreApplication::translate("TestingView", "\320\241\320\261\321\200\320\276\321\201 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        experiment->setText(QCoreApplication::translate("TestingView", "\320\237\321\200\320\276\320\262\320\265\321\201\321\202\320\270 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265(N \321\200\320\260\320\267)", nullptr));
        paintTitle->setText(QCoreApplication::translate("TestingView", "\320\240\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\267\320\264\320\265\321\201\321\214", nullptr));
        resTitle->setText(QCoreApplication::translate("TestingView", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", nullptr));
        cleanPaint->setText(QCoreApplication::translate("TestingView", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        downloadImg->setText(QCoreApplication::translate("TestingView", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\321\203", nullptr));
        startTestIMG->setText(QCoreApplication::translate("TestingView", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\260\321\202\321\214", nullptr));
        result->setText(QString());
        fMeasure->setText(QCoreApplication::translate("TestingView", "f-\320\274\320\265\321\200\320\260:", nullptr));
        recall->setText(QCoreApplication::translate("TestingView", "\320\237\320\276\320\273\320\275\320\276\321\202\320\260:", nullptr));
        precision->setText(QCoreApplication::translate("TestingView", "\320\237\321\200\320\265\321\206\320\270\320\267\320\270\320\276\320\275\320\275\320\276\321\201\321\202\321\214:", nullptr));
        time->setText(QCoreApplication::translate("TestingView", "\320\227\320\260\321\202\321\200\320\260\321\207\320\265\320\275\320\275\320\276\320\265 \320\262\321\200\320\265\320\274\321\217:", nullptr));
        accuracy->setText(QCoreApplication::translate("TestingView", "\320\241\321\200\320\265\320\264\320\275\321\217\321\217 \321\202\320\276\321\207\320\275\320\276\321\201\321\202\321\214:", nullptr));
        valueAccuracy->setText(QCoreApplication::translate("TestingView", "0.0", nullptr));
        valuePrecision->setText(QCoreApplication::translate("TestingView", "0.0", nullptr));
        valueRecall->setText(QCoreApplication::translate("TestingView", "0.0", nullptr));
        valueFMeasure->setText(QCoreApplication::translate("TestingView", "0.0", nullptr));
        valueTime->setText(QCoreApplication::translate("TestingView", "0.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestingView: public Ui_TestingView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTING_VIEW_H
