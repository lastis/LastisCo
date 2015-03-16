compile:
	g++ -D TESTING main.cpp ../core/ShipMap.cpp ../core/Matrix3D.cpp  \
	../core/Pathfinder.cpp ../core/PriorityQueue.cpp ../core/Room.cpp \
	../core/LinkedList.cpp ../core/Base.cpp ../core/Person.cpp \
	../core/jobs/Job.cpp ../core/jobs/Task.cpp  ../core/jobs/TaskMaster.cpp \
	../core/jobs/TaskFarm.cpp ../core/jobs/JobFarm.cpp \
   	../core/Path.cpp -lunittest++
test:
	./a.out
grind:
	valgrind ./a.out
