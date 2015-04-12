class ShipCrew {
public:
    static const int MAX_CREW = 100;

    ShipCrew();

    int cntCrew;
    Person* crew[MAX_CREW];
};
