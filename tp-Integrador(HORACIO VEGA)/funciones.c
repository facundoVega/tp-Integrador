#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "funciones.h"
#include "funciones2.h"
#include "lib2.h"


/********************DESARROLLO DE LAS FUNCIONES PERTENECIENTES A CADA UNA DE LOS CASOS DEL SWITCH EN LA FUNCION MAIN***************************************/


/*muestra un menu de opciones en pantalla
*/
void mostrar_menu()
{
        
        printf("\tMENU PRINCIPAL:\n\n\n");
        printf("\t1_INGRESAR\n");
        printf("\t2_MOSTRAR\n");
        printf("\t3_INSERTAR\n");
        printf("\t4_INSERTAR Y DESPLAZAR\n");
        printf("\t5_ELIMINAR ELEMENTO\n");
        printf("\t6_CONSULTAR TAMANIO\n");
        printf("\t7_BORRAR TODO ARRAY\n");
        printf("\t8_CLONAR Y MOSTRAR CLON\n");
        printf("\t9_CONSULTAR SI HAY ELEMENTOS CARGADOS\n");
        printf("\t10_CONSULTAR INDICE PRIMERA APARICION DE ELEMENTO\n");
        printf("\t11_CONSULTAR CONTENCION DE UN ELEMENTO\n");
        printf("\t12_MOSTRAR Y BORRAR NUMERO\n");
        printf("\t13_CREAR NUEVA SUBLISTA E IMPRIMIRLA EN PANTALLA\n");
        printf("\t14_INGRESAR VALORES Y VERIFICAR SI PERTENECEN AL ARRAYLIST\n");
        printf("\t15_CONSULTAR CONTENCIONDE UN ELEMENTO 2\n");
        printf("\t16_CONSULTAR INDICE PRINERA APARICION DE UN ELEMENTO 2\n");
        printf("\t17_ELIMINAR ELEMENTO 2\n");
        printf("\t18_CONTAR ELEMENTOS\n");
        printf("\t19_CLONAR Y GUARDAR EN ARCHIVO\n");
        printf("\t20_SALIR\n\n\n\n");
        printf("Ingrese un numero segun la opcion que desea realizar\n");
        
     
     
     
}


int mostrar_y_validar_menu()
{
    int a=0;
    int opcion;
    
    do
    {
        if(a)
             printf("ERROR,el numero ingresado no pertenece a una opcion valida para el menu\nIntente nuevamente\n\n");
             

             mostrar_menu();
             fflush(stdin);
             scanf("%d", &opcion);
             system("cls");
        
             a=1;
        
    }
    while(opcion<1||opcion>20);
    
    return opcion;
    
    
    
}


void ingresar(ArrayList* self,int* aux)
{
     char resp='s';
     int a=0;
     int opcion=1;
     
     while(opcion!=5)
     {
                     opcion=mostrar_y_validar_menu_ingresar();
                     
                     switch(opcion)
                     {
                                   case 1:
                                        crearInt_y_guardar_en_array(self);
                                        break;
                                        
                                   case 2:
                                        crearString_y_guardar_en_array(self);
                                        break;
                                        
                                   case 3:
                                        crearChar_y_guardar_en_array(self);
                                        break;
                                        
                                   case 4:
                                        crearFloat_y_guardar_en_array(self);
                                        break;
                     }
                     
                     
     }

    
    
                    
                 
                                     
    
}


void mostrar(ArrayList* self)
{
     int i;
     int type;
     
     
     
     for(i=0;i<self->size;i++)
     {
     
                         type=getType(self->Get(self,i));
                         
                         switch(type)
                         {
                                     case ENTERO:
                                          printf("%d\n",*(int *)self->Get(self,i));
                                          break;
                              
                                     case FLOAT:
                                          printf("%.2f\n",*(float *)self->Get(self,i));
                                          break;
                                          
                                     case CHAR:
                                          printf("%c\n", *(char *)self->Get(self,i));
                                          break;
                                          
                                     case STRING:
                                          printf("%s\n", (char *)self->Get(self,i));
                                          break;
                              
                              
                         }     

                              

     
                               
                              
                              
                              
     }
     
     
     system("PAUSE");
     system("cls");
     
}


