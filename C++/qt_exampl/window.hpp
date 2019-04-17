#ifndef QT_WINDOW_HPP
#define QT_WINDOW_HPP

#include <QWidget>
#include <QPushButton>

//class QPushButton;
class window : public QWidget
{
    public:
        explicit window (QWidget* parent = 0);
    private:
        QPushButton* m_button;
};

#endif
