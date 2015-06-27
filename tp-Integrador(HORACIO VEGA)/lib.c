#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "funciones.h"
#include "funciones2.h"
#include <string.h>
#include "lib2.h"


/*******************************************************DESARROLLOS DE  LAS FUNCIONES DEL ARRAYLIST*********************************************************/




//Crea y retorna un nuevo ArrayList.
ArrayList* newArrayList(void)
{
           ArrayList* pList;
           
           pList=(ArrayList *)malloc(sizeof(ArrayList));
           
           pList->size=0;
           
           pList->pElements=malloc(sizeof(void *)*10);
           pList->reservedSize=10;
           
           pList->add=add;
           pList->Size=Size;
           pList->set=set;
           pList->remov=remov;
           pList->clear=clear;
           pList->clone=clone;
           pList->Get=get; 
           pList->contains=contains;
           pList->push=push;
           pList->indexOf=indexOf;
           pList->isEmpty=isEmpty;
           pList->pop=pop;
           pList->subList=subList;
           pList->containsAll=containsAll;
           pList->containsByValue=containsByValue;
           pList->indexByValue=indexByValue;
           pList->removeByValue=removeByValue;
           pList->count=count;
           return pList;
           
           
           
}

//Agrega un elemento al final del ArrayList.
void add(ArrayList* self,void* element)
{
     
     if(self->size==self->reservedSize)
     {
                         resizeUp(self);              
                                       
                                       
     }
     self->pElements[self->size]=element;
     self->size++;
     
     
     
}

//Elimina el ArrayList.
void deleteArrayList(ArrayList* p)
{
     
     free(p);
     
     
     
     
}

//Retorna el tamanio del ArrayList.
int Size(ArrayList* pList)
{
    
    return pList->size;
    
    
    
    
}

//Retorna un puntero al elemento que se encuentra en el indice especificado.
void * get(ArrayList* self , int index)
{
           if(self->size>=index)
           {                    return self->pElements[index];     
           
           }
           
           return NULL;
}

//comprueba si existe el elemento que se le pasa como parametro.
int contains(ArrayList* self, void* element)
{
    int i;
    
    for(i=0;i<self->size;i++)
    {
                             
                             if(element==self->pElements[i])
                             {
                                                             return 1;
                                                             
                                                             
                             }
                             
                             
    }
    
    return 0;
    
    
    
}

int resizeUp(ArrayList* pList)
{
    int newSize;
    void* ptr;
    
    newSize= sizeof(void *) * (pList->reservedSize+INCREMENT);
    
    ptr=realloc(pList->pElements,newSize);
    
    if(ptr==NULL)
    {
                 printf("No se pudo realocar memoria\n");
                 system("PAUSE");
                 system("cls");
                 return 0;
                 
    }
    else
    {
        pList->pElements=ptr;
        pList->reservedSize=pList->reservedSize+ INCREMENT;
        return 1;
        
        
    }
    
    
    
}
//Inserta un elemento en ArrayList en el indice especificado.
void set(ArrayList* self, int index,void* element)
{
     if(self->size>=index)
     {
                        self->pElements[index]=element;
                         
                         
                         
                         
     }
     
     
     
     
}

//Elimina un elemento en ArrayList en el indice especificado.
void remov(ArrayList* self,int index)
{
     int i;
     for(i=index;i<self->size-1;i++)
     {
                                self->pElements[i]=self->pElements[i+1];
                                
                                
                                
     }
                         self->pElements[self->size-1]=NULL;
                         self->size--;
     

}


//Borra todos los elementos del ArrayList.
void clear(ArrayList* self)
{
    /* int i;
     
     for(i=0;i<self->size;i++)
     {
                                   self->pElements[i]=NULL;
                                   
                                   
                                   
                                   
     }
     self->size=0;
     */
     deleteArrayList(self);
     self=newArrayList();
     
}


void contract(ArrayList* pList,int index)
{//Contrae la lista eliminando la posicion index.
     int i;
     
     for(i=index;i<pList->size-1;i++)
     {
                                    pList->pElements[i]=pList->pElements[i+1];
                                    
                                    
                                    
     }
     
     pList->pElements[pList->size-1]=NULL;
     
     
     

}


//Retorna un nuevo ArrayList copia del ArrayList original.
ArrayList* clone(ArrayList* self)
{
           ArrayList* pList;
           pList=newArrayList();
           int i;
         
         pList->size=self->size;
         pList->reservedSize=self->reservedSize;
         
           for(i=0;i<self->size;i++)
           {
                                    pList->pElements[i]=self->pElements[i];
                                    
                                    
                                    
           }                        
                                    
           
           
               
          return pList;
           
           
}


/*Expande la lista generando un espacio para la posicion index.
/*En caso de que la memoria reservada sea igual al tamaño del array reservara 10 espacios mas.
*/
void expand(ArrayList* pList,int index)
{
     int i;
     
     if(pList->size==pList->reservedSize)
     {
                                         resizeUp(pList);
                                         
                                         
     }     
     
     for(i=pList->size-1;i>=index;i--)
     {
                                      
                                      
                                      pList->pElements[i+1]=pList->pElements[i];
                                      
                                      
     }
     
     pList->pElements[index]=NULL;
     
     
     
}

