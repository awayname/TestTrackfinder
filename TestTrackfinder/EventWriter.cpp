/*
 * EventWriter.cxx
 *
 *  Created on: 07.12.2021
 *      Author: tstockmanns
 */

#include "EventWriter.h"

EventWriter::EventWriter(std::string outFile) : fOutStream(outFile) {
}

EventWriter::~EventWriter() {
	fOutStream.close();
}

void EventWriter::WriteEvent(std::vector<PndLectureTrackCand>& trackCands)
{

	for (auto trackCand : trackCands) {
		if (fFirst == true) {
			trackCand.PrintCSVHeader(fOutStream);
			fFirst = false;
		}
		trackCand.PrintCSV(fOutStream);
	}
}
