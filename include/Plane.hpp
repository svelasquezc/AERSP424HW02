#ifndef PLANE_HPP
#define PLANE_HPP
#include <string>
#include <random>
#include <utility>

class Plane {
private:
    double pos_, vel_, distance_, loiterTime_;
    bool atSCE;
    std::string origin_, destination_;
    //TODO: implement container Question 1;
protected:
    double waitTime_;
public:
    Plane(std::string from, std::string to): origin_(from), destination_(to){
        distance_= 0; //TODO: calculate distance using container Question 1;
        pos_ = 0;
        vel_ = 0;
        waitTime_ = 0;
        loiterTime_ = 0;
        atSCE = false;
    };

    virtual ~Plane(){};

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
        if (pos_ > distance_){
            pos_ += vel_*dt;
            atSCE = 0;
            return;
        }
        if (destination_ == "SCE"){
            atSCE = true;
        }
        timeOnGround();
        std::swap(origin_,destination_);
        pos_ = 0;
    };

    double position() const {
        return pos_;
    };

    double velocity() const {
        return pos_;
    };

    double loiterTime() const {
        return pos_;
    };

    std::string origin() const {
        return origin_;
    };

    std::string destination() const {
        return destination_;
    };

    void velocity(const double& vel){
        vel_ = vel;
    };

    void loiterTime(const double& _loiterTime) {
        loiterTime_ = _loiterTime;
    };

    virtual std::string planeType() const {
        return "GA";
    }

    virtual void timeOnGround() = 0;

    static double drawFromNormalDist(const double& mean, const double& std){
        std::random_device rd{};
        std::mt19937 gen{ rd() };
        std::normal_distribution<> d{ mean, std };
        return d(gen);
    }
};

#endif /* PLANE_HPP */