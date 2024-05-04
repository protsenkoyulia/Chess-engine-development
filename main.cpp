#include <QApplication>
#include "UI/Board.h"
#include "BASE/chess.cpp"
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    UI::Board board;

    board.show();

    return QApplication::exec();
}