void insertar(ArrayList* self)
{
     
     if(self->isEmpty(self))
     {
                      
                      float* flotante;
                      char* string;                       
                      int* num;                       
                      char* caracter;
                      int opcion;
                      int indice;
     
                      opcion=pedir_y_validar_entero("ingrese que es lo que quiere ingresar  :\n1una letra\t2_un entero\t3_un decimal\t_4una palabra\n",4,1);
                      indice=pedir_y_validar_entero("ingrese indice()",self->size,1);
                      indice--;
                      
                      switch(opcion)
                      {                
                                       case 1:
                                            caracter=newChar();
                                            *caracter=pedir_char(" caracter a insertar ");
                                            self->set(self,indice,caracter);                 
                                            break;
                                            
                                       case 2:
                                            num=newInt();
                                            *num=pedir_entero("numero entero a insertar");
                                            self->set(self,indice,num);
                                            break;
                                            
                                       case 3:
                                            flotante=newFloat();
                                            *flotante=pedir_flotante("numero decimal a insertar");
                                            self->set(self,indice,flotante);
                                            break;
                                            
                                       case 4:
                                            string=newString();
                                            pedir_y_validar_cadena("cadena a insertar",string,CARACTERESCADENA-1);
                                            self->set(self,indice,string);
                                            break;
                   
                   }
                   
     }
     else
     {
         printf("no hay elementos cargados por lo que esta opcion no esta disiponible\n");
         system("PAUSE");
         system("cls");
         
         
         
     }
     
     
     
     
}


void desplazar_e_ingresar(ArrayList* self)
{
     
     if(self->isEmpty(self))
     {
           int opcion;
           int indice;
           char* caracter;
           int* num;
           float* real;
           char* string;
     
     
                   
           opcion=pedir_y_validar_entero("ingrese que es lo que quiere ingresar  :\n1una letra\t2_un entero\t3_un decimal\t_4una palabra\n",4,1);
           indice=pedir_y_validar_entero("ingrese indice",self->size,1);
           indice--;
      
                   
                                
                      switch(opcion)
                     {
                                   case 1:
                                        caracter=newChar();
                                        *caracter=pedir_char(" caracter");
                                        self->push(self,indice,caracter);
                                        break;
                                        
                                   case 2:
                                        num=newInt();
                                        *num=pedir_entero("numero entero");
                                        self->push(self,indice,num);
                                        break;
                                        
                                   case 3:
                                        real=newFloat();
                                        *real=pedir_flotante("numero real");
                                        self->push(self,indice,real);
                                        break;
                                        
                                   case 4:
                                        string=newString();
                                        pedir_y_validar_cadena("cadena",string,CARACTERESCADENA-1);
                                        self->push(self,indice,string);
                                        break;
                     }
      }
      else
      {
          
                   printf("no hay elementos cargados por lo que esta opcion no esta disiponible\n");
                   system("PAUSE");
                   system("cls");
         
          
          
          
      }        
                   
                   
     
      



     
     
}
void eliminar(ArrayList* self)
{
     
     if(self->isEmpty(self))
     {
                            int indice;
     
                            indice=pedir_y_validar_entero("ingrese indice",self->size,1);
     
                            indice--;
                            remov(self,indice);
     
     }
     else
     {
         
                            printf("no hay elementos cargados por lo que esta opcion no esta disiponible\n");
                            system("PAUSE");
                            system("cls");
         
          
          
         
     }
     
     
     
}

void consultar_tamanio(ArrayList* self)
{
     printf("EL TAMAÑO DE LA LISTA ES: %d\n\n", self->Size(self));
     system("PAUSE");
     system("cls");
     
     
     
}



void borrar_todo(ArrayList* self)
{
     
          
     if(self->isEmpty(self))
     {
                            self->clear(self);
     
     }
     else
     {
         
              printf("No hay elemeentos en la lista que borrar\n");
              system("PAUSE");
              system("cls");
         
         
     }
     
     
     
     
}



ArrayList* clonar_y_mostrar_clon(ArrayList* self)
{
         
                   
     if(self->isEmpty(self))
     {
        struct  ArrayList* cloneList;                        
         int i;
         cloneList=self->clone(self);  
         
          mostrar(cloneList);
          free(cloneList);
              
     }
     else
     {
         
                       printf("No hay elemeentos en la lista que borrar\n");
                       system("PAUSE");
                       system("cls");
         
         
     }              

                     
                            
                            
}


