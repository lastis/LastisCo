#include <unittest++/UnitTest++.h>
#include "../core/ShipMap.h"
#include <iostream>

SUITE(Some){
    ShipMap map;

    TEST(Instantiate){
        map = ShipMap(2,2);
    }
}

int main(int argc, const char *argv[])
{
	return UnitTest::RunAllTests();
}
