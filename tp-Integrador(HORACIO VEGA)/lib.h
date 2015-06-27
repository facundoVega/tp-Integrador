#define INCREMENT 10
#define ENTERO 1
#define FLOAT 2
#define CHAR 3
#define STRING 4
#define CARACTERESCADENA 21



/***********************************************************PROTOTIPO DE FUNCIONES DEL ARRAYLIST************************************************************/

typedef struct descriptor{
        
        int type;
        int size;
        
        
        }descriptor;



typedef struct ArrayList{
        
        int size;
        void **pElements;
        int reservedSize;

        
        
        void (*set)();
        void (*add)();
        int(*Size)();
        void (*remov)();
        void(*clear)();
        struct ArrayList* (* clone)();
        void* (*Get)();
        int (*contains)();
        void(*push)();
        int(*indexOf)();
        int(*isEmpty)();
        void* (*pop)();
        struct ArrayList* (*subList)();
        int (* containsAll)();
        int (* containsByValue)();
        int (* indexByValue)();
        void(* removeByValue)();
        int (* count)();
        
        }ArrayList;
        
        
        
        
ArrayList* newArrayList(void);
void add(ArrayList*,void*);
void deleteArrayList(ArrayList*);
int Size(ArrayList*);
void* get(ArrayList* , int);
int contains(ArrayList*, void*);
int resizeUp(ArrayList*);
void set(ArrayList*, int,void*);
void remov(ArrayList*,int);
void clear(ArrayList*);
ArrayList* clone(ArrayList*);
void expand(ArrayList*,int);
void push(ArrayList*, int, void*);
int indexOf(ArrayList*, void*);
int isEmpty(ArrayList*);
void contract(ArrayList*,int);
void* pop(ArrayList*,int);
ArrayList* subList(ArrayList*,int,int);
int containsAll(ArrayList*,ArrayList*);
int containsByValue(ArrayList*, void*);
int indexByValue(ArrayList*, void*);
void removeByValue(ArrayList*, void*);
int count(ArrayList*,void*);

