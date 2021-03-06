#include "sculptor.h"
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel **[nx];
    for(int i=0; i<nx; i++){
        v[i] = new Voxel *[ny];
        for(int j=0; j<ny; j++){
            v[i][j] = new Voxel [nz];
            for(int k=0; k<nz; k++){
                v[i][j][k].isOn = false;
            }
        }
    }

}

Sculptor::~Sculptor(){
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            delete [] v[i][j];
        }
    }
    for(int i=0; i<nx; i++){
        delete [] v[i];
    }
    delete [] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha){
    this->r = r;
    this->g = g;
    this->b = b;
    this->alpha = alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].alpha = alpha;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::writeOFF(char *filename){

    limpaVoxels();
    int Qvoxels = 0;

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].isOn == true){
                    Qvoxels++;
                }
            }
        }
    }

    ofstream arq;
    arq.open(filename);
    if(!arq.is_open()){
        cout << "fail" << endl;
        exit(0);
    }

    arq << "OFF"<<endl;
    arq << 8*Qvoxels << " " << 6*Qvoxels << " 0 "<< endl;

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].isOn == true){
                    arq << i-0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                    arq << i-0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                    arq << i+0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                    arq << i+0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                    arq << i-0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                    arq << i-0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                    arq << i+0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                    arq << i+0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                }
            }
        }
    }

    Qvoxels = 0;

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].isOn == true){

                    arq << "4 " <<
                           8*Qvoxels << " " << 3 + 8*Qvoxels << " " << 2 + 8*Qvoxels
                    << " " << 1 + 8*Qvoxels << " " << v[i][j][k].r << " " << v[i][j][k].g << " " <<
                    v[i][j][k].b << " " << v[i][j][k].alpha << endl;

                    arq << "4 " << 4 + 8*Qvoxels << " " << 5 + 8*Qvoxels << " " << 6 + 8*Qvoxels
                    << " " << 7 + 8*Qvoxels << " " << v[i][j][k].r << " " << v[i][j][k].g << " " <<
                    v[i][j][k].b << " " << v[i][j][k].alpha << endl;

                    arq << "4 " << 8*Qvoxels << " " << 1 + 8*Qvoxels << " " << 5 + 8*Qvoxels
                    << " " << 4 + 8*Qvoxels << " " << v[i][j][k].r << " " << v[i][j][k].g << " " <<
                    v[i][j][k].b << " " << v[i][j][k].alpha << endl;

                    arq << "4 " << 8*Qvoxels << " " << 4 + 8*Qvoxels << " " << 7 + 8*Qvoxels
                    << " " << 3 + 8*Qvoxels << " " << v[i][j][k].r << " " << v[i][j][k].g << " " <<
                    v[i][j][k].b << " " << v[i][j][k].alpha << endl;

                    arq << "4 " << 3 + 8*Qvoxels << " " << 7 + 8*Qvoxels << " " << 6 + 8*Qvoxels
                    << " " << 2 + 8*Qvoxels << " " << v[i][j][k].r << " " << v[i][j][k].g << " " <<
                    v[i][j][k].b << " " << v[i][j][k].alpha << endl;

                    arq << "4 " << 1 + 8*Qvoxels << " " << 2 + 8*Qvoxels << " " << 6 + 8*Qvoxels
                    << " " << 5 + 8*Qvoxels << " " << v[i][j][k].r << " " << v[i][j][k].g << " " <<
                    v[i][j][k].b << " " << v[i][j][k].alpha << endl;

                    Qvoxels++;
                }
            }
        }
    }

    arq.close();
}
