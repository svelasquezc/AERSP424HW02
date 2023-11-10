#include <iostream>
#include <memory>

#include<TrafficControl/Airliner.hpp>
#include<TrafficControl/GeneralAviation.hpp>
#include <TrafficControl/ATC.hpp>

int main(){

    const double timeStep = 20;
    auto AA5915 = std::make_shared<Airliner>(Airliner("AA", "SCE", "PHL"));
    auto UA5236 = std::make_shared<Airliner>(Airliner("UA", "SCE", "ORD"));
    auto UA4465 = std::make_shared<Airliner>(Airliner("UA", "SCE", "EWR"));
    auto AA6240 = std::make_shared<Airliner>(Airliner("AA", "SCE", "ORD"));
    auto GA_PHL = std::make_shared<GeneralAviation>(GeneralAviation("SCE", "PHL"));
    auto GA_EWR = std::make_shared<GeneralAviation>(GeneralAviation("SCE", "EWR"));
    auto GA_ORD = std::make_shared<GeneralAviation>(GeneralAviation("SCE", "ORD"));

    AA5915->velocity(470.0/3600);
    UA5236->velocity(515.0/3600);
    UA4465->velocity(480.0/3600);
    AA6240->velocity(500.0/3600);
    GA_PHL->velocity(140.0/3600);
    GA_EWR->velocity(160.0/3600);
    GA_ORD->velocity(180.0/3600);

    auto atc = ATC();
    atc.registerPlane(AA5915); atc.registerPlane(UA5236); atc.registerPlane(UA4465); atc.registerPlane(AA6240);
    atc.registerPlane(GA_PHL); atc.registerPlane(GA_EWR); atc.registerPlane(GA_ORD);

    auto totalTimesteps = 10;
    unsigned int nTimestep = 0;
    while (nTimestep < totalTimesteps){
            AA5915->operate(timeStep);
            atc.controlTraffic();
            std::cout << "AA5915 position: "<< AA5915->position() <<std::endl;
            UA5236->operate(timeStep);
            atc.controlTraffic();
            std::cout << "UA5236 position: "<< UA5236->position() <<std::endl;
            UA4465->operate(timeStep);
            atc.controlTraffic();
            std::cout << "UA4465 position: "<< UA4465->position() <<std::endl;
            AA6240->operate(timeStep);
            atc.controlTraffic();
            std::cout << "AA6240 position: "<< AA6240->position() <<std::endl;
            GA_PHL->operate(timeStep);
            atc.controlTraffic();
            std::cout << "GA_PHL position: "<< GA_PHL->position() <<std::endl;
            GA_EWR->operate(timeStep);
            atc.controlTraffic();
            std::cout << "GA_EWR position: "<< GA_EWR->position() <<std::endl;
            GA_ORD->operate(timeStep);
            std::cout << "GA_ORD position: "<< GA_ORD->position() <<std::endl;
            atc.controlTraffic();

            nTimestep++;
    }

    return 0;
}