void hay_elementos(ArrayList * self)
{
    if(self->isEmpty(self))
    {
                printf("El arrayList contiene elementos\n");
                system("PAUSE");
                system("cls");           
                           
                           
    }
    else
    {
        printf("El arrayList no tiene elementos cargados\n ");
        system("PAUSE");
        system("cls");
        
        
        
    }
    
    
    
    
    
}


void consultar_indice_primer_elemento(ArrayList* self)
{
     printf("funcion no disponible\n");
     system("PAUSE");
     system("cls");
  /*   
     int opcion;
     int pos;
     int* num;
     char* caracter;
     char* string;
     float* flotante;
      
      opcion=pedir_y_validar_entero("ingrese que es lo que quiere ingresar  :\n1una letra\t2_un entero\t3_un decimal\t_4una palabra\n",4,1);
     
     
      switch(opcion)
      {
                                  
                                   case 1:
                                        caracter=newChar();
                                        *caracter=pedir_char(" caracter");
                                        
                                        break;
                                        
                                   case 2:
                                        num=newInt();
                                        *num=pedir_entero("numero entero");
                                        self->push(self,indice,num);
                                        break;
                                        
                                   case 3:
                                        real=newFloat();
                                        *real=pedir_flotante("numero real");
                                        self->push(self,indice,real);
                                        break;
                                        
                                   case 4:
                                        string=newString();
                                        pedir_y_validar_cadena("cadena",string,CARACTERESCADENA-1);
                                        self->push(self,indice,string);
                                        break;       
                    
                    
      }
     /*
     //pido un numero para verificar en que posicion se encuentra del arrayList.
     num=pedir_entero("Ingrese un numero para verificar en que indice del arrayList aparcece por vez primera\n");
     
     //comparo el valor del numero ingresado por cada uno  de los valores de los elemenstos del arraylist mediante una funcion.
     pos=comparar_valor(num,self);
     
     if(pos==-1)
     {
                printf("El numero ingresado no forma parte del arrayList\n");
                system("PAUSE");
                system("cls");
                
                
                
     }
     else
     {
         
         printf("El indice de la primera aparicion del elemento en el arrayList es:%d\n\n", self->indexOf(self,self->pElements[pos])+1);
         
         
         
         
     }
     
     
     
     */
     
}



/*Funcion que compara un numero con los valores de cada uno de los elementos del arrayList.
/*Antes de comparar a los elementos del arrayList se le aplica una conversion forzada de tipos a "int"
/*retorna la posicion donde se da la igualdad entre los elementos.
*/
int comparar_valor(int num,ArrayList* self)
{
     int i;
     
     for(i=0;i<self->size;i++)
     {
                           if(self->pElements[i]!=NULL)
                           {   
                              if(*(int *)self->pElements[i]==num)
                              {
                                       return i;
                                       
                                       
                                       
                              }
                           }  
                              
     }
     
     return -1;
     
     
     
     
}


void consultar_contenido(ArrayList* self)
{
     
     
     if(self->isEmpty(self))
     {
                            int num;
                            int pos;
     
                            num=pedir_entero("Ingrese numero para verificar si pertenece al ArrayList");
                            pos=comparar_valor(num,self);
          
                            if(pos==-1)
                            {
                                       if(self->contains(self,&num)==0)
                                       {
                                                printf("El numero ingresado no pertenece al ArrayList\n");
                                                system("PAUSE");
                                                system("cls");
                                                
                                       }
                
                
                
                           }     
                           else
                           {
         
                               if(self->contains(self,self->pElements[pos]))
                               {
                                                      printf("El numero ingresado esta contenido en el ArrayList\n");
                                                      system("PAUSE");
                                                      system("cls");
                                                      
                                                      
                               }
         
                             }
         
         
         
     }
     else
     {
                               printf("no hay elementos cargados por lo que esta opcion no esta disiponible\n");
                               system("PAUSE");
                               system("cls");
         
          
         
         
         
     }
     
     
     
     
     
}



