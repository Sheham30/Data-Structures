// Name: Syed Sheham Hassan
// Seat Number: B20103070
// Content: "Binary Search Trees"

#include <stdio.h>
#include <stdlib.h>

// ****Nodes****
struct BTNode
{
    int data;
    struct BTNode *leftChild;
    struct BTNode *rightChild;
};
struct BTNode *root = NULL;

// ****01****
void insert()
{
    struct BTNode *tmp = (struct BTNode *)malloc(sizeof(struct BTNode));

    printf("Enter a number to insert: ");
    scanf("%d", &tmp->data);

    tmp->leftChild = NULL;
    tmp->rightChild = NULL;

    if (root == NULL)
    {
        root = tmp;
    }
    else
    {
        struct BTNode *curr = root;

        int i = 0;
        while (i == 0)
        {
            if (tmp->data <= curr->data)
            {
                if (curr->leftChild == NULL)
                {
                    curr->leftChild = tmp;
                    break;
                }
                else
                {
                    curr = curr->leftChild;
                }
            }
            else if (tmp->data > curr->data)
            {
                if (curr->rightChild == NULL)
                {
                    curr->rightChild = tmp;
                    break;
                }
                else
                {
                    curr = curr->rightChild;
                }
            }
        }
    }
}

// ****02****
int In_Order_TraversalLNR(struct BTNode *Node)
{
    if (Node != NULL)
    {
        In_Order_TraversalLNR(Node->leftChild);
        printf("%d  ", Node->data);
        In_Order_TraversalLNR(Node->rightChild);
    }
}

// ****03****
int Pre_Order_Traversal(struct BTNode *Node)
{
    if (Node != NULL)
    {
        printf("%d  ", Node->data);
        Pre_Order_Traversal(Node->leftChild);
        Pre_Order_Traversal(Node->rightChild);
    }
}

// ****04****
int Post_Order_Traversal(struct BTNode *Node)
{
    if (Node != NULL)
    {
        Post_Order_Traversal(Node->leftChild);
        Post_Order_Traversal(Node->rightChild);
        printf("%d  ", Node->data);
    }
}

// ****05****
int Search()
{
    int i, flag = 0;
    printf("Enter a value to search: ");
    scanf("%d", &i);

    struct BTNode *curr = root;

    while (curr != NULL)
    {
        if (i == curr->data)
        {
            printf("\nFound\n");
            flag = 1;
            break;
        }
        else if (i < curr->data)
        {
            curr = curr->leftChild;
        }
        else if (i > curr->data)
        {
            curr = curr->rightChild;
        }
    }
    if (flag == 0)
    {
        printf("\nNot Found\n");
    }
}

// // ****06****
struct BTNode *rec_insert(struct BTNode *root, struct BTNode *temp)
{

    if (root == NULL)
    {
        return temp;
    }

    if (temp->data > root->data)
    {
        root->rightChild = rec_insert(root->rightChild, temp);
    }
    else if (temp->data < root->data)
    {
        root->leftChild = rec_insert(root->leftChild, temp);
    }
}
int insert_recc()
{
    struct BTNode *tmp = (struct BTNode *)malloc(sizeof(struct BTNode));

    printf("\nEnter a value to insert: ");
    scanf("%d", &tmp->data);

    tmp->leftChild = NULL;
    tmp->rightChild = NULL;

    root = rec_insert(root, tmp);
}

// ****07****
int search_rec(struct BTNode *Node, int i)
{
    if (Node != NULL)
    {
        if (i == Node->data)
        {
            return 1;
        }
        else if (Node->data < i)
        {
            return search_rec(Node->rightChild, i);
        }
        else if (Node->data > i)
        {
            return search_rec(Node->leftChild, i);
        }
    }
    else if (Node == NULL)
    {
        return -1;
    }
}
int search_recc()
{
    int i, j;
    printf("Enter a value to search: ");
    scanf("%d", &i);

    j = search_rec(root, i);
    // printf("%d", j);

    if (j == 1)
    {
        printf("\nFound\n");
    }
    if (j == -1)
    {
        printf("\nNot Found\n");
    }
}

// ****08****


// -----------------------------------------------------
int main()
{
    printf("\n***********Binary Search Tree**********\n");
    int i = 0;

    while (i != 9)
    {
        printf("\nEnter\n1. insert | 2. In_Order_Traversal | 3. Pre_Order_Traversal | 4. Post_Order_Traversal | \n5. Search | 6. InsertRec | 7. SearchRec | 8. Delete | 9. Exit\n");
        scanf("%d", &i);

        if (i == 1)
        {
            insert();
        }
        if (i == 2)
        {
            In_Order_TraversalLNR(root);
        }
        if (i == 3)
        {
            Pre_Order_Traversal(root);
        }
        if (i == 4)
        {
            Post_Order_Traversal(root);
        }
        if (i == 5)
        {
            Search();
        }
        if (i == 6)
        {
            insert_recc();
        }
        if (i == 7)
        {
            search_recc();
        }
        if (i == 8)
        {
            delete ();
        }
    }
    return 0;
}