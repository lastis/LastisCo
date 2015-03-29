#include <unittest++/UnitTest++.h>

#include "../core/ShipMap.h"
#include "../core/Person.h"
#include "../core/objects/Corn.h"
#include "../core/jobs/TaskInteract.h"
#include "../core/jobs/TaskMove.h"
#include <iostream>

using namespace std;

SUITE(Identifiers){
    // Not sure how to test this further. There might be merit to checking 
    // this somehow because many methods use these identifiers to do other
    // tests. It can be hard to trace back if the error comes from this 
    // code. 
    TEST(Initialization){
        blocks::properties::initArrays();
    }
}

SUITE(BLOCKS){
    TEST(CORN){
        Corn corn = Corn();
    }
}

SUITE(PERSON){
    TEST(INVENTORY){
        Base item1 = Base();
        Base item2 = Base();
        Base item3 = Base();
        Base item4 = Base();
        Base item5 = Base();
        Base item6 = Base();
        item1.ID = 1;
        item2.ID = 2;
        item3.ID = 3;
        item4.ID = 4;
        item5.ID = 5;
        item6.ID = 6;
        Person person = Person();
        // Add things to inventory, returns true if successful.
        CHECK(person.addToInventory(item1,10));
        CHECK(person.addToInventory(item2,20));
        CHECK(person.addToInventory(item3,30));
        CHECK(person.addToInventory(item4,40));
        CHECK(person.addToInventory(item5,50));
        // addToInventory should return false if there
        // is no more room in the inventory.
        CHECK(person.addToInventory(item6,60) == false);
        // Check that the ID has been added to the inventory with 
        // the correct ammount.
        CHECK_EQUAL(person.inventory[0],1);
        CHECK_EQUAL(person.inventoryAmount[0],10);
        CHECK_EQUAL(person.inventory[1],2);
        CHECK_EQUAL(person.inventoryAmount[1],20);
        CHECK_EQUAL(person.inventory[2],3);
        CHECK_EQUAL(person.inventoryAmount[2],30);
        CHECK_EQUAL(person.inventory[3],4);
        CHECK_EQUAL(person.inventoryAmount[3],40);
        CHECK_EQUAL(person.inventory[4],5);
        CHECK_EQUAL(person.inventoryAmount[4],50);
    }
}

