#define INCREMENT 10
#define ENTERO 1
#define FLOAT 2
#define CHAR 3
#define STRING 4
#define CARACTERESCADENA 21


/********************************************PROTOTIPOS DE SUBFUNCIONES DEL ARRAYLIST**************************************************************************/

void* myMalloc(int ,int);
int getType(void* element);



int contTypeChar(ArrayList*, void*);
int contTypeString(ArrayList*, void*);
int contTypeInt(ArrayList*, void*);
int contTypeFloat(ArrayList*,void*);
int castingRemoveInt(ArrayList*,void*);
int castingRemoveFloat(ArrayList*, void*);
int castingRemoveChar(ArrayList*,void*);
int castingRemoveString(ArrayList*,void*);
int castingCharLookAndReturnIndex(ArrayList*, void*);
int castingFloatLookAndReturnIndex(ArrayList*, void*);
int castingIntLookAndReturnIndex(ArrayList*, void*);
int castingStringLookAndReturnIndex(ArrayList*, void*);
int casting_look_float(ArrayList*, void*);
int casting_look_int(ArrayList*, void*);
int casting_look_char(ArrayList*, void*);
int casting_look_string(ArrayList*, void*);
char pedir_char(char[]);
char* newChar();
int* newInt();
float* newFloat();
char* newString();
void crearInt_y_guardar_en_array(ArrayList*);
void crearFloat_y_guardar_en_array(ArrayList*);
void crearChar_y_guardar_en_array(ArrayList*);
void crearString_y_guardar_en_array(ArrayList*);
