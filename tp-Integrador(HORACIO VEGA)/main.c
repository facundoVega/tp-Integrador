#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "funciones.h"
#include "funciones2.h"
#include "lib2.h"



int main(int argc, char *argv[])
{
    ArrayList* pList;
    int opcion;
    int* aux;
    


    pList=newArrayList();
    
    while(opcion!=20)
    {
                    
                    opcion=mostrar_y_validar_menu();
                    
                    switch(opcion)
                    {
                                  case 1:
                                       ingresar(pList,aux);//implementacion funcion "add"
                                       break;
                                  
                                  
                                  case 2:
                                       mostrar(pList);//implementacion funcion "get"
                                       break;
                                  
                                  case 3:
                                       insertar(pList);//implementacion funcion "set"
                                       break;
                                      
                                    
                                  case 4:
                                       desplazar_e_ingresar(pList);//implementacion funcion "push"
                                       break;
                                       
                                  case 5:
                                       eliminar(pList);//implementacion funcion "remov"
                                       break;
                                  
                                  case 6:
                                       consultar_tamanio(pList);//Implementacion funcion "size".
                                       break;
                                       
                                  case 7:
                                       borrar_todo(pList);//Implementacion funcion "clear"
                                       break;
                                       
                                  case 8:
                                       clonar_y_mostrar_clon(pList); //Implementacion funcion "clone"
                                       break;   
                                       
                                  case 9:
                                       hay_elementos(pList);//Implementacion funcion "isEmpty".
                                       break;         
                                       
                                       
                                  case 10:
                                       consultar_indice_primer_elemento(pList);//Implementacion funcion "indexOf"
                                       break; 
                                       
                                  case 11:
                                       consultar_contenido(pList);//Implementacion funcion "contains".
                                       break;
                                       
                                       
                                  case 12:
                                       recuperar_elemento_y_borrar(pList);//Implementacion funcion "pop".
                                       break;
                                       
                                  case 13:
                                       crear_y_mostrar_sublista(pList);//Implementacion funcion "subList".
                                       break;
                                       
                                       
                                  case 14:
                                       consultar_existe_elementos(pList);//Implementecacion funcion "containsAll".
                                       break;
                                       
                                  case 15:
                                       verificar_contenido(pList);//Implementacion funcion "containsByValue"
                                       break;
                                       
                                  case 16:
                                       consultar_indice2(pList);//Implementacion funcion "indexByValue".
                                       break;
                                       
                                  case 17:
                                       eliminar2(pList);//Implementacion funcion "removeByValue".
                                       break;
                                       
                                  case 18:
                                       contador_elemento(pList);//implementacion funcion "count".
                                       break;
                                       
                                       
                                       
                                  case 19:
                                       clonarYArchivar(pList);//funcion donde se interactua con un archivo.
                                       break;
                    }
                    
                    
                    
    }
  
  
  //system("PAUSE");	
  return 0;
}
