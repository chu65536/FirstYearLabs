#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int tdata;

struct node;
typedef node * link;

struct node{
    tdata data;
    link son;
    link brother;
};

// Search node and prevnode by data
void search_node(tdata node, link *pos, link *prevpos, link cur, link prev, bool *error){
    if (cur->data == node) {
        *pos = cur;
        *prevpos = prev;
        *error = false;
        return;
    }
    if (cur->son) search_node(node, pos, prevpos, cur->son, cur, error);
    if (cur->brother) search_node(node, pos, prevpos, cur->brother, cur, error);
}

// Add son by father and son data
void add_son(tdata father, tdata son, link tree){

    link cur, prev;
    bool error = true;
    search_node(father, &cur, &prev, tree, tree, &error);

    if (error){
        printf("_____________________________________________________\n");
        printf("Wrong info\n");
        return;
    }

    if (cur->data == father){
    
        if (cur->son == NULL){
            link new_node = (link)malloc(sizeof(link));
            new_node->data = son;
            new_node->brother = NULL;
            new_node->son = NULL;
            cur->son = new_node;
        }
        else{
            cur = cur->son;
            while(cur->brother != NULL) cur = cur->brother;
            link new_node = (link)malloc(sizeof(link));
            new_node->data = son;
            new_node->brother = NULL;
            new_node->son = NULL;
            cur->brother = new_node;
        }

    }
}

// Removing process
void removing(link cur){
    if (cur->son){
        removing(cur->son);
    }
    if (cur->brother){
        removing(cur->brother);
    }

    cur->son = NULL;    
    cur->brother = NULL;
    cur->data = 0;
    free(cur);
}

// Remove subtree by data
void remove_node(tdata node, link tree){
    link cur, prev;
    bool error = true;
    search_node(node, &cur, &prev, tree, tree, &error);

    if (error) {
        printf("_____________________________________________________\n");
        printf("Wrong info\n");
        return;
    }

    if (cur->son) {
        removing(cur->son);
        cur->son = NULL;
    }

    if (prev->brother && prev->brother->data == cur->data){
        prev->brother = cur->brother;
    }
    else {
        prev->son = cur->brother;
    }

    cur->son = NULL;
    cur->brother = NULL;
    cur->data = 0;
    free(cur);
}

// Generate random tree witn n nodes
void generate_tree(link cur){
    if (!cur->son && !cur->brother){
        int flip = rand() % 2;

        if (flip){
            link new_node = (link)malloc(sizeof(link));
            new_node->data = rand() % 20 + 1;
            new_node->son = NULL;
            new_node->brother = NULL;
            cur->son = new_node;
        }
        else{
            link new_node = (link)malloc(sizeof(link));
            new_node->data = rand() % 20 + 1;
            new_node->son = NULL;
            new_node->brother = NULL;
            cur->brother = new_node;
        }
        return;
    }

    int choose = rand() % 2;

    if (choose){
        if (cur->son) generate_tree(cur->son);
        else {
            link new_node = (link)malloc(sizeof(link));
            new_node->data = rand() % 20 + 1;
            new_node->son = NULL;
            new_node->brother = NULL;
            cur->son = new_node;
        }
    } 
    else{
        if (cur->brother) generate_tree(cur->brother);
        else{
            link new_node = (link)malloc(sizeof(link));
            new_node->data = rand() % 20 + 1;
            new_node->son = NULL;
            new_node->brother = NULL;
            cur->brother = new_node;
        }
    }
}

// Set tree root
void set_root(link *root){
    printf("Input root value -> ");
    int root_value;
    scanf("%d", &root_value);

    link new_root;
    new_root = (link)malloc(sizeof(link));
    
    new_root->son = NULL;
    new_root->brother = NULL;
    new_root->data = root_value;

    *root = new_root;
}

// Set random tree root
void set_random_root(link* root) {

    link new_root;
    new_root = (link)malloc(sizeof(link));
    new_root->brother = NULL;
    new_root->data = rand() % 20 + 1;


    link new_node;

    new_node = (link)malloc(sizeof(link));
    new_node->son = NULL;
    new_node->brother = NULL;
    new_node->data = rand() % 20 + 1;

    new_root->son = new_node;

    *root = new_root;   
}

// Remove whole tree
void remove_tree(link root, bool *empty){
    printf("You are going to remove whole tree. Are you sure? y/n\n");
    char check;
    scanf(" %c", &check);

    if (check != 'y') {
        printf("_____________________________________________________\n");
        printf("Canceled");
        return;
    }
    *empty = true;

    if (root->son){
        remove_node(root->son->data, root);
    }
    
    root->data = 0;
    root->son = NULL;
    root->brother = NULL;
    free(root);

    printf("_____________________________________________________\n");
    printf("Tree was sucsesfully removed\n");
}

