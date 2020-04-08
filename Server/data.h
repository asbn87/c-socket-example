#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct hash_node {						// Hash node
	char key[16];						// Key value storing the 15 digit number from indata.dat
	char val[6];						// Value storing the 5 chars from indata.dat
	struct hash_node* next;					// Pointer to next hash node
};

struct hash_table {						// Hash table
	unsigned int size;					// Size of hash table
	struct hash_node** list;				// List of hash nodes
};

unsigned long hash_code(unsigned int size, const char* key);	// Hash the key
char* lookup(struct hash_table* tbl, char* key);		// Lookup key in hash table
struct hash_table* create_hash_table(int size);			// Allocate memory for hash table
void init_hash_table(struct hash_table* mem);			// Copy file content to hash table
