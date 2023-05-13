#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* create_node(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int count_nodes(struct Node* node) {
    if (node == NULL)
        return 0;
    else
        return 1 + count_nodes(node->left) + count_nodes(node->right);
}

int main() {
    // Exemplo de uso
    struct Node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);

    printf("%d", count_nodes(root)); // saída: 5

    return 0;
}
