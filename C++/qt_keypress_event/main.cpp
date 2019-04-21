#include "keypress.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    key_press* key_p = new key_press();
    key_p->show();

    return app.exec();
}
