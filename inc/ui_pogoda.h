/********************************************************************************
** Form generated from reading UI file 'pogoda.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POGODA_H
#define UI_POGODA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
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
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_7;
    QDateEdit *date_edit;
    QCheckBox *animations_checkBox;
    QTimeEdit *time_edit;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_13;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_12;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_6;
    QGraphicsView *graphicsView_4;
    QGraphicsView *graphicsView_2;
    QGridLayout *gridLayout_15;
    QComboBox *city_dropdown;
    QDateEdit *date_edit2;
    QSpacerItem *horizontalSpacer_2;
    QTimeEdit *time_edit2;
    QGridLayout *gridLayout_11;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout_14;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QGraphicsView *graphicsView_3;
    QGraphicsView *graphicsView;
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
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_13->addWidget(label_2, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_4, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_13, 4, 0, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_12->addWidget(label_4, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_6, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_12, 0, 0, 1, 1);

        graphicsView_4 = new QGraphicsView(tab_2);
        graphicsView_4->setObjectName(QString::fromUtf8("graphicsView_4"));

        gridLayout_2->addWidget(graphicsView_4, 1, 0, 1, 1);

        graphicsView_2 = new QGraphicsView(tab_2);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));

        gridLayout_2->addWidget(graphicsView_2, 5, 0, 1, 1);

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

        time_edit2 = new QTimeEdit(tab_2);
        time_edit2->setObjectName(QString::fromUtf8("time_edit2"));
        time_edit2->setMaximumTime(QTime(23, 0, 0));
        time_edit2->setCalendarPopup(false);

        gridLayout_15->addWidget(time_edit2, 0, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout_15, 8, 0, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_11->addWidget(label_3, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_5, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_11, 2, 0, 1, 1);

        gridLayout_14 = new QGridLayout();
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_14->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_3, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_14, 6, 0, 1, 1);

        graphicsView_3 = new QGraphicsView(tab_2);
        graphicsView_3->setObjectName(QString::fromUtf8("graphicsView_3"));

        gridLayout_2->addWidget(graphicsView_3, 3, 0, 1, 1);

        graphicsView = new QGraphicsView(tab_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout_2->addWidget(graphicsView, 7, 0, 1, 1);

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
        QObject::connect(time_edit2, SIGNAL(timeChanged(QTime)), MainWindow, SLOT(update()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Pogoda w Polsce", nullptr));
        date_edit->setDisplayFormat(QApplication::translate("MainWindow", "dd/MM", nullptr));
        animations_checkBox->setText(QApplication::translate("MainWindow", "animacje", nullptr));
        time_edit->setDisplayFormat(QApplication::translate("MainWindow", "HH:00", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "mapa", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "wykres 1", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "wykres 1", nullptr));
        city_dropdown->setItemText(0, QApplication::translate("MainWindow", "Warszawa", nullptr));
        city_dropdown->setItemText(1, QApplication::translate("MainWindow", "Wroc\305\202aw", nullptr));
        city_dropdown->setItemText(2, QApplication::translate("MainWindow", "Pozna\305\204", nullptr));
        city_dropdown->setItemText(3, QApplication::translate("MainWindow", "Gda\305\204sk", nullptr));
        city_dropdown->setItemText(4, QApplication::translate("MainWindow", "Katowice", nullptr));
        city_dropdown->setItemText(5, QApplication::translate("MainWindow", "\305\201\303\263d\305\272 ", nullptr));

        date_edit2->setDisplayFormat(QApplication::translate("MainWindow", "dd/MM", nullptr));
        time_edit2->setDisplayFormat(QApplication::translate("MainWindow", "HH:00", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "wykres 1", nullptr));
        label->setText(QApplication::translate("MainWindow", "wykres 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "wykresy", nullptr));
        exit_button->setText(QApplication::translate("MainWindow", "exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POGODA_H
