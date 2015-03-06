namespace ID{

    const int LOW = 1;
    const int HIGH = 2;
    const int BOTH = 3;
    const int FULL = 4;

    const int COUNT = 4;

    const unsigned int SPACE = 0;  
    const unsigned int AIR = 1;
    const unsigned int THICK_WALL = 2;
    const unsigned int WALL = 3;
    const unsigned int FLOOR = 4;

    static int arrayIDs[4];

    static void initIDs(){
        arrayIDs[SPACE]  = BOTH;
        arrayIDs[AIR]    = BOTH;
        arrayIDs[THICK_WALL]    = FULL;
        arrayIDs[WALL]   = HIGH;
        arrayIDs[FLOOR]  = LOW;
    }
}
