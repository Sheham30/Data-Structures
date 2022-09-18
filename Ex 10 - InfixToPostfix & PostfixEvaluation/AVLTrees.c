#include <stdio.h>
#include <stdlib.h>
struct AVLTree
{
    int data;
    int height;
    struct AVLTree *left;
    struct AVLTree *right;
};
struct AVLTree *root = NULL;

int max_val(int a, int b)
{
    //a > b ? a : b; bro yahan apko return b to krana tha to correction mene likh di
    return a>b? a:b;
}

int getHeight(struct AVLTree *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    return ptr->height;
}

int getBalance(struct AVLTree *curr)
{
    if (curr == NULL)
    {
        return 0;
    }
    return getHeight(curr->left) - getHeight(curr->right);
}

struct AVLTree *rotate_right(struct AVLTree *y)
{
    struct AVLTree *x = y->left;
    struct AVLTree *z = x->right;
    x->right = y;
    y->left = z;
    x->height = max_val(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max_val(getHeight(y->left), getHeight(y->right)) + 1;
    return (x);
}

struct AVLTree *rotate_left(struct AVLTree *y)
{
    struct AVLTree *x = y->right;
    struct AVLTree *z = x->left;
    x->left = y;
    y->right = z;
    
    x->height = max_val(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max_val(getHeight(y->left), getHeight(y->right)) + 1;
    //return (y); Yar ye chiz to apko tree return to kreygi mger purany wala we want our updated tree or wo 'x' me return hoga
    return (x);
}

struct AVLTree *insert(struct AVLTree *node, int key)
{   
    if (node == NULL)
    {   
        struct AVLTree *temp = (struct AVLTree *)malloc(sizeof(struct AVLTree));
        temp->data = key;
        temp->left = NULL;
        temp->right = NULL;
        temp->height = 0;
        return (temp);
    }

    if (node->data > key)
    {
        node->left = insert(node->left, key);
    }
    else if (node->data < key)
    {
        node->right = insert(node->right, key);
    }
    //return node; // agar ap yahan per return node krado to bhai starting 3 values to glat set krra hai, ye nhi ayega

    node->height = max_val(getHeight(node->left), getHeight(node->right)) + 1;
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->data)
        return rotate_right(node);

    // Right Right Case
    if (balance < -1 && key > node->right->data)
        return rotate_left(node);

    // Left Right Case
    if (balance > 1 && key > node->left->data)
    {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->data)
    {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

void preorderTraversal(struct AVLTree *curr)
{

    if (curr != NULL)
    {
        printf("%d   ", curr->data);
        preorderTraversal(curr->left);
        preorderTraversal(curr->right);
    }
    else if(root == NULL){
        printf("No tree exists");
    }
}
void main()
{
    int choice;
    printf("1.Insert\t2.Pre order print\t3.Pre order print\t4.Post order print\t5.Insertion using recursion\t6.Search \t7.Search using recursion \t8.Delete");
    printf("\nEnter:");
    scanf("%d", &choice);
    while (choice != 0000)
    {

        if (choice == 1)
        {
            int data;
            printf("data: ");
            scanf("%d", &data);
            root = insert(root, data);
        }

        else if (choice == 2)
        {
            printf("\n\n");
            preorderTraversal(root);
            printf("\n\n");
        }
        printf("1.Insert\t2.In order print\t3.Pre order print\t4.Post order print\t5.Insertion using recursion\t6.Search \t7.Search using recursion \t8.Delete");
        printf("\nEnter:");
        scanf("%d", &choice);
    }
}