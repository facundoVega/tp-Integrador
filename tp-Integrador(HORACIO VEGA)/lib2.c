#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "funciones.h"
#include "funciones2.h"
#include "lib2.h"


/************************************DESARROLLO DE SUBFUNCIONES DEL ARRAYLIST*******************************************************************************/

//crea un espacio de forma dinamica y le guarda metadatos.
void* myMalloc(int size,int type)
{
      void* ptr_tmp;
      descriptor* desc;
      
      
      desc=(descriptor *)malloc(size+sizeof(descriptor));
      
      desc->size=size;
      desc->type=type;
      
      ptr_tmp=desc+1;
      
      return ptr_tmp;
      
      
      
}

//retorna el tipo de dato que es la variable.
int getType(void* element)
{
    descriptor* desc;
    
    desc=(descriptor *)element;
    
    return (desc-1)->type;
    
    
    
    
    
    
}



/***realiza una conversion de tipo del elemento pasado como void  a int,y luego busca(por valor) si hay una  aparicion en el arrayList*//////
/*retorna uno si hay una igualdad, retorna 0 si no la hay.
*/
int casting_look_int(ArrayList* self, void* element)
{
    int i;
    int type;
    
    for(i=0;i<self->size;i++)
    {
                             type=getType(self->Get(self,i));
                             
                             if(type==ENTERO)
                             {
                                                                   
                                                                   if(*(int *)self->Get(self,i)==*(int *)element)
                                                                   {                                     
                                                                                                         return 1;
                                      
                                      
                                      
                                                                    }
                                                                    
                             }
                             
                             
                             
    }
    return 0;
    
    
    
    
}


/***realiza una conversion de tipo del elemento pasado como void  a float,y luego busca(por valor) si hay una  aparicion en el arrayList*//////
/*retorna uno si hay una igualdad, retorna 0 si no la hay.
*/

int casting_look_float(ArrayList* self, void* element)
{
        int i;
        int type;
        
    for(i=0;i<self->size;i++)
    {
                             
                             type=getType(self->Get(self,i));
                             
                             if(type==FLOAT)
                             {
                                            
                                            if(*(float *)self->Get(self,i)==*(float *)element)
                                            {
                                                       return 1;
                                      
                                      
                                      
                                             }
                                             
                             }
                             
                             
                             
    }
    return 0;
    
    
    
    
    
}

/***realiza una conversion de tipo del elemento pasado como void  a char,y luego busca(por valor) si hay una  aparicion en el arrayList*//////
/*retorna uno si hay una igualdad, retorna 0 si no la hay.
*/

int casting_look_char(ArrayList* self, void* element)
{
    
            int i;
            int type;
    
    for(i=0;i<self->size;i++)
    {
                             type=getType(self->Get(self,i));
                             
                             if(type==CHAR)
                             {
                                           if(*(char *)self->Get(self,i)==*(char *)element)
                                           {
                                                     return 1;
                                      
                                      
                                      
                                            }
                                            
                                      
                             }
                             
                             
                             
    }
    return 0;
    
    
    
    
    
    
}

/***realiza una conversion de tipo del elemento pasado como void  a string,y luego busca(por valor) si hay una  aparicion en el arrayList*//////
/***retorna 1 si hay una igualdad,retorna 0 sino la hay***********************/
int casting_look_string(ArrayList* self, void* element)
{
                int i;
                int type;
                
                
    
    for(i=0;i<self->size;i++)
    {
                             type=getType(self->Get(self,i));
                             
                             if(strcmp((char *)self->Get(self,i),(char *)element)==0)
                             {
                                      return 1;
                                      
                                      
                                      
                             }
                             
                             
                             
    }
    return 0;
    
    
    
    
    
    
    
}


//si el elemento es de tipo char ,cuenta cuantas veces aparece en la lista y retorna esa cantidad.
int contTypeChar(ArrayList* self, void* element)
{
    int cont=0;
    int i;
    int type;
    
    for(i=0;i<self->size;i++)
    {
                             type=getType(self->Get(self,i));
                             
                             if(type==CHAR)
                             {
                                           if(*(char *)element==*(char *)self->Get(self,i))
                                           { 
                                                    cont++;                                                                    
                                                     
                                           }
                                           
                                           
                                           
                             }
                             
                             
                             
    }
    
    return cont;
    
    
}
//si el elemento es de tipo string ,cuenta cuantas veces aparece en la lista y retorna esa cantidad.
int contTypeString(ArrayList* self, void* element)
{
    
        
    int cont=0;
    int i;
    int type;
    
    for(i=0;i<self->size;i++)
    {
                             type=getType(self->Get(self,i));
                             
                             if(type==STRING)
                             {
                                           if(strcmp((char *)element,(char *)self->Get(self,i))==0)                                           
                                            {
                                                                    cont++;
                                                     
                                            }
                                           
                                           
                                           
                             }
                             
                             
                             
    }
    
    return cont;
    
    
    
    
}

