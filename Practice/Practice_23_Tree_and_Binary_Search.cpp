// #include <iostream>
// #include <stdio.h>
// using namespace std;

// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;
// };

// int isBST(struct Node *root)
// {
//     static struct Node *prev = NULL;
//     if (root != NULL)
//     {
//         if (!isBST(root->left))
//         {
//             return 0;
//         }
//         if (prev != NULL && prev->data >= root->data)
//         {
//             return 0;
//         }
//         prev = root;
//         return isBST(root->right);
//     }
//     else
//     {
//         return 1;
//     }
// }

// struct Node *searching(struct Node *root, int data)
// {
//     if (root != NULL)
//     {
//         if (root->data > data)
//         {
//             searching(root->left, data);
//         }
//         else if (root->data < data)
//         {
//             searching(root->right, data);
//         }
//         else
//         {
//             return root;
//         }
//     }
//     else
//     {

//         return NULL;
//     }
// }

// struct Node *searchIterative(struct Node *root, int data)
// {
//     while (root != NULL)
//     {
//         if (root->data > data)
//         {
//             root = root->left;
//         }
//         else if (root->data < data)
//         {
//             root = root->right;
//         }
//         else
//         {
//             return root;
//         }
//     }
//     return NULL;
// }

// struct Node *createNode(int data)
// {
//     struct Node *n = (struct Node *)malloc(sizeof(struct Node));
//     n->data = data;
//     n->left = NULL;
//     n->right = NULL;
//     return n;
// }

// void inOrder(struct Node *root)
// {
//     if (root != NULL)
//     {
//         inOrder(root->left);
//         printf("%d ", root->data);
//         inOrder(root->right);
//     }
// }

// void insertion(struct Node *root, int data)
// {
//     struct Node *n = createNode(data);
//     while (root != NULL)
//     {

//         if (root->left == NULL && root->data > data)
//         {
//             root->left = n;
//             break;
//         }
//         else if (root->right == NULL && root->data < data)
//         {
//             root->right = n;
//             break;
//         }
//         else if (root->data > data)
//         {
//             root = root->left;
//         }
//         else if (root->data < data)
//         {
//             root = root->right;
//         }
//         else
//         {
//             printf("given data is already exist in the tree");
//             break;
//         }
//     }
// }

// int main()
// {
//     struct Node *n = createNode(8);
//     struct Node *n1 = createNode(5);
//     struct Node *n2 = createNode(11);
//     struct Node *n3 = createNode(3);
//     struct Node *n4 = createNode(6);
//     struct Node *n5 = createNode(9);
//     n->left = n1;
//     n->right = n2;
//     n1->left = n3;
//     n1->right = n4;
//     n2->left = n5;
//     insertion(n, 4);
//     printf("\n");
//     inOrder(n);
//     return 0;
// }

// #include <iostream>
// #include <stdio.h>
// using namespace std;

// int binarySearch(int arr[], int n, int data)
// {
//     int low = 0;
//     int high = n - 1;
//     int mid;
//     while (low <= high)
//     {
//         mid = (low + high) / 2;
//         if (arr[mid] > data)
//         {
//             high = mid - 1;
//         }
//         else if (arr[mid] < data)
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             return data;
//         }
//     }
//     return -1;
// }

// int main()
// {

//     return 0;
// }

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

    return 0;
}