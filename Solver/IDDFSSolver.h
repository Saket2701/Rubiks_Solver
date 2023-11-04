//
// Created by saket on 02-11-2023.
//

#include<bits/stdc++.h>
#include "../Model/GenericRubiksCube.h"
#include "DFSSolver.h"

#ifndef RUBIKS_IDDFSSOLVER_H
#define RUBIKS_IDDFSSOLVER_H

template<typename T, typename H>
class IDDFSSolver {

private:
    int max_search_depth;
    vector<GenericRubiksCube::MOVE> moves;

public:
    T rubiksCube;

    IDDFSSolver(T _rubiksCube, int _max_search_depth = 7) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

//    Used DFSSolver with increasing max_search_depth
    vector<GenericRubiksCube::MOVE> solve() {
        for (int i = 1; i <= max_search_depth; i++) {
            DFSSolver<T, H> dfsSolver(rubiksCube, i);
            moves = dfsSolver.solve();
            if (dfsSolver.rubiksCube.isSolved()) {
                rubiksCube = dfsSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }


};

#endif //RUBIKS_IDDFSSOLVER_H
