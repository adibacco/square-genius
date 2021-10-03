#pragma once
#include <iostream>
#include <cstring>
#include <vector>

#include "Piece.h"

using namespace std;

class Grid
{
	size_t rows;
	size_t cols;
	int8_t* grid;
public:
	Grid(size_t r, size_t c) {
		this->rows = r;
		this->cols = c;
		grid = new int8_t[r * c];
		memset(grid, 0, r * c);
	}

    size_t GetSize() {
        return rows * cols;
    }

    void Clear() {
        memset(grid, 0, rows * cols);

    }

    int8_t& operator()(size_t i, size_t j) {
        return *(grid + i * cols + j);
    }

    void SetPins(vector<size_t>& pins) {

        for (vector<size_t>::iterator it = pins.begin(); it != pins.end(); it++) {
            size_t r = *it / cols;
            size_t c = *it % rows;

            SetPinAt(r, c);


        }
    }

    void SetPinAt(size_t r, size_t c) {

        grid[r * cols + c] = static_cast<int>(Piece::Tile::busy);
    }

    bool PlacePieceAt(Piece& piece, size_t idx) {
        size_t r = idx / cols;
        size_t c = idx % rows;

        bool placeable = true;

        for (size_t pi = 0; pi < piece.GetRows(); pi++) {
            for (size_t pj = 0; pj < piece.GetCols(); pj++) {
                if (piece(pi, pj) != static_cast<int>(Piece::Tile::empty)) {
                    if (((r + pi) < rows) && ((c + pj) < cols)) {
                        if (grid[(r + pi) * cols + c + pj] != static_cast<int>(Piece::Tile::empty))
                            placeable = false;
                        else
                            placeable = true;
                    }
                    else
                        placeable = false;
                }
                else
                    placeable = true;

                if (!placeable)
                    break;
            }
            if (!placeable)
                break;
        }

        if (placeable) {
            for (size_t pi = 0; pi < piece.GetRows(); pi++) {
                for (size_t pj = 0; pj < piece.GetCols(); pj++) {
                    if (piece(pi, pj) != static_cast<int>(Piece::Tile::empty))
                        *(grid + (r + pi) * cols + c + pj) = piece(pi, pj);
                }
            }
        }
        return placeable;

    }

    bool isComplete() {
        for (size_t r = 0; r < rows; r++) {
            for (size_t c = 0; c < cols; c++) {
                if (grid[r * cols + c] == static_cast<int>(Piece::Tile::empty))
                    return false;
            }
        }
        return true;
    }

    void Print() {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++)
                std::cout << (int)*(grid + i * cols + j) << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;

    }

};

