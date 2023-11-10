#ifndef ATC_HPP
#define ATC_HPP

#include <memory>
#include <vector>
#include <iostream>

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

    void controlTraffic(){
        unsigned int landedPlanes = 0;
        for (auto plane_ptr : registeredPlanes) landedPlanes += plane_ptr->atSCE();

        if (landedPlanes < MAX_LANDED_PLANE_NUM) return;

        for (auto plane_ptr : registeredPlanes){
            if (!plane_ptr->atSCE() &&
             plane_ptr->distanceToSCE() <= AIRSPACE_DISTANCE &&
             plane_ptr->loiterTime() == 0) 
             plane_ptr->loiterTime(100);
        }
    }
};

#endif /* ATC_HPP */