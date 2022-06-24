#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Sculptor.h"
#include "Interpretador.h"


int main(){
    Sculptor *coin;
    Interpretador translator;
    std::vector<FiguraGeometrica*> figuras;

    figuras = translator.parse("sculptor.txt");

    coin = new Sculptor(translator.getDx(), translator.getDy(), translator.getDz());

    for(size_t i = 0; i < figuras.size(); i++){
        figuras[i] -> draw(*coin);
    }

    coin -> writeOFF((char*)"coin.off");

    for(size_t i = 0; i < figuras.size(); i++){
        delete figuras[i];
    }

    delete coin;
    return 0;

}
