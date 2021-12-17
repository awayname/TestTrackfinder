/*
 * PndLectureTrackCand.h
 *
 *  Created on: 22.11.2021
 *      Author: tstockmanns
 */

#ifndef DATA_PNDLECTURETRACKCAND_H_
#define DATA_PNDLECTURETRACKCAND_H_

#include <array>
#include <ostream>
#include <vector>
#include <iostream>

class PndLectureTrackCand {
public:
    PndLectureTrackCand();
    virtual ~PndLectureTrackCand();

    void AddHit(int index) { fHitIndices.push_back(index); }

    void SetEventId(int evt) { fEventId = evt; }
    void SetMomentum(double px, double py, double pz) {
        fMomentum = { px, py, pz };
    }
    void SetPosition(double x, double y, double z) { fPosition = { x, y, z }; }

    void PrintCSVHeader(std::ostream& out = std::cout) const;
    void PrintCSV(std::ostream& out = std::cout) const;

    friend std::ostream& operator<<(std::ostream& os,
        const PndLectureTrackCand& track) {
        os << "Event_ID: " << track.fEventId << " hits ";
        for (auto hit : track.fHitIndices) {
            os << hit << "/";
        }
        os << " momentum " << track.fMomentum[0] << "/" << track.fMomentum[1] << "/"
            << track.fMomentum[2];
        os << " at position " << track.fPosition[0] << "/" << track.fPosition[1]
            << "/" << track.fPosition[2];
        return os;
    }

private:
    int fEventId = -1;                               //< Event identifier
    std::vector<int> fHitIndices;                    //< Index of the hit which belongs to this track candidate (is PndSttLectureHit::fPointID)
    std::array<double, 3> fMomentum{ -1., -1, -1. };   //< momentum vector of the track in GeV/c
    std::array<double, 3> fPosition{ -1., -1., -1. };  //< position where the momentum vector is determined in cm (should be at the start of the track)
    int fMCIndex = -1;                               //< MC truth index to the true track (only used by ideal track finder)
};

#endif /* DATA_PNDTRACKCAND_H_ */
