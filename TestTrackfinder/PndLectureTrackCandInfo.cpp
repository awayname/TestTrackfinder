/*
 * PndLectureTrackCandInfo.cxx
 *
 *  Created on: 15.12.2021
 *      Author: tstockmanns
 */

#include "PndLectureTrackCandInfo.h"

#include <algorithm>
#include <cmath>

PndLectureTrackCandInfo::PndLectureTrackCandInfo() {
	// TODO Auto-generated constructor stub
}

PndLectureTrackCandInfo::~PndLectureTrackCandInfo() {
	// TODO Auto-generated destructor stub
}

std::pair<int, int> PndLectureTrackCandInfo::GetHighestMCIndex() const {
	std::pair<int, int> result{ -1, 0 };
	for (auto hitInfo : fMCHitInfo) {
		if (result.second < hitInfo.second) {
			result = hitInfo;
		}
	}
	return result;
}

double PndLectureTrackCandInfo::GetPurity()
{
	double result = 0.;
	double sum = 0;
	for (auto info : fMCHitInfo) {
		sum += info.second;
	}
	int index = GetHighestMCIndex().first;
	if (index < 0) {
		return -1.;
	}
	result = static_cast<double>(fMCHitInfo[index]) / sum;
	return result;
}

void PndLectureTrackCandInfo::CalcEfficiency(std::vector<PndSttLectureHit> hits)
{
	int index = GetHighestMCIndex().first;
	int nMCHits = 0;

	for (auto hit : hits) {
		if (hit.GetMCIndex() == index) {
			nMCHits++;
		}
	}
	fEfficiency = static_cast<double>(GetHighestMCIndex().second) / nMCHits;
}


void PndLectureTrackCandInfo::CalcDeltaP(PndLectureTrackCand track, std::vector<PndMCTrack> mctracks)
{
	int index = GetHighestMCIndex().first;
	PndMCTrack mctrack = mctracks[index];
	fDPz = mctrack.GetMomentumZ() - track.GetMomentumZ();

	double mcX = mctrack.GetMomentumX();
	double mcY = mctrack.GetMomentumY();

	double x = track.GetMomentumX();
	double y = track.GetMomentumY();

	fDPt = std::sqrt(mcX * mcX + mcY * mcY) - std::sqrt(x * x + y * y);
}
