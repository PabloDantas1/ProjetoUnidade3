#include "cutellipsoid.h"
#include "sculptor.h"
#include "figurageometrica.h"
#include <cmath>
#include <iostream>

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->rx=rx;
    this->ry=ry;
    this->rz=rz;
}

CutEllipsoid::~CutEllipsoid(){

}

void CutEllipsoid::draw(Sculptor &s){

    for(int i=(xcenter-rx); i<=(xcenter+rx); i++){
        for(int j=(ycenter-ry); j<=(ycenter+ry); j++){
            for(int k=(zcenter-rz); k<=(zcenter+rz); k++){
                if(pow(float(i-xcenter)/float(xcenter),2) + pow(float(j-ycenter)/float(ry),2) + pow(float(k-zcenter)/float(rz),2) <= 1){
                    s.cutVoxel(i,j,k);
                }
            }
        }
    }
}
