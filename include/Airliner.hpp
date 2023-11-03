#ifndef AIRLINER_HPP
#define AIRLINER_HPP
#include <string>
#include "Plane.hpp"

class Airliner : public Plane {
private:
    std::string airline_;
public:

    Airliner(std::string airline, std::string from, std::string to): Plane(from, to), airline_(airline)
    {}

    ~Airliner() = default;
    
    std::string planeType() const override {
        return "Airline";
    }
    
    void timeOnGround() override {
        waitTime_ = Airliner::drawFromNormalDist(1800,600);
    }
};

#endif /* AIRLINER_HPP */