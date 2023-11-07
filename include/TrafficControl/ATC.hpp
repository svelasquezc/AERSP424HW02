#ifndef ATC_HPP
#define ATC_HPP

#include <memory>
#include <vector>

#include "Plane.hpp"


class ATC {
private:
    static constexpr int MAX_LANDED_PLANE_NUM = 2;
    static constexpr int AIRSPACE_DISTANCE = 50;
    std::vector<std::shared_ptr<Plane>> registeredPlanes;
    
public:
    ATC() = default;
    ~ATC() = default;

    void registerPlane(std::shared_ptr<Plane> plane_ptr){
        registeredPlanes.push_back(plane_ptr);
    }

    void controlTraffic(const unsigned int& currentPlaneNumber){
        unsigned int landedPlanes = 0;
        for (unsigned int i=0; i<= currentPlaneNumber; ++i){
            landedPlanes += registeredPlanes[i]->atSCE();
        }
        if (landedPlanes < MAX_LANDED_PLANE_NUM) return;
        for (unsigned int i=0; i<= currentPlaneNumber; ++i){
            if (!registeredPlanes[i]->atSCE() &&
             registeredPlanes[i]->distanceToSCE() <= AIRSPACE_DISTANCE &&
             registeredPlanes[i]->loiterTime() == 0) 
             registeredPlanes[i]->loiterTime(100);
        }
    }
};

#endif /* ATC_HPP */