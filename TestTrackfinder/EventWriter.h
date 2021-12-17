/*
 * EventWriter.h
 *
 *  Created on: 07.12.2021
 *      Author: tstockmanns
 */

#ifndef EVENTHANDLER_EVENTWRITER_H_
#define EVENTHANDLER_EVENTWRITER_H_

#include <fstream>
#include <string>

#include "PndLectureTrackCand.h"





class EventWriter {
public:
	explicit EventWriter(std::string outFile);
	virtual ~EventWriter();
	void WriteEvent(std::vector<PndLectureTrackCand>& trackCands);

private:
	std::ofstream fOutStream;
	bool fFirst = true;
};

#endif /* EVENTHANDLER_EVENTWRITER_H_ */
