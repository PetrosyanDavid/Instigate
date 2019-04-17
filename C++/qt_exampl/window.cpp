#include "window.hpp"
#include <QCoreApplication>

window::window (QWidget *parent) :
    QMainWindow(parent)
{
    m_button = new QPushButton("My Button", this);
    m_button->setGeometry(QRect(QPoint(100, 100),QSize(200,50)));

    connect(m_button, SIGNAL (released()), this, SLOT(handleButton()));
}

void window::handleButton()
{
    m_button->setText("Example");
    m_button->resize(100, 100);
}

//window::~window ()
//{}
