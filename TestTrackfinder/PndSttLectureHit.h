/*
 * PndSttLectureHit.h
 *
 *  Created on: 17.11.2021
 *      Author: tstockmanns
 */

#ifndef DETECTORS_STT_PNDSTTLECTUREHIT_H_
#define DETECTORS_STT_PNDSTTLECTUREHIT_H_

 //#include <TObject.h>

#include <iostream>
#include <vector>

class PndSttLectureHit {
public:
    PndSttLectureHit() {};
    PndSttLectureHit(int eventId, int tubeId, int pointId, int mcIndex, double x, double y,
        double z, double dx, double dy, double dz, std::vector<int> neighbors, int sectorID, int layerID,
        bool isSkewed);
    ~PndSttLectureHit() {};

    int GetEventId() const { return fEventId; };
    int GetTubeId() const { return fTubeId; };
    int GetMCIndex() const { return fMCIndex; };
    int GetPointId() const { return fPointId; };

    double X() const { return fX; }
    double Y() const { return fY; }
    double Z() const { return fZ; }

    double DX() const { return fDX; }
    double DY() const { return fDY; }
    double DZ() const { return fDZ; }

    int GetSectorID() const { return fSectorID; }
    int GetLayerID() const { return fLayerID; }
    int IsSkewed() const { return fIsSkewed; }
    std::vector<int> GetNeighbors() const { return fNeighbors; }

    friend std::ostream& operator<<(std::ostream& os,
        const PndSttLectureHit& hit) {
        os << "MCIndex: " << hit.GetMCIndex() << " pointID: " << hit.GetPointId()
            << " TubeId: " << hit.GetTubeId() << " x/y/z " << hit.X() << "/"
            << hit.Y() << "/" << hit.Z() << " SectorID/LayerID " << hit.GetSectorID()
            << "/" << hit.GetLayerID() << " neighbors: ";
        for (auto neighbor : hit.GetNeighbors()) {
            os << neighbor << "/";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& os, PndSttLectureHit& hit) {
        int nNeighbors = -1;
        os >> hit.fEventId;
        os.get();
        os >> hit.fMCIndex;
        os.get();
        os >> hit.fPointId;
        os.get();
        os >> hit.fTubeId;
        os.get();
        os >> hit.fX;
        os.get();
        os >> hit.fY;
        os.get();
        os >> hit.fZ;
        os.get();
        os >> hit.fDX;
        os.get();
        os >> hit.fDY;
        os.get();
        os >> hit.fDZ;
        os.get();
        os >> hit.fSectorID;
        os.get();
        os >> hit.fLayerID;
        os.get();
        os >> hit.fIsSkewed;
        os.get();
        os >> nNeighbors;
        for (int i = 0; i < nNeighbors; i++) {
            int neighbor = -1;
            os.get();
            os >> neighbor;
            hit.fNeighbors.push_back(neighbor);
        }
        return os;
    }

private:
    int fEventId = -1;      //< Event index
    int fTubeId = -1;       //< Tube identifier
    int fMCIndex = -1;      //< Index of Monte-Carlo Track which created this hit
    int fPointId = -1;      //< Index of Monte-Carlo Point
    double fX = -1.;        //< Reconstructed x position of hit in [cm]
    double fY = -1.;        //< Reconstructed y position of hit in [cm]
    double fZ = -1.;        //< Reconstructed z position of hit in [cm]

    double fDX = -1.;       //< Sigma error in x position of hit in [cm]
    double fDY = -1.;       //< Sigma error in x position of hit in [cm]
    double fDZ = -1.;       //< Sigma error in x position of hit in [cm]

    std::vector<int> fNeighbors;    //< vector of tubeId`s of neighboring tubes
    int fSectorID;                  //< sector in the STT where this hit is created
    int fLayerID;                   //< lacer in the STT where this is created (inner layer is 0)
    bool fIsSkewed;                 //< information if this tube is skewed (or parallel) to the beam axis (z)
};

#endif /* DETECTORS_STT_PNDSTTLECTUREHIT_H_ */
