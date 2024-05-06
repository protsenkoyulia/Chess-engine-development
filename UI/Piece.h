//
// Created by misha on 03.05.24.
//

#ifndef CHESS_ENGINE_PIECE_H
#define CHESS_ENGINE_PIECE_H

#include <QString>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

namespace UI {

    enum PieceType {
        WHITE_KING,
        WHITE_QUEEN,
        WHITE_ROOK,
        WHITE_BISHOP,
        WHITE_KNIGHT,
        WHITE_PAWN,
        BLACK_KING,
        BLACK_QUEEN,
        BLACK_ROOK,
        BLACK_BISHOP,
        BLACK_KNIGHT,
        BLACK_PAWN
    };

    class Piece : public QWidget {
        Q_OBJECT

        QLabel* imagePiece{};

        PieceType type;

        QPoint oldPos;

    public:

        static QString convertTypeToUNICODE(PieceType);

        explicit Piece(PieceType, QWidget* parent = nullptr);

        Piece(const Piece &);

        ~Piece() override;

        Piece& operator = (const Piece &);

    protected:

        void mousePressEvent(QMouseEvent *) override;

        void mouseMoveEvent(QMouseEvent *) override;

        void mouseReleaseEvent(QMouseEvent *) override;

    private:

        void initImage();

    signals:

        void doMove(Piece *);

        void selected(Piece *);
    };

}

#endif //CHESS_ENGINE_PIECE_H
