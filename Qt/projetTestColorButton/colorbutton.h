#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QWidget>
#include <QPushButton>



class ColorButton : public QPushButton
{
    Q_OBJECT

public:
    explicit ColorButton(QWidget *parent = nullptr);
    //~ColorButton();

    QColor getColor();
    void setColor(QColor c);
    void paintEvent (QPaintEvent *event);

private slots:
    void Couleur();


private :
    QColor m_color;
};

#endif // COLORBUTTON_H
