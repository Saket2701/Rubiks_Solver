cmake_minimum_required(VERSION 3.26)
project(RUBIKS)

set(CMAKE_CXX_STANDARD 14)

add_executable(RUBIKS main.cpp
        Model/GenericRubiksCube.cpp
        Model/GenericRubiksCube.h
        Model/RubiksCube3dArray.cpp
        Solver/BFSSolver.h
        Solver/DFSSolver.h
        Model/PatternDatabase/PatternDatabase.h
        Model/RubiksCube1dArray.cpp
        Model/RubiksCubeBitboard.cpp
        Solver/IDAstarSolver.h
        Solver/IDDFSSolver.h
        PatternDatabases/CornerDBMaker.cpp
        PatternDatabases/CornerPatternDatabase.cpp
        PatternDatabases/math.cpp
        PatternDatabases/NibbleArray.cpp
        PatternDatabases/PatternDatabase.cpp
)
