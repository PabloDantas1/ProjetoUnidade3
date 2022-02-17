#include "cutsphere.h"
#include <cmath>
#include "sculptor.h"
#include "figurageometrica.h"
#include <iostream>

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius){

    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->radius=radius;
}

CutSphere::~CutSphere(){

}

void CutSphere::draw(Sculptor &s){

    for ( int i = 0 ; i <(2*xcenter); i ++)
    {
        for ( int j = 0 ; j < (2*ycenter); j ++)
        {
            for ( int k = 0 ; k < (2*zcenter); k ++)
            {
                if (((i-xcenter) * (i-xcenter) + (j-ycenter) * (j-ycenter) + (k-zcenter) * (k-zcenter)) <= (radius*radius))
                {
                   s.cutVoxel(i,j,k);
                }
            }
        }
    }
}
