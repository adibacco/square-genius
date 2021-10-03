// SquareGrid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include "Piece.h"
#include "Grid.h"
#include "State.h"

using namespace std;


void populatePieces(map<int, vector<Piece*>*>& pieces) {

    vector<Piece*>* redPieces = new vector<Piece*>();
    int8_t red[2][3] = { { 0, 1, 1 }, { 1, 1, 0 } };
    Piece* p = new Piece(2, 3, (int8_t*)&red[0][0], Piece::Tile::red);
    redPieces->push_back(p);

    int8_t redflipv[2][3] = { { 1, 1, 0 }, { 0, 1, 1 } };
    Piece* p = new Piece(2, 3, (int8_t*)&redflipv[0][0], Piece::Tile::red);
    redPieces->push_back(p);

    int8_t redccw90[3][2] = { { 1, 0 }, { 1, 1 }, { 0, 1 } };
    p = new Piece(3, 2, (int8_t*)&redccw90[0][0], Piece::Tile::red);
    redPieces->push_back(p);

    int8_t redfliph[3][2] = { { 0, 1 }, { 1, 1 }, { 1, 0 } };
    p = new Piece(3, 2, (int8_t*)&redfliph[0][0], Piece::Tile::red);
    redPieces->push_back(p);


    vector<Piece*>* orangePieces = new vector<Piece*>();
    int8_t orange[1][3] = { { 1, 1, 1 } };
    p = new Piece(1, 3, (int8_t*)&orange[0][0], Piece::Tile::orange);
    orangePieces->push_back(p);

    int8_t orangeccw90[3][1] = { { 1 }, { 1 }, { 1 } };
    p = new Piece(3, 1, (int8_t*)&orangeccw90[0][0], Piece::Tile::orange);
    orangePieces->push_back(p);


    vector<Piece*>* bluePieces = new vector<Piece*>();
    int8_t blue[1][1] = { { 1 } };
    p = new Piece(1, 1, (int8_t*)&blue[0][0], Piece::Tile::blue);
    bluePieces->push_back(p);


    vector<Piece*>* violetPieces = new vector<Piece*>();
    int8_t violet[2][2] = { { 1, 0 }, { 1, 1 } };
    p = new Piece(2, 2, (int8_t*)&violet[0][0], Piece::Tile::violet);
    violetPieces->push_back(p);

    int8_t violetcw90[2][2] = { { 1, 1 }, { 1, 0 } };
    p = new Piece(2, 2, (int8_t*)&violetcw90[0][0], Piece::Tile::violet);
    violetPieces->push_back(p);

    int8_t violetcw180[2][2] = { { 1, 1 }, { 0, 1 } };
    p = new Piece(2, 2, (int8_t*)&violetcw180[0][0], Piece::Tile::violet);
    violetPieces->push_back(p);

    int8_t violetccw90[2][2] = { { 0, 1 }, { 1, 1 } };
    p = new Piece(2, 2, (int8_t*)&violetccw90[0][0], Piece::Tile::violet);
    violetPieces->push_back(p);


    vector<Piece*>* yellowPieces = new vector<Piece*>();
    int8_t yellow[2][3] = { { 0, 1, 0 }, { 1, 1, 1 } };
    p = new Piece(2, 3, (int8_t*)&yellow[0][0], Piece::Tile::yellow);
    yellowPieces->push_back(p);

    int8_t yellowflipv[2][3] = { { 1, 1, 1 }, { 0, 1, 0 } };
    p = new Piece(2, 3, (int8_t*)&yellowflipv[0][0], Piece::Tile::yellow);
    yellowPieces->push_back(p);

    int8_t yellowccw90[3][2] = { { 0, 1}, { 1, 1 }, { 0, 1 } };
    p = new Piece(3, 2, (int8_t*)&yellowccw90[0][0], Piece::Tile::yellow);
    yellowPieces->push_back(p);

    int8_t yellowcw90[3][2] = { { 1, 0}, { 1, 1 }, { 1, 0 } };
    p = new Piece(3, 2, (int8_t*)&yellowcw90[0][0], Piece::Tile::yellow);
    yellowPieces->push_back(p);


    vector<Piece*>* greenPieces = new vector<Piece*>();
    int8_t green[2][2] = { { 1, 1}, { 1, 1 } };
    p = new Piece(2, 2, (int8_t*)&green[0][0], Piece::Tile::green);
    greenPieces->push_back(p);

    vector<Piece*>* grayPieces = new vector<Piece*>();
    int8_t gray[1][4] = { { 1, 1, 1, 1 } };
    p = new Piece(1, 4, (int8_t*)&gray[0][0], Piece::Tile::gray);
    grayPieces->push_back(p);

    int8_t graycw90[4][1] = { { 1 }, { 1 }, { 1 }, { 1 } };
    p = new Piece(4, 1, (int8_t*)&graycw90[0][0], Piece::Tile::gray);
    grayPieces->push_back(p);

    vector<Piece*>* lightbluePieces = new vector<Piece*>();
    int8_t lightblue[3][2] = { { 1, 0 }, { 1, 0 }, { 1, 1 } };
    p = new Piece(3, 2, (int8_t*)&lightblue[0][0], Piece::Tile::lightblue);
    lightbluePieces->push_back(p);

    int8_t lightblueflip[3][2] = { { 1, 1 }, { 1, 0 },  { 1, 0 } };
    p = new Piece(3, 2, (int8_t*)&lightblueflip[0][0], Piece::Tile::lightblue);
    lightbluePieces->push_back(p);

    int8_t lightbluecw90[2][3] = { { 1, 0, 0 }, { 1, 1, 1 } };
    p = new Piece(2, 3, (int8_t*)&lightbluecw90[0][0], Piece::Tile::lightblue);
    lightbluePieces->push_back(p);

    int8_t lightblueccw90[2][3] = { { 0, 0, 1 }, { 1, 1, 1 } };
    p = new Piece(2, 3, (int8_t*)&lightblueccw90[0][0], Piece::Tile::lightblue);
    lightbluePieces->push_back(p);

    vector<Piece*>* brownPieces = new vector<Piece*>();
    int8_t brown[1][2] = { { 1, 1 } };
    p = new Piece(1, 2, (int8_t*)&brown[0][0], Piece::Tile::brown);
    brownPieces->push_back(p);

    int8_t browncw90[2][1] = { { 1 }, { 1 } };
    p = new Piece(2, 1, (int8_t*)&browncw90[0][0], Piece::Tile::brown);
    brownPieces->push_back(p);

    pieces[static_cast<int>(Piece::Tile::red)] = redPieces;
    pieces[static_cast<int>(Piece::Tile::orange)] = orangePieces;
    pieces[static_cast<int>(Piece::Tile::blue)] = bluePieces;
    pieces[static_cast<int>(Piece::Tile::violet)] = violetPieces;
    pieces[static_cast<int>(Piece::Tile::yellow)] = yellowPieces;
    pieces[static_cast<int>(Piece::Tile::green)] = greenPieces;
    pieces[static_cast<int>(Piece::Tile::gray)] = grayPieces;
    pieces[static_cast<int>(Piece::Tile::lightblue)] = lightbluePieces;
    pieces[static_cast<int>(Piece::Tile::brown)] = brownPieces;

}



