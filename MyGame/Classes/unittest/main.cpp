#include <unittest++/UnitTest++.h>

#include "../core/ShipMap.h"
#include <iostream>

using namespace std;

SUITE(Identifiers){
    // Not sure how to test this further. There might be merit to checking 
    // this somehow because many methods use these identifiers to do other
    // tests. It can be hard to trace back if the error comes from this 
    // code. 
    TEST(Initialization){
        blocks::properties::initArrays();
        blocks::properties::clearIDs();
    }
}

SUITE(Rooms){

    TEST(Init){
        Room room = Room();
    }

}

SUITE(PriorityQueue){
    TEST(Init){
        Node node1 = Node();
        Node node2 = Node();
        Node node3 = Node();
        Node node4 = Node();
        
        PriorityQueue queue = PriorityQueue();
        PriorityQueue queuelist[2];
    }

    TEST(PushNPop){
        Node node1 = Node();
        Node node2 = Node();
        Node node3 = Node();
        Node node4 = Node();
        node4.fValue = 1;
        node2.fValue = 2;
        node1.fValue = 3;
        node3.fValue = 4;
        
        PriorityQueue queue = PriorityQueue();
        queue.push(&node1);
        queue.push(&node2);
        queue.push(&node3);
        queue.push(&node4);
        queue.push(&node4);

        CHECK(queue.empty() == false);

        CHECK_EQUAL(5,queue.size());
        CHECK_EQUAL(1,queue.top()->fValue);
        queue.pop();
        CHECK_EQUAL(1,queue.top()->fValue);
        queue.pop();
        CHECK_EQUAL(2,queue.top()->fValue);
        queue.pop();
        CHECK_EQUAL(3,queue.top()->fValue);
        queue.pop();
        CHECK_EQUAL(4,queue.top()->fValue);
        queue.pop();
        CHECK_EQUAL(0,queue.size());

        CHECK(queue.empty() == true);

        queue.pop();
        CHECK_EQUAL(0,queue.size());
        queue.push(&node1);
        CHECK_EQUAL(1,queue.size());
    }
}

SUITE(Matix3D){
    TEST(Init){
        Matrix3D mat1 = Matrix3D(1,1,1);
        Matrix3D mat2 = Matrix3D(0,0,0);
        Matrix3D mat3 = Matrix3D();
    }

    TEST(Assignments){
        Matrix3D mat = Matrix3D(3,4,5);
        unsigned int*** pMat = mat.getMatrix();
        unsigned int* pMatFlat = mat.getMatrixFlat();
        int O = mat.getO();
        int N = mat.getN();
        int M = mat.getM();
        int cnt = 0;
        for (int i = 0; i < O; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    pMat[i][j][k] = cnt;
                    cnt++;
                }
            }
        }
        cnt = 0;
        for (int i = 0; i < O*N*M; i++) {
            CHECK_EQUAL(cnt, pMatFlat[i]);
            cnt ++;
        }
    }

}

