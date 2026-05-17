#include <iostream>

#include "stack/stack.h"
#include "queue/queue.h"
#include "linked_list/linked_list.h"
#include "bst/bst.h"
#include "graph_traversal/dfs_bfs.h"

int main() {
    std::cout << "=========================\n";
    std::cout << "  cpp-dsa-implementation\n";
    std::cout << "=========================\n\n";

    // ======================
    // STACK DEMO
    // ======================
    std::cout << "[STACK DEMO]\n";
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << "Top: " << s.peek() << "\n";
    std::cout << "Size: " << s.size() << "\n\n";

    // ======================
    // QUEUE DEMO
    // ======================
    std::cout << "[QUEUE DEMO]\n";
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << "Front: " << q.getFront() << "\n";
    std::cout << "Rear: " << q.getRear() << "\n\n";

    // ======================
    // LINKED LIST DEMO
    // ======================
    std::cout << "[LINKED LIST DEMO]\n";
    LinkedList list;
    list.insertFront(10);
    list.insertBack(20);
    list.insertBack(30);
    list.display();
    std::cout << "Size: " << list.size() << "\n\n";

    // ======================
    // BST DEMO
    // ======================
    std::cout << "[BST DEMO]\n";
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(7);

    std::cout << "Inorder (sorted): ";
    tree.inorder();
    std::cout << "Search 7: " << tree.search(7) << "\n\n";

    // ======================
    // BFS_DFS DEMO
    // ======================
    std::cout << "[BFS/DFS DEMO]\n";
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(3, 4);

    std::cout << "DFS: ";
    g.DFS(0);

    std::cout << "BFS: ";
    g.BFS(0);

    return 0;

}