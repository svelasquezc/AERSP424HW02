#ifndef ATC_HPP
#define ATC_HPP

#include <memory>
#include <vector>

#include "Plane.hpp"


class ATC {
private:
    std::vector<std::unique_ptr<Plane>> registeredPlanes;
        
}

#endif /* ATC_HPP */