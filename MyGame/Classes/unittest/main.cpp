#include <unittest++/UnitTest++.h>

#include "../core/main/ShipMaster.h"
#include "../core/items/ItemMatrix.h"
#include <iostream>

using namespace std;

SUITE(Identifiers){
    // Not sure how to test this further. There might be merit to checking 
    // this somehow because many methods use these identifiers to do other
    // tests. It can be hard to trace back if the error comes from this 
    // code. 
    TEST(Initialization){
        blocks::properties::initialize();
    }
}

SUITE(ItemMatrix){
    TEST(AddAndRemove){
        ItemMatrix mat = ItemMatrix(5,5,5);
        Item**** pMat = mat.getMatrix();
        CHECK(pMat[0][0][0] == NULL);
        CHECK(pMat[4][4][4] == NULL);

        Item* item = (Item*) new ItemTest();
        pMat[0][0][0] = item;
    }
}

SUITE(Items){
    TEST(Corn){
        // Make a corn. It must be placed in order to grow.
        Corn corn = Corn();
        corn.setPlaced(true);
        int cornID = blocks::CENTER_CORN;
        CHECK_EQUAL(cornID,corn.ID);
        int& stage = corn.stage;
        int& time = corn.time;
        int stage0 = Corn::STAGE_0;
        // Check that initializtion is correct and the update method.
        CHECK_EQUAL(stage0, stage);
        CHECK_EQUAL(0, time);
        corn.update(); // 1
        CHECK_EQUAL(1, time);
        corn.update(); // 2
        corn.update(); // 3
        corn.update(); // 4
        corn.update(); // 5
        corn.update(); // 6
        CHECK(corn.isFinished());
        int stageFinal = Corn::STAGE_FINAL;
        CHECK_EQUAL(stageFinal, stage);
        corn.update(); // 7
        CHECK_EQUAL(stageFinal, stage);
        corn.reset();
        CHECK_EQUAL(stage0, stage);
        CHECK_EQUAL(0, time);

        // Check interaction works and the person gets two
        // corns.
        corn.update(); // 1
        corn.update(); // 2
        corn.update(); // 3
        corn.update(); // 4
        corn.update(); // 5
        corn.update(); // 6
        Person person = Person();
        corn.interact(person);
        int amount = 2;
        CHECK(person.hasInInventory(cornID,amount));
    }
}

SUITE(Person){
    TEST(INVENTORY){
        Person person = Person();
        // Add things to inventory, returns true if successful.
        // The first number is item IDs.
        CHECK(person.addToInventory(1,10));
        CHECK(person.addToInventory(2,20));
        CHECK(person.addToInventory(3,30));
        CHECK(person.addToInventory(4,40));
        CHECK(person.addToInventory(5,50));
        // addToInventory should return false if there
        // is no more room in the inventory.
        CHECK(person.addToInventory(6,60) == false);
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

        // Check get methods for inventory works. 
        // Do we have 1 or more of ID = 1? 
        CHECK(person.hasInInventory(1,1));
        // Do we have 10 or more of ID = 1? 
        CHECK(person.hasInInventory(1,10));
        CHECK(person.hasInInventory(2,20));
        CHECK(person.hasInInventory(3,29));
        // Check false assertions.
        CHECK(person.hasInInventory(1,20) == false);
        CHECK(person.hasInInventory(2,40) == false);
        CHECK(person.hasInInventory(6,70) == false);
        CHECK(person.hasInInventory(7,0) == false);
        CHECK(person.hasInInventory(0,0) == false);
        CHECK(person.hasInInventory(0,1) == false);
    }
}

