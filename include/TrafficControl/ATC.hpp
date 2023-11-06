#ifndef ATC_HPP
#define ATC_HPP

#include <memory>
#include <vector>

#include "Plane.hpp"


class ATC {
private:
    static constexpr int MAX_LANDED_PLANE_NUM = 2;
    static constexpr int AIRSPACE_DISTANCE = 50;
    std::vector<std::unique_ptr<Plane>> registeredPlanes;
    
public:
    ATC() = default;
    ~ATC() = default;

    void registerPlane(std::unique_ptr<Plane>&& plane_ptr){
        registeredPlanes.push_back(plane_ptr);
    }

    void controlTraffic(){
        unsigned int landedPlanes = 0;
        
    }
};

#endif /* ATC_HPP */