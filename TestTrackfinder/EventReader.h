/*
 * EventReader.h
 *
 *  Created on: 07.12.2021
 *      Author: tstockmanns
 */

#ifndef EVENTHANDLER_EVENTREADER_H_
#define EVENTHANDLER_EVENTREADER_H_

#include "EventReader.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

template <class T>
class EventReader {
public:
    explicit EventReader(std::string fileName, bool firstLine = true);
    virtual ~EventReader();

    bool GetNextEvent(std::vector<T>& event);

private:
    bool fFirstLine = true;
    int fCurrentEvent = -1;
    T fPreviousHit;
    std::ifstream fInStream;
};

template <class T>
EventReader<T>::EventReader(std::string fileName, bool firstLine)
    : fInStream(fileName), fFirstLine(firstLine) {
    std::cout << "InStream.is_open " << fInStream.is_open() << " for File " << fileName << std::endl;
}

template <class T>
EventReader<T>::~EventReader() {}

template <class T>
bool EventReader<T>::GetNextEvent(std::vector<T>& event) {
    if (fInStream.is_open()) {
        std::string line;
        if (fFirstLine == true) {
            std::getline(fInStream, line);
            fFirstLine = false;
        }
        if (fCurrentEvent < 0) {
            std::getline(fInStream, line);
            std::istringstream is(line);
            is >> fPreviousHit;
            fCurrentEvent = fPreviousHit.GetEventId();
        }
        event.push_back(fPreviousHit);
        while (std::getline(fInStream, line)) {
            T hit;
            std::istringstream is(line);
            is >> hit;
            if (hit.GetEventId() == fCurrentEvent) {
                event.push_back(hit);
            }
            else {
                fPreviousHit = hit;
                fCurrentEvent = hit.GetEventId();
                return true;
            }
        }
        return false;
    }
    return false;
}

#endif /* EVENTHANDLER_EVENTREADER_H_ */
