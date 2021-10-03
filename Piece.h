#pragma once
#include <iostream>
#include <stdint.h>


class Piece
{
	size_t r;
	size_t c;

	int8_t* p;
 

public:
	enum class Transform { ccw90, ccw180, cw90, cw180, flipHoriz, flipVert };
	enum class Tile { empty = 0, busy = 1, blue = 2, yellow=3, green=4, orange=5, lightblue=6, gray=7, brown=8, violet=9, red=10 };


	Piece(size_t r, size_t c, int8_t* pca, Tile tile) {
		this->r = r;
		this->c = c;

		p = new int8_t[r*c];

		for (size_t i = 0; i < r; i++)
			for (size_t j = 0; j < c; j++) {
				*(p + i*c + j) = *(pca + i * c + j) * static_cast<int>(tile);
			}

	}

	int8_t& operator()(size_t i, size_t j) {
		return *(p + i * c + j);
	}

	size_t GetRows() const {
		return r;
	}

	size_t GetCols() const {
		return c;
	}

	void Transform(Transform t) {
		switch (t) {
		case Transform::ccw90:
		{
			size_t nr = c;
			size_t nc = r;
			int8_t* npa = new int8_t[nr*nc];
			for (size_t i = 0; i < r; i++)
				for (size_t j = 0; j < c; j++)
					*(npa + (nr - j - 1)*r + i) = *(p + i*c + j);
			delete[] p;

			r = nr;
			c = nc;
			p = npa;
		}
			break;
		case Transform::flipHoriz:
		{
			int8_t* npa = new int8_t[r*c];
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					*(npa + i*c + c - j - 1) = *(p + i*c + j);
				}
			}
			delete[] p;

			p = npa;

		}
			break;


		}
	}

	size_t Coverage() {
		size_t coverage = 0;

		for (size_t i = 0; i < r; i++) {
			for (size_t j = 0; j < c; j++)
				if (*(p + i * c + j) != static_cast<int>(Piece::Tile::empty))
					coverage++;
		}

		return coverage;
	}
	void Print() {
		for (size_t i = 0; i < r; i++) {
			for (size_t j = 0; j < c; j++)
				std::cout << (int) *(p + i*c + j) << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;

	}

};

