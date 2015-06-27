#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "funciones.h"
#include "funciones2.h"
#include "lib2.h"


/**************************************************DESARROLLO DE FUNCIONES DE INGRESOS DE DATOS POR PANTALLA**************************************************/





 /*pide un entero por pantalla
 *recibe una cadena que es el dato que se mostrara en pantalle para recibir el valor
 *retorna el numero ingresado.
 */
int pedir_entero(char mensaje[])
{
    long int numero;
    
    printf("ingrese %s \n", mensaje);
    fflush(stdin);
    scanf("%d", &numero);
    system("cls");
    return numero;
    
    
    
}


/*Muestra un mensaje por pantalla ,luego espera recibir un caracter,valida que ese caracter sea 
/*"s" o "n",Retorna el caracter validado.
*/
char preguntar_y_validar(char preg[])
{
     char resp;
     int a=0;
     
     do
     {
         if(a)
              printf("ERROR,conteste con \"S\" para indicar si y con \"N\" para indicar no\nIntente nuevamente\n");
     
          printf("%s\?\n",preg);
          fflush(stdin);
          scanf("%c", &resp);
          system("cls");
          
          a=1;
          resp=tolower(resp);
     
     }
     while(resp!='s'&&resp!='n');
     
     
     return resp;
     
     
     

}


int pedir_y_validar_entero(char mensaje[],int max,int min)
{
    int aux;
    int a=0;
    
    
    do
    {
        if(a)
             printf("Error,ingrese nuevamente\n");
             
             
        aux=pedir_entero(mensaje);
        
        
        a=1;
        
        
        
    }
    while(aux<min ||aux>max);
    
    return aux;
    

    
    
    
    
}

//muestra un menu de opciones para ingresar elementos.
void mostrar_menu_ingresar()
{
     printf("\tMENU INGRESAR:\n\n\n");
     printf("\t1_INGRESAR UN NUMERO ENTERO\n");
     printf("\t2_INGRESAR UNA PALABRA\n");
     printf("\t3_INGRESAR UNA LETRA\n");
     printf("\t4_INGRESAR UN NUMERO DECIMAL\n");
     printf("\t5_VOLVER AL MENU\n\n\n");
     
     
     
     printf("Elija una opcion segun lo que desee ingresar\n");
     
     
     
     
}


//muestra el menu ingresar y recibe un numero perteneciente a una de las opciones del menu.
//valida que el numero ingresado pertenezca a una de las opciones y retorna ese numero ya validado.

int mostrar_y_validar_menu_ingresar()
{
    int a=0;
    int num;
    
    do
    {
        
        
        if(a)
             printf("ERROR, ingrese un valor pertenenciente  a las opciones del menu ingresar\n");
             
             
        mostrar_menu_ingresar();
        fflush(stdin);
        scanf("%d", &num);
        system("cls");
        
        a=1;
    }
    while(num>5||num<1);
    
    return num;
    
    
    
    
    
    
    
}



/*
/*pide y recibe un numero de tipo float por pantalla.
/*La cadena de caracteres recibida como parametro se mostrara en pantalla para indicar al ususario que valor debera ingresar
*/
float pedir_flotante(char mensaje[])
{
      float num;
      
      printf("Ingrese %s\n", mensaje);
      fflush(stdin);
      scanf("%f", &num);
      system("cls");
      
      return num;
      
      
      
      
}

//pide un caracter por pantalla, retorna el caracter ingresado.
char pedir_char(char mensaje[])
{
     char element;
     
     printf("ingrese %s\n", mensaje);
     fflush(stdin);
     scanf("%c", &element);
     system("cls");
     
     return element;
     
     
     
     
}





/* recibe el ingreso de una cadena por consola
/*El primer parametro que recibe es para mostrar un mensaje en pantalla en funcion del dato que se quiere obtener.
/*El segundo es donde se va a almacenar la cadena recibida.
*/

void pedir_cadena(char mensaje[],char vector[])
{
     
     
     printf("Ingrese %s\n", mensaje);
     fflush(stdin);
     scanf("%s",vector);
     system("cls");
     
     
     
     
}


/*recibe el ingreseo de una cadena por consola
/*valida que la cantidad de caracteres ingresados no supere el limite para el dato
/*el primero char que recibe es para el mensaje que se mostrara en pantalla el segundo para almacenar la cadena recibida
/*y el entero es el limite maximo de carateres.
*/
void pedir_y_validar_cadena(char mensaje[],char vector[],int max)
{
     char a=0;
     char aux[500];
     
     do
     {
          if(a)
          {     
                printf("Se excedio el maximo de caracteres a ingresar \nIntente nuevamente\n");
               
          }
          pedir_cadena(mensaje,aux);
          a=1;
          
          
          
     }
     while(strlen(aux)>max||strlen(aux)<1);
     
     strcpy(vector,aux);
     
     
}
