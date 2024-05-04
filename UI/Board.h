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

    public:

        explicit Board(QWidget* parent = nullptr);

        ~Board() override;

    private:

        void initCells();

        QWidget* createCell(int, int);

        void initPiece();

        Piece* createPiece(PieceType type);

        void parseFen(QString);

        static PieceType parseFenToPieceType(char);

    private slots:

        void handleMove(Piece*);

    };

} // UI

#endif //CHESS_ENGINE_BOARD_H
