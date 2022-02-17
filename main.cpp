#include <iostream>
#include <vector>
#include "sculptor.h"
#include "figurageometrica.h"
#include "putbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "putvoxel.h"
#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"
#include "cutvoxel.h"
#include "interpretador.h"

using namespace std;

int main(){

    Sculptor *s1;

    Interpretador parser;
    vector<FiguraGeometrica*> figs;

    figs = parser.parse((char*)"ler.txt");

    s1 = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

    for(size_t i=0; i<figs.size(); i++){
        figs[i]->draw(*s1);
    }

    s1->writeOFF((char*)"saida.off");

    for(size_t i=0; i<figs.size(); i++){
        delete figs[i];
    }
    delete s1;
    cout<< "Deu certo" <<endl;
    return 0;
}
