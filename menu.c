#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

int main()
{
    Table* table = 0;
    int command = 0;
    while(command != 'q')
    {
        printf("Enter 1 to insert \n     2 to delete \n     3 to display \n     4 to update\n     5 to quit\n");
        printf("Enter command: ");
        fflush(stdin);
        scanf("%d",&command);
        fflush(stdin);
        // char key[1000];
        // int value;
        if(command == 1)
        {
            char key[1000];
            int value;
            printf("Enter key: ");gets(key);
            fflush(stdin);
            printf("Enter value: ");scanf("%d", &value);
            fflush(stdin);
            table = insert(table, key, value);
        }
        else if(command == 2)
        {
            char key[1000];
            printf("Enter key to delete: ");gets(key);
            fflush(stdin);
            table = _delete(table, key);
        }
        else if(command == 3)
        {
            display(table);
        }
        else if(command == 4)
        {
            char key[1000];
            int value;
            printf("Enter key whose value you want to update: ");
            gets(key);fflush(stdin);
            printf("New value: ");
            scanf("%d", &value);fflush(stdin);
            table = update(table, key, value);
        }
        else if(command == 5)
                return 0;
        else
            printf("command not found!\n");
    }
}