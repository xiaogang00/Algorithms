#define LEN 30
typedef struct node
{
       int key;
       int next;
       int prev;
}node,array[LEN];

void init(array &array);
int node malloc_int(array &array);
void free_int(array &array,int i);

