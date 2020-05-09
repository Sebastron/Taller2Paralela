#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include "db.h"

using namespace std;
/*
struct promedio{
    std::string rut;
    float ranking;
    float nem;
    float matematica;
    float lenguaje;
    float ciencias;
    float historia;

};
*/
void integrantes(){
    char a = 160;
    std::cout << std::endl << "Integrantes:" << std::endl;
    std::cout << "Sebasti"<<a<<"n Garrido Valenzuela" << std::endl;
    std::cout << "Ramiro Uribe Garrido" << std::endl;
    std::cout << "Javier G"<<a<<"lvez González" << std::endl;
}   

int aleatoreo(int inferior, int superior){
    return (rand() % (superior - (inferior + 1))) +inferior;
}

/*float fpromedio(float nem, float ranking, float matematica, float lenguaje, float ciencia, float historia){
    return (nem + ranking + matematica + lenguaje + historia + ciencia)/6;
}
*/

void main_profe() {
    srand((unsigned int) time(0));
    PGconn* conexion = dbconnect((char *)DBSERVER,DBPUERTO,(char *)DBNAME,(char *)DBUSER,(char *)DBPASSWORD);
    for (unsigned long rut = 14916641; rut <= 19932391; rut++) {
        int nem = aleatoreo(475, 750);
        int ranking = aleatoreo(475, 750);
        int matematica = aleatoreo(475, 750);
        int lenguaje = aleatoreo(475, 750);
        int ciencias = aleatoreo(475, 750);
        int historia = aleatoreo(475, 750);
        std::string linea;
        linea = "INSERT INTO puntajes (rut, nem, ranking, matematica, lenguaje, ciencias, historia) VALUES ('" + to_string(rut) + "','" + to_string(nem) + "','" + to_string(ranking) + "','" + to_string(matematica)+ "','" + to_string(lenguaje) + "','" + to_string(ciencias) + "','" + to_string(historia) + "');";
        PGresult* resultado = dbquery(conexion, (char *)linea.c_str());
        dbfree(resultado);
    }
    dbclose(conexion);
    std::cout << std::endl << "Archivo puntajes.csv creado" << std::endl;
}

void generarprom(){
    std::cout << "Generando archivo prompuntajes2.csv" << std::endl;
    std::ofstream archivoSalida("prompuntajes2.csv");
    PGconn* conexion = dbconnect((char *)DBSERVER,(int)DBPUERTO,(char *)DBNAME,(char *)DBUSER,(char *)DBPASSWORD);
    std::string lin = "SELECT rut, round((nem+ranking+matematica+lenguaje+ciencias+historia)/6) FROM puntajes;";
    PGresult* resultado = dbquery(conexion, (char *)lin.c_str());
    long filas = dbnumrows(resultado);
    for(int i=0; i<filas; i++){
        std::string rut = dbresult(resultado,i,0);
        std::string prom = dbresult(resultado,i,1);
        std::string line = rut + ";" + prom;
        archivoSalida << line << std::endl;  
    } 
    archivoSalida.close();
    std::cout << std::endl << "Archivo prompuntajes2.csv creado" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "Taller 2: BD Postgresql en C/C++" << std::endl;
    generarprom();
    integrantes();
    return EXIT_SUCCESS;
    
}