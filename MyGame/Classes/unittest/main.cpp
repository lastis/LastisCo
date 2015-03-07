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

SUITE(Matix3D){
    TEST(Init){
        Matrix3D mat1 = Matrix3D(1,1,1);
        Matrix3D mat2 = Matrix3D(0,0,0);
    }

    TEST(Assignments){
        Matrix3D mat = Matrix3D(3,4,5);
        int*** pMat = mat.getMatrix();
        int* pMatFlat = mat.getMatrixFlat();
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

SUITE(ShipMap){
    TEST(Instantiate){
        ShipMap map = ShipMap(2,3,4); 
    }
}

int main()
{
	return UnitTest::RunAllTests();
}