// Tree visualisation
void print_tree(link cur, int n){
    if (cur->son) print_tree(cur->son, n + 1);
    if (cur->brother) print_tree(cur->brother, n);
    
    for (int i = 0; i < n; i++) printf("   ");
    printf("\\__%d\n", cur->data);    
}

// Find deep of tree
void find_deep(int *deep, int n, link cur){
    if (n > *deep){
        *deep = n; 
    }

    if (cur->son){
        find_deep(deep, n + 1, cur->son);
    }
    if (cur->brother){
        find_deep(deep, n, cur->brother);
    }
}

// Function that calculating level with the most nodes
void function_34(int *levels, int n, link cur){
    levels[n]++;

    if (cur->son){
        function_34(levels, n + 1, cur->son);
    }
    if (cur->brother){
        function_34(levels, n, cur->brother);
    }
}

//------------------------------------------------------------
int main(){
    
    srand(time(NULL));

    link tree;
    bool empty = true, exit = false;
    int key;

    while(1){
        printf("\n");
        printf("__________Menu__________\n");
        printf("1. Print tree\n");
        printf("2. Generate random tree\n");
        printf("3. Set root\n");
        printf("4. Add son\n");
        printf("5. Remove node\n");
        printf("6. Remove whole tree\n");
        printf("7. Find level with the most nodes\n");
        printf("8. Exit\n");


        printf("Input key -> ");
        scanf("%d", &key);
        printf("_____________________________________________________\n");

        switch (key){
            // 1. Print tree
            case 1:
                if (!empty){
                    print_tree(tree, 0);
                }
                else{
                    printf("Tree is empty\n");
                }
                break;
            // 2. Generate random tree
            case 2:
                if (empty){
                    printf("Input number of nodes -> ");
                    int n;
                    scanf("%d", &n);

                    if (n < 2){
                        printf("_____________________________________________________\n");
                        printf("Number must be greater then 1\n");
                        break;
                    }

                    set_random_root(&tree);

                    n -= 2;
                    for (int i = 0; i < n; i++){
                        generate_tree(tree->son);
                    }

                    printf("Tree generated\n");

                    empty = false;
                }
                else{
                    printf("Tree already exists. Want to generated new? y/n\n");
                    char check;
                    scanf(" %c", &check);
                    
                    if (check == 'y'){
                        printf("Input number of nodes -> ");
                        int n;
                        scanf("%d", &n);

                        if (n < 2) {
                            printf("_____________________________________________________\n");
                            printf("Number must be greater then 1\n");
                            break;
                        }

                        remove_tree(tree, &empty);
                        if (!empty) break;
                        set_random_root(&tree);

                        n -= 2;
                        for (int i = 0; i < n; i++) {
                            generate_tree(tree->son);
                        }

                        empty = false;
                        printf("Tree generated\n");
                    }
                    else{
                        printf("_____________________________________________________\n");
                        printf("Canceled");
                    }
                }
                break;
            // 3. Set root
            case 3:
                if (empty){
                    set_root(&tree);

                    empty = false;
                }
                else{
                    printf("Root already exists\n");
                }
    
                break;
            // 4. Add son
            case 4:
                if (!empty){
                    printf("Input father <space> son -> ");
                    int father, son;
                    scanf("%d%d", &father, &son);
                    
                    add_son(father, son, tree);
                }
                else{
                    printf("Tree is empty\n");
                }

                break;
            // 5. Remove node
            case 5:
                if (!empty){
                    printf("Input node -> ");
                    int node;
                    scanf("%d", &node);

                    if (node == tree->data) {
                        remove_tree(tree, &empty);
                    }
                    else{
                        remove_node(node, tree);
                    }
                }
                else{
                    printf("Tree is empty\n");
                }
                break;
            // 6. Remove whole tree
            case 6:
                if (!empty){
                    remove_tree(tree, &empty);
                }
                else{
                    printf("Tree is empty\n");
                }
                break;
            // 7. Find level with the most nodes
            case 7:
                if (!empty){
                    int deep = 1;
                    find_deep(&deep, 1, tree);

                    int levels[deep + 1];
                    for (int i = 1; i < deep + 1; i++) {
                        levels[i] = 0;
                    }

                    function_34(levels, 1, tree);

                    int mx = 0;
                    int ans = 1;
                    for (int i = 1; i < deep + 1; i++){
                        if (levels[i] > mx){
                            mx = levels[i];
                            ans = i;
                        }
                    }

                    printf("Level with the most nodes is: %d\n", ans);
                }
                else{
                    printf("Tree is empty\n");
                }
                break;
            // 8. Exit
            case 8:
                exit = true;
                break;
        }

        if (exit) break;
    }
}