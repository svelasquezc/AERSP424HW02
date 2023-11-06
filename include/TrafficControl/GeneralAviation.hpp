#ifndef GENERAL_AVIATION_HPP
#define GENERAL_AVIATION_HPP

#include "Plane.hpp"

class GeneralAviation: public Plane {
public:
    GeneralAviation(std::string from, std::string to): Plane(from, to) {}

    ~GeneralAviation() = default;

    void timeOnGround() override {
        waitTime_ = GeneralAviation::drawFromNormalDist(600, 60);
    }
};

#endif /* GENERAL_AVIATION_HPP */