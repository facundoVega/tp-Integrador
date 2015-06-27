#define INCREMENT 10
#define ENTERO 1
#define FLOAT 2
#define CHAR 3
#define STRING 4
#define CARACTERESCADENA 21


/*************************PROTOTIPOS DE LAS FUNCIONES PERTENECIENTES A CADA UNO DE LOS CASOS DEL SWITCH DE LA FUNCION MAIN*************************************/



void mostrar_menu();
int mostrar_y_validar_menu();
void ingresar(ArrayList*,int*);
void mostrar(ArrayList*);
void insertar(ArrayList*);
void desplazar_e_ingresar(ArrayList*);
void eliminar(ArrayList*);
void consultar_tamanio(ArrayList*);
void borrar_todo(ArrayList*);
ArrayList* clonar_y_mostrar_clon(ArrayList*);
void hay_elementos(ArrayList*);
void consultar_indice_primer_elemento(ArrayList*);
int comparar_valor(int,ArrayList*);
void consultar_contenido(ArrayList*);
void recuperar_elemento_y_borrar(ArrayList*);
void crear_y_mostrar_sublista(ArrayList*);
void mostrar_ArrayList(ArrayList*);
void consultar_existe_elementos(ArrayList*);
void verificar_contenido(ArrayList*);
void consultar_indice2(ArrayList*);
void eliminar2(ArrayList*);
void contador_elemento(ArrayList*);
void clonarYArchivar(ArrayList*);
