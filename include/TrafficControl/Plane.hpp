#ifndef PLANE_HPP
#define PLANE_HPP
#include <string>
#include <random>
#include <utility>
#include <map>

class Plane {
private:
    using AirspaceType = std::map<std::pair<std::string, std::string>, double>;
    double position_, velocity_, distance_, loiterTime_;
    bool atSCE;
    std::string origin_, destination_;
    static const AirspaceType airspace;
protected:
    double waitTime_;
public:
    Plane(std::string from, std::string to): origin_(from), destination_(to){
        distance_= airspace[{origin_, destination_}]; //TODO: calculate distance using container Question 1;
        position_ = 0;
        velocity_ = 0;
        waitTime_ = 0;
        loiterTime_ = 0;
        atSCE = false;
    };

    virtual ~Plane() = default;

    void operate(const double& dt){
        if (loiterTime_ != 0){
            loiterTime_ -= dt;
            if (loiterTime_ < 0) loiterTime_ = 0;
            return;
        }
        if (waitTime_ != 0){
            waitTime_ -= dt;
            if (waitTime_ < 0) waitTime_ = 0;
            return;
        }
        if (position_ > distance_){
            position_ += velocity_*dt;
            atSCE = 0;
            return;
        }
        if (destination_ == "SCE"){
            atSCE = true;
        }
        timeOnGround();
        std::swap(origin_,destination_);
        position_ = 0;
    };

    double position() const {
        return position_;
    };

    double velocity() const {
        return velocity_;
    };

    double loiterTime() const {
        return loiterTime_;
    };

    std::string origin() const {
        return origin_;
    };

    std::string destination() const {
        return destination_;
    };

    void velocity(const double& vel){
        velocity_ = vel;
    };

    void loiterTime(const double& _loiterTime) {
        loiterTime_ = _loiterTime;
    };

    double distanceToSCE() const {
        if (destination_ == "SCE") return distance_ - position_;
        return -1;
    };

    virtual std::string planeType() const {
        return "GA";
    };

    virtual void timeOnGround() = 0;

    static double drawFromNormalDist(const double& mean, const double& std){
        std::random_device rd{};
        std::mt19937 gen{ rd() };
        std::normal_distribution<> d{ mean, std };
        return d(gen);
    };
};

const Plane::AirspaceType Plane::airspace = { 
    { {"SCE","ORD"}, 640}, // miles
    { {"ORD","SCE"}, 640},
    { {"SCE","PHL"}, 160},
    { {"PHL","SCE"}, 160},
    { {"SCE","EWR"}, 220},
    { {"EWR","SCE"}, 220},
};

#endif /* PLANE_HPP */