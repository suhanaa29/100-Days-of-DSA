/*CLONE GRAPH*/

struct Node* map[101];

struct Node* clone(struct Node* s) {
    if (s == NULL) return NULL;

    if (map[s->val]) return map[s->val];

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = s->val;
    newNode->numNeighbors = s->numNeighbors;
    map[s->val] = newNode;

    if (s->numNeighbors > 0) {
        newNode->neighbors = (struct Node**)malloc(s->numNeighbors * sizeof(struct Node*));
        for (int i = 0; i < s->numNeighbors; i++) {
            newNode->neighbors[i] = clone(s->neighbors[i]);
        }
    } else {
        newNode->neighbors = NULL;
    }

    return newNode;
}

struct Node *cloneGraph(struct Node *s) {
    for (int i = 0; i < 101; i++) {
        map[i] = NULL;
    }
    return clone(s);
}
