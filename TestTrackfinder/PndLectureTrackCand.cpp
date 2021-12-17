/*
 * PndTrackCand.cxx
 *
 *  Created on: 22.11.2021
 *      Author: tstockmanns
 */

#include "PndLectureTrackCand.h"

PndLectureTrackCand::PndLectureTrackCand() {
	// TODO Auto-generated constructor stub

}

PndLectureTrackCand::~PndLectureTrackCand() {
	// TODO Auto-generated destructor stub
}

void PndLectureTrackCand::PrintCSVHeader(std::ostream& out) const
{
	out << "event_id," << "momentum_x,momentum_y,momentum_z," << "position_x,position_y,position_z," << "nHits," << "hits" << std::endl;
}

void PndLectureTrackCand::PrintCSV(std::ostream& out) const
{
	out << fEventId << ",";
	out << fMomentum[0] << "," << fMomentum[1] << "," << fMomentum[2] << ",";
	out << fPosition[0] << "," << fPosition[1] << "," << fPosition[2] << ",";
	out << fHitIndices.size();
	for (auto hit : fHitIndices) {
		out << "," << hit;
	}
	out << std::endl;
}