//si el elemento es de tipo int ,cuenta cuantas veces aparece en la lista y retorna esa cantidad.
int contTypeInt(ArrayList* self, void* element)
{
            
    int cont=0;
    int i;
    int type;
    
    for(i=0;i<self->size;i++)
    {
                             type=getType(self->Get(self,i));
                             
                             if(type==ENTERO)
                             {
                                           if(*(int *)element==*(int *)self->Get(self,i))   
                                           {                                        
                                                     cont++;
                                                     
                                           
                                           }
                                           
                                           
                             }
                             
                             
                             
    }
    
    return cont;
    
    
    
    
    
}

//si el elemento es de tipo float ,cuenta cuantas veces aparece en la lista y retorna esa cantidad.
int contTypeFloat(ArrayList* self ,void* element)
{
    
    int cont=0;
    int i;
    int type;
    
    for(i=0;i<self->size;i++)
    {
                             type=getType(self->Get(self,i));
                             
                             if(type==FLOAT)
                             {
                                           if(*(float *)element==*(float *)self->Get(self,i))      
                                           {
                                                                                
                                                     cont++;
                                                     
                                           
                                           }
                                           
                                           
                             }
                             
                             
                             
    }
    
    return cont;
    
    
    
    
}


//castea el puntero void a char , busca si su valor esta contenido en el array si hay igualdad retorna la posicion sino la hay retornara -1.
int castingCharLookAndReturnIndex(ArrayList* self, void* element)
{
    int i;
    int type;
    
    for(i=0;i<self->size;i++)
    {
                             type=getType(self->Get(self,i));
                             
                             if(type==CHAR)
                             {
                                           if(*( char *)element==*(char *)self->Get(self,i))
                                           {
                                                 return i;
                                                 
                                                 
                                           }
                                           
                                           
                             }
                             
                             
                             
    }
    return-1;
    
    
    
    
}


//castea el puntero void a float , busca si su valor esta contenido en el array si hay igualdad retorna la posicion sino la hay retornara -1.
int castingFloatLookAndReturnIndex(ArrayList* self, void* element)
{
    int i;
    int type;
    
    for(i=0;i<self->size;i++)
    {
                             type=getType(self->Get(self,i));
                             
                             if(type==FLOAT)
                             {
                                           if(*( float *)element==*(float *)self->Get(self,i))
                                           {
                                                 return i;
                                                 
                                                 
                                           }
                                           
                                           
                             }
                             
                             
                             
    }
    return-1;
    
    
    
}


//castea el puntero void a int , busca si su valor esta contenido en el array si hay igualdad retorna la posicion sino la hay retornara -1.
int castingIntLookAndReturnIndex(ArrayList* self, void* element)
{
        int i;
    int type;
    
    for(i=0;i<self->size;i++)
    {
                             type=getType(self->Get(self,i));
                             
                             if(type==ENTERO)
                             {
                                           if(*( int *)element==*(int *)self->Get(self,i))
                                           {
                                                 return i;
                                                 
                                                 
                                           }
                                           
                                           
                             }
                             
                             
                             
    }
    return-1;
    
    
    
}


//castea el puntero void a string , busca si su valor esta contenido en el array si hay igualdad retorna la posicion sino la hay retornara -1.
int castingStringLookAndReturnIndex(ArrayList* self, void* element)
{
        int i;
    int type;
    
    for(i=0;i<self->size;i++)
    {
                             type=getType(self->Get(self,i));
                             
                             if(type==STRING)
                             {
                                           if(strcmp(( char *)element,(char *)self->Get(self,i))==0)
                                           {
                                                 return i;
                                                 
                                                 
                                           }
                                           
                                           
                             }
                             
                             
                             
    }
    return-1;
    
    
    
}


//castea el puntero a void a int y compara con los valores del array casteados a int si hay una igualdad borra el puntero del array y devuelve 1 si no devuelve 0.
int castingRemoveInt(ArrayList* self,void* element)
{
    int type;
    int i;
    
    for(i=0;i<self->size;i++)
    {
                             type=getType(self->Get(self,i));
                             
                             if(type==ENTERO)
                             {
                                             if(*(int *)element==*(int *)self->Get(self,i))
                                             {
                                                      self->remov(self,i);
                                                      return 1;
                                                      
                                                      
                                                      
                                             }
                                             
                                             
                                             
                                             
                             }
                             
                             
                             
    }
    return 0;
    
    
    
}

