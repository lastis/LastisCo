#include <unittest++/UnitTest++.h>
#include "../core/ShipMap.h"
#include <iostream>
#include "../core/Identifiers.h"

using namespace std;

SUITE(Some){
    ShipMap map;

    TEST(Instantiate){
        map = ShipMap(2,2,2);
    }
}

int main()
{
	return UnitTest::RunAllTests();
}
