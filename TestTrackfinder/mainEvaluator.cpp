#include <iostream>
#include <string>
#include <vector>

#include "TrackEvaluatorHandler.h"

int main(int argc, char** argv) {
    int i = 1;
    std::string trackCandFile("");
    std::string hitFile("");
    std::string mcFile("");
    std::string trackInfoFile("");	//< output file
    std::string mcInfoFile("");		//< output file

    for (; i < argc; ++i) {
        if (!strcmp(argv[i], "-trackcandfile")) {
            if (i + 1 < argc) {
                trackCandFile = argv[i + 1];
            }
        }
        else if (!strcmp(argv[i], "-hitfile")) {
            if (i + 1 < argc) {
                hitFile = argv[i + 1];
            }
        }
        else if (!strcmp(argv[i], "-mcfile")) {
            if (i + 1 < argc) {
                mcFile = argv[i + 1];
            }
        }
        else if (!strcmp(argv[i], "-trackinfofile")) {
            if (i + 1 < argc) {
                trackInfoFile = argv[i + 1];
            }
        }
        else if (!strcmp(argv[i], "-mcinfofile")) {
            if (i + 1 < argc) {
                mcInfoFile = argv[i + 1];
            }
        }
    }
    std::cout << "TrackCandFile: " << trackCandFile << " HitFile: " << hitFile
        << " mcFile: " << mcFile << " trackInfoFile: " << trackInfoFile << " MCInfoFile: " << mcInfoFile << std::endl;

    TrackEvaluatorHandler handler(trackCandFile, hitFile, mcFile, trackInfoFile, mcInfoFile);

    handler.ProcessEvents();

    return 0;
}