SUITE(LinkedList){

    TEST(Init){
        LinkedList list1;
        LinkedList list2 = LinkedList();
        list1 = LinkedList();
    }

    TEST(Iteration){
        LinkedList list1 = LinkedList();
        CHECK(list1.next() == NULL);
        ItemTest obj1 = ItemTest();
        ItemTest obj2 = ItemTest();
        ItemTest obj3 = ItemTest();
        obj1.ID = 1;
        obj2.ID = 2;
        obj3.ID = 3;
        list1.add(&obj1);
        list1.add(&obj2);
        list1.add(&obj3);
        CHECK_EQUAL(3,list1.next()->ID);
        CHECK_EQUAL(2,list1.next()->ID);
        CHECK_EQUAL(1,list1.next()->ID);
        CHECK(list1.next() == NULL);
        list1.resetIterator();
        CHECK_EQUAL(3,list1.next()->ID);
        CHECK_EQUAL(2,list1.next()->ID);
        CHECK_EQUAL(1,list1.next()->ID);
        CHECK(list1.next() == NULL);
    }

    TEST(Add){
        LinkedList list1 = LinkedList();
        ItemTest obj1 = ItemTest();
        ItemTest obj2 = ItemTest();
        ItemTest obj3 = ItemTest();
        list1.add(&obj1);
        list1.add(&obj2);
        list1.add(&obj3);
        CHECK(list1.isEmpty() == false);
        LinkedList list2 = LinkedList();
        list2.add(&obj1);
        CHECK(list2.isEmpty() == false);
        CHECK_EQUAL(1,list2.getLength());
    }

    TEST(Remove){
        LinkedList list1 = LinkedList();
        ItemTest obj1 = ItemTest();
        ItemTest obj2 = ItemTest();
        ItemTest obj3 = ItemTest();
        list1.add(&obj1);
        list1.add(&obj2);
        list1.add(&obj3);
        CHECK(list1.isEmpty() == false);
        list1.pop();
        list1.pop();
        list1.pop();
        CHECK(list1.isEmpty() == true);
        LinkedList list2 = LinkedList();
        list2.add(&obj1);
        list2.pop();
    }

    TEST(RemoveWithID){
        LinkedList list1 = LinkedList();
        ItemTest obj1 = ItemTest();
        ItemTest obj2 = ItemTest();
        ItemTest obj3 = ItemTest();
        obj1.ID = 1;
        obj2.ID = 2;
        obj3.ID = 3;
        obj1.UID = 1;
        obj2.UID = 2;
        obj3.UID = 3;
        list1.add(&obj1);
        list1.add(&obj2);
        list1.add(&obj3);
        list1.popWithID(1);
        list1.popWithID(3);
        list1.popWithID(2);
        CHECK_EQUAL(0,list1.getLength());

        LinkedList list2 = LinkedList();
        list2.add(&obj1);
        list2.add(&obj2);
        list2.add(&obj3);
        list2.popWithUID(1);
        list2.popWithUID(3);
        list2.popWithUID(2);
        CHECK_EQUAL(0,list2.getLength());
    }

    TEST(SearchAndDestroy){
        LinkedList list1 = LinkedList();
        ItemTest obj1 = ItemTest();
        ItemTest obj2 = ItemTest();
        ItemTest obj3 = ItemTest();
        obj1.UID = 2;
        obj2.UID = 3;
        obj3.UID = 4;
        list1.add(&obj1);
        list1.add(&obj2);
        list1.add(&obj3);
        list1.popWithUID(3);
        /* int N = list1.getLength(); */
        /* CHECK_EQUAL(2,N); */
        /* Base* obj = list1.findWithUID(3); */
        /* CHECK(NULL == obj); */
    }

    TEST(Find){
        LinkedList list1 = LinkedList();
        ItemTest obj1 = ItemTest();
        ItemTest obj2 = ItemTest();
        ItemTest obj3 = ItemTest();
        obj1.UID = 1;
        obj2.UID = 2;
        obj3.UID = 3;
        list1.add(&obj1);
        list1.add(&obj2);
        list1.add(&obj3);
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
    TEST(PushNPop){
        PathNode node1 = PathNode();
        PathNode node2 = PathNode();
        PathNode node3 = PathNode();
        PathNode node4 = PathNode();
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

SUITE(Jobs){
    TEST(JobFarm){
        // Test if we can give a person one seed and if he will place the rest.
        Person person = Person();
        person.loc = Location(8,1,0);
        ShipMaster ship = ShipMaster(1,20,20);
        JobFarm job = JobFarm(ship);
        person.addToInventory(blocks::CENTER_CORN,1);

        // Make a 2x2 field of corn that we want to be sowed.
        int crops = 4;
        Corn** corn = new Corn*[crops]; 
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                corn[i*2 + j] = (Corn*) 
                    ship.createItem(blocks::CENTER_CORN,Location(i,j,0));
            }
        }
        CHECK_EQUAL(4,ship.getItemPendingCount());
        int cnt = 0;
        while (cnt < 100){
            job.deligateTask(person);
            person.update();
            corn[0]->update();
            corn[1]->update();
            corn[2]->update();
            corn[3]->update();
            cnt++;
            // Break the loop early if all corn is finished;
            if (corn[0]->isFinished() == false) continue;
            if (corn[1]->isFinished() == false) continue;
            if (corn[2]->isFinished() == false) continue;
            if (corn[3]->isFinished() == false) continue;
            break;
        }
        for (int i = 0; i < crops; i++) {
            CHECK(corn[i]->isPlaced());
        }
        delete[] corn;
    }
}

SUITE(Tasks){
    TEST(Init){
        ShipMaster ship = ShipMaster(1,5,5);

        Location start = Location(0,0,0);
        Location goal = Location(4,4,0);

        // Put the path in the task.
        TaskMove* task = new TaskMove(ship,start,goal);
        // Put the task in the person. 
        Person person = Person();
        person.setTask(task);
    }

    TEST(TaskPlace){
        // Generates false error.
        ShipMaster ship = ShipMaster(1,5,5);

        // Make a path so the task can walk to the interaction object.
        Location start = Location(0,1,0);
        Location goal = Location(4,1,0);

        // By setting the location of the object, we define where it will
        // be placed on the shipmap.
        Item* corn = ship.createItem(blocks::CENTER_CORN,goal);

        // Put the path in the task.
        TaskPlace* task = new TaskPlace(corn,ship,start);
        CHECK(corn->UID != 0);
        // Put the task in the person. Tasks should be deleted by person.
        // Give the persons some seeds so he can place the object.
        Person person = Person();
        person.addToInventory(corn->ID,1);
        person.loc = start;
        person.setTask(task);
        CHECK(task->hasPath());
        CHECK(task->isFinished() == false);
        // Three steps to the object, one step for placing.
        person.update(); // 1.
        person.update(); // 2.
        person.update(); // 3.
        // Still not placed. 
        CHECK_EQUAL(1, ship.getItemPendingCount());
        person.update(); // 4.
        CHECK_EQUAL(0, ship.getItemPendingCount());
        CHECK_EQUAL(1, ship.getItemPlacedCount());
        unsigned int*** map = ship.shipMap->getMap();
        int cornID = blocks::CENTER_CORN;
        CHECK_EQUAL(cornID, map[0][1][4]);
    }

    TEST(TaskInteract){
        ShipMaster ship = ShipMaster(1,5,5);

        // Make a path so the task can walk to the interaction object.
        Location start = Location(0,1,0);
        Location goal = Location(4,1,0);

        // Make a placed corn object we can interact with.
        Corn* corn = new Corn();
        corn->setPlaced(true);
        corn->loc = goal;
        // Make the corn "ripe".
        corn->update(); // 1
        corn->update(); // 2
        corn->update(); // 3
        corn->update(); // 4
        corn->update(); // 5
        corn->update(); // 6
        CHECK(corn->isFinished());

        TaskInteract* task = new TaskInteract(corn,ship,start);
        // Put the task in the person. Tasks should be deleted by person.
        Person person = Person();
        person.loc = start;
        person.setTask(task);
        // Three steps to the object, one step for interacting.
        person.update(); // 1.
        person.update(); // 2.
        person.update(); // 3.
        int amount = 2;
        int cornID = blocks::CENTER_CORN;
        CHECK(person.hasInInventory(cornID,amount) == false);
        person.update(); // 4.
        CHECK(person.hasInInventory(cornID,amount));
        // The task should also have been removed from the person.
        CHECK(person.hasTask() == false);
        delete corn;
    }

    TEST(WalkTask){
        ShipMaster ship = ShipMaster(1,5,5);

        Location start = Location(0,1,0);
        Location goal = Location(4,1,0);

        // Put the path in the task.
        TaskMove* task = new TaskMove(ship,start,goal);
        // Put the task in the person. 
        Person person = Person();
        person.loc = start;
        person.setTask(task);
        // Walk the person. Distance to goal is 4.
        // Check that the tasks is not removed during this update.
        person.update();
        CHECK(person.hasTask() == true);
        person.update();
        CHECK(person.hasTask() == true);
        person.update();
        CHECK(person.hasTask() == true);
        person.update();
        // The task should also have been removed from the person.
        CHECK(person.hasTask() == false);
        // Check the person arrived at the desired position.
        CHECK_EQUAL(4,person.loc.x);
        CHECK_EQUAL(1,person.loc.y);
        CHECK_EQUAL(0,person.loc.z);
    }
}

SUITE(Location){
    TEST(Init){
        Location loc1 = Location(3,3,3);
        Location loc2 = loc1;
        CHECK_EQUAL(3,loc1.x);
        CHECK_EQUAL(3,loc1.y);
        CHECK_EQUAL(3,loc1.z);
        CHECK_EQUAL(3,loc2.x);
        CHECK_EQUAL(3,loc2.y);
        CHECK_EQUAL(3,loc2.z);
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
        // Create a path we can use.
        unsigned int* pathInt = new unsigned int[5];
        pathInt[0] = directions::EAST;
        pathInt[1] = directions::NORTH;
        pathInt[2] = directions::SOUTH;
        pathInt[3] = directions::WEST;
        pathInt[4] = directions::NO_DIRECTION;

        // Check assignment.
        Path path = Path(pathInt,5);
        Path path1;
        path1 = path;


        // Check the two equal paths.
        CHECK(path.hasPath() == true);
        CHECK_EQUAL(path.getLength(),5);
        CHECK(path.isComplete() == false);
        CHECK_EQUAL(EAST,path.getNextDirection());
        CHECK_EQUAL(NORTH,path.getNextDirection());
        CHECK_EQUAL(SOUTH,path.getNextDirection());
        CHECK_EQUAL(WEST,path.getNextDirection());
        CHECK_EQUAL(NO_DIRECTION,path.getNextDirection());
        CHECK(path.isComplete() == true);

        CHECK(path1.hasPath() == true);
        CHECK_EQUAL(path1.getLength(),5);
        CHECK(path1.isComplete() == false);
        CHECK_EQUAL(EAST,path1.getNextDirection());
        CHECK_EQUAL(NORTH,path1.getNextDirection());
        CHECK_EQUAL(SOUTH,path1.getNextDirection());
        CHECK_EQUAL(WEST,path1.getNextDirection());
        CHECK_EQUAL(NO_DIRECTION,path1.getNextDirection());
        CHECK(path1.isComplete() == true);

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
        Path path = pathfinder.findPath(start, goal);
        /* pathfinder.printDirMap(0); */
        int sumX = 0;
        int sumY = 0;
        int sumZ = 0;
        for (int i = 0; i < MAX_PATH_LENGTH; i++) {
            unsigned int dir = path.getNextDirection();
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
        Path path = pathfinder.findPath(start, goal);
        /* pathfinder.printDirMap(0); */
        /* std::cout << "return from path " << std::endl; */
        int sumX = 0;
        int sumY = 0;
        int sumZ = 0;
        for (int i = 0; i < MAX_PATH_LENGTH; i++) {
            unsigned int dir = path.getNextDirection();
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
        Path path1 = pathfinder.findPath(start, goal);
        /* pathfinder.printDirMap(0); */
        int sumX = 0;
        int sumY = 0;
        int sumZ = 0;
        for (int i = 0; i < MAX_PATH_LENGTH; i++) {
            unsigned int dir = path1.getNextDirection();
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
    }

    TEST(ManyPaths){
        using namespace directions;
        Matrix3D map = Matrix3D(50,50,50);
        Pathfinder pathfinder = Pathfinder(map);
        unsigned int*** ptr = map.getMatrix();
        // Block one block in the middle of the path.
        ptr[2][2][2] = BLOCK_ALL;
        Location start = Location(0,2,2);
        Location goal = Location(4,2,2);
        int sumX = 0;
        int sumY = 0;
        int sumZ = 0;
        for (int run = 0; run < 10; run++) {
            Path path = pathfinder.findPath(start, goal);
            for (int i = 0; i < MAX_PATH_LENGTH; i++) {
                int dir = path.getNextDirection();
                if (dir == NO_DIRECTION) break;
                if (dir == EAST) sumX++;
                if (dir == WEST) sumX--;
                if (dir == NORTH) sumY++;
                if (dir == SOUTH) sumY--;
                if (dir == UP) sumZ++;
                if (dir == DOWN) sumZ--;
            }
        }
        CHECK_EQUAL(4*10, sumX);
        CHECK_EQUAL(0*10, sumY);
        CHECK_EQUAL(0*10, sumZ);
        
    }
}

SUITE(ShipCrew){
    TEST(AddCrew){
        ShipCrew ship = ShipCrew();
        Location loc1 = Location(1,1,1);
        Location loc2 = Location(2,1,1);
        int crewID = 1;
        ship.createCrewMember(crewID,loc1);
        ship.createCrewMember(crewID,loc2);
        CHECK_EQUAL(2,ship.getCrewCount());
    }
}

SUITE(ShipItems){
    TEST(CreateAndPlaceItems){
        // Problems can arise if items have the same UID.
        ShipItems ship = ShipItems();

        Location loc1 = Location(1,1,1);
        Location loc2 = Location(2,1,1);
        int UID1 = 1;
        int UID2 = 2;
        Item* obj1 = ship.createItem(blocks::CENTER_CORN,UID1, loc1);
        Item* obj2 = ship.createItem(blocks::CENTER_CORN,UID2, loc2);
        CHECK(obj1->isPlaced() == false);
        CHECK(obj2->isPlaced() == false);
        CHECK_EQUAL(2,ship.getItemPendingCount());
        CHECK(obj1->ID != 0);
        CHECK(obj2->ID != 0);
        CHECK(ship.placeItem(obj1));
        CHECK(ship.placeItem(obj2));
        CHECK(obj1->isPlaced());
        CHECK(obj2->isPlaced());
        CHECK_EQUAL(2,ship.getItemPlacedCount());
        CHECK_EQUAL(0,ship.getItemPendingCount());
    }

}

SUITE(ShipMap){
    TEST(PlaceRoom){
        // Generates false errors.
        ShipMap ship = ShipMap(3,20,20);
        Location* loc1 = new Location[9];
        Location* loc2 = new Location[9];
        // Make room 3x3 at z = 1, y = 2, x = 2. 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                loc1[i*3 + j].x = 1+j;
                loc1[i*3 + j].y = 1+i;
                loc1[i*3 + j].z = 1;
            }
        }
        // Make room 3x3 next to previous at z = 1, y = 5, x = 5. 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                loc2[i*3 + j].x = 4+j;
                loc2[i*3 + j].y = 4+i;
                loc2[i*3 + j].z = 1;
            }
        }
        // Create the rooms in the ship
        int UID1 = 1;
        int UID2 = 2;
        ship.placeRoom(loc1, 9, UID1);
        ship.placeRoom(loc2, 9, UID2);
        delete[] loc1;
        delete[] loc2;
    }

    TEST(PlaceItem){
        ShipMap ship = ShipMap(3,3,3);
        Location loc1 = Location(1,1,1);
        Location loc2 = Location(2,2,2);
        // Item ids
        int UID1 = 1;
        int UID2 = 2;
        ship.placeItem(UID1,loc1);
        ship.placeItem(UID2,loc2);
        CHECK_EQUAL(UID1,ship.getMap()[1][1][1]);
        CHECK_EQUAL(UID2,ship.getMap()[2][2][2]);
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
        ship.placeRoom(loc1, 9, 1);
        ship.placeRoom(loc2, 9, 2);

        CHECK(1 == ship.getRoomUidFromLoc(loc1[0]));
        CHECK(2 == ship.getRoomUidFromLoc(loc2[0]));

        delete[] loc1;
        delete[] loc2;
    }

    TEST(BlockCombination){
        // TODO: Split this code into multiple tests.
        // Test if both sides of a wall is blocked when one wall is inserted
        ShipMap ship = ShipMap(5,5,5); 
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

    TEST(UpdateBlockedMap){
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
}

SUITE(ShipMaster){
    TEST(Instantiate){
        ShipMaster ship = ShipMaster(5,5,5); 
    }

    TEST(UpdateItems){
        ShipMaster ship = ShipMaster(5,5,5);

        Location loc1 = Location(1,1,1);
        Location loc2 = Location(2,1,1);
        Location loc3 = Location(3,1,1);
        Location loc4 = Location(4,1,1);
        Corn* obj1 = (Corn*) ship.createItem(blocks::CENTER_CORN, loc1);
        Corn* obj2 = (Corn*) ship.createItem(blocks::CENTER_CORN, loc2);
        Corn* obj3 = (Corn*) ship.createItem(blocks::CENTER_CORN, loc3);
        Corn* obj4 = (Corn*) ship.createItem(blocks::CENTER_CORN, loc4);
        // Corn objects must be placed to be updated.
        CHECK(ship.placeItem(obj1));
        CHECK(ship.placeItem(obj2));
        CHECK(ship.placeItem(obj3));
        CHECK(ship.placeItem(obj4));
        // Check that the time increases when we call update.
        CHECK(obj1->isPlaced());
        CHECK_EQUAL(0,obj1->time);
        ship.update();
        CHECK_EQUAL(1,obj1->time);
        CHECK_EQUAL(1,obj2->time);
        CHECK_EQUAL(1,obj3->time);
        CHECK_EQUAL(1,obj4->time);
    }

    TEST(UpdateJobs){
        // The ship has job farm implemented and will run it on all persons
        // added to the object.
        int crewID = 1;
        ShipMaster ship = ShipMaster(3,20,20);
        Location loc1 = Location(1,1,1);
        Person* person = ship.createCrewMember(crewID,loc1);
        person->addToInventory(blocks::CENTER_CORN,1);
        // Make a 2x2 field of corn that we want to be sowed.
        int crops = 4;
        Corn** corn = new Corn*[crops]; 
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                corn[i*2 + j] = (Corn*) 
                    ship.createItem(blocks::CENTER_CORN,Location(i,j,0));
            }
        }
        CHECK_EQUAL(4,ship.getItemPendingCount());
        int cnt = 0;
        while (cnt < 100){
            ship.update();
            cnt++;
            // Break the loop early if all corn is finished;
            if (corn[0]->isFinished() == false) continue;
            if (corn[1]->isFinished() == false) continue;
            if (corn[2]->isFinished() == false) continue;
            if (corn[3]->isFinished() == false) continue;
            break;
        }
        for (int i = 0; i < crops; i++) {
            CHECK(corn[i]->isPlaced());
        }
        delete[] corn;
    }

    TEST(UpdateCrew){
        ShipMaster ship = ShipMaster(5,5,5);
        Location loc1 = Location(1,1,1);
        Location loc2 = Location(2,1,1);

        // Put the path in the task.
        TaskMove* task = new TaskMove(ship,loc1,loc2);
        int crewID = 1;
        Person* person = ship.createCrewMember(crewID,loc1);
        person->loc = loc1;
        // Put the task in the person. 
        person->setTask(task);
        // Check that the person moves on update.
        CHECK_EQUAL(1,person->loc.x);
        ship.update();
        CHECK_EQUAL(2,person->loc.x);
    }

    TEST(CreateRoom){
        // Generates false errors.
        // Gives unittest memory errors in valgrind.
        // Create a room and check if the room has been
        // added to the rooms map.
        ShipMaster ship = ShipMaster(5,5,5);
        Location* loc = new Location[9];
        // Make room 3x3 at z = 2. 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                loc[i*3 + j].x = 1+j;
                loc[i*3 + j].y = 1+i;
                loc[i*3 + j].z = 2;
            }
        }
        // Create a room at the locations with ID = 1.
        ship.createRoom(loc, 9, 1);
        unsigned int*** map = ship.shipMap->getMapRooms();
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

    TEST(PlaceItems){
        ShipMaster ship = ShipMaster(3,20,20);
        Location loc1 = Location(5,5,1);
        Item* obj1 = ship.createItem(blocks::CENTER_CORN,loc1);
        CHECK_EQUAL(1,ship.getItemPendingCount());
        CHECK(obj1->ID != 0);
        CHECK(ship.isVacant(loc1));
        // Generates errors.
        CHECK(ship.placeItem(obj1));
        CHECK_EQUAL(0,ship.getItemPendingCount());
        // Generates false errors.
        CHECK_EQUAL(1,ship.getItemPlacedCount());
    }



    TEST(AddItemsToRooms){
        ShipMaster ship = ShipMaster(3,20,20);
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

        // Add one corn object in the first location of room 1 and 2 
        // and check that they have been placed correctly.
        Item* obj1 = ship.createItem(blocks::CENTER_CORN,loc1[0]);
        CHECK(obj1->ID != 0);
        CHECK(ship.isVacant(obj1->loc));
        // Generates strange error.
        CHECK(ship.placeItem(obj1));

        Item* obj2 = ship.createItem(blocks::CENTER_CORN,loc2[0]);
        CHECK(obj2->ID != 0);
        CHECK(ship.isVacant(obj2->loc));
        // Generates strange error.
        CHECK(ship.placeItem(obj2));

        // Also add one object outside the rooms.
        Item* obj3 = ship.createItem(blocks::CENTER_CORN,Location(10,10,1));
        ship.placeItem(obj3);
        // Check that the object have non-zero UIDs.
        CHECK(obj1->UID != 0);
        CHECK(obj2->UID != 0);
        CHECK(obj3->UID != 0);

        // Check if the objects have been added to the map.
        using namespace blocks;
        unsigned int*** map = ship.shipMap->getMap();
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
        CHECK_EQUAL(3,ship.getItemPlacedCount());
        CHECK_EQUAL(1,room1->getItemCnt());
        CHECK_EQUAL(1,room2->getItemCnt());

        delete[] loc1;
        delete[] loc2;
    }


}

int main()
{
	return UnitTest::RunAllTests();
}
