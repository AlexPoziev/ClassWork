#include "binaryTree.h"

#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

typedef struct Tree {
    Node *root;
} Tree;

Tree* createTree(void) {
    Tree *temp = malloc(sizeof(Tree));
    temp->root = NULL;
    return temp;
}

int buildTreeFromArray(int *array, unsigned int arraySize, Tree *tree) {
    for (int i = 0; i < arraySize; ++i) {
        int errorCode = addValue(tree, array[i]);
        if (errorCode) {
            return 1;
        }
    }

    return 0;
}

// put (sorted) data from tree to array
void putTreeToArray(int* array, Node *child, unsigned int *currentNumber) {
    if (child == NULL) {
        return;
    }

    putTreeToArray(array, child->leftChild, currentNumber);

    array[*currentNumber] = child->value;
    ++(*currentNumber);

    putTreeToArray(array, child->rightChild, currentNumber);
}

int sortArrayByTree(int *array, unsigned int arraySize, Tree *tree) {
    if (array == NULL || tree == NULL) {
        return -1;
    }

    if (arraySize <= 0) {
        return -2;
    }

    int errorCode = buildTreeFromArray(array, arraySize, tree);
    if (errorCode == 1) {
        return 1;
    }

    unsigned int currentNumber = 0;
    putTreeToArray(array, tree->root, &currentNumber);

    return 0;
}

Node* findPosition(Tree *tree, int value) {
    Node *currentNode = tree->root;
    if (currentNode->value == value) {
        return currentNode;
    }

    Node *nextNode = currentNode->value >= value ? currentNode->leftChild : currentNode->rightChild;
    while (nextNode != NULL) {
        currentNode = nextNode;
        nextNode = currentNode->value > value ? currentNode->leftChild : currentNode->rightChild;
    }

    return currentNode;
}

int addValue(Tree *tree, int value) {
    if (tree == NULL) {
        return 1;
    }

    if (tree->root == NULL) {
        tree->root = malloc(sizeof(Node));
        if (tree->root == NULL) {
            return 1;
        }

        tree->root->leftChild = NULL;
        tree->root->rightChild = NULL;
        tree->root->value = value;

        return 0;
    }

    Node *currentNode = findPosition(tree, value);
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return 1;
    }

    newNode->value = value;
    newNode->rightChild = NULL;
    newNode->leftChild = NULL;

    if (newNode->value == currentNode->value) {
        newNode->leftChild = currentNode->leftChild;
        currentNode->leftChild = newNode;
    } else {
        newNode->value < currentNode->value
        ? (currentNode->leftChild = newNode)
        : (currentNode->rightChild = newNode);
    }

    return 0;
}

void deleteTreeRecursion(Node *child) {
    if (child == NULL) {
        return;
    }

    deleteTreeRecursion(child->leftChild);
    deleteTreeRecursion(child->rightChild);

    free(child);
    child = NULL;
}

void deleteTree(Tree **dictionary) {
    deleteTreeRecursion((*dictionary)->root);

    free(*dictionary);
    *dictionary = NULL;
}