void recuperar_elemento_y_borrar(ArrayList* self)
{
     if(self->isEmpty(self))
     {
                            int indice;
                            int *pType;
                            int type;
                            
                            indice=pedir_y_validar_entero("indice del elemento a borrar", self->size,1);
                            indice--;
     
                            pType= self->pop(self,indice);
                            
                            //obtengo de que tipo es el puntero eliminado.
                            type=getType(pType);
                            
                            switch(type)
                            {
                                        case ENTERO:
                                             printf("El valor eliminado de la lista fue: %d\n\n\n", *(int *)pType);
                                             break;
                                        
                                        case FLOAT:
                                             printf("El valor eliminado de la lista fue: %.2f\n\n\n", *(float *)pType);
                                             break;
                                             
                                        case CHAR:
                                             printf("El valor eliminado de la lista fue: %.c\n\n\n", *(char *)pType);
                                             break;
                                        
                                        case STRING:
                                             printf("El valor eliminado de la lista fue: %s\n\n\n", (char *)pType);
                                             break;
                            }
                            
     
                            system("PAUSE");
                            system("cls");
     }
     else
     {
         
                  
                            printf("no hay elementos cargados por lo que esta opcion no esta disiponible\n");
                            system("PAUSE");
                            system("cls");
         
         
         
     }     
}



void crear_y_mostrar_sublista(ArrayList* self)
{
     if(self->isEmpty(self))
     {
     
                            int from,to;
                            ArrayList* pList;
     
                            from=pedir_y_validar_entero("indice desde donde quiere empezar a copiar el ArrayList",self->size,1);
                            to=pedir_y_validar_entero("indice hasta donde quiere copiar el ArrayList",self->size,1);
     
                            from--;
                            to--;
     
                            pList=self->subList(self,from,to);
     
     
     
                            mostrar(pList);
     
     }
     else
     {
         
                            printf("no hay elementos cargados por lo que esta opcion no esta disiponible\n");
                            system("PAUSE");
                            system("cls");
         
     }
     
     
     
}


//El desarrollo de esta funcion esta especialmente manipulado para poder hacer uso de la funcion containsall. 
void consultar_existe_elementos(ArrayList* self)
{
     if(self->isEmpty(self))
     {
          int i=0;
          int pos;
          int auxNum;
          ArrayList* pList;
          char resp='s';
     
          pList=newArrayList();
     
          while(resp=='s'&&i!=self->size)
          {
                     auxNum=pedir_entero("numero para verificar si se encuntra en el ArrayList");
                     
                     
                     //recupero la posicion en donde se da la igualdad entre el numero ingresado y el valor de un elemento del arraylist.
                     pos=comparar_valor(auxNum,self);
                     
                     //El elemento que pertenece a la posicion obtenida en la linea anterior sera adherido a pList para luego comparar punteros con punteros.
                     pList->add(pList,self->pElements[pos]);
                     
                     
                     resp=preguntar_y_validar("desea ingresar otro numero");
                     
                     i++;
                     
                     if(i==self->size)
                     {
                                      printf("la cantidad de valores ingresados es igual a la cantidad de valores\n contenidos en el arrayList Por lo tanto no va a poder ingresar mas valores\n\n\n");
                                      
                                      
                                      
                     }
                     
          }
     
     
     
          if(self->containsAll(self,pList))
          {
                                      printf("Los elementos anteriormente ingresados pertenecen al ArrayList\n");
                                      system("PAUSE");
                                      system("cls");
                                      
                                      
                                      
          }
          else
          {
                                               printf("Los elementos anteriormente ingresados NO pertenecen al ArrayList\n");
                                               system("PAUSE");
                                               system("cls");
         
         
         }
     }
     else
     {
         
                            printf("no hay elementos cargados por lo que esta opcion no esta disiponible\n");
                            system("PAUSE");
                            system("cls");
         
         
     }
     
     
     
     
     
}



