namespace ID{

    static const int LOW = 1;
    static const int HIGH = 2;
    static const int BOTH = 3;
    static const int FULL = 4;

    static const int COUNT = 5;

    static const unsigned int SPACE = 0;  
    static const unsigned int AIR = 1;
    static const unsigned int THICK_WALL = 2;
    static const unsigned int WALL = 3;
    static const unsigned int FLOOR = 4;

    static unsigned int* arrayIDs;

    static void initIDs(){
        arrayIDs = new unsigned int[COUNT];
        arrayIDs[SPACE]  = BOTH;
        arrayIDs[AIR]    = BOTH;
        arrayIDs[THICK_WALL]    = FULL;
        arrayIDs[WALL]   = HIGH;
        arrayIDs[FLOOR]  = LOW;
    }

    static void resetIDs(){
        delete[] arrayIDs;
    }
}
