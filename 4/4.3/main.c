#include "func.h"

int main() 
{
    Node* root = NULL;
    int choice;

    while (1) 
    {
        printf("\n1. Добавить контакт\n");
        printf("2. Удалить контакт\n");
        printf("3. Изменить контакт\n");
        printf("4. Отобразить контакты\n");
        printf("5. Выйти\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                add_contact(&root);
                break;
            case 2:
                delete_contact(&root);
                break;
            case 3:
                edit_contact(root);
                break;
            case 4:
                display_contacts(root);
                break;
            case 5:
                exit(0);
            default:
                printf("Неверный выбор!\n");
        }
    }
    return 0;
}
