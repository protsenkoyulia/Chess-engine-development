//
// Created by misha on 03.05.24.
//

#include "Piece.h"

UI::Piece::Piece(PieceType type, QWidget *parent) : QWidget(parent) {
    this->type = type;
    initImage();

    installEventFilter(this);
}

UI::Piece::Piece(const UI::Piece &piece) : QWidget(piece.parentWidget()) {
    this->type = piece.type;
    initImage();
}

void UI::Piece::initImage() {
    imagePiece = new QLabel(this);

    QFont font;
    font.setPointSize(92);
    imagePiece->setFont(font);
    imagePiece->setAlignment(Qt::AlignCenter);
    imagePiece->setGeometry(0, 0, 100, 100);
    imagePiece->setText(convertTypeToUNICODE(type));
}

UI::Piece &UI::Piece::operator=(const UI::Piece &piece) {
    this->type = piece.type;
    initImage();

    return *this;
}

UI::Piece::~Piece() {
    delete imagePiece;
}

QString UI::Piece::convertTypeToUNICODE(UI::PieceType type) {
    {
        switch (type) {
            case WHITE_KING:
                return QString::fromWCharArray(L"\x2654");
            case WHITE_QUEEN:
                return QString::fromWCharArray(L"\x2655");
            case WHITE_ROOK:
                return QString::fromWCharArray(L"\x2656");
            case WHITE_BISHOP:
                return QString::fromWCharArray(L"\x2657");
            case WHITE_KNIGHT:
                return QString::fromWCharArray(L"\x2658");
            case WHITE_PAWN:
                return QString::fromWCharArray(L"\x2659");
            case BLACK_KING:
                return QString::fromWCharArray(L"\x265A");
            case BLACK_QUEEN:
                return QString::fromWCharArray(L"\x265B");
            case BLACK_ROOK:
                return QString::fromWCharArray(L"\x265C");
            case BLACK_BISHOP:
                return QString::fromWCharArray(L"\x265D");
            case BLACK_KNIGHT:
                return QString::fromWCharArray(L"\x265E");
            case BLACK_PAWN:
                return QString::fromWCharArray(L"\x265F");
            default:
                return "";
        }
    }
}

void UI::Piece::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        oldPos = event->pos();

        emit selected(this);
    }
}

void UI::Piece::mouseMoveEvent(QMouseEvent *event) {
    QPoint delta = event->pos() - oldPos;
    move(pos() + delta);
}

void UI::Piece::mouseReleaseEvent(QMouseEvent *event) {
    emit doMove(this);
}
