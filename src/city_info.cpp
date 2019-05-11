#include "city_info.h"


city_info::city_info()
{
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(Qt::white);
    back_text = scene->addText("back");
    back_text->setPos(100, 100);
    back_text->setFlag(QGraphicsItem::ItemIsSelectable);

    QObject::connect(scene, SIGNAL(selectionChanged()), this, SLOT(back_selected()));
}


void city_info::back_selected()
{
    if(back_text->isSelected())
        emit change_scene();
}



