#include <stdio.h>
#include <stdlib.h>

// Base structure for each node of list
struct Node {
    int data;
    struct Node *next;
};

// Renaming for convenience
typedef struct Node node;

void displayNodeList(node *head) {
    /*
        displauys the linked list in the format
        index > data | address | next
    */
    node *traversingNode = head;
    int counter = 0;
    if (traversingNode == NULL) {
        printf("List empty\n");
        return;
    }
    while (traversingNode != NULL) {
        printf("%3d > %3d | %8p | %8p\n", counter++, traversingNode -> data, traversingNode, traversingNode -> next);
        traversingNode = traversingNode -> next;
    }
}


node *createNode() {
    /*
        Returns a new node pointing to NULL in O(1) time
    */
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> next = NULL;
    return newNode;
}

int countNodes(node *head) {
    int counter = 0;
    node *traversingNode = head;
    while (traversingNode != NULL) {
        traversingNode = traversingNode -> next;
        counter++;
    }
    return counter;
}

void insertNode_Front(node **head, int data) {
    /*
        Inserts node in front of the list and changes head.
        O(1) time.
    */
    node *newNode = createNode();
    newNode -> data = data;
    if (head == NULL) {
        (*head) = newNode;
        printf("newNode - %p\n", newNode);
        printf("head - %p\n", (*head));
    } else {
        newNode -> next = (*head);
        (*head) = newNode;
    }
}

void insertNode_Rear(node **head, int data) {
    /*
        Inserts node in rear of the list.
        O(n) time.
    */
    node *newNode = createNode();
    newNode -> data = data;
    if ((*head) == NULL) {
        (*head) = newNode;
    } else {
        // Create a temporary node to traverse to the end of the list
        node *traversingNode = (*head);
        while (traversingNode -> next != NULL) {
            traversingNode = traversingNode -> next;
        }

        // Attach the node onto the list
        traversingNode -> next = newNode;
    }
}

void insertNode(node **head, int targetIndex, int data) {
    /*
        Inserts node at given index.
        Note: I am using 0-index. targetIndex=1 refers to the 2nd element in the linked list
        O(n) time.
    */
    node *newNode = createNode();
    newNode -> data = data;
    if ((*head) == NULL) {
        // If list is empty, insertion at any index other than 0 doesnt make sense
        if (targetIndex != 0) {
            printf("Invalid index\n");
            return;
        }
        (*head) = newNode;
    } else {
        // Create temporary node to traverse to the node one behind insertion point
        node *traversingNode = (*head);
        int currentIndex = 0;
        while (currentIndex < targetIndex - 1) {
            if (traversingNode -> next == NULL) {
                printf("Invalid index\n");
                return;
            }
            traversingNode = traversingNode -> next;
            currentIndex++;
        }
        newNode -> next = traversingNode -> next;       // Now there are two nodes linked to insertion point
        traversingNode -> next = newNode;               // Change the traversing node to point to new node, thereby inserting node at given index
    }
}


int search(node *head, int searchElement) {
    /*
        Searches for an element in linked list.
        Returns index of element or -1 if not found.
        O(n) time.
    */
    int currentIndex = 0;               // Keep track
    node *traversingNode = head;
    while (traversingNode != NULL) {
        if (traversingNode -> data == searchElement) {
            return currentIndex;
        } else {
            traversingNode = traversingNode -> next;
            currentIndex++;
        }
    }
    return -1;
}

void deleteNode_Front(node **head) {
    /*
        Deletes head node.
        O(1) time.    
    */
    if ((*head) == NULL) {
        return;
    } else {
        node *temp = (*head);
        (*head) = (*head) -> next;
        free(temp);
    }
}

void deleteNode_Rear(node **head) {
    /*
        Deletes rear node.
        O(n) time.
    */
    if ((*head) == NULL) {
        return;
    } else {
        // Traverse to the end of the linked list
        node *prev, *curr;
        prev = (*head);
        curr = (*head) -> next;
        while (curr -> next != NULL) {
            prev = curr;
            curr = curr -> next;
        }
        // Set second last node to point to NULL and free the last node
        prev -> next = NULL;
        free(curr);
    }
}

void deleteNode_Index(node **head, int targetIndex) {
    /*
        Delete node at any given index.
        O(n) time.
    */
    if ((*head) == NULL) {
        return;
    } else {
        if (targetIndex == 0) {
            deleteNode_Front(head);
        } else {
            node *prev, *curr;
            curr = (*head);
            int currentIndex = 0;
            while (currentIndex  < targetIndex) {
                if (curr -> next == NULL) {
                    printf("Invalid index\n");
                    return;
                }
                prev = curr;
                curr = curr -> next;
                currentIndex++;
            }
            prev -> next = curr -> next;
            free(curr);
        }
    }
}

void reverseNodeList(node **head) {
    node *prev = NULL, *next = NULL;
    node *curr = (*head);

    while (curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    (*head) = prev;
}

int main() {

    // Simple user menu
    node *head = NULL;
    char c;
    int data;
    int targetIndex;
    int searchElement;
    printf("---------------\nA - Display List\nB - Insert Element at head\nC - Insert Element at rear\nD - Insert Element\n");
    printf("E - Search\nF - Count nodes\n");
    printf("G - Delete Head Node\nH - Delete Rear node\nI - Delete node at index\nJ - Delete node by value\n");
    printf("K - Reverse list\n");
    printf("---------------\n");
    while (1) {
        switch ((c = getchar())) {
            case 'A':
                displayNodeList(head);
                break;
            case 'B':
                printf("Data to insert > ");scanf("%d", &data);
                insertNode_Front(&head, data);
                break;
            case 'C':
                printf("Data to insert > ");scanf("%d", &data);
                insertNode_Rear(&head, data);
                break;
            case 'D':
                printf("Index to insert at > "); scanf("%d", &targetIndex);
                printf("Data to insert > ");scanf("%d", &data);
                insertNode(&head, targetIndex, data);
                break;
            case 'E':
                printf("Element to search for > "); scanf("%d", &searchElement);
                printf("Found at index : %d\n", search(head, searchElement));
                break;
            case 'F':
                printf("List has %d nodes\n", countNodes(head));    
                break;
            case 'G':
                deleteNode_Front(&head);
                break;
            case 'H':
                deleteNode_Rear(&head);
                break;
            case 'I':
                printf("Index to delete > "); scanf("%d", &targetIndex);
                deleteNode_Index(&head, targetIndex);
            case 'J':
                reverseNodeList(&head);
                break;
            case '\n':
                break;
            default:
                break;
        }
    }

}