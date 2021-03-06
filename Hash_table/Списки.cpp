#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <ctype.h>
#include <assert.h>

#define TRASH 0xFEFEFEFE
#define CANARY 0xBADF00D
#define MAX_STR_LEN 100
#define HASH_TABLE_SIZE 10




typedef struct ListElem
    {
        double can1;
        char info[MAX_STR_LEN];
        ListElem* next;
        ListElem* prev;
        double can2;
    };

typedef struct List
    {
        double can1;
        int elem_amount;
        ListElem* head;
        ListElem* tail;
        double can2;
    };


void ListElem_ctor(ListElem* This, int info)   ;
void ListElem_dtor(ListElem* This);
bool List_OK(const ListElem* This);
void Head_insert(List* This, ListElem* Insert) ;
void Tail_insert(List* This, ListElem* Insert)    ;
void Insert_before(ListElem* This, ListElem* Insert) ;
void Insert_after(ListElem* This, ListElem* Insert)  ;
void Elem_delete(ListElem* This)                     ;
void Do_test(int* hash_int_table, int (*Hash_function) (char*), List* hash_table) ;
int Word_read (FILE* file, char* s)      ;
int Hash_func1(char* word);
int Hash_func2(char* word);
int Hash_func3(char* word);
int Hash_func4(char* word);
void Hash_table_show(List* hash_tables);
void Do_test_with_num(List* hash_tables, int fnum);
void Hash_end_insert(List* hash_table, int position, ListElem* This);
void List_ctor(List* This);
void Printing(List* hash_table);


int main()
    {
        List hash_tables[HASH_TABLE_SIZE] ;
        for (int i = 0; i < HASH_TABLE_SIZE;)
        {
            List_ctor(&hash_tables[i]);
            i++;
        }

        int which_func = 0;
        printf("Enter num of function\n");
        scanf("%i", &which_func);

        Do_test_with_num(hash_tables, which_func);
        printf("asd\n");
        Hash_table_show(hash_tables);

        Printing(hash_tables);
        return 0;

    }




void List_ctor(List* This)
{
    This->can1 = CANARY;
    This->elem_amount = 0;
    This->head = NULL;
    This->tail = NULL;
    This->can2 = CANARY;
}

void ListElem_ctor(ListElem* This, char* info)
    {
        This->can1 = CANARY;
        strcpy(This->info, info);
        This->next = NULL;
        This->prev = NULL;
        This->can2 = CANARY;
    }


void ListElem_dtor(ListElem* This)
    {
        strcpy(This->info, "Trash");
        This->next = NULL;
        This->prev = NULL;
    }

bool List_OK(const ListElem* This)
    {
        return (This ->can1 == CANARY) &&
           (This ->can2 == CANARY) ;

    }

void Head_insert(List* This, ListElem* Insert)
    {
        Insert->next = This->head;
        This->head = Insert;
        (Insert->next)->prev = Insert;
    }

void Tail_insert(List* This, ListElem* Insert)
    {
        if (This->tail != NULL)
        {
            Insert->prev = This->tail;
            (Insert->prev)->next = Insert;
            This->tail = Insert;
            This->elem_amount++;
        }
        else
        {
            Insert->prev = NULL;
            This->head = Insert;
            This->tail = Insert;
            This->elem_amount++;
        }
    }

void Insert_before(ListElem* This, ListElem* Insert)
    {
        (This->prev)->next = Insert;
        Insert->prev = This->prev;
        Insert->next = This;
        This->prev = Insert;
    }

void Insert_after(ListElem* This, ListElem* Insert)
    {
        (This->next)->prev = Insert;
        Insert->next = This->next;
        Insert->prev = This;
        This->next = Insert;
    }

void Elem_delete(ListElem* This)
    {
        (This->prev)->next = This->next;
        (This->next)->prev = This->prev;
        ListElem_dtor(This);
    }


void Do_test(List* hash_table, int (*Hash_function) (char*) )
    {
        int position = 0;
        FILE* file = fopen("hash_test.txt", "r");
        char word[MAX_STR_LEN];

        while (1)
            {
                if (Word_read(file, word) == -1) break;
                position = Hash_function(word) % HASH_TABLE_SIZE ;
                //printf("word = %s \n",  word);


                ListElem* a = (ListElem*)calloc(1, sizeof(ListElem));
                ListElem_ctor(a, word);

                Hash_end_insert(hash_table, position, a);

            }
        fclose(file);
    }



int Word_read (FILE* file, char* s)
    {
        char c = fgetc (file);
        while (c == ' ' || c == '\n')
        {
            c = fgetc(file);
        }
        if (c == EOF) return -1;

        int i=0;
        while ((c != ' ') && (c != '\n') && (c != EOF ))
            {
                s[i] = c;

                c = fgetc (file);
                if (c == EOF) return -1;

                i++;
            }
        s[i] = '\0';
        return 0;
    }


void Hash_end_insert(List* hash_table, int position, ListElem* This)
    {
        Tail_insert(&hash_table[position], This);
    }

void Hash_table_show(List* hash_tables)
    {
        for (int i = 0; i < HASH_TABLE_SIZE ; )
            {
                printf("Hash num. %i got %i words in it. \n",  i,  hash_tables[i].elem_amount);
                i++;
            }
    }

void Printing(List* hash_tables)
{
    int maximum = 0;
    for (int i = 0; i < HASH_TABLE_SIZE;)
    {
        if (hash_tables[i].elem_amount > maximum)
        {
            maximum = hash_tables[i].elem_amount;
        }
        i++;
    }

    int a = 0;
    for (int i = 0; i < HASH_TABLE_SIZE;)
    {
        double a = 170.0 * hash_tables[i].elem_amount / maximum;
        int z = 0;
        printf("%d hash: "); // %.*s", i, a, "**********************************************************************************************************************************************");
        while ( z < a)
        {
            printf("*");
            z++;
        }
        printf("\n");
        i++;
    }
}

void Do_test_with_num(List* hash_tables, int fnum)
{
    switch (fnum)
    {
        case 1:
            Do_test(hash_tables, Hash_func1); break;
        case 2:
            Do_test(hash_tables, Hash_func2); break;
        case 3:
            Do_test(hash_tables, Hash_func3); break;
        case 4:
            Do_test(hash_tables, Hash_func4); break;

        default: assert(!"Wrong function");
    }
}



int Hash_func1(char* word)
    {
        return (int)word[1];
    }

int Hash_func2(char* word)
{
    return strlen(word);
}

int Hash_func3(char* word)
{
    int a = 0;
    for (int i = 0; word[i]; )   // kill!
    {
        a = a + word[i];
        i++;
    }
    return a;
}

int Hash_func4(char* word)
{
    int a = 0;
    int i = 0;
    for (i = 0; word[i]; )
    {
        a = a + word[i];
        i++;
    }
    return (i)? a / i : 0;
}

// a << 1  a >> 31