SUITE(Pathfinder){
    TEST(Init){
        Pathfinder pathfinder1 = Pathfinder();
        Matrix3D map = Matrix3D(5,5,5);
        Pathfinder pathfinder2 = Pathfinder(map);
    }

    TEST(SimplePath){
        using namespace directions;
        Matrix3D map = Matrix3D(1,5,5);
        Pathfinder pathfinder = Pathfinder(map);
        unsigned int*** ptr = map.getMatrix();
        Location start = Location(1,2,0);
        Location goal = Location(4,2,0);
        int N = 20;
        unsigned int* path = new unsigned int[N];
        pathfinder.findPath(start, goal, N, path);
        /* pathfinder.printDirMap(0); */
        int sumX = 0;
        int sumY = 0;
        int sumZ = 0;
        for (int i = 0; i < N; i++) {
            unsigned int dir = path[i];
            if (dir == NO_DIRECTION) break;
            if (dir == EAST) sumX++;
            if (dir == WEST) sumX--;
            if (dir == NORTH) sumY++;
            if (dir == SOUTH) sumY--;
            if (dir == UP) sumZ++;
            if (dir == DOWN) sumZ--;
        }
        CHECK_EQUAL(3, sumX);
        CHECK_EQUAL(0, sumY);
        CHECK_EQUAL(0, sumZ);
        
        delete[] path;
    }

    TEST(BlockedPath){
        using namespace directions;
        Matrix3D map = Matrix3D(1,5,5);
        Pathfinder pathfinder = Pathfinder(map);
        unsigned int*** ptr = map.getMatrix();
        /* ptr[0][2][1] = ID::BLOCK_ALL; */
        ptr[0][2][2] = BLOCK_ALL;
        /* ptr[0][2][3] = ID::BLOCK_ALL; */
        ptr[0][3][2] = BLOCK_ALL;
        ptr[0][1][2] = BLOCK_ALL;
        Location start = Location(0,2,0);
        Location goal = Location(4,2,0);
        int N = 20;
        unsigned int* path = new unsigned int[N];
        for (int i = 0; i < N; i++) {
            path[i] = 0;
        }
        /* std::cout << "starting blocked path" << std::endl; */
        pathfinder.findPath(start, goal, N, path);
        /* pathfinder.printDirMap(0); */
        /* std::cout << "return from path " << std::endl; */
        int sumX = 0;
        int sumY = 0;
        int sumZ = 0;
        for (int i = 0; i < N; i++) {
            unsigned int dir = path[i];
            if (dir == NO_DIRECTION) break;
            if (dir == EAST) sumX++;
            if (dir == WEST) sumX--;
            if (dir == NORTH) sumY++;
            if (dir == SOUTH) sumY--;
            if (dir == UP) sumZ++;
            if (dir == DOWN) sumZ--;
        }
        CHECK_EQUAL(4, sumX);
        CHECK_EQUAL(0, sumY);
        CHECK_EQUAL(0, sumZ);
        
        delete[] path;
        /* std::cout << "finishing blocked path" << std::endl; */
    }

    TEST(WallPath){
        using namespace directions;
        Matrix3D map = Matrix3D(1,5,5);
        Pathfinder pathfinder = Pathfinder(map);
        unsigned int*** ptr = map.getMatrix();
        ptr[0][3][2] = BLOCK_WEST;
        ptr[0][2][2] = BLOCK_WEST;
        ptr[0][1][2] = BLOCK_WEST;
        /* ptr[0][3][2] = ID::BLOCK_EAST; */
        /* ptr[0][2][2] = ID::BLOCK_EAST; */
        /* ptr[0][1][2] = ID::BLOCK_EAST; */
        Location start = Location(0,2,0);
        Location goal = Location(4,2,0);
        int N = 20;
        unsigned int* path1 = new unsigned int[N];
        for (int i = 0; i < N; i++) {
            path1[i] = 0;
        }
        pathfinder.findPath(start, goal, N, path1);
        /* pathfinder.printDirMap(0); */
        int sumX = 0;
        int sumY = 0;
        int sumZ = 0;
        for (int i = 0; i < N; i++) {
            unsigned int dir = path1[i];
            /* cout << "direction: "<< dir << endl; */
            if (dir == NO_DIRECTION) break;
            if (dir == EAST) sumX++;
            if (dir == WEST) sumX--;
            if (dir == NORTH) sumY++;
            if (dir == SOUTH) sumY--;
            if (dir == UP) sumZ++;
            if (dir == DOWN) sumZ--;
        }
        /* cout << "DID IT" << endl; */
        CHECK_EQUAL(4, sumX);
        CHECK_EQUAL(0, sumY);
        CHECK_EQUAL(0, sumZ);
        
        delete[] path1;
    }

    TEST(ManyPaths){
        using namespace directions;
        Matrix3D map = Matrix3D(50,50,50);
        Pathfinder pathfinder = Pathfinder(map);
        unsigned int*** ptr = map.getMatrix();
        ptr[2][2][3] = BLOCK_ALL;
        ptr[2][2][2] = BLOCK_ALL;
        ptr[2][2][1] = BLOCK_ALL;
        Location start = Location(0,2,2);
        Location goal = Location(4,2,2);
        int N = 20;
        unsigned int* path = new unsigned int[N];
        int sumX = 0;
        int sumY = 0;
        int sumZ = 0;
        for (int run = 0; run < 20; run++) {
            pathfinder.findPath(start, goal, N, path);
            for (int i = 0; i < N; i++) {
                int dir = path[i];
                if (dir == NO_DIRECTION) break;
                if (dir == EAST) sumX++;
                if (dir == WEST) sumX--;
                if (dir == NORTH) sumY++;
                if (dir == SOUTH) sumY--;
                if (dir == UP) sumZ++;
                if (dir == DOWN) sumZ--;
            }
        }
        CHECK_EQUAL(4*N, sumX);
        CHECK_EQUAL(0*N, sumY);
        CHECK_EQUAL(0*N, sumZ);
        
        delete[] path;
    }

}

