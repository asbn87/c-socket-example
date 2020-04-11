#include "data.h"

unsigned long hash_code(unsigned int size, const char* key)
{
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    for (; i < key_len; ++i)
	value = value * 37 + key[i];

    value = value % size;

    return value;
}

struct hash_table* create_hash_table(int size)
{
    struct hash_table* tbl = (struct hash_table*)malloc(sizeof(struct hash_table));

    tbl->size = size;
    tbl->list = calloc((size_t)tbl->size, sizeof(struct hash_node*));

    return tbl;
}

char* lookup(struct hash_table* tbl, char* key)
{
    int pos = hash_code(tbl->size, key);
    struct hash_node* list = tbl->list[pos];
    struct hash_node* temp = list;

    while (temp)
    {
	if (strcmp(temp->key, key) == 0)
	    return temp->val;

	temp = temp->next;
    }
    return "";
}

void init_hash_table(struct hash_table* mem)
{
    FILE* file_p = NULL;
    char key[16];
    char value[6];
    char ch;
    bool value_flag = 0;
    int pos_node = 0;
    unsigned long pos_list;

    printf("Getting indata...\n");
    fopen_s(&file_p, "indata.dat", "r");

    while ((ch = fgetc(file_p)) != EOF) {

	if (ch == '\n')
	{
	    pos_list = hash_code(mem->size, key);
	    struct hash_node* list = mem->list[pos_list];
	    struct hash_node* node = (struct hash_node*)malloc(sizeof(struct hash_node));
	    struct hash_node* tmp = list;

	    while (tmp) {
		if (tmp->key == key)
		{
		    strncpy(tmp->val, value, 6);
		    break;
		}
		tmp = tmp->next;
	    }

	    if (node) 
	    {
		strncpy(node->key, key, 16);
		strncpy(node->val, value, 6);
		node->next = list;
	    }

	    mem->list[pos_list] = node;
	    memset(key, 0, sizeof(key));
	    memset(value, 0, sizeof(value));
	    value_flag = 0;
	    pos_node = 0;
	    continue;
	}

	if (ch == '\t')
	{
	    pos_node = 0;
	    value_flag = 1;
	    continue;
	}

	if (value_flag == 0)
	    key[pos_node++] = ch;

	if (value_flag == 1)
	    value[pos_node++] = ch;
    }

    printf("Closing file...\n");
    fclose(file_p);
}
