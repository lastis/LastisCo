#include <unittest++/UnitTest++.h>
#include "../core/ShipMap.h"
#include <iostream>
#include "../core/Identifiers.h"

using namespace std;

SUITE(Identifiers){
    /* TEST(Initialization){ */
    /*     ID::initIDs(); */
    /*     for (int i = 0; i < ID::COUNT; i++) { */
    /*         CHECK(ID::arrayIDs[i] != 0); */
    /*     } */
    /* } */
}

SUITE(Some){
    ShipMap map;

    TEST(Instantiate){
        map = ShipMap(2,3,4);
    }
}

int main()
{
	return UnitTest::RunAllTests();
}
