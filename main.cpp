#include "bits/stdc++.h"

using namespace std;

#include "Model/RubiksCube3dArray.cpp"
#include "Model/RubiksCube1dArray.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Solver/IDAstarSolver.h"
#include "PatternDatabases/CornerPatternDatabase.h"
#include "PatternDatabases/CornerDBMaker.h"

int main() {
    cout << "=======================================" << endl;
    cout << "  Rubik's Cube Solver Main Program" << endl;
    cout << "=======================================" << endl;
    cout << "          Created by Saket2701         " << endl;
    cout << "=======================================" << endl;

    cout << "Choose an option:" << endl;
    cout << "1. View a corner pattern" << endl;
    cout << "2. Solve a Rubik's Cube" << endl;

    int option;
    cin >> option;

    if (option == 1) {
        CornerPatternDatabase cornerDB;
        RubiksCubeBitboard cube;
        cube.print();
        cout << "***************************************" << endl;
        cout << "*      Viewing a Corner Pattern       *" << endl;
        cout << "***************************************" << endl;
        cout << "Number of Moves: " << (int) cornerDB.getNumMoves(cube) << "\n";
        cornerDB.setNumMoves(cube, 5);
        cout << "Updated Number of Moves: " << (int) cornerDB.getNumMoves(cube) << "\n";
        cube.randomShuffleCube(1);
        cube.print();
        cout << "Number of Moves after Shuffling: " << (int) cornerDB.getNumMoves(cube) << "\n";
        cornerDB.setNumMoves(cube, 6);
        cout << "Updated Number of Moves: " << (int) cornerDB.getNumMoves(cube) << "\n";
    } else if (option == 2) {
        RubiksCube3dArray cube;
        cube.print();

        cout << "Enter the number of shuffling moves: ";
        int numShuffleMoves;
        cin >> numShuffleMoves;

        vector<GenericRubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(numShuffleMoves);
        for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
        cout << "\n";
        cube.print();

        cout << "Choose a solver (1 for DFS, 2 for BFS, 3 for IDDFS, 4 for IDA*): ";
        int solverChoice;
        cin >> solverChoice;

        if (solverChoice == 1) {
            cout << "***************************************" << endl;
            cout << "*            DFS Solver                *" << endl;
            cout << "***************************************" << endl;

            cout << "Choose a Rubik's Cube model:" << endl;
            cout << "1. 1D Array Model" << endl;
            cout << "2. 3D Array Model" << endl;
            cout << "3. Bitboard Model" << endl;

            int cubeModelChoice;
            cin >> cubeModelChoice;

            GenericRubiksCube* cube = nullptr;

            if (cubeModelChoice == 1) {
                RubiksCube1dArray cube;
                DFSSolver<RubiksCube1dArray, Hash1d> dfsSolver(cube, 8);
                vector<GenericRubiksCube::MOVE> solve_moves = dfsSolver.solve();

                cout << "Solution: ";
                for (auto move: solve_moves) cout << cube.getMove(move) << " ";
                cout << "\n";
                dfsSolver.rubiksCube.print();
            } else if (cubeModelChoice == 2) {
                RubiksCube3dArray cube;
                DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 8);
                vector<GenericRubiksCube::MOVE> solve_moves = dfsSolver.solve();

                cout << "Solution: ";
                for (auto move: solve_moves) cout << cube.getMove(move) << " ";
                cout << "\n";
                dfsSolver.rubiksCube.print();
            } else if (cubeModelChoice == 3) {
                RubiksCubeBitboard cube;
                DFSSolver<RubiksCubeBitboard, HashBitboard> dfsSolver(cube, 8);
                vector<GenericRubiksCube::MOVE> solve_moves = dfsSolver.solve();

                cout << "Solution: ";
                for (auto move: solve_moves) cout << cube.getMove(move) << " ";
                cout << "\n";
                dfsSolver.rubiksCube.print();
            } else {
                cout << "Invalid model choice. Please choose 1 for 1D Array, 2 for 3D Array, or 3 for Bitboard." << endl;
                return 0;
            }
        } else if (solverChoice == 2) {
            cout << "***************************************" << endl;
            cout << "*            BFS Solver                *" << endl;
            cout << "***************************************" << endl;

            cout << "Choose a Rubik's Cube model:" << endl;
            cout << "1. 1D Array Model" << endl;
            cout << "2. 3D Array Model" << endl;
            cout << "3. Bitboard Model" << endl;

            int cubeModelChoice;
            cin >> cubeModelChoice;

            GenericRubiksCube* cube = nullptr;

            if (cubeModelChoice == 1) {
                RubiksCube1dArray cube;
                BFSSolver<RubiksCube1dArray, Hash1d> bfsSolver(cube, 8);
                vector<GenericRubiksCube::MOVE> solve_moves = bfsSolver.solve();

                cout << "Solution: ";
                for (auto move: solve_moves) cout << cube.getMove(move) << " ";
                cout << "\n";
                bfsSolver.rubiksCube.print();
            } else if (cubeModelChoice == 2) {
                RubiksCube3dArray cube;
                BFSSolver<RubiksCube3dArray, Hash3d> bfsSolver(cube, 8);
                vector<GenericRubiksCube::MOVE> solve_moves = bfsSolver.solve();

                cout << "Solution: ";
                for (auto move: solve_moves) cout << cube.getMove(move) << " ";
                cout << "\n";
                bfsSolver.rubiksCube.print();
            } else if (cubeModelChoice == 3) {
                RubiksCubeBitboard cube;
                BFSSolver<RubiksCubeBitboard, HashBitboard> bfsSolver(cube, 8);
                vector<GenericRubiksCube::MOVE> solve_moves = bfsSolver.solve();

                cout << "Solution: ";
                for (auto move: solve_moves) cout << cube.getMove(move) << " ";
                cout << "\n";
                bfsSolver.rubiksCube.print();
            } else {
                cout << "Invalid model choice. Please choose 1 for 1D Array, 2 for 3D Array, or 3 for Bitboard." << endl;
                return 0;
            }
        } else if (solverChoice == 3) {
            cout << "***************************************" << endl;
            cout << "*            IDDFS Solver              *" << endl;
            cout << "***************************************" << endl;

            cout << "Choose a Rubik's Cube model:" << endl;
            cout << "1. 1D Array Model" << endl;
            cout << "2. 3D Array Model" << endl;
            cout << "3. Bitboard Model" << endl;

            int cubeModelChoice;
            cin >> cubeModelChoice;

            GenericRubiksCube* cube = nullptr;

            if (cubeModelChoice == 1) {
                RubiksCube1dArray cube;
                IDDFSSolver<RubiksCube1dArray, Hash1d> iddfsSolver(cube, 7);
                vector<GenericRubiksCube::MOVE> solve_moves = iddfsSolver.solve();

                cout << "Solution: ";
                for (auto move: solve_moves) cout << cube.getMove(move) << " ";
                cout << "\n";
                iddfsSolver.rubiksCube.print();
            } else if (cubeModelChoice == 2) {
                RubiksCube3dArray cube;
                IDDFSSolver<RubiksCube3dArray, Hash3d> iddfsSolver(cube, 7);
                vector<GenericRubiksCube::MOVE> solve_moves = iddfsSolver.solve();

                cout << "Solution: ";
                for (auto move: solve_moves) cout << cube.getMove(move) << " ";
                cout << "\n";
                iddfsSolver.rubiksCube.print();
            } else if (cubeModelChoice == 3) {
                RubiksCubeBitboard cube;
                IDDFSSolver<RubiksCubeBitboard, HashBitboard> iddfsSolver(cube, 7);
                vector<GenericRubiksCube::MOVE> solve_moves = iddfsSolver.solve();

                cout << "Solution: ";
                for (auto move: solve_moves) cout << cube.getMove(move) << " ";
                cout << "\n";
                iddfsSolver.rubiksCube.print();
            } else {
                cout << "Invalid model choice. Please choose 1 for 1D Array, 2 for 3D Array, or 3 for Bitboard." << endl;
                return 0;
            }
        } else if (solverChoice == 4) {
            cout << "***************************************" << endl;
            cout << "*            IDA* Solver               *" << endl;
            cout << "***************************************" << endl;

            cout << "Choose a Rubik's Cube model:" << endl;
            cout << "1. 1D Array Model" << endl;
            cout << "2. 3D Array Model" << endl;
            cout << "3. Bitboard Model" << endl;

            int cubeModelChoice;
            cin >> cubeModelChoice;

            GenericRubiksCube* cube = nullptr;

            if (cubeModelChoice == 1) {
                RubiksCube1dArray cube;
                string fileName = "Databases/cornerDepth5V1.txt";
                IDAstarSolver<RubiksCube1dArray, Hash1d> idaStarSolver(cube, fileName);
                auto moves = idaStarSolver.solve();
                idaStarSolver.rubiksCube.print();

                cout << "Solution: ";
                for (auto move: moves) cout << cube.getMove(move) << " ";
                cout << "\n";
                return 0;
            } else if (cubeModelChoice == 2) {
                RubiksCube3dArray cube;
                string fileName = "Databases/cornerDepth5V1.txt";
                IDAstarSolver<RubiksCube3dArray, Hash3d> idaStarSolver(cube, fileName);
                auto moves = idaStarSolver.solve();
                idaStarSolver.rubiksCube.print();

                cout << "Solution: ";
                for (auto move: moves) cout << cube.getMove(move) << " ";
                cout << "\n";
                return 0;
            } else if (cubeModelChoice == 3) {
                string fileName = "Databases/cornerDepth5V1.txt";
                RubiksCubeBitboard cube;
                IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
                auto moves = idaStarSolver.solve();
                idaStarSolver.rubiksCube.print();

                cout << "Solution: ";
                for (auto move: moves) cout << cube.getMove(move) << " ";
                cout << "\n";
                return 0;
            } else {
                cout << "Invalid model choice. Please choose 1 for 1D Array, 2 for 3D Array, or 3 for Bitboard." << endl;
                return 0;
            }
        } else {
            cout << "Invalid solver choice. Please choose 1 for DFS, 2 for BFS, 3 for IDDFS, 4 for IDA* ." << endl;
        }
    } else {
        cout << "Invalid option. Please choose 1 to view a corner pattern or 2 to solve a Rubik's Cube." << endl;
    }
    return 0;
}
