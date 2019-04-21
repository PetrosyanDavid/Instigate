#include "keypress.hpp"
key_press::key_press(QWidget* parent)
    : QWidget(parent)
{
    my_label = new QLabel("Label");
    main_layout = new QVBoxLayout;
    main_layout->addWidget(my_label);
    setLayout(main_layout);
}

void key_press::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Tab) {
        my_label->setText("You Pressed Esc");
    } else {
        my_label->setText("You pressed something else");
    }
}

void key_press::keyReleaseEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Tab) {
        my_label->setText("You released Esc");
    } else {
        my_label->setText("You released something else");
    }
}
