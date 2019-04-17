#ifndef QT_WINDOW_HPP
#define QT_WINDOW_HPP

#include <QWidget>
#include <QPushButton>
#include <QMainWindow>

//class QPushButton;
class window : public QMainWindow
{
    Q_OBJECT
    public:
        explicit window (QWidget* parent = 0);
        //~window();
    private:
        QPushButton* m_button;
    private slots:
        void handleButton();
};

#endif
