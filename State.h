#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Piece.h"

using namespace std;

class State
{
	map<int, pair<pair<int, int>, pair<int, int>>> state;
	map<int, vector<Piece*>*> pieces;

public:
	State(map<int, vector<Piece*>*> pieces, size_t gridSize) {

        for (map<int, vector<Piece*>*>::iterator mit = pieces.begin(); mit != pieces.end(); mit++) {
            vector<Piece*>* v = mit->second;
            state[mit->first] = make_pair(make_pair( v->size()-1, gridSize-1), make_pair(v->size() - 1, gridSize - 1));

        }
	}

	void Print() {
		for (map<int, pair<pair<int, int>, pair<int, int>>>::iterator it = state.begin(); it != state.end(); it++) {
			cout << it->second.second.first << " " << it->second.second.second << "; ";
		}
		cout << endl;
	}

    int64_t Count() {
		int64_t num = 1;
		for (map<int, pair<pair<int, int>, pair<int, int>>>::iterator it = state.begin(); it != state.end(); it++) {
			num = num * (it->second.first.first + 1)* (it->second.first.second + 1);
		}
		return num;
	}

	bool UpdateElement(map<int, pair<pair<int, int>, pair<int, int>>>::iterator it) {
		pair<int, int> initial = it->second.first;
		pair<int, int> current = it->second.second;
		if (current.second > 0) {
			current.second = current.second - 1;
			it->second.second = current;
			return true;
		}
		else {
			if (current.first > 0) {
				current.first = current.first - 1;
				current.second = initial.second;
				it->second.second = current;
				return true;
			}
		}

		return false;
	}

	void ReinitializeElement(map<int, pair<pair<int, int>, pair<int, int>>>::iterator it) {
		pair<int, int> initial = it->second.first;
		it->second.second = initial;
	}


	bool next() {
		bool newState = false;

		for (map<int, pair<pair<int, int>, pair<int, int>>>::iterator nxt, it = state.begin(); it != state.end(); it++) {
			if (UpdateElement(it)) {
				newState = true;
				break;
			}
			else {
				nxt = std::next(it, 1);
				if (nxt != state.end()) {
					ReinitializeElement(it);
					UpdateElement(nxt);
					newState = true;
					break;
				}
				else {
					newState = false;
					break;
				}
			}

		}

		return newState;
	}

	map<int, pair<pair<int, int>, pair<int, int>>>& GetState() {
		return state;
	}

};

