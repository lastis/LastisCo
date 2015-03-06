namespace IDs{

    namespace All{
        const unsigned int SPACE = 0;  
        const unsigned int AIR = 1;
        const unsigned int THICK_WALL = 2;
        const unsigned int WALL = 3;
        const unsigned int FLOOR = 4;
    }

    namespace Full{
        const unsigned int THICK_WALL = All::THICK_WALL;
    }

    namespace Both{
        const unsigned int SPACE = All::SPACE;
    }

    namespace Low{
        using namespace All;
        const unsigned int FLOOR = FLOOR;
    }

    namespace High{
        using namespace All;

    }
}
