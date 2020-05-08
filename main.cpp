#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <sstream>
#include "db.h"

using namespace std;

struct promedio{
    std::string rut;
    float ranking;
    float nem;
    float matematica;
    float lenguaje;
    float ciencias;
    float historia;

};

void integrantes(){
    char a = 160;
    std::cout << std::endl << "Integrantes:" << std::endl;
    std::cout << "Sebasti"<<a<<"n Garrido Valenzuela" << std::endl;
    std::cout << "Ramiro Uribe Garrido" << std::endl;
    std::cout << "Javier G"<<a<<"lvez González" << std::endl;
}   

float fpromedio(float nem, float ranking, float matematica, float lenguaje, float ciencia, float historia){
    return (nem + ranking + matematica + lenguaje + historia + ciencia)/6;
}


void generarprom(){
    std::ofstream archivoSalida("prompuntajes.csv");
    promedio prueba;
    ifstream  lectura; 
    lectura.open("puntajes.csv",ios::in);
    for(std::string linea; std::getline(lectura,linea); ){
        std::stringstream registro (linea);
        std::string dato;
        for(int columna = 0; std::getline(registro, dato, ';'); columna++){
            switch (columna){
            case 0:
                prueba.rut = dato;
            case 1:
                prueba.nem = std::stof(dato);
            case 2:
                prueba.ranking = std::stof(dato);
            case 3:
                prueba.matematica =std::stof(dato);
            case 4:
                prueba.lenguaje =std::stof(dato);
            case 5:
                prueba.historia =std::stof(dato);
            case 6:
                prueba.ciencias=std::stof(dato);
            break;
            }
        }
        float prompuntaje = fpromedio(prueba.nem, prueba.ranking, prueba.matematica, prueba.lenguaje, prueba.historia, prueba.ciencias);
        std::string lin;
        lin = prueba.rut + ";" + std::to_string(prompuntaje);
        archivoSalida << lin << std::endl;   
    }
    archivoSalida.close();
    std::cout << std::endl << "Archivo prompuntajes.csv creado" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "Taller 2: BD " << std::endl;
    bool comprobacion;
    generarprom();
    integrantes();
    return EXIT_SUCCESS;
    
}