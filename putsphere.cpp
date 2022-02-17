#include "putsphere.h"
#include "sculptor.h"
#include <cmath>
#include <iostream>
#include "figurageometrica.h"

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float alpha){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->radius=radius;
    this->r=r;
    this->g=g;
    this->b=b;
    this->alpha=alpha;
}

PutSphere::~PutSphere(){

}

void PutSphere::draw(Sculptor &s){

    s.setColor(r, g, b, alpha);
    for ( int i = 0 ; i <(2*xcenter); i ++)
    {
        for ( int j = 0 ; j < (2*ycenter); j ++)
        {
            for ( int k = 0 ; k < (2*zcenter); k ++)
            {
                if (((i-xcenter) * (i-xcenter) + (j-ycenter) * (j-ycenter) + (k-zcenter) * (k-zcenter)) <= (radius*radius))
                {
                   s.putVoxel(i,j,k);
                }
            }
        }
    }
}