SUITE(LinkedList){

    TEST(Init){
        LinkedList list1;
        LinkedList list2 = LinkedList();
        list1 = LinkedList();
    }

    TEST(Add){
        LinkedList list1 = LinkedList();
        ObjectTest obj1 = ObjectTest();
        ObjectTest obj2 = ObjectTest();
        ObjectTest obj3 = ObjectTest();
        list1.add(obj1);
        list1.add(obj2);
        list1.add(obj3);
        CHECK(list1.isEmpty() == false);
    }

    TEST(Remove){
        LinkedList list1 = LinkedList();
        ObjectTest obj1 = ObjectTest();
        ObjectTest obj2 = ObjectTest();
        ObjectTest obj3 = ObjectTest();
        list1.add(obj1);
        list1.add(obj2);
        list1.add(obj3);
        CHECK(list1.isEmpty() == false);
        list1.pop();
        list1.pop();
        list1.pop();
        CHECK(list1.isEmpty() == true);
    }

    TEST(SearchAndDestroy){
        LinkedList list1 = LinkedList();
        ObjectTest obj1 = ObjectTest();
        ObjectTest obj2 = ObjectTest();
        ObjectTest obj3 = ObjectTest();
        obj1.UID = 2;
        obj2.UID = 3;
        obj3.UID = 4;
        list1.add(obj1);
        list1.add(obj2);
        list1.add(obj3);
        list1.removeWithUID(3);
        /* int N = list1.getLength(); */
        /* CHECK_EQUAL(2,N); */
        /* Base* obj = list1.findWithUID(3); */
        /* CHECK(NULL == obj); */
    }

    TEST(Find){
        LinkedList list1 = LinkedList();
        ObjectTest obj1 = ObjectTest();
        ObjectTest obj2 = ObjectTest();
        ObjectTest obj3 = ObjectTest();
        obj1.UID = 1;
        obj2.UID = 2;
        obj3.UID = 3;
        list1.add(obj1);
        list1.add(obj2);
        list1.add(obj3);
        Base* obj = list1.findWithUID(2);
        CHECK_EQUAL(obj,&obj2);
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
        Matrix3D mat4;
        mat4 = mat1;
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

SUITE(Tasks){
    TEST(Init){
        // Make a path
        Matrix3D map = Matrix3D(1,5,5);
        Pathfinder pathfinder = Pathfinder(map);

        Location start = Location(0,0,0);
        Location goal = Location(4,4,0);
        Path* path = pathfinder.findPath(start, goal);

        // Put the path in the task.
        TaskMove task = TaskMove();
        task.setPath(path);
        // Put the task in the person. 
        Person person = Person();
        person.setTask(&task);
        delete path;
    }

    TEST(WalkTask){
        // Make a path
        Matrix3D map = Matrix3D(1,5,5);
        Pathfinder pathfinder = Pathfinder(map);

        Location start = Location(0,0,0);
        Location goal = Location(4,4,0);
        Path* path = pathfinder.findPath(start, goal);

        // Put the path in the task.
        TaskMove task = TaskMove();
        task.setPath(path);
        // Put the task in the person. 
        Person person = Person();
        person.loc = start;
        person.setTask(&task);
        // Walk the person.
        person.update();
        person.update();
        person.update();
        person.update();
        person.update();
        person.update();
        person.update();
        person.update();
        person.update();
        person.update();
        person.update();
        person.update();
        // Check the person arrived at the desired position.
        CHECK_EQUAL(4,person.loc.x);
        CHECK_EQUAL(4,person.loc.y);
        CHECK_EQUAL(0,person.loc.z);

        delete path;
    }
}

SUITE(Location){
    TEST(Init){
        Location loc1 = Location(3,3,3);
        Location loc2 = Location(4,4,4);
    }

    TEST(Assignment){
        Location loc1 = Location(3,4,5);
        CHECK_EQUAL(3,loc1.x);
        CHECK_EQUAL(4,loc1.y);
        CHECK_EQUAL(5,loc1.z);
    }

    TEST(Distance){
        Location loc1 = Location(3,3,3);
        Location loc2 = Location(4,4,4);
        CHECK_EQUAL(3,Location::distanceManhatten(loc1,loc2));
    }
}

SUITE(Pathfinder){
    TEST(PathInit){
        Path path = Path(NULL,0);
        CHECK(path.hasPath() == false);
        CHECK(path.isComplete() == true);
        CHECK_EQUAL(path.getLength(),0);
    }

    TEST(PathAssign){
        using namespace directions;
        unsigned int* pathInt = new unsigned int[5];
        pathInt[0] = directions::EAST;
        pathInt[1] = directions::NORTH;
        pathInt[2] = directions::SOUTH;
        pathInt[3] = directions::WEST;
        pathInt[4] = directions::NO_DIRECTION;
        Path path = Path(pathInt,5);
        CHECK(path.hasPath() == true);
        CHECK_EQUAL(path.getLength(),5);
        CHECK(path.isComplete() == false);
        CHECK_EQUAL(EAST,path.getNextDirection());
        CHECK_EQUAL(NORTH,path.getNextDirection());
        CHECK_EQUAL(SOUTH,path.getNextDirection());
        CHECK_EQUAL(WEST,path.getNextDirection());
        CHECK_EQUAL(NO_DIRECTION,path.getNextDirection());
        CHECK(path.isComplete() == true);
    }

    TEST(Init){
        Pathfinder pathfinder1 = Pathfinder();
        Matrix3D map = Matrix3D(5,5,5);
        Pathfinder pathfinder2 = Pathfinder(map);
    }

    TEST(SimplePath){
        using namespace directions;
        Matrix3D map = Matrix3D(1,5,5);
        Pathfinder pathfinder = Pathfinder(map);
        Location start = Location(1,2,0);
        Location goal = Location(4,2,0);
        Path* path = pathfinder.findPath(start, goal);
        /* pathfinder.printDirMap(0); */
        int sumX = 0;
        int sumY = 0;
        int sumZ = 0;
        for (int i = 0; i < MAX_PATH_LENGTH; i++) {
            unsigned int dir = path->getNextDirection();
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
        
        delete path;
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
        /* std::cout << "starting blocked path" << std::endl; */
        Path* path = pathfinder.findPath(start, goal);
        /* pathfinder.printDirMap(0); */
        /* std::cout << "return from path " << std::endl; */
        int sumX = 0;
        int sumY = 0;
        int sumZ = 0;
        for (int i = 0; i < MAX_PATH_LENGTH; i++) {
            unsigned int dir = path->getNextDirection();
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
        
        delete path;
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
        Path* path1 = pathfinder.findPath(start, goal);
        /* pathfinder.printDirMap(0); */
        int sumX = 0;
        int sumY = 0;
        int sumZ = 0;
        for (int i = 0; i < MAX_PATH_LENGTH; i++) {
            unsigned int dir = path1->getNextDirection();
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
        
        delete path1;
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
        int sumX = 0;
        int sumY = 0;
        int sumZ = 0;
        for (int run = 0; run < 10; run++) {
            Path* path = pathfinder.findPath(start, goal);
            for (int i = 0; i < MAX_PATH_LENGTH; i++) {
                int dir = path->getNextDirection();
                if (dir == NO_DIRECTION) break;
                if (dir == EAST) sumX++;
                if (dir == WEST) sumX--;
                if (dir == NORTH) sumY++;
                if (dir == SOUTH) sumY--;
                if (dir == UP) sumZ++;
                if (dir == DOWN) sumZ--;
            }
            delete path;
        }
        CHECK_EQUAL(4*10, sumX);
        CHECK_EQUAL(0*10, sumY);
        CHECK_EQUAL(0*10, sumZ);
        
    }

}

SUITE(ShipMap){
    TEST(Instantiate){
        ShipMap ship = ShipMap(5,5,5); 
    }


    TEST(CreateRoom){
        // Create a room and check if the room has been
        // added to the rooms map.
        ShipMap ship = ShipMap(5,5,5);
        Location* loc = new Location[9];
        // Make room 3x3 at z = 2. 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                loc[i*3 + j].x = 1+j;
                loc[i*3 + j].y = 1+i;
                loc[i*3 + j].z = 2;
            }
        }
        ship.createRoom(loc, 9, 0);
        unsigned int*** map = ship.getMapRooms();
        CHECK_EQUAL(1,map[2][1][1]);
        CHECK_EQUAL(1,map[2][1][2]);
        CHECK_EQUAL(1,map[2][1][3]);
        CHECK_EQUAL(1,map[2][2][1]);
        CHECK_EQUAL(1,map[2][2][2]);
        CHECK_EQUAL(1,map[2][2][3]);
        CHECK_EQUAL(1,map[2][3][1]);
        CHECK_EQUAL(1,map[2][3][2]);
        CHECK_EQUAL(1,map[2][3][3]);
        delete[] loc;
    }

    TEST(GetRoomFromLocation){
        ShipMap ship = ShipMap(3,20,20);
        Location* loc1 = new Location[9];
        // Make room 3x3 at z = 1, y = 2, x = 2. 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                loc1[i*3 + j].x = 2+j;
                loc1[i*3 + j].y = 2+i;
                loc1[i*3 + j].z = 1;
            }
        }
        Location* loc2 = new Location[9];
        // Make room 3x3 next to previous at z = 1, y = 5, x = 5. 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                loc2[i*3 + j].x = 5+j;
                loc2[i*3 + j].y = 5+i;
                loc2[i*3 + j].z = 1;
            }
        }
        // Create the rooms in the ship
        ship.createRoom(loc1, 9, 0);
        ship.createRoom(loc2, 9, 1);

        // Find rooms from the location and make sure they
        // are different.
        Room* room1 = ship.getRoom(loc1[0]);
        Room* room2 = ship.getRoom(loc2[0]);
        CHECK(room1 != NULL);
        CHECK(room2 != NULL);
        CHECK(room1 != room2);
        CHECK(room1->UID != 0);
        CHECK(room2->UID != 0);

        delete[] loc1;
        delete[] loc2;
    }

    TEST(AddObjects){
        ShipMap ship = ShipMap(3,20,20);
        Location* loc1 = new Location[9];
        // Make room 3x3 at z = 1, y = 2, x = 2. 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                loc1[i*3 + j].x = 1+j;
                loc1[i*3 + j].y = 1+i;
                loc1[i*3 + j].z = 1;
            }
        }
        Location* loc2 = new Location[9];
        // Make room 3x3 next to previous at z = 1, y = 5, x = 5. 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                loc2[i*3 + j].x = 4+j;
                loc2[i*3 + j].y = 4+i;
                loc2[i*3 + j].z = 1;
            }
        }
        // Create the rooms in the ship
        Room* room1 = ship.createRoom(loc1, 9, 0);
        Room* room2 = ship.createRoom(loc2, 9, 1);

        // Add one corn object in the first location of room 1.
        Object* obj1 = ship.addObject(blocks::CENTER_CORN,loc1[0]);
        CHECK(obj1 != NULL);
        Object* obj2 = ship.addObject(blocks::CENTER_CORN,loc2[0]);
        CHECK(obj2 != NULL);
        // Also add one object outside the rooms.
        Object* obj3 = ship.addObject(blocks::CENTER_CORN,Location(10,10,1));
        CHECK(obj3 != NULL);
        // Check that the object have non-zero UIDs.
        CHECK(obj1->UID != 0);
        CHECK(obj2->UID != 0);
        CHECK(obj3->UID != 0);

        // Check if the objects have been added to the map.
        using namespace blocks;
        unsigned int*** map = ship.getMap();
        int x,y,z;
        x = loc1[0].x;
        y = loc1[0].y;
        z = loc1[0].z;
        CHECK_EQUAL(CENTER_CORN,map[z][y][x]);
        x = loc2[0].x;
        y = loc2[0].y;
        z = loc2[0].z;
        CHECK_EQUAL(CENTER_CORN,map[z][y][x]);
        CHECK_EQUAL(CENTER_CORN,map[1][10][10]);

        // Check that shipmap only holds one object and the rooms hold
        // the rest.
        CHECK_EQUAL(1,ship.getObjectCntLoose());
        CHECK_EQUAL(1,room1->getObjectCnt());
        CHECK_EQUAL(1,room2->getObjectCnt());


        delete[] loc1;
        delete[] loc2;
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
        map[2][2][2] = blocks::CENTER_METAL;
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

    TEST(BlockCombination){
        // TODO: Split this code into multiple tests.
        // Test if both sides of a wall is blocked when one wall is inserted
        ShipMap ship = ShipMap(5,5,5); 
        unsigned int*** map = ship.getMap();
        unsigned int*** mapWallsNorth = ship.getMapNorthWalls();
        unsigned int*** mapWallsEast = ship.getMapEastWalls();
        unsigned int*** mapFloor = ship.getMapFloor();
        unsigned int*** mapAccess = ship.getMapAccess();
        mapFloor[2][2][2] = blocks::FLOOR_METAL;
        mapWallsEast[2][2][2] = blocks::WALL_METAL;
        mapWallsNorth[2][2][2] = blocks::WALL_METAL;
        ship.updateMapAccess();
        using namespace directions;
        CHECK_EQUAL(BLOCK_EAST,mapAccess[2][2][2]&BLOCK_EAST);
        CHECK_EQUAL(0,mapAccess[2][2][2]&BLOCK_WEST);
        CHECK_EQUAL(BLOCK_DOWN,mapAccess[2][2][2]&BLOCK_DOWN);
    }
}

int main()
{
	return UnitTest::RunAllTests();
}
