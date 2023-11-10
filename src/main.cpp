#include <iostream>
#include<TrafficControl/Airliner.hpp>
#include<TrafficControl/GeneralAviation.hpp>
#include <TrafficControl/ATC.hpp>

#include <Visualization/HW2_Visualizer.hpp>


int main(int argc, char** argv){
    const double timeStep = 50.0;
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

    auto viz = HW2_VIZ();

    while (!viz.close()){

            AA5915->operate(timeStep);
            atc.controlTraffic();
            UA5236->operate(timeStep);
            atc.controlTraffic();
            UA4465->operate(timeStep);
            atc.controlTraffic();
            AA6240->operate(timeStep);
            atc.controlTraffic();
            GA_PHL->operate(timeStep);
            atc.controlTraffic();
            GA_EWR->operate(timeStep);
            atc.controlTraffic();
            GA_ORD->operate(timeStep);
            atc.controlTraffic();

            viz.visualizePlane(AA5915->planeType(), AA5915->origin(), AA5915->destination(), AA5915->position());
            viz.visualizePlane(UA5236->planeType(), UA5236->origin(), UA5236->destination(), UA5236->position());
            viz.visualizePlane(UA4465->planeType(), UA4465->origin(), UA4465->destination(), UA4465->position());
            viz.visualizePlane(AA6240->planeType(), AA6240->origin(), AA6240->destination(), AA6240->position());
            viz.visualizePlane(GA_PHL->planeType(), GA_PHL->origin(), GA_PHL->destination(), GA_PHL->position());
            viz.visualizePlane(GA_EWR->planeType(), GA_EWR->origin(), GA_EWR->destination(), GA_EWR->position());
            viz.visualizePlane(GA_ORD->planeType(), GA_ORD->origin(), GA_ORD->destination(), GA_ORD->position());
            
            viz.update(timeStep);
    }
}
