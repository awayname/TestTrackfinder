/*
 * TrackFinderBase.h
 *
 *  Created on: 07.12.2021
 *      Author: tstockmanns
 */

#ifndef TRACKFINDERBASE_TRACKFINDERBASE_H_
#define TRACKFINDERBASE_TRACKFINDERBASE_H_

#include "PndLectureTrackCand.h"
#include "PndSttLectureHit.h"
#include "PndMCTrack.h"

class TrackFinderBase {
public:
    TrackFinderBase() {};
    virtual ~TrackFinderBase() {};

    virtual std::vector<PndLectureTrackCand> FindTracks(std::vector<PndSttLectureHit>& hits) = 0;
    virtual std::vector<PndLectureTrackCand> FindTracks(std::vector<PndSttLectureHit>& hits, std::vector<PndMCTrack>& mctracks) {
        std::cout << "FindTracks with two MC tracks not implemented!" << std::endl;
        std::vector<PndLectureTrackCand> result;
        return result;
    };
};

#endif /* TRACKFINDERBASE_TRACKFINDERBASE_H_ */