SUITE(ShipMap){
    TEST(Instantiate){
        ShipMap ship = ShipMap(5,5,5); 
    }

    TEST(BlockingMovement){
        // TODO: Split this code into multiple tests.
        // Test if both sides of a wall is blocked when one wall is inserted
        ShipMap ship = ShipMap(5,5,5); 
        unsigned int*** map = ship.getMap();
        unsigned int*** mapWallsNorth = ship.getMapNorthWalls();
        unsigned int*** mapWallsEast = ship.getMapEastWalls();
        unsigned int*** mapAccess = ship.getMapAccess();
        mapWallsEast[2][2][2] = blocks::WALL_METAL;
        CHECK_EQUAL(0,mapAccess[2][2][2]);
        ship.updateMapAccess();
        CHECK_EQUAL(directions::BLOCK_EAST,mapAccess[2][2][2]);
        CHECK_EQUAL(directions::BLOCK_WEST,mapAccess[2][2][3]);
        ship.updateMapAccess();
        CHECK_EQUAL(directions::BLOCK_EAST,mapAccess[2][2][2]);
        CHECK_EQUAL(directions::BLOCK_WEST,mapAccess[2][2][3]);
        // Remove the wall, is the map reset?
        mapWallsEast[2][2][2] = 0;
        ship.updateMapAccess();
        CHECK_EQUAL(0,mapAccess[2][2][2]);

        // Check that the north wall works too.
        mapWallsNorth[2][2][2] = blocks::WALL_METAL;
        ship.updateMapAccess();
        CHECK_EQUAL(directions::BLOCK_NORTH,mapAccess[2][2][2]);
        CHECK_EQUAL(directions::BLOCK_SOUTH,mapAccess[2][3][2]);
        ship.updateMapAccess();
        CHECK_EQUAL(directions::BLOCK_NORTH,mapAccess[2][2][2]);
        CHECK_EQUAL(directions::BLOCK_SOUTH,mapAccess[2][3][2]);
        mapWallsNorth[2][2][2] = 0;
        ship.updateMapAccess();
        CHECK_EQUAL(0,mapAccess[2][2][2]);

        // Check blocks that block every direction.
        map[2][2][2] = blocks::FULL_METAL;
        ship.updateMapAccess();
        CHECK_EQUAL(directions::BLOCK_ALL,mapAccess[2][2][2]);
        CHECK_EQUAL(directions::BLOCK_EAST,mapAccess[2][2][1]);
        CHECK_EQUAL(directions::BLOCK_WEST,mapAccess[2][2][3]);
        CHECK_EQUAL(directions::BLOCK_NORTH,mapAccess[2][1][2]);
        CHECK_EQUAL(directions::BLOCK_SOUTH,mapAccess[2][3][2]);
        CHECK_EQUAL(directions::BLOCK_UP,mapAccess[1][2][2]);
        CHECK_EQUAL(directions::BLOCK_DOWN,mapAccess[3][2][2]);
        map[2][2][2] = 0;
        ship.updateMapAccess();
        CHECK_EQUAL(0,mapAccess[2][2][2]);
        
    }
}

int main()
{
	return UnitTest::RunAllTests();
}
