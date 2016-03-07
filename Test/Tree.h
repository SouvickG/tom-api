#ifndef TREE_H
#define TREE_H

#include <string>

#define MAXQSIZE 100

struct node
{
  int score; // the score or label of the node
  char word[100]; // the word stored in the node
  node *left; // the pointer to left child of the node
  node *right; // the pointer to right child of the node
  node *parent; // the pointer to parent node
};

class Tree
{
    public:
        Tree(); // Constructor
        virtual ~Tree(); // Destructor

        //Unit tests have been implemented for these methods
        Tree* initTree(); // Initialize an empty tree
        Tree* createTree(); // Create a tree with only the root
        node* createNewNode(int score, const char* word); // Create a new node with the information available
        void setScore(node* targetnode,int score); // sets the score field of the given node
        int getScore(node* targetnode);  // returns the score associated with the node
        node* addChild(struct node* targetnode, node* nodetoadd); // Given the target node, it adds the nodetoadd as one of its child
        node* addLeftChild(node* targetnode, node* child); // Adds left child to the given node
        node* addRightChild(node* targetnode, node* child); // Adds right child to the given node
        node* getNodeParent(node* targetnode); // given a node, it returns the parent of the node
        bool isRoot(Tree *t,node *curnode); // returns if current node is the root of the tree
        void setWord(node* targetnode, const char* word); // sets the word field of the given node
        char* getWord(node* targetnode); // returns the word associated with the node
        int getRootLabel(Tree *t); // returns the label associated with the root of the tree
        node* getNode(Tree *t, char* word); // searches the tree for the word and returns the node
        node* findnode(node *root,char *word);
        int getNodeLabel(Tree *t,char* word); // searches the tree for the word and returns the label of the node if found
        bool hasChildren(node* targetnode); // returns true if the given node has children
        bool isComma(node* targetnode); // returns if the word contained in the given node is a comma
        bool isPeriod(node* targetnode); // returns if the word contained in the given node is a period
        bool isEmpty(node* rootnode); //given the root,returns true if the tree is empty
        bool isTerminal(node* targetnode); // returns true if the given node is a terminal or leaf node
        node* getNodes(Tree *t,char* word); // returns a list of nodes which matches the search for word
        bool ifEqualNodes(node *n1, node *n2); // returns true if two nodes are equal

        Tree* changeNodeWord(Tree *t, const char *oldword, const char *newword);
        Tree* changeNodeScore(Tree *t, int oldscore, int newscore);
        Tree* changeNodeWordByTarget(Tree *t, node *targetnode, const char *word);
        Tree* changeNodeScoreByTarget(Tree *t, node *targetnode, int score);
        void postOrderTreeTraversal(node *rootnode); // given the root, it calls the recursive method
        void postOrderTraversal(node* rootnode); // recursive implementation which prints the list of nodes in post-order

        int getNodeParentLabel(node* targetnode); // returns the label of the parent node
        node* getLeftChild(node* targetnode); //returns the left child of the given node
        node* getRightChild(node* targetnode); //returns the right child of the given node
        node* getNodeSiblings(Tree *t,node* targetnode); //  given a node, it returns the siblings of that node
        int getNodeSiblingLabels(Tree *t, node* targetnode); // given a node, it returns the labels of the siblings of that node
        node* getNodeChildren(Tree *t, node* targetnode); // returns the list of children of the given node

        bool ifIdenticalTrees(node* root1, node* root2); // given the roots of two trees, it returns true if the trees are identical
        int numOfLeafNodes(node* rootnode); // given the root, it returns the number of leaf nodes in the tree

        //Implementation functions
        Tree* buildTreeFromFile(char *filename);
        void appendCharacterToWord(char* s, char c);
        node* getOriginalRoot(Tree *t);
        void writeTreeToFile(Tree *t);



        //No unit tests have been implemented for these methods
        node* findnode_t(node *root,char *word);
        void destroyTree(node* root); // destroys the tree
        Tree* setRoot(Tree *t,node *root);
        node* getRoot(Tree *t); // returns the root of the tree
        void inOrderTreeTraversal(node *rootnode); // given the root, it calls the recursive method
        void preOrderTreeTraversal(node *rootnode); // given the root, it calls the recursive method
        void inOrderTraversal(node* rootnode); // recursive implementation which prints the list of nodes in in-order
        void preOrderTraversal(node* rootnode); // recursive implementation which prints the list of nodes in pre-order


        void iterativePreorder(node *root);
        // Functions for level order traversal
        void levelOrderTraversal(node* rootnode); // given the root, it prints the list of nodes in level-order
        node** createQueue(int *frnt, int *rear); // creates a queue to store the nodes
        void enqueue(node **queue_t, int *rear, node *newnode); // adds nodes to the queue
        node* dequeue(node **queue_t, int *frnt, int *rear); // removes and returns nodes from the queue

        int sizeOfTree(node* rootnode); // given the root, it returns the size of the tree

    protected:
    private:
         node* root;

};

#endif // TREE_H
