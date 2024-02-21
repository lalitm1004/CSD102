/*
Write a C program to remove duplicates from a single unsorted linked list.

Example 1:
    Input: n = 5, Input data for nodes = [1, 2, 3, 3, 4]
    Output: 1 2 3 4

Example 2:
    Input: n = 6, Input data for nodes = [1, 2, 3, 3, 4, ,4]
    Output: 1 2 3 4
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node node;

node *createNodeList(int n) {
  node *base = (node *)malloc(sizeof(node));
  node *prevNode = base;
  for (int i = 0; i < n; i++) {
    int data;
    scanf("%d", &data);
    if (i == 0) {
      base->data = data;
      continue;
    }

    node *nextNode = (node *)malloc(sizeof(node));
    nextNode->data = data;
    prevNode->next = nextNode;
    prevNode = nextNode;
  }
  prevNode->next = NULL;
  return base;
}

void displayNodeList(node *base) {
  node *temp = base;
  while (temp->next != NULL) {
    printf("%d ", temp -> data);
    temp = temp->next;
  }
  printf("%d", temp->data);
}

// void removeDuplicate(node *base, int n) {
  
//   int set[n];
//   int len = 0;
  
//   node *prev = NULL;
//   node *curr = base;

//   while (curr != NULL) {
//     printf("%d %p\n", curr -> data, curr -> next);
//     int isUnique = 1;
//     for (int i = 0; i < len; i++) {
//       if (curr -> data == set[i]) {
//         isUnique = 0;
//         break;
//       }
//     }

//     if (isUnique) {
//       printf("Unique - %d\n", curr -> data);
//       prev = curr;
//       set[len++] = curr -> data;
//     } else {
//       printf("NotUnique - %d\n", curr -> data);
//       prev -> next = curr -> next;
//     }
//     if(curr -> next != NULL) curr = curr -> next;
//   }
// }

void removeDuplicates(node* start) {
    node *ptr1, *ptr2, *dup;
    ptr1 = start;

    // Pick elements one by one
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;

        while (ptr2->next != NULL) {
            if (ptr1->data == ptr2->next->data) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

int main() {
  int n;
  scanf("%d", &n);

  node *node0 = createNodeList(n);
  // displayNodeList(node0);
  removeDuplicates(node0);
  displayNodeList(node0);
  return 0;
}