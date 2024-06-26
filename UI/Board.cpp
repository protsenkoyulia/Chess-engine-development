//
// Created by misha on 03.05.24.
//

#include "Board.h"
#include <stdexcept>
#include <QDebug>

namespace UI {

    Board::Board(QWidget *parent) : QWidget(parent)
    {
        initCells();
        initPiece();
        parseFen("8/8/5k2/8/8/8/8/8");
    }

    Board::~Board() {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                delete cells[i][j];
                delete pieces[i][j];
            }
            delete cells[i];
            delete pieces[i];
        }

        delete cells;
        delete pieces;
    }

    QWidget *Board::createCell(int row, int column) {
        auto* cell = new QWidget(this);

        cell->setGeometry(row * 100, column * 100, 100, 100);

        if ((row + column) % 2 == 0) {
            cell->setStyleSheet("background-color: rgb(192, 192, 192)");
        } else {
            cell->setStyleSheet("background-color: rgb(64, 64, 64)");
        }

        return cell;
    }

    void Board::initCells()  {
        cells = new QWidget ** [8];

        for (int i = 0; i < 8; i++) {
            cells[i] = new QWidget * [8];

            for (int j = 0; j < 8; j++) {
                cells[i][j] = createCell(i, j);
            }
        }
    }

    void Board::initPiece() {
        pieces = new Piece **[8];

        for (int i = 0; i < 8; i++) {
            pieces[i] = new Piece *[8];
        }
    }

    Piece* Board::createPiece(PieceType type) {
        auto* piece = new Piece(type, this);

        connect(piece, SIGNAL(doMove(Piece *)), this, SLOT(handleMove(Piece *)));

        return piece;
    }

    void Board::handleMove(Piece *piece) {
        int x = (piece->pos().x() + 50) / 100;
        int y = (piece->pos().y() + 50) / 100;

        auto cell = cells[x][y];
        piece->setGeometry(cell->x(), cell->y(), 100, 100);
    }

    void Board::parseFen(QString fen) {
        int index = fen.indexOf(" ");
        fen = (index != -1) ? fen.left(index) : fen;

        for (int i = 0; i < 8; i++) {
            index = fen.indexOf("/");

            QString left = fen.left(index);
            fen = fen.right(fen.length() - index - 1);

            for (int j = 0, step = 0; j < left.length(); j++, step++) {

                bool isDigit = false;
                int tmp = QString(left[j]).toInt(&isDigit);
                if (isDigit) {
                    step += tmp - 1;
                    continue;
                }

                Piece* piece = createPiece(parseFenToPieceType(left[j].toLatin1()));
                const QPoint &point = cells[step][i]->pos();
                piece->setGeometry(point.x(), point.y(), 100, 100);

                pieces[step][i] = piece;
            }
        }
    }

    PieceType Board::parseFenToPieceType(char symbol) {
        switch (symbol) {
            case 'K':
                return WHITE_KING;
            case 'Q':
                return WHITE_QUEEN;
            case 'R':
                return WHITE_ROOK;
            case 'B':
                return WHITE_BISHOP;
            case 'N':
                return WHITE_KNIGHT;
            case 'P':
                return WHITE_PAWN;
            case 'k':
                return BLACK_KING;
            case 'q':
                return BLACK_QUEEN;
            case 'r':
                return BLACK_ROOK;
            case 'b':
                return BLACK_BISHOP;
            case 'n':
                return BLACK_KNIGHT;
            case 'p':
                return BLACK_PAWN;
            default:
                throw std::invalid_argument("cannot convert symbol to piece!");;
        }
    }

} // UI