#include "colorbutton.h"
#include "mainwindow.h"

#include <QColorDialog>
#include <QPainter>


ColorButton::ColorButton(QWidget *parent) : QPushButton(parent)

{
    connect(this, SIGNAL(clicked()), this, SLOT(Couleur()));
}

QColor ColorButton::getColor()
{
     return m_color;
}

void ColorButton::setColor(QColor c)
{
    m_color=c;
}

void ColorButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);

    QPainter painter (this);
    QPen pen (m_color);
    QBrush brush (m_color);

    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(4, 4, width()-8,height() -8);


}

void ColorButton::Couleur()
{

    m_color = QColorDialog::getColor();


}


