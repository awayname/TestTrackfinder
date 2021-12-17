
#include <iostream>
#include <string>
#include <vector>

#include "PndSttLectureHit.h"
#include "EventHandler.h"
#include "IdealTrackFinder.h"

int main(int argc, char** argv) {
    int i = 1;
    std::string inputFile("./data/SimpleCase_1Muon.csv");
    std::string mcFile("./data/SimpleCase_1Muon_MC.csv");
    std::string outputFile("./data/IdealTracking.csv");
    std::string branchName("IdealTrack");

    for (; i < argc; ++i) {
        if (!strcmp(argv[i], "-inputfile")) {
            if (i + 1 < argc) {
                inputFile = argv[i + 1];
            }
        }
        else if (!strcmp(argv[i], "-mcfile")) {
            if (i + 1 < argc) {
                mcFile = argv[i + 1];
            }
        }
        else if (!strcmp(argv[i], "-outputfile")) {
            if (i + 1 < argc) {
                outputFile = argv[i + 1];
            }
        }
    }
    std::cout << "InputFile: " << inputFile << " outputFile: " << outputFile
        << " mcFile: " << mcFile << std::endl;

    TrackFinderBase* finder = new IdealTrackFinder();

    EventHandler handler(finder, inputFile, outputFile, mcFile);

    handler.ProcessEvents();


    return 0;
}
