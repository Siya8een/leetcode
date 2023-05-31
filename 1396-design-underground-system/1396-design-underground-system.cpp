#include <unordered_map>
#include <string>

class UndergroundSystem {
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        const auto& checkInData = checkIns[id];
        const string& startStation = checkInData.first;
        int checkInTime = checkInData.second;
        
        string route = startStation + "-" + stationName;
        travelTimes[route].first += t - checkInTime;  // Accumulate total travel time
        travelTimes[route].second++;  // Increment count of trips for the route
        
        checkIns.erase(id);  // Remove check-in data for the customer
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "-" + endStation;
        const auto& travelTimeData = travelTimes[route];
        int totalTravelTime = travelTimeData.first;
        int tripCount = travelTimeData.second;
        
        return static_cast<double>(totalTravelTime) / tripCount;
    }
    
private:
    unordered_map<int, pair<string, int>> checkIns;  // Stores check-in information for customers
    unordered_map<string, pair<int, int>> travelTimes;  // Stores total travel time and trip count for each route
};