int main()
{
    std::cout << "Starting!\n";

    map<int, vector<Piece*>*> pieces;

    populatePieces(pieces);


    for (map<int, vector<Piece*>*>::iterator mit = pieces.begin(); mit != pieces.end(); mit++) {
        vector<Piece*>* v = mit->second;

        for (vector<Piece*>::iterator it = (*v).begin(); it != (*v).end(); it++) {
            (*it)->Print();
        }

        cout << endl;
    }

    Grid* grid = new Grid(6, 6);
    vector<size_t> pins{ 0, 12, 18, 3, 15, 21 };
    grid->SetPins(pins);
 
    grid->Print();

    size_t coverage = 0;

    for (map<int, vector<Piece*>*>::iterator mit = pieces.begin(); mit != pieces.end(); mit++) {
        vector<Piece*>* v = mit->second;
        coverage += v->at(0)->Coverage();
    }

    cout << coverage << endl;

    State* state = new State(pieces, grid->GetSize());

    size_t count = 0;
    cout << "States count " << state->Count() << endl;
    do {
        map<int, pair<pair<int, int>, pair<int, int>>> current = state->GetState();
        //state->Print();

        grid->Clear();
        grid->SetPins(pins);
        /*
        for (map<int, pair<pair<int, int>, pair<int, int>>>::iterator it = current.begin(); it != current.end(); it++) {
            pair<pair<int, int>, pair<int, int>> testPiece = it->second;
            
        }
        */
        count++;
        if (count % 100000 == 0)
            cout << "count " << count << endl;
    } while (state->next());

    cout << "Count " << count << endl;

}


