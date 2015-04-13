single:
	g++ -D TESTING main.cpp \
    -lunittest++
compile:
	g++ -D TESTING main.cpp \
    ../core/*.cpp           \
    ../core/enteties/*.cpp  \
    ../core/items/*.cpp     \
    ../core/jobs/*.cpp      \
    ../core/main/*.cpp      \
    ../core/map/*.cpp       \
    ../core/rooms/*.cpp     \
    -lunittest++
test:
	./a.out
grind:
	valgrind ./a.out
