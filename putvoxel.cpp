#include "putvoxel.h"
#include "sculptor.h"
#include "figurageometrica.h"
#include <iostream>

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float alpha){

    this->x=x;
    this->y=y;
    this->z=z;
    this->r=r;
    this->g=g;
    this->b=b;
    this->alpha=alpha;
}

PutVoxel::~PutVoxel(){

}

void PutVoxel::draw(Sculptor &s){

    s.setColor(r, g, b, alpha);
    s.putVoxel(x, y, z);
}
