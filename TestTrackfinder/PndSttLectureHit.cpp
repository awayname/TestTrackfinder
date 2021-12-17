/*
 * PndSttLectureHit.cxx
 *
 *  Created on: 17.11.2021
 *      Author: tstockmanns
 */

#include "PndSttLectureHit.h"

PndSttLectureHit::PndSttLectureHit(int eventId, int tubeId, int pointId, int mcIndex,
    double x, double y, double z, double dx,
    double dy, double dz, std::vector<int> neighbors, int sectorID, int layerID,
    bool isSkewed)
    : fEventId(eventId),
    fTubeId(tubeId),
    fPointId(pointId),
    fMCIndex(mcIndex),
    fX(x),
    fY(y),
    fZ(z),
    fDX(dx),
    fDY(dy),
    fDZ(dz),
    fNeighbors(neighbors),
    fSectorID(sectorID),
    fLayerID(layerID),
    fIsSkewed(isSkewed)
{}
