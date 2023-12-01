# Implementing bintree in c
Found this exercise online and thought its a good way to learn some c

Your job is to implement a binary search tree, a data structure of connected nodes with a tree shape. Each node has a node identifier (a number), data (payload), and 2 children (left and right). The children are other nodes referenced with a pointer, with the constraint that the left node’s ID is less than the parent node’s ID, and the right node’s ID is larger than the parent node ID. No two nodes will have the same identifier. A node can have less than two children; in that case, one or more of its child pointers can be NULL.
