#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact 
{
    char first_name[50];
    char surname[50];
    char patronymic[50];
    char workplace[100];
    char job[100];
    char phone[15];
    char email[50];
    char social[100];
} Contact;

typedef struct Node 
{
    Contact contact;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

int max(int a, int b);
int get_height(Node* node);
int get_balance_factor(Node* node);
Node* create_node(Contact contact);
Node* right_rotate(Node* node);
Node* left_rotate(Node* node);
Node* insert_node(Node* root, Contact contact);
Node* find_min_value_node(Node* node);
Node* delete_node(Node* root, const char* surname);
void print_contact(Contact contact);
void inorder_traversal(Node* root);
void add_contact(Node** root);
void delete_contact(Node** root);
void edit_contact(Node* root);
void display_contacts(Node* root);

#endif