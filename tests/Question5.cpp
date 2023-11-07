#include <memory>
#include <iostream>

#include<TrafficControl/Plane.hpp>
#include<TrafficControl/Airliner.hpp>
#include<TrafficControl/GeneralAviation.hpp>


int main(){
    const int timeStep = 20;
    std::unique_ptr<Plane> AA5915 = std::make_unique<Airliner>(Airliner("AA", "SCE", "PHL"));
    std::unique_ptr<Plane> UA5236 = std::make_unique<Airliner>(Airliner("UA", "SCE", "ORD"));
    std::unique_ptr<Plane> UA4465 = std::make_unique<Airliner>(Airliner("UA", "SCE", "EWR"));
    std::unique_ptr<Plane> AA6240 = std::make_unique<Airliner>(Airliner("AA", "SCE", "ORD"));
    std::unique_ptr<Plane> GA_PHL = std::make_unique<GeneralAviation>(GeneralAviation("SCE", "PHL"));
    std::unique_ptr<Plane> GA_EWR = std::make_unique<GeneralAviation>(GeneralAviation("SCE", "EWR"));
    std::unique_ptr<Plane> GA_ORD = std::make_unique<GeneralAviation>(GeneralAviation("SCE", "ORD"));

    AA5915->velocity(470);
    UA5236->velocity(515);
    UA4465->velocity(480);
    AA6240->velocity(500);
    GA_PHL->velocity(140);
    GA_EWR->velocity(160);
    GA_ORD->velocity(180);

    

    auto totalTimesteps = 10;
    unsigned int nTimestep = 0;
    while (nTimestep < totalTimesteps){
            AA5915->operate(timeStep);
            std::cout << "AA5915 position: "<< AA5915->position() <<std::endl;
            UA5236->operate(timeStep);
            std::cout << "UA5236 position: "<< UA5236->position() <<std::endl;
            UA4465->operate(timeStep);
            std::cout << "UA4465 position: "<< UA4465->position() <<std::endl;
            AA6240->operate(timeStep);
            std::cout << "AA6240 position: "<< AA6240->position() <<std::endl;
            GA_PHL->operate(timeStep);
            std::cout << "GA_PHL position: "<< GA_PHL->position() <<std::endl;
            GA_EWR->operate(timeStep);
            std::cout << "GA_EWR position: "<< GA_EWR->position() <<std::endl;
            GA_ORD->operate(timeStep);
            std::cout << "GA_ORD position: "<< GA_ORD->position() <<std::endl;
    }
    return 0;
}