//castea el puntero a void a int y compara con los valores del array casteados a int si hay una igualdad borra el puntero del array y devuelve 1 si no devuelve 0
int castingRemoveFloat(ArrayList* self, void* element)
{
    
    int type;
    int i;
    
    for(i=0;i<self->size;i++)
    {
                             type=getType(self->Get(self,i));
                             
                             if(type==FLOAT)
                             {
                                             if(*(float *)element==*(float *)self->Get(self,i))
                                             {
                                                      self->remov(self,i);
                                                      return 1;
                                                      
                                                      
                                                      
                                             }
                                             
                                             
                                             
                                             
                             }
                             
                             
                             
    }
    return 0;
    
    
    
    
    
}

//castea el puntero a void a int y compara con los valores del array casteados a int si hay una igualdad borra el puntero del array y devuelve 1 si no devuelve 0
int castingRemoveChar(ArrayList* self,void* element)
{
    int type;
    int i;
    
    for(i=0;i<self->size;i++)
    {
                             type=getType(self->Get(self,i));
                             
                             if(type==CHAR)
                             {
                                             if(*(char *)element==*(char *)self->Get(self,i))
                                             {
                                                      self->remov(self,i);
                                                      return 1;
                                                      
                                                      
                                                      
                                             }
                                             
                                             
                                             
                                             
                             }
                             
                             
                             
    }
    return 0;
    
    
    
    
    
}

//castea el puntero a void a int y compara con los valores del array casteados a int si hay una igualdad borra el puntero del array y devuelve 1 si no devuelve 0
int castingRemoveString(ArrayList* self,void* element)
{
        int type;
    int i;
    
    for(i=0;i<self->size;i++)
    {
                             type=getType(self->Get(self,i));
                             
                             if(type==STRING)
                             {
                                             if(strcmp((char *)element,(char *)self->Get(self,i))==0)
                                             {
                                                      self->remov(self,i);
                                                      return 1;
                                                      
                                                      
                                                      
                                             }
                                             
                                             
                                             
                                             
                             }
                             
                             
                             
    }
    return 0;
    
}

/***********************************************************CONSTRUCTORES DE TIPOS DE DATOS DINAMICOS Y CON METADATA***************************************/

//crea  un char de forma dinamica,retorna un puntero al elemento creado;
char* newChar()
{
      char* element;
      
      element=myMalloc(sizeof(char),CHAR);
                                          
      return element;
      
      
}

//crea  un int de forma dinamica retorna un puntero al elemento creado 
int* newInt()
{
     int* element;
     
     element=myMalloc(sizeof(int), ENTERO);
     
     return element;
     
     
}

//crea un float de forma dinamica retorna un puntero al elemento creado.
float* newFloat()
{
       
       float* element;
       
       element=myMalloc(sizeof(float), FLOAT);
       
       return element;
       
       
       
}

//crea un string de forma dinamica retorna un puntero al elemento creado.
char* newString()
{
      
      char* element;
      
      element=myMalloc(sizeof(float)*CARACTERESCADENA,STRING);
      
      return element;
      
      
}



/*************************FUNCIONES QUE CREAN TIPOS DE DATOS DINAMICOS CON METADA E INSERTAN EN EL ARRAYLIST***********************************************/


//crea de forma dinamica un entero le asigna un valor y lo guarda en el arrayList.

void crearInt_y_guardar_en_array(ArrayList* self)
{
     
     
     int* num;
     
     num=myMalloc(sizeof(int),ENTERO);
     
     *num=pedir_entero("numero entero");
     
     
     self->add(self,num);
     
     
     
}

void crearFloat_y_guardar_en_array(ArrayList* self)
{
     
     float *num;
     
     num=myMalloc(sizeof(float), FLOAT);
     
     *num=pedir_flotante("numero decimal");
     
     self->add(self,num);
     
     
     
     
}

//pide un caracter por pantalla y lo ingresa al arrayList.
void crearChar_y_guardar_en_array(ArrayList* self)
{
     
     char* element;
     
     element=myMalloc(sizeof(char), CHAR);
     
     *element=pedir_char("caracter");
     
     self->add(self,element);
     
     
     
}

//pide una cadena por pantalla y la ingresa al arrayList.
void crearString_y_guardar_en_array(ArrayList* self)
{
     char* element;
     
     element=newString();
     
     pedir_y_validar_cadena("palabra",element,CARACTERESCADENA-1);
     
     self->add(self,element);
     
     
}
    
    
    
    


