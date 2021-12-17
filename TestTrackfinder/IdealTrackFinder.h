/*
 * IdealTrackFinder.h
 *
 *  Created on: 22.11.2021
 *      Author: tstockmanns
 */

#ifndef IDEALTRACKFINDER_IDEALTRACKFINDER_H_
#define IDEALTRACKFINDER_IDEALTRACKFINDER_H_

#include <vector>

#include "PndLectureTrackCand.h"
#include "PndMCTrack.h"
#include "PndSttLectureHit.h"
#include "TrackFinderBase.h"

class IdealTrackFinder : public TrackFinderBase {
public:
    IdealTrackFinder();
    virtual ~IdealTrackFinder();

    std::vector<PndLectureTrackCand> FindTracks(std::vector<PndSttLectureHit>& hits) {
        std::cout << "The ideal track finder needs MC track data in addition" << std::endl;
        std::vector<PndLectureTrackCand> result;
        return result;
    }

    std::vector<PndLectureTrackCand> FindTracks(std::vector<PndSttLectureHit>& hits, std::vector<PndMCTrack>& mctracks);
};

#endif /* IDEALTRACKFINDER_IDEALTRACKFINDER_H_ */
