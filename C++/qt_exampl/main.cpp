#include <QApplication>
#include <QDebug>
#include <QPushButton>
#include <window.hpp>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    window window;
    window.showMaximized();
    return app.exec();
}
