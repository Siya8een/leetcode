class ParkingSystem {
private:
    int availableSlots[4];  // Index 0 is not used, 1 represents big, 2 represents medium, 3 represents small.

public:
    ParkingSystem(int big, int medium, int small) {
        availableSlots[1] = big;
        availableSlots[2] = medium;
        availableSlots[3] = small;
    }

    bool addCar(int carType) {
        if (availableSlots[carType] > 0) {
            availableSlots[carType]--;
            return true;
        }
        return false;
    }
};
