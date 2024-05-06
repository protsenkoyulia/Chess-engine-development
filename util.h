//
// Created by misha on 06.05.24.
//

#ifndef CHESS_ENGINE_UTIL_H
#define CHESS_ENGINE_UTIL_H

#include "BASE/chess.cpp"
#include <QObject>

namespace util {

    static chess::Board b;

    class MoveValidator {
    public:
        static bool isValidMove(const std::string& move) {
            const chess::LegalMoveGenerator &generator = b.legal_moves();

            for(chess::Move m: generator){
                if (m.uci() == move){
                    return true;
                }
            }

            return false;
        }
    };

    static QObject* updateObject = new QObject;

    class BoardImage : public QObject {
    public:
        static std::string getBoardFen() {
            return b.fen();
        }

        static void doMove(const std::string& move) {
            b.push_uci(move);
            updateObject->destroyed(nullptr);
        };

        static QObject* getUpdateObject() {
            return updateObject;
        }
    };

}

#endif //CHESS_ENGINE_UTIL_H
