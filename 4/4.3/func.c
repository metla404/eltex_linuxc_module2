#include "func.h"

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int get_height(Node* node) 
{
    if (node == NULL)
        return -1;
    return node->height;
}

int get_balance_factor(Node* node) 
{
    if (node == NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

Node* create_node(Contact contact) 
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->contact = contact;
    new_node->height = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* right_rotate(Node* node) 
{
    Node* new_root = node->left;
    node->left = new_root->right;
    new_root->right = node;

    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    new_root->height = max(get_height(new_root->left), get_height(new_root->right)) + 1;

    return new_root;
}

Node* left_rotate(Node* node) 
{
    Node* new_root = node->right;
    node->right = new_root->left;
    new_root->left = node;

    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    new_root->height = max(get_height(new_root->left), get_height(new_root->right)) + 1;

    return new_root;
}

Node* insert_node(Node* root, Contact contact) 
{
    if (root == NULL)
        return create_node(contact);

    if (strcmp(contact.surname, root->contact.surname) < 0)
        root->left = insert_node(root->left, contact);
    else if (strcmp(contact.surname, root->contact.surname) > 0)
        root->right = insert_node(root->right, contact);
    else {
        printf("Контакт с таким именем уже есть\n");
        return root;
    }

    root->height = max(get_height(root->left), get_height(root->right)) + 1;

    int balance_factor = get_balance_factor(root);

    if (balance_factor > 1) 
    {
        if (strcmp(contact.surname, root->left->contact.surname) < 0)
            return right_rotate(root);
        else 
        {
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }
    }

    if (balance_factor < -1) 
    {
        if (strcmp(contact.surname, root->right->contact.surname) > 0)
            return left_rotate(root);
        else 
        {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }
    }

    return root;
}

Node* find_min_value_node(Node* node) 
{
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* delete_node(Node* root, const char* surname) 
{
    if (root == NULL)
        return root;

    if (strcmp(surname, root->contact.surname) < 0)
        root->left = delete_node(root->left, surname);
    else if (strcmp(surname, root->contact.surname) > 0)
        root->right = delete_node(root->right, surname);
    else 
    {
        if (root->left == NULL || root->right == NULL) 
        {
            Node* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }

        Node* temp = find_min_value_node(root->right);
        root->contact = temp->contact;
        root->right = delete_node(root->right, temp->contact.surname);
    }

    if (root == NULL)
        return root;

    root->height = max(get_height(root->left), get_height(root->right)) + 1;

    int balance_factor = get_balance_factor(root);

    if (balance_factor > 1) 
    {
        if (get_balance_factor(root->left) >= 0)
            return right_rotate(root);
        else 
        {
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }
    }

    if (balance_factor < -1) 
    {
        if (get_balance_factor(root->right) <= 0)
            return left_rotate(root);
        else 
        {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }
    }

    return root;
}

void print_contact(Contact contact) 
{
    printf("\nИмя: %s\n", contact.first_name);
    printf("Фамилия: %s\n", contact.surname);
    printf("Отчество: %s\n", contact.patronymic);
    printf("Место работы: %s\n", contact.workplace);
    printf("Должность: %s\n", contact.job);
    printf("Телефон: %s\n", contact.phone);
    printf("Email: %s\n", contact.email);
    printf("Соц. сеть: %s\n", contact.social);
}

void inorder_traversal(Node* root) 
{
    if (root == NULL)
        return;

    inorder_traversal(root->left);
    print_contact(root->contact);
    inorder_traversal(root->right);
}

void add_contact(Node** root) 
{
    Contact new_contact;

    printf("\nВведите имя: ");
    scanf("%s", new_contact.first_name);

    printf("Введите фамилию: ");
    scanf("%s", new_contact.surname);

    printf("Введите отчество: ");
    scanf("%s", new_contact.patronymic);

    printf("Введите место работы: ");
    scanf("%s", new_contact.workplace);

    printf("Введите должность: ");
    scanf("%s", new_contact.job);

    printf("Введите номер телефона: ");
    scanf("%s", new_contact.phone);

    printf("Введите email: ");
    scanf("%s", new_contact.email);

    printf("Введите соц. сеть: ");
    scanf("%s", new_contact.social);

    *root = insert_node(*root, new_contact);
}

void delete_contact(Node** root) 
{
    char surname[50];

    printf("\nВведите фамилию удаляемого контакта: ");
    scanf("%s", surname);

    *root = delete_node(*root, surname);
}

void edit_contact(Node* root) 
{
    char surname[50];
    Node* current;
    Contact new_contact;

    printf("\nВведите фамилию изменяемого контакта: ");
    scanf("%s", surname);

    current = root;
    while (current != NULL) 
    {
        if (strcmp(surname, current->contact.surname) < 0)
            current = current->left;
        else if (strcmp(surname, current->contact.surname) > 0)
            current = current->right;
        else
            break;
    }

    if (current == NULL) 
    {
        printf("Такого контакта нет\n");
        return;
    }

    printf("Введите новое имя (ничего не вводите, чтобы оставить значение): ");
    scanf("%s", new_contact.first_name);
    if (strlen(new_contact.first_name) > 0)
        strcpy(current->contact.first_name, new_contact.first_name);

    printf("Введите новое отчество (ничего не вводите, чтобы оставить значение): ");
    scanf("%s", new_contact.patronymic);
    if (strlen(new_contact.patronymic) > 0)
        strcpy(current->contact.patronymic, new_contact.patronymic);

    printf("Введите новое место работы (ничего не вводите, чтобы оставить значение): ");
    scanf("%s", new_contact.workplace);
    if (strlen(new_contact.workplace) > 0)
        strcpy(current->contact.workplace, new_contact.workplace);

    printf("Введите новую должность (ничего не вводите, чтобы оставить значение): ");
    scanf("%s", new_contact.job);
    if (strlen(new_contact.job) > 0)
        strcpy(current->contact.job, new_contact.job);

    printf("Введите новый номер (ничего не вводите, чтобы оставить значение): ");
    scanf("%s", new_contact.phone);
    if (strlen(new_contact.phone) > 0)
        strcpy(current->contact.phone, new_contact.phone);

    printf("Введите новый email (ничего не вводите, чтобы оставить значение): ");
    scanf("%s", new_contact.email);
    if (strlen(new_contact.email) > 0)
        strcpy(current->contact.email, new_contact.email);

    printf("Введите новую соц. сеть (ничего не вводите, чтобы оставить значение): ");
    scanf("%s", new_contact.social);
    if (strlen(new_contact.social) > 0)
        strcpy(current->contact.social, new_contact.social);
}

void display_contacts(Node* root) 
{
    printf("\nКонтакты:\n");
    inorder_traversal(root);
}
