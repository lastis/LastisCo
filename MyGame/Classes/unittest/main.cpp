#include <unittest++/UnitTest++.h>
#include "../core/ShipMap.h"
#include <iostream>
#include "../core/Identifiers.h"

using namespace std;

SUITE(Identifiers){
    TEST(Initialization){
        ID::initIDs();
        for (int i = 0; i < ID::COUNT; i++) {
            CHECK(ID::arrayIDs[i] != 0);
        }
        ID::clearIDs();
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
        Matrix3D map = Matrix3D(5,5,5);
        Pathfinder pathfinder = Pathfinder(map);
        unsigned int*** ptr = map.getMatrix();
        Location start = Location(1,2,2);
        Location goal = Location(4,2,2);
        int N = 20;
        int* path = new int[N];
        pathfinder.findPath(start, goal, N, path);
        int sumX = 0;
        int sumY = 0;
        int sumZ = 0;
        for (int i = 0; i < N; i++) {
            int dir = path[i];
            if (dir == -1) break;
            if (dir == 0) sumX++;
            if (dir == 3) sumX--;
            if (dir == 1) sumY++;
            if (dir == 4) sumY--;
            if (dir == 2) sumZ++;
            if (dir == 5) sumZ--;
        }
        CHECK_EQUAL(3, sumX);
        CHECK_EQUAL(0, sumY);
        CHECK_EQUAL(0, sumZ);
        
        delete[] path;
    }

    TEST(BlockedPath){
        Matrix3D map = Matrix3D(5,5,5);
        Pathfinder pathfinder = Pathfinder(map);
        unsigned int*** ptr = map.getMatrix();
        ptr[2][2][3] = 1;
        ptr[2][2][2] = 1;
        ptr[2][2][1] = 1;
        Location start = Location(0,2,2);
        Location goal = Location(4,2,2);
        int N = 20;
        int* path = new int[N];
        pathfinder.findPath(start, goal, N, path);
        int sumX = 0;
        int sumY = 0;
        int sumZ = 0;
        for (int i = 0; i < N; i++) {
            int dir = path[i];
            if (dir == -1) break;
            if (dir == 0) sumX++;
            if (dir == 3) sumX--;
            if (dir == 1) sumY++;
            if (dir == 4) sumY--;
            if (dir == 2) sumZ++;
            if (dir == 5) sumZ--;
        }
        CHECK_EQUAL(4, sumX);
        CHECK_EQUAL(0, sumY);
        CHECK_EQUAL(0, sumZ);
        
        delete[] path;
    }

    TEST(ManyPaths){
        Matrix3D map = Matrix3D(101,101,101);
        Pathfinder pathfinder = Pathfinder(map);
        unsigned int*** ptr = map.getMatrix();
        ptr[2][2][3] = 1;
        ptr[2][2][2] = 1;
        ptr[2][2][1] = 1;
        Location start = Location(0,2,2);
        Location goal = Location(4,2,2);
        int N = 20;
        int* path = new int[N];
        for (int run = 0; run < 20; run++) {
            pathfinder.findPath(start, goal, N, path);
            int sumX = 0;
            int sumY = 0;
            int sumZ = 0;
            for (int i = 0; i < N; i++) {
                int dir = path[i];
                if (dir == -1) break;
                if (dir == 0) sumX++;
                if (dir == 3) sumX--;
                if (dir == 1) sumY++;
                if (dir == 4) sumY--;
                if (dir == 2) sumZ++;
                if (dir == 5) sumZ--;
            }
            CHECK_EQUAL(4, sumX);
            CHECK_EQUAL(0, sumY);
            CHECK_EQUAL(0, sumZ);
        }
        
        delete[] path;
    }

}

SUITE(ShipMap){
    TEST(Instantiate){
        ShipMap map = ShipMap(2,3,4); 
    }
}

int main()
{
	return UnitTest::RunAllTests();
}
