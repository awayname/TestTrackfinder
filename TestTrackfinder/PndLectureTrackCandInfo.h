/*
 * PndLectureTrackCandInfo.h
 *
 *  Created on: 15.12.2021
 *      Author: tstockmanns
 */

#pragma once

#include "PndLectureTrackCand.h"
#include "PndSttLectureHit.h"
#include "PndMCTrack.h"

#include <map>
#include <utility>
#include <iostream>
#include <vector>

class PndLectureTrackCandInfo {
public:
    PndLectureTrackCandInfo();
    virtual ~PndLectureTrackCandInfo();

    void SetEventId(int id) { fEventId = id; }
    void AddHit(int mcTrackId) { fMCHitInfo[mcTrackId]++; }
    void CalcEfficiency(std::vector<PndSttLectureHit> hits);
    void CalcDeltaP(PndLectureTrackCand track, std::vector<PndMCTrack> mctracks);

    std::pair<int, int> GetHighestMCIndex() const;

    int GetEventId() const { return fEventId; }
    double GetPurity();
    double GetEfficiency() const { return fEfficiency; }
    double GetDPt() const { return fDPt; }
    double GetDPz() const { return fDPz; }

    void PrintCSVHeader(std::ostream& os) {
        os << "eventId,"
            << "efficiency,"
            << "purity,"
            << "delta_pt,"
            << "delta_pz,"
            << "nMCTracks,"
            << "mctrack,"
            << "nHits" << std::endl;
    }

    void PrintCSV(std::ostream& os) {
        os << fEventId << "," << fEfficiency << "," << GetPurity() << "," << fDPt << "," << fDPz << ",";
        os << fMCHitInfo.size();
        for (auto hitInfo : fMCHitInfo) {
            os << "," << hitInfo.first << "," << hitInfo.second;
        }
        os << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, PndLectureTrackCandInfo& hit) {
        os << "EventId " << hit.fEventId << " efficiency: " << hit.fEfficiency
            << " purity: " << hit.GetPurity() << " DeltaP(t/z): " << hit.fDPt << "/"
            << hit.fDPz << " MCTrackInfo:";
        for (auto hitInfo : hit.fMCHitInfo) {
            os << " [" << hitInfo.first << "|" << hitInfo.second << "]";
        }
        return os;
    }

private:
    int fEventId = -1;
    std::map<int, int> fMCHitInfo;  //< map of MC trackIndex vs. hits of MC track
    double fEfficiency = -1.;  //< ratio of found hits of best MCTrack vs. all hits of MC track

    double fDPt = -10000.0;  //< difference of reconstructed transversal momentum to MC momentum (MC - reco)
    double fDPz = -10000.0;  //< difference of reconstructed longitudinal momentum to MC momentum (MC - reco)
};

