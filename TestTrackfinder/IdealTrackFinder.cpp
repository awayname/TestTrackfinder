/*
 * IdealTrackFinder.cxx
 *
 *  Created on: 22.11.2021
 *      Author: tstockmanns
 */

#include "IdealTrackFinder.h"
#include <map>

IdealTrackFinder::IdealTrackFinder() {
}

IdealTrackFinder::~IdealTrackFinder() {
}

std::vector<PndLectureTrackCand> IdealTrackFinder::FindTracks(std::vector<PndSttLectureHit>& hits, std::vector<PndMCTrack>& mctracks)
{
	std::map<int, PndLectureTrackCand> trackCands;
	std::vector<PndLectureTrackCand> result;

	for (int hitIndex = 0; hitIndex < hits.size(); hitIndex++) {
		PndSttLectureHit hit = hits[hitIndex];
		trackCands[hit.GetMCIndex()].AddHit(hitIndex);
	}
	for (auto& trackCand : trackCands) {
		trackCand.second.SetMomentum(mctracks[trackCand.first].GetMomentumX(), mctracks[trackCand.first].GetMomentumY(), mctracks[trackCand.first].GetMomentumZ());
		trackCand.second.SetPosition(mctracks[trackCand.first].GetStartVertexX(), mctracks[trackCand.first].GetStartVertexY(), mctracks[trackCand.first].GetStartVertexZ());
		trackCand.second.SetEventId(mctracks[trackCand.first].GetEventId());
		result.push_back(trackCand.second);
	}
	return result;
}
