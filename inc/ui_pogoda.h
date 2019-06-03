/********************************************************************************
** Form generated from reading UI file 'pogoda.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POGODA_H
#define UI_POGODA_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_10;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_4;
    QGraphicsView *map;
    QGraphicsView *cityinfo;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_7;
    QDateEdit *date_edit;
    QCheckBox *animations_checkBox;
    QTimeEdit *time_edit;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QtCharts::QChartView *temperature;
    QGridLayout *gridLayout_11;
    QtCharts::QChartView *humidity;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_15;
    QComboBox *city_dropdown;
    QDateEdit *date_edit2;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_14;
    QGridLayout *gridLayout_13;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_8;
    QSpacerItem *horizontalSpacer;
    QPushButton *exit_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(919, 639);
        MainWindow->setSizeIncrement(QSize(0, 0));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Cantarell\";\n"
""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        map = new QGraphicsView(tab);
        map->setObjectName(QString::fromUtf8("map"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(map->sizePolicy().hasHeightForWidth());
        map->setSizePolicy(sizePolicy);
        map->setMinimumSize(QSize(350, 250));
        map->setSizeIncrement(QSize(0, 0));
        map->setMouseTracking(true);

        gridLayout_4->addWidget(map, 0, 0, 1, 1);

        cityinfo = new QGraphicsView(tab);
        cityinfo->setObjectName(QString::fromUtf8("cityinfo"));
        cityinfo->setMaximumSize(QSize(350, 16777215));

        gridLayout_4->addWidget(cityinfo, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        date_edit = new QDateEdit(tab);
        date_edit->setObjectName(QString::fromUtf8("date_edit"));
        date_edit->setDateTime(QDateTime(QDate(2019, 4, 8), QTime(0, 0, 0)));
        date_edit->setCalendarPopup(true);

        gridLayout_7->addWidget(date_edit, 0, 0, 1, 1);

        animations_checkBox = new QCheckBox(tab);
        animations_checkBox->setObjectName(QString::fromUtf8("animations_checkBox"));
        animations_checkBox->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Cantarell Light\";"));

        gridLayout_7->addWidget(animations_checkBox, 2, 0, 1, 1);

        time_edit = new QTimeEdit(tab);
        time_edit->setObjectName(QString::fromUtf8("time_edit"));
        time_edit->setReadOnly(false);
        time_edit->setMaximumTime(QTime(23, 0, 0));

        gridLayout_7->addWidget(time_edit, 1, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_7, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_2, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_6, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        temperature = new QtCharts::QChartView(tab_2);
        temperature->setObjectName(QString::fromUtf8("temperature"));

        gridLayout_2->addWidget(temperature, 1, 0, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));

        gridLayout_2->addLayout(gridLayout_11, 2, 0, 1, 1);

        humidity = new QtCharts::QChartView(tab_2);
        humidity->setObjectName(QString::fromUtf8("humidity"));

        gridLayout_2->addWidget(humidity, 3, 0, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));

        gridLayout_2->addLayout(gridLayout_12, 0, 0, 1, 1);

        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        city_dropdown = new QComboBox(tab_2);
        city_dropdown->addItem(QString());
        city_dropdown->addItem(QString());
        city_dropdown->addItem(QString());
        city_dropdown->addItem(QString());
        city_dropdown->addItem(QString());
        city_dropdown->addItem(QString());
        city_dropdown->setObjectName(QString::fromUtf8("city_dropdown"));
        city_dropdown->setMinimumSize(QSize(90, 0));

        gridLayout_15->addWidget(city_dropdown, 0, 1, 1, 1);

        date_edit2 = new QDateEdit(tab_2);
        date_edit2->setObjectName(QString::fromUtf8("date_edit2"));
        date_edit2->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(date_edit2->sizePolicy().hasHeightForWidth());
        date_edit2->setSizePolicy(sizePolicy1);
        date_edit2->setMinimumSize(QSize(80, 0));
        date_edit2->setDateTime(QDateTime(QDate(2019, 4, 8), QTime(0, 0, 0)));
        date_edit2->setCalendarPopup(true);

        gridLayout_15->addWidget(date_edit2, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_2, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_15, 6, 0, 1, 1);

        gridLayout_14 = new QGridLayout();
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));

        gridLayout_2->addLayout(gridLayout_14, 5, 0, 1, 1);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));

        gridLayout_2->addLayout(gridLayout_13, 4, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_10->addWidget(tabWidget, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer, 0, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_10, 0, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer, 0, 0, 1, 1);

        exit_button = new QPushButton(centralwidget);
        exit_button->setObjectName(QString::fromUtf8("exit_button"));
        exit_button->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Cantarell\";"));

        gridLayout_8->addWidget(exit_button, 0, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_9, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 919, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(exit_button, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(city_dropdown, SIGNAL(currentTextChanged(QString)), MainWindow, SLOT(update()));
        QObject::connect(animations_checkBox, SIGNAL(stateChanged(int)), animations_checkBox, SLOT(update()));
        QObject::connect(date_edit, SIGNAL(dateChanged(QDate)), MainWindow, SLOT(update()));
        QObject::connect(time_edit, SIGNAL(timeChanged(QTime)), MainWindow, SLOT(update()));
        QObject::connect(date_edit2, SIGNAL(dateChanged(QDate)), MainWindow, SLOT(update()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Pogoda w Polsce", nullptr));
        date_edit->setDisplayFormat(QApplication::translate("MainWindow", "dd/MM", nullptr));
        animations_checkBox->setText(QApplication::translate("MainWindow", "animations", nullptr));
        time_edit->setDisplayFormat(QApplication::translate("MainWindow", "HH:00", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "map", nullptr));
        city_dropdown->setItemText(0, QApplication::translate("MainWindow", "Warsaw", nullptr));
        city_dropdown->setItemText(1, QApplication::translate("MainWindow", "Wroclaw", nullptr));
        city_dropdown->setItemText(2, QApplication::translate("MainWindow", "Poznan", nullptr));
        city_dropdown->setItemText(3, QApplication::translate("MainWindow", "Gdansk", nullptr));
        city_dropdown->setItemText(4, QApplication::translate("MainWindow", "Katowice", nullptr));
        city_dropdown->setItemText(5, QApplication::translate("MainWindow", "Krakow", nullptr));

        date_edit2->setDisplayFormat(QApplication::translate("MainWindow", "dd/MM", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "charts", nullptr));
        exit_button->setText(QApplication::translate("MainWindow", "exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POGODA_H