//Desplaza los elementos e inserta en la posicion index.
void push(ArrayList* self, int index, void* element)
{
     expand(self,index);
     
     self->pElements[index]=element;
     self->size++;
     
     
     
     
     
}


int indexOf(ArrayList* self, void* element)
{
    
    int i;
    
    for(i=0;i<self->size;i++)
    {
                             if(self->pElements[i]==element)
                             {
                                                            return i;
                                                            
                                                            
                                                            
                             }
                             
                             
                             
    }
    
    return -1;
    
    
    
    
}

//Retorna 1 si el ArrayList tiene elementos y 0 si no los tiene.
int isEmpty(ArrayList* self)
{
    
    int i;
    
    for(i=0;i<self->size;i++)
    {
                             if(self->pElements[i]!=NULL)
                             {
                                                         return 1;
                                                         
                                                         
                                                         
                             }
                             
                             
                             
    }
    
    return 0;
    
    
    
}

//Retorna uhn puntero al elemento que se encuentra en el indice especificado  y luego lo elimina de la lista.
void* pop(ArrayList* self,int index)
{
           void* pEle;
           
           if(self->size>index)
           {
                               pEle=self->pElements[index];
                               contract(self, index);
                               
                               self->size--;
                               return pEle;
                               
                               
                               
                               
                               
           }
           
           return NULL;
           
           
           
           
           
           
}

//Retorna un nuevo ArrayList con el subconjunto de elementos.
ArrayList* subList(ArrayList* self,int from,int to)
{
           ArrayList* pList;
           int i;
             
           pList=newArrayList();
           
           if(from<to)
           {
                      for(i=from;i<=to;i++)
                      {
                                           pList->add(pList,self->pElements[i]);
                                       
                                       
                                       
                      }
                      
           }

           
           if(from>to)
           {
                          
                     for(i=from;i>=to;i--)
                     {
                                          pList->add(pList,self->pElements[i]);
                                                 
                                          
                                          
                     }     
                          
                          
               }
               if(from==to)
               {
                           pList->add(pList,self->pElements[to]);
                           
                           
                           
               }
               
               
               return pList;
           
           
           
}


//Comprueba si los elementos pasados son contenidos por el ArrayList.
int containsAll(ArrayList* self,ArrayList* array)
{
 
    int i,j;
    int flagCont=0;
    for(i=0;i<array->size;i++)
    {
                              
                              
                              for(j=0;j<self->size;j++)
                              {
                                                       
                                                       if(array->pElements[i]==self->pElements[j])
                                                       {
                                                                                                  flagCont++;
                                                                                                  break;
                                                           
                                                           
                                                           
                                                       
                                                       
                                                       }
                                                       
                                                       
                                                       
                              }
                              
                              
                              
                              
                              
                              
    }   
    
    if(flagCont==array->size&& array->size!=0)
    {
                             return 1;
    
    }
    else
    {
        return 0;
        
        
    }
    
    
    
}    

//verifica si contiene el valor informativo contenido en el puntero ("element") pasado como parametro.
int containsByValue(ArrayList* self, void* element)
{
    int i;
    switch(getType(element))
    {
                            case ENTERO:
                                 return casting_look_int(self,element);
                                 break;
                                 
                            case FLOAT:
                                 return casting_look_float(self,element);
                                 break;
                                 
                            case CHAR:
                                 return casting_look_char(self,element);
                                break;
                                 
                            case STRING:
                                 return casting_look_string(self,element);
                                 break;

                                 
                                                          
                                                          
    }
                            
}

//retorna el indice de la lista donde el valor es igual al contenido informatico en el puntero pasado como parametro.si no hay igualdad retornara -1.
int indexByValue(ArrayList* self, void* element)
{
    
    int type;
    
    type=getType(element);
    
    switch(type)
    {
                            case ENTERO:
                                 return castingIntLookAndReturnIndex(self, element);
                                 break;
                                 
                            case FLOAT:
                                 return castingFloatLookAndReturnIndex(self, element);
                                 break;
                                 
                            case CHAR:
                                 return castingCharLookAndReturnIndex(self, element);
                                break;
                                 
                            case STRING:
                                 return castingStringLookAndReturnIndex(self, element);
                                 break;

                              
                
                
    }
    
    
    
    
    
    
}


//Borra el primer elemento de la lista el cual el valor es igual al valor informativo del puntero pasado como parametro.
void removeByValue(ArrayList* self, void* element)
{
     int type;
     
     type=getType(element);
     
     switch(type)
     {
                 case ENTERO:
                      castingRemoveInt(self,element);
                      break;
                      
                 case FLOAT:
                      castingRemoveFloat(self, element);
                      break;
                      
                 case CHAR:
                      castingRemoveChar(self,element);
                      break;
                      
                 case STRING:
                      castingRemoveString(self,element);
                      break;
     }
     
     
     
     

}

//Retorna el numero de veces que aparece el valor informativo del puntero "element" en la lista.
int count(ArrayList* self,void* element)
{
    
    int type;
    
    type=getType(element);
    
    switch(type)
    {
                case ENTERO:
                     return  contTypeInt(self, element);
                     break;
                     
                case FLOAT:
                     return contTypeFloat(self,element);
                     break;
                     
                case STRING:
                     return contTypeString(self,element);
                     break;
                     
                case CHAR:
                     return contTypeChar(self, element);
                     break;
                
    }
    
    
    
    
    
    
}


