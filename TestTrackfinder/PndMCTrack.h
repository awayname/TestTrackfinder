
#ifndef PNDMCTRACK_H
#define PNDMCTRACK_H 1

#include <iostream>
#include <math.h>

class PndMCTrack {

public:
    /**  Default constructor  **/
    PndMCTrack();

    /**  Standard constructor  **/
    ////  not used!!
    //  PndMCTrack(Int_t pdgCode, Int_t motherID, TVector3 startVvertex,
    //	     double startTime, TLorentzVector momentum, Int_t  nPoint=0);

    /**  Copy constructor  **/
    PndMCTrack(const PndMCTrack& track);

    /**  Destructor  **/
    virtual ~PndMCTrack();

    /**  Output to screen  **/
    void Print(std::ostream& out = std::cout) const;

    friend std::ostream& operator<<(std::ostream& out, PndMCTrack& track)
    {
        track.Print();
        return out;
    }

    /**  Accessors  **/
    int GetEventId() const { return fEventId; }
    int GetPdgCode() const { return fPdgCode; }
    int GetMotherID() const { return fMotherID; }
    double GetStartVertexX() const { return fStartX; }
    double GetStartVertexY() const { return fStartY; }
    double GetStartVertexZ() const { return fStartZ; }
    double GetStartTime() const { return fStartT; }
    double GetMomentumX() const { return fPx; }
    double GetMomentumY() const { return fPy; }
    double GetMomentumZ() const { return fPz; }
    double GetPt() const { return sqrt(fPx * fPx + fPy * fPy); }
    /*
    int GetStsPoints()  const { return   (fPoints &  15        )        ; }
    */

    void SetMotherID(int id) { fMotherID = id; }
    /*
    void SetStsPoints(Int_t np);
    */

private:
    int fEventId;
    /**  PDG particle code  **/
    int fPdgCode;

    /** Momentum components at production [GeV]  **/
    double fPx, fPy, fPz;

    /**  Index of mother track. Zero( Minus One???) for primary particles.  **/
    int fMotherID;


    /** Coordinates of start vertex [cm, ns]  **/
    double fStartX, fStartY, fStartZ, fStartT;

    friend std::istream& operator>>(std::istream& os, PndMCTrack& hit) {
        int nNeighbors = -1;
        os >> hit.fEventId;
        os.get();
        os >> hit.fPdgCode;
        os.get();
        os >> hit.fMotherID;
        os.get();
        os >> hit.fStartX;
        os.get();
        os >> hit.fStartY;
        os.get();
        os >> hit.fStartZ;
        os.get();
        os >> hit.fStartT;
        os.get();
        os >> hit.fPx;
        os.get();
        os >> hit.fPy;
        os.get();
        os >> hit.fPz;

        return os;
    }

    /**  Bitvector representing the number of MCPoints for this track in
     **  each subdetector. The detectors are represented by
     **  This goes to fPoints:
     **  DRC:  Bit  0 -  1  (2 bit max. value 3)
     **  MDT:  Bit  2 -  3  (2 bit max. value 3)
     **  MVD:  Bit  4 -  5  (2 bit max. value 3)
     **  DCH:  Bit  6 -  7  (2 bit max. value 3)
     **  EMC:  Bit  8 -  9  (2 bit max. value 3)
     **  STT:  Bit 10 - 11  (2 bit max. value 3)
     **  TPC:  Bit 12 - 13  (2 bit max. value 3)
     **  TOF:  Bit 14 - 15  (2 bit max. value 3)
     **  GEM:  Bit 16 - 17  (2 bit max. value 3)
     **  DSK:  Bit 18 - 19  (2 bit max. value 3)
     **  HYP:  Bit 20 - 21  (2 bit max. value 3)
     **  RPC:  Bit 22 - 23  (2 bit max. value 3)
     **  LUMI: Bit 24 - 25  (2 bit max. value 3)
     **  HYPG: Bit 26 - 27  (2 bit max. value 3)
     **  FTS:  Bit 28 - 29  (2 bit max. value 3)

     **  The respective point numbers can be accessed and modified **/

    int fPoints;

};

#endif
