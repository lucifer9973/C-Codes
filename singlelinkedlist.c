/*4.1 Write a program to create a single linked list of n nodes and perform the following menu based operations on it using function:
i. Insert a node at specific position 
ii. Deletion of an element from specific position
iii. Count nodes
iv. Traverse the linked list.
4.2 In addition to 4.1, perform following operations using function on the single linked list:
 i. search an element in the list
ii. sort the list in ascending order
iii. reverse the list
*/
#include <stdio.h>
#include <stdlib.h>
    struct Node {
    int data;
    struct Node* next;
};
    struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertNode(struct Node** head, int data, int position) {
        struct Node* newNode = createNode(data);
        if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Node inserted at position 1.\n");
        return;
    }
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
        if (temp == NULL) {
        printf("Invalid position. Node not inserted.\n");
        return;
    }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted at position %d.\n", position);
}
    void deleteNode(struct Node** head, int position) {
        if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
        if (position == 1) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Node deleted from position 1.\n");
        return;
    }
        struct Node* temp = *head;
        struct Node* prev = NULL;
        for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
        if (temp == NULL) {
        printf("Invalid position. Node not deleted.\n");
        return;
    }
        prev->next = temp->next;
        free(temp);
        printf("Node deleted from position %d.\n", position);
}
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
        void traverseList(struct Node* head) {
        if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
        struct Node* current = head;
        printf("Linked List: ");
        while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
    void searchNode(struct Node* head, int data) {
    struct Node* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == data) {
            printf("Node with data %d found at position %d.\n", data, position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("Node with data %d not found in the list.\n", data);
}
    struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; 
}
    struct Node* reverseList(struct Node*head) 
      {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; 
}


    int main() {
        struct Node* head = NULL;
        int n, choice, data, position;
        printf("Enter the number of nodes: ");
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        insertNode(&head, data, i);
    }
    while (1) {
            printf("\nMenu:\n");
            printf("1. Insert a node at a specific position\n");
            printf("2. Delete a node from a specific position\n");
            printf("3. Count nodes\n");
            printf("4. Traverse the linked list\n");
            printf("5. Search for a node\n");
            printf("6. Reverse the linked list\n");
            printf("7. Sort the linked list\n");
            printf("8. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertNode(&head, data, position);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;
            case 3:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 4:
                traverseList(head);
            case 5;
                printf("Enter data to search: ");
                scanf("%d", &data);
                searchNode(head, data);
                break;
            case 6:
                head = reverseList(head);
                printf("Linked list reversed.\n");
                break;
            case 7:
               sortList();
            default:
                printf("Invalid choice. Please try again.\n");
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}