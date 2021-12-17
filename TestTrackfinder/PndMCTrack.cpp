// -------------------------------------------------------------------------
// -----                      PndMCTrack source file                   -----
// -----                  Created 03/08/04  by V. Friese (CbmMCTrack)  -----
// -----                  Created 11/02/09  by  M. Al-Turany           -----
// -------------------------------------------------------------------------

#include <iostream>

#include "PndMCTrack.h"
#include <limits>
using namespace std;
// -----   Default constructor   -------------------------------------------
PndMCTrack::PndMCTrack()
    : fEventId(-1), fPdgCode(0), fPx(0), fPy(0), fPz(0), fMotherID(-1), fStartX(0), fStartY(0), fStartZ(0), fStartT(0), fPoints(0)
{
}
// -------------------------------------------------------------------------

// -----   Standard constructor   ------------------------------------------
/*// Not used at all?
PndMCTrack::PndMCTrack(int pdgCode, int motherID, TVector3 startVertex,
           double startTime, TLorentzVector momentum, int  nPoint){
  fPdgCode  = pdgCode;
  fMotherID = motherID;
  fSecondMotherID = -1;
  fStartX   = startVertex.X();
  fStartY   = startVertex.Y();
  fStartZ   = startVertex.Z();
  fStartT   = startTime;
  fPx       = momentum.Px();
  fPy       = momentum.Py();
  fPz       = momentum.Pz();
  fE        = momentum.E();
  if (nPoint >= 0) fPoints = nPoint;
  else             fPoints = 0;
  fGeneratorFlags=0;
}
*/
// -------------------------------------------------------------------------

// -----   Copy constructor   ----------------------------------------------
PndMCTrack::PndMCTrack(const PndMCTrack& track)
    : fEventId(track.fEventId), fPdgCode(track.fPdgCode), fPx(track.fPx), fPy(track.fPy), fPz(track.fPz), fMotherID(track.fMotherID), fStartX(track.fStartX), fStartY(track.fStartY), fStartZ(track.fStartZ), fStartT(track.fStartT), fPoints(track.fPoints)
{
}
// -------------------------------------------------------------------------

// -----   Destructor   ----------------------------------------------------
PndMCTrack::~PndMCTrack() {}
// -------------------------------------------------------------------------

// -----   Public method Print   -------------------------------------------
void PndMCTrack::Print(std::ostream& out) const
{
    out << "EventId: " << fEventId << ", mother : " << fMotherID << ", Type " << fPdgCode << ", momentum (" << fPx << "/" << fPy << "/" << fPz << ") GeV/c"
        << ", position (" << fStartX << "/" << fStartY << "/" << fStartZ << "/" << fStartT << ") cm,s" << endl;
}
// -------------------------------------------------------------------------