void verificar_contenido(ArrayList* self)
{
     
     
     if(self->isEmpty(self))
     {
                            
                            int* num;
                            float* f;
                            int opcion;
                            char* letra;
                            char* cadena;
     
                            opcion=pedir_y_validar_entero("ingrese que es lo que quiere verificar si hay :\n1una letra\t2_un entero\t3_un decimal\t_4una palabra\n",4,1);
     
     
     
                            switch(opcion)
                            {
                                          case 1:
               
                                          letra=newChar(); 
                                          *letra=pedir_char("caracter");        
                                          if(self->containsByValue(self, letra))
                                          {
                                                                         printf("lo contiene\n");
                              
                              
                                          }
                                          else
                                              printf("no lo contiene\n");
                                          break;
               
                                          case 2:
                                               num=newInt();
                                               *num=pedir_entero("numero");
               
                                               if(self->containsByValue(self, num))
                                               {
                                                                              printf("lo contiene\n");
                              
                              
                                                }
                                                else
                                                printf("no lo contiene\n");
                                                break;
               
                                                case 3:
                                                     f=newFloat();
                                                     *f=pedir_flotante("decimal");
                                                     if(self->containsByValue(self, f))
                                                     {
                                                          printf("lo contiene\n");
                              
                              
                                                      }
                                                      else
                                                          printf("no lo contiene\n");
                                                      break;
               
               
               
                                             case 4:
                                                  cadena=newString();
                                                  pedir_y_validar_cadena("palabra a verificar",cadena,CARACTERESCADENA-1);
               
                                                  if(self->containsByValue(self,cadena))
                                                  {
                                                     printf("lo contiene\n");
                                                     
                                                     
                                                  }
                                                  else
                                                  {
                                                      printf("no lo contiene\n");
                   
                   
                                                  }
                                                  break;
                               }
         
         
         
                               system("PAUSE");
                               system("cls");
      }
      else
      {
          
                            printf("no hay elementos cargados por lo que esta opcion no esta disiponible\n");
                            system("PAUSE");
                            system("cls");
          
      }
}


void consultar_indice2(ArrayList* self)
{
     
     if(self->isEmpty(self))
     {
                            int opcion;
                            char* caracter;
                            int* num;
                            float* flotante;
                            char* string;
                            int index;
     
     
                            opcion=pedir_y_validar_entero("ingrese que es lo que quiere verificar su indice :\n1una letra\t2_un entero\t3_un decimal\t_4una palabra\n",4,1);
     
     
                            switch(opcion)
                            {
                                          case 1:
                                               caracter=newChar();
                                               *caracter= pedir_char("caracter a verificar posicion");
                                               index=self->indexByValue(self,caracter);
                                               if(index!=-1)
                                               {
                                                            printf("EL INDICE DE LA PRIMERA APARICION DEL ELEMENTO ES:  %d\n", index);
                                     
                                     
                                                }
                                                else
                                                {
                                                    printf("ELEMENTO NO CONTENIDO EN ARRAYLIST\n");
                            
                                                 }
                                                 break;
                        
                                                 case 2:
                                                      num=newInt();
                                                      *num=pedir_entero("numero a consultar posicion");
                                                      index=self->indexByValue(self,num);
                                                      if(index!=-1)
                                                      {
                                                                   printf("EL INDICE DE LA PRIMERA APARICION DEL ELEMENTO ES:  %d\n", index);
                                     
                                     
                                                       }
                                                       else
                                                       {
                                                           printf("ELEMENTO NO CONTENIDO EN ARRAYLIST\n");
                            
                                                        }
                                                        break;
                        
                                                        case 3:
                                                        flotante=newFloat();
                                                        *flotante=pedir_flotante("numero real a consultar posicion");
                                                        index=self->indexByValue(self,flotante);
                                                        if(index!=-1)
                                                        {
                                                                     printf("EL INDICE DE LA PRIMERA APARICION DEL ELEMENTO ES:  %d\n", index);
                                     
                                     
                                                         }
                                                         else
                                                         {
                                                             printf("ELEMENTO NO CONTENIDO EN ARRAYLIST\n");
                            
                                                          }
                                                          break;
                        
                                                          case 4:
                                                          string=newString();
                                                          pedir_y_validar_cadena("palabra a consultar posicion",string,CARACTERESCADENA-1);
                                                          index=self->indexByValue(self,string);
                                                          if(index!=-1)
                                                          {
                                                                       printf("EL INDICE DE LA PRIMERA APARICION DEL ELEMENTO ES:  %d\n", index);
                                     
                                     
                                                           }
                                                           else
                                                           {
                                                               printf("ELEMENTO NO CONTENIDO EN ARRAYLIST\n");
                            
                                                            }
                        
                                                            break;
                             
                   
                   
                   
                             }
                              system("PAUSE");
                              system("cls");
                              
                             
     }
     else
     {
                             printf("no hay elementos cargados por lo que esta opcion no esta disiponible\n");
                            system("PAUSE");
                            system("cls");
                       
                       
     }
     
     
     
     
}

