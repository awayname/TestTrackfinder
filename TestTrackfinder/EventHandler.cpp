/*
 * EventHandler.cpp
 *
 *  Created on: 06.12.2021
 *      Author: tstockmanns
 */

#include "EventHandler.h"

#include <vector>

#include "EventReader.h"
#include "EventWriter.h"
#include "PndMCTrack.h"
#include "PndSttLectureHit.h"

EventHandler::EventHandler(TrackFinderBase* finder, std::string inputFile,
    std::string outputFile, std::string mcFile)
    : fTrackFinder(finder),
    fInFile(inputFile),
    fOutFile(outputFile),
    fMCFile(mcFile) {}

EventHandler::~EventHandler() {
    if (fTrackFinder != nullptr) delete (fTrackFinder);
}

void EventHandler::ProcessEvents() {
    EventReader<PndSttLectureHit> reader(fInFile);

    EventReader<PndMCTrack>* MCreader = nullptr;

    EventWriter writer(fOutFile);

    if (fMCFile.length() > 0) {
        MCreader = new EventReader<PndMCTrack>(fMCFile);
    }

    std::vector<PndSttLectureHit> hits;
    std::vector<PndMCTrack> mcTracks;
    std::vector<PndLectureTrackCand> trackCands;
    int evt = 0;
    while (reader.GetNextEvent(hits)) {
        if (MCreader != nullptr) {
            MCreader->GetNextEvent(mcTracks);
            trackCands = fTrackFinder->FindTracks(
                hits, mcTracks);  // todo: check if eventId of MC event is identical
                                  // to Hit event
        }
        else {
            trackCands = fTrackFinder->FindTracks(hits);
        }
        writer.WriteEvent(trackCands);
        hits.clear();
        mcTracks.clear();
        trackCands.clear();
    }
    if (MCreader != nullptr) { //duplication necessary to process last event
        MCreader->GetNextEvent(mcTracks);
        trackCands = fTrackFinder->FindTracks(hits, mcTracks);  // todo: check if eventId of MC event is identical to Hit event
    }
    else {
        trackCands = fTrackFinder->FindTracks(hits);
    }
    writer.WriteEvent(trackCands);
    hits.clear();
    mcTracks.clear();
    trackCands.clear();
    if (MCreader != nullptr) {
        delete (MCreader);
    }
}
