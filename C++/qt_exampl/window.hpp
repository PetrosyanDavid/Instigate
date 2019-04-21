#ifndef QT_WINDOW_HPP
#define QT_WINDOW_HPP

#include <QWidget>
#include <QPushButton>
#include <QMainWindow>
#include <QKeyEvent>

//class QPushButton;
class window : public QMainWindow
{
    Q_OBJECT
    public:
        explicit window (QWidget* parent = 0);
        void key_press_event(QKeyEvent*);
        //~window();
    private:
        QPushButton* m_button;
    private slots:
        void handleButton();
};

#endif
