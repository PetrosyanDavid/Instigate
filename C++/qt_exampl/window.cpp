#include "window.hpp"
#include <QCoreApplication>

window::window (QWidget *parent) :
    QMainWindow(parent)
{
    m_button = new QPushButton("My Button", this);
    m_button->setGeometry(QRect(QPoint(100, 100),QSize(200,50)));

    connect(m_button, SIGNAL (released()), this, SLOT(handleButton()));
}

void window::key_press_event (QKeyEvent* event)
{
    if (event->key() == Qt::Key_Q) {
        m_button->setText("You Pressed Tab");
    } else {
        m_button->setText("You pressed something else");
    }
}

void window::handleButton()
{
    m_button->setText("Example");
    m_button->resize(100, 100);
}

//window::~window ()
//{}
