//
// Created by misha on 03.05.24.
//

#ifndef CHESS_ENGINE_BOARD_H
#define CHESS_ENGINE_BOARD_H

#include <QWidget>
#include "Piece.h"

namespace UI {

    class Board : public QWidget {
        Q_OBJECT

        QWidget*** cells;

        Piece*** pieces;

        QPoint fromMove;

    public:

        explicit Board(QWidget* parent = nullptr);

        ~Board() override;

    private:

        void initCells();

        QWidget* createCell(int, int);

        void initPiece();

        Piece* createPiece(PieceType type);

        void parseFen(QString);

        void clearBoard();

        static PieceType parseFenToPieceType(char);

        static QString convertCoordinateToChessPosition(QPoint);

    private slots:

        void handleSelected(Piece *);

        void handleMove(Piece *);

        void updateBoard(QObject *);

    };

} // UI

#endif //CHESS_ENGINE_BOARD_H
