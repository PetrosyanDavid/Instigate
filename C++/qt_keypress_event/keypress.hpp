#ifndef KEYPRESS_HPP
#define KEYPRESS_HPP

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QApplication>

class key_press : public QWidget
{
    Q_OBJECT
    public:
        key_press(QWidget* parent = 0);

    protected:
        void keyPressEvent(QKeyEvent*);
        void keyReleaseEvent(QKeyEvent*);

    private:
        QLabel* my_label;
        QVBoxLayout* main_layout;
};

#endif //keypress.hpp
