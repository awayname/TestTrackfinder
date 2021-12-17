/*
 * EventHandler.h
 *
 *  Created on: 06.12.2021
 *      Author: tstockmanns
 */

#ifndef EVENTHANDLER_EVENTHANDLER_H_
#define EVENTHANDLER_EVENTHANDLER_H_

#include <string>
#include "TrackFinderBase.h"

class EventHandler {
public:
	EventHandler(TrackFinderBase* finder, std::string inputFile, std::string outputFile, std::string mcFile = "");
	virtual ~EventHandler();

	void SetTrackFinder(TrackFinderBase* finder) {
		fTrackFinder = finder;
	}

	void Init();

	void ProcessEvents();

private:
	std::string fOutFile;
	std::string fInFile;
	std::string fMCFile;

	TrackFinderBase* fTrackFinder = nullptr;
};

#endif /* EVENTHANDLER_EVENTHANDLER_H_ */