void eliminar2(ArrayList* self)
{
     if(self->isEmpty(self))
     {
     
                            int type;
                            int opcion;
                            int* num;
                            float* flotante;
                            char* caracter;
                            char* string;
     
                            opcion=pedir_y_validar_entero("ingrese que es lo que quiere borrar  :\n1una letra\t2_un entero\t3_un decimal\t_4una palabra\n",4,1);
     
                            switch(opcion)
                            {
                                          case 1:
                                               caracter=newChar();
                                               *caracter=pedir_char("caracter a borrar");
                                               self->removeByValue(self, caracter);
                                               break;
                   
                                          case 2:
                                               num=newInt();
                                               *num=pedir_entero("numero a borrar");
                                               self->removeByValue(self,num);
                                               break;
                        
                                          case 4:
                                               string=newString();
                                               pedir_y_validar_cadena("palabra a borrar",string,CARACTERESCADENA-1);
                                               self->removeByValue(self,string);
                                               break;
                        
                        
                                         case 3:
                                              flotante=newFloat();
                                              *flotante=pedir_flotante("numero a eliminar");
                                              self->removeByValue(self,flotante);
                                              break;
                        }
     }
     else
     {
         
                            printf("no hay elementos cargados por lo que esta opcion no esta disiponible\n");
                            system("PAUSE");
                            system("cls");
         
         
     }
     
}



void contador_elemento(ArrayList* self)
{
     if(self->size==0)
     {
                      printf("no hay elementos cargados por lo tanto esta opcion no esta disponible\n");
                      system("pause");
                      system("cls");
                      
                      
                      
     }
     else
     {
            int* num;
            char* caracter;
            float* flotante;
            char *string;
            int opcion;
            int cant;
            opcion=pedir_y_validar_entero("ingrese que es lo que quiere borrar  :\n1una letra\t2_un entero\t3_un decimal\t_4una palabra\n",4,1);
            
            
     
          switch(opcion)
          {
                   case 1:
                        caracter=newChar();
                        *caracter=pedir_char("caracter a contar");
                        cant=self->count(self,caracter);
                        printf("la cantidad de veces que aparece es de :%d\n", cant);
                        break;
                   
                   case 2:
                        num=newInt();
                        *num=pedir_entero("numero a contar");
                        printf("la cantidad de veces que aparece es de :%d\n", self->count(self,num));
                        break;
                        
                   case 4:
                        string=newString();
                        pedir_y_validar_cadena("palabra a contar",string,CARACTERESCADENA-1);
                        printf("la cantidad de veces que aparece es de :%d\n", self->count(self,string));
                        break;
                        
                        
                   case 3:
                        flotante=newFloat();
                        *flotante=pedir_flotante("numero a contar");
                        printf("la cantidad de veces que aparece es de :%d\n", self->count(self,flotante));
                        break;
      
          }         
          system("PAUSE");
          system("cls");         
     }
     
            
     
     
     
     
     
     
}


void clonarYArchivar(ArrayList* self)
{
     
     
     if(self->isEmpty(self))
     {
                            FILE* fp;
                            int type;
                            int i;
                            ArrayList*   pList;
      
                            fp=fopen("archivo.txt", "a");
      
                            if(fp!=NULL)
                            {
                                        pList=self->clone(self);
                  
                                        for(i=0;i<self->size;i++)
                                        {
                  
                                             type=getType(pList->Get(self,i));
                                           
                                             switch(type)
                                             {
                                                       case ENTERO:
                                                            fprintf(fp,"%d\n", *(int *)pList->Get(self,i));
                                                            break;
                                                            
                                                       case FLOAT:
                                                            fprintf(fp,"%.2f\n", *(float *)pList->Get(self,i));
                                                            break;
                                                            
                                                       case CHAR:
                                                            fprintf(fp, "%c\n", *(char *)pList->Get(self,i));
                                                            break;
                                                            
                                                       case STRING:
                                                            fprintf(fp,"%s\n", (char *)pList->Get(self,i));
                                                            break;
                                                            
                                                            
                                                       
                                                   }
                  
                  
                                               }
                                               printf("operacion de escritura de archivo exitosa\n");
                                               system("PAUSE");
                                               system("cls");
                  
                                               if(fclose(fp))
                                               {
                                                             printf("ERROR AL CERRAR EL ARCHIVO\n");
                                
                                
                                                 }
                  
                                        }
                                        free(pList);
     
     }
     else
     {
         
                               printf("no hay elementos cargados por lo tanto esta opcion no esta disponible\n");
                               system("pause");
                               system("cls");
                      
         
         
     }
     
     
     
     
     
}


