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
        tree->root->value

        return 0;
    }

    bool isEnd = false;
    Node *currentNode = findPosition(tree, token, &isEnd);
    Node *newNode = malloc(sizeof(Node));
    char *newWord = calloc(strlen(word), sizeof(char));
    stpcpy(newWord, word);

    if (newNode == NULL) {
        return 1;
    }
    // if found same token
    if (isEnd == false) {
        free(currentNode->word);
        currentNode->word = newWord;

        return 0;
    }
    // if new token
    newNode->parent = currentNode;
    newNode->token = token;
    newNode->word = newWord;
    newNode->rightChild = NULL;
    newNode->leftChild = NULL;

    newNode->token < currentNode->token
    ? (currentNode->leftChild = newNode)
    : (currentNode->rightChild = newNode);

    return 0;
}

char* getWord(Tree *dictionary, int token) {
    if (dictionary == NULL) {
        return NULL;
    }
    bool isEnd = false;
    Node *currentNode = findPosition(dictionary, token, &isEnd);
    return isEnd ? NULL : currentNode->word;
}

bool isContain(Tree *dictionary, int token) {
    if (dictionary == NULL) {
        return false;
    }
    bool isEnd = false;
    findPosition(dictionary, token, &isEnd);

    return !isEnd;
}

// get most right of left children
Node* getMostRight(Node* root) {
    Node *currentNode = root->leftChild;
    Node *next = currentNode->rightChild;
    while (next != NULL) {
        currentNode = next;
        next = currentNode->rightChild;
    }

    return currentNode;
}

int deleteWord(Tree *dictionary, int token) {
    if (dictionary == NULL) {
        return 1;
    }

    bool isEnd = false;
    Node *currentNode = findPosition(dictionary, token, &isEnd);
    if (isEnd) {
        return 0;
    }
    // childfree case
    if (currentNode->leftChild == NULL && currentNode->rightChild == NULL) {
        currentNode->parent->token > token
        ? (currentNode->parent->leftChild = NULL)
        : (currentNode->parent->rightChild = NULL);

        free(currentNode->word);
        free(currentNode);

        return 0;
    }
    // case only child
    if (currentNode->leftChild == NULL || currentNode->rightChild == NULL) {
        Node *temp = currentNode->leftChild == NULL ? currentNode->rightChild : currentNode->leftChild;
        temp->parent = currentNode->parent;
        currentNode->parent->token > token
        ? (currentNode->parent->leftChild = temp)
        : (currentNode->parent->rightChild = temp);

        free(currentNode->word);
        free(currentNode);

        return 0;
    }
    // case two children
    Node *mostRight = getMostRight(currentNode);
    currentNode->token = mostRight->token;
    free(currentNode->word);
    currentNode->word = mostRight->word;
    if (mostRight->leftChild != NULL) {
        mostRight->leftChild->parent = mostRight->parent;
    }
    // case if most right is first right child of current
    mostRight->parent != currentNode
    ? (mostRight->parent->rightChild = mostRight->leftChild)
    : (mostRight->parent->leftChild = mostRight->leftChild);

    free(mostRight);

    return 0;
}

void deleteTreeRecursion(Node *child) {
    if (child == NULL) {
        return;
    }

    deleteTreeRecursion(child->leftChild);
    deleteTreeRecursion(child->rightChild);

    free(child->word);
    child->word = NULL;
    free(child);
    child = NULL;
}

void deleteTree(Tree **dictionary) {
    deleteTreeRecursion((*dictionary)->root);

    free(*dictionary);
    *dictionary = NULL;
}