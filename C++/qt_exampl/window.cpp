#include "window.hpp"
#include <QPushButton>

window::window (QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(400, 200);

    m_button = new QPushButton("Hello", this);
    m_button->setGeometry(10, 10, 80, 30);
}
