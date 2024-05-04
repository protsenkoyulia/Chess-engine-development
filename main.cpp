#include <QApplication>
#include "UI/Board.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    UI::Board board;

    board.show();

    return QApplication::exec();
}
