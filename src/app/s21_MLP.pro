QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 #O3 march=native
QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CFLAGS = -march=native
#QMAKE_CXX = g++ -std=c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cc \
    model/model.cc \
    model/neural_network/graph/graph_layer.cc \
    model/neural_network/graph/graph_net.cc \
    model/neural_network/matrix/matrix_net.cc \
    model/parser/parserData.cc \
    model/parser/parserWeights.cc \
    model/tester/tester.cc \
    model/trainer/trainer.cc \
    view/learning_view.cc \
    view/paintscene.cc \
    view/qcustomplot.cc \
    controller/controller.cc \
    view/testing_view.cc

HEADERS += \
    model/model.h \
    model/neural_network/graph/graph_layer.h \
    model/neural_network/graph/graph_net.h \
    model/neural_network/graph/graph_neuron.h \
    model/neural_network/matrix/matrix_net.h \
    model/neural_network/neural_network.h \
    model/parser/parserData.h \
    model/parser/parserWeights.h \
    model/tester/tester.h \
    model/trainer/trainer.h \
    view/learning_view.h \
    view/paintscene.h \
    view/qcustomplot.h \
    controller/controller.h \
    view/testing_view.h

FORMS += \
    view/learning_view.ui \
    view/testing_view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    model/.DS_Store \
    model/Parser/.DS_Store
