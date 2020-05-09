/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   db.h
 * Author: sebastiangarridov
 *
 * Created on 8 de mayo de 2020, 0:32
 */

#ifndef DB_H
#define DB_H

#ifdef __cplusplus
extern "C" {
#endif
/**
 * Abre la conexion de la base de datos
 * @param servidor ip del servidor postgresql
 * @param puerto puerto del servidor postgresql
 * @param nombredb nombre de la base de datos
 * @param usuario usuario a conectar
 * @param password contraseña del usuario
 * @return  objeto conexion
 */
#define DBSERVER "192.168.1.98" //No olvidar cambiar su ip del postgresql
#define DBPUERTO 5432
#define DBNAME "psudb"
#define DBUSER "psu"
#define DBPASSWORD "sebastian1996" //No olvidar cambiar la contraseña

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <postgresql/libpq-fe.h>
    
    PGconn* dbconnect(char* servidor, int puerto, char* nombredb, char* usuario, char* password);
    /**
     * 
     * @param conexion Puntero a la conexion 
     */
    
    void dbclose(PGconn* conexion);
    
    /**
     * Consulta en la base de datos
     * @param conexion conexion abierta al motor
     * @param consulta Consulta sql
     * @return el resultado de la consulta
     */
    PGresult* dbquery(PGconn* conexion, char* consulta);
    
    /**
     * 
     * @param resultado Estructura con el resultado
     * @return la cantidad de filas del dicho resultado
     */
    long dbnumrows(PGresult* resultado);
    
    /**
     * 
     * @param resultado Estructura del resultado
     * @param fila Fila a consultar
     * @param columna Columna a obtener
     * @return EL valor correspondiente a fila/columna sobre el set de resultado
     */
    char* dbresult(PGresult* resultado, int fila, int columna);
    /**
     * Liberar recursos
     * @param resultado Estructura con el resultado
     */
    void dbfree(PGresult *resultado);
#ifdef __cplusplus
}
#endif

#endif /* DB_H */

