#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <Tree.h>
#include <fstream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

Tree::Tree()
{
    //Constructor
    root = NULL;
}

Tree::~Tree()
{
    //Destructor
    destroyTree(root);
}

void Tree::destroyTree(node* root)
{
    // destroys the tree recursively
    if(root!=NULL)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        root->parent = NULL;
        root->left=NULL;
        root->right=NULL;
        delete root;
    }
}

Tree* Tree::initTree()
{
    // Initialize an empty tree
    Tree *t = new Tree();
    return t;
}

Tree* Tree::createTree()
{
    try
    {
        // Create a tree with only the root
        // The root is a dummy node which does not contain any words
        Tree *t = initTree();
        node *root = createNewNode(0,"Root");
        //cout<<"Setting root(inside CT):"<<root<<endl;
        if(!root)
            throw "The root has not been created properly\n";
        t = t->setRoot(t,root);
        return t;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }

    return NULL;
}

Tree* Tree::setRoot(Tree *t,node *root)
{
    try
    {
        if(t==NULL)
            throw "The tree does not exist";
        if(root==NULL)
            throw "The root is NULL";
        t->root = root;
        //cout<<"Setting root(inside SR):"<<t->root<<endl;
        return t;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    catch (...)
    {
        cout<<"Error setting tree root"<<endl;
    }
    return NULL;
}

node* Tree::getOriginalRoot(Tree *t)
{
    try
    {
        if(t==NULL)
            throw "Tree does not exist";
        //cout<<"Returning root(from GR)"<<t->root<<endl;
        node *dummyroot = t->root;
        if(dummyroot->left)
            return dummyroot->left;
        return NULL;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
}

node* Tree::getRoot(Tree *t)
{
    try
    {
        if(t==NULL)
            throw "Tree is null";
        //cout<<"Returning root(from GR)"<<t->root<<endl;
        node *dummyroot = t->root;
        if(dummyroot)
            return dummyroot;
        return NULL;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
}

node* Tree::createNewNode(int score, const char* word)
{
    // Create a new node with the information available
    node* n = NULL;
    try
    {
        if (score<0)
            throw "Score cannot be negative";
        n = new node;
        n->left=NULL;
        n->right = NULL;
        n->parent = NULL;
        n->score = score;
        strcpy(n->word,word);
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return n;
}

void Tree::setScore(node* targetnode,int score)
{
    try
    {
        // sets the score field of the given node
        if (score<0)
            throw "Score cannot be negative";
        if (targetnode==NULL)
            throw "The target node does not exist";
        targetnode->score = score;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
}

void Tree::setWord(node* targetnode,const char* word)
{
    try
    {
        // sets the word field of the given node
        if (targetnode==NULL)
            throw "The target node does not exist";
        strcpy(targetnode->word,word);
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
}

node* Tree::addChild(struct node* targetnode, node* nodetoadd)
{
    try
    {
        // Given the target node, it adds the nodetoadd as one of its child
        if(targetnode==NULL)
        {
            throw "Error! The parent node does not exist";
            return NULL;
        }
        if (nodetoadd==NULL)
        {
            throw "Error! The node to add is NULL";
            return NULL;
        }
        if (targetnode->left==NULL)
        {
            nodetoadd = addLeftChild(targetnode,nodetoadd);
            return nodetoadd;
        }
        if (targetnode->right == NULL)
        {
            nodetoadd = addRightChild(targetnode,nodetoadd);
            return nodetoadd;
        }
        throw "Error! Already two children exists";
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return nodetoadd;
}

// Adds the new node as the left child of the current node and
// returns a pointer to the child node
node* Tree::addLeftChild(node* targetnode, node* child)
{
    try{
        // Adds left child to the given node
        if (targetnode==NULL)
        {
            throw "(Error)The current(target) node does not exist";
            return NULL;
        }
        if(child==NULL)
        {
            throw "(Error)The child node does not exist";
            return child;
        }
        if (targetnode->left != NULL)
        {
            throw "(Error)There is already a left child";
        }
        targetnode->left = child;
        child->parent = targetnode;
        return child;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return NULL;
}

// Adds the new node as the right child of the current node and
// returns a pointer to the child node
node* Tree::addRightChild(node* targetnode, node* child)
{
    try{
        // Adds right child to the given node
        if (targetnode==NULL)
        {
            throw "(Error)The current(target) node does not exist";
            return NULL;
        }
        if(child==NULL)
        {
            throw "(Error)The child node does not exist";
            return child;
        }
        if (targetnode->right != NULL)
        {
            throw "(Error)There is already a right child";
        }
        targetnode->right = child;
        child->parent = targetnode;
        return child;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return NULL;
}

node* Tree::getNodeParent(node* targetnode)
{
    try
    {
        // given a node, it returns the parent of the node
        if(targetnode==NULL)
        {
            throw "Current node is invalid";
            return NULL;
        }
        if(targetnode->parent)
        {
            //cout<<targetnode->parent->word<<endl;
            return targetnode->parent;
        }
        else
            throw "Parent does not exist";
        return NULL;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return NULL;
}

void Tree::inOrderTreeTraversal(node *rootnode)
{
    try
    {
        if (rootnode==NULL)
            throw "Root node is null. Cannot traverse";
        inOrderTraversal(rootnode);
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
}

void Tree::inOrderTraversal(node* rootnode)
{
    // given the root, it prints the list of nodes in inorder
    if(rootnode!=NULL)
    {
        inOrderTraversal(rootnode->left);
        cout<<"  "<<rootnode->score<<":"<<rootnode->word<<endl;
        inOrderTraversal(rootnode->right);
    }
}

void Tree::preOrderTreeTraversal(node *rootnode)
{
    try
    {
        if (rootnode==NULL)
            throw "Root node is null. Cannot traverse";
        preOrderTraversal(rootnode);
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
}

void Tree::preOrderTraversal(node* rootnode)
{
    if(rootnode!=NULL)
    {
        cout<<"  "<<rootnode->score<<":"<<rootnode->word<<endl;
        preOrderTraversal(rootnode->left);
        preOrderTraversal(rootnode->right);
    }
}

void Tree::postOrderTreeTraversal(node *rootnode)
{
    try
    {
        if (rootnode==NULL)
            throw "Root node is null. Cannot traverse";
        postOrderTraversal(rootnode);
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
}

void Tree::postOrderTraversal(node* rootnode)
{
    // given the root, it prints the list of nodes in inorder
    if(rootnode!=NULL)
    {
        postOrderTraversal(rootnode->left);
        postOrderTraversal(rootnode->right);
        cout<<"  "<<rootnode->score<<":"<<rootnode->word<<endl;
    }
}

int Tree::getScore(node* targetnode)
{
    try
    {
        if(targetnode==NULL)
            throw "Target node does not exist";
        return targetnode->score;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return -1;
}

char* Tree::getWord(node* targetnode)
{
    try
    {
        if(targetnode==NULL)
            throw "Target node does not exist";
        return targetnode->word;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return "NULL";
}

bool Tree::isRoot(Tree *t,node *curnode)
{
    try
    {
        if(t==NULL)
            throw "The tree does not exist";
        if(curnode==NULL)
            throw "Current node does not exist";
        node *root = t->getRoot(t);
        //cout<<curnode<<"---"<<root<<endl;;
        if (curnode==root)
            return true;
        return false;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return false;
}

int Tree::getRootLabel(Tree *t)
{
    try
    {
        if(t==NULL)
            throw "The tree does not exist!";
        node *root = t->getRoot(t);
        if(root)
            return root->score;
        return 0;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return -1;
}

node* Tree::getNode(Tree *t,char* word)
{
    try
    {
        if(t==NULL)
            throw "The tree does not exist";
        if(strcmp(word,"")==0)
            throw "Not valid for empty strings";
        node *root = t->getRoot(t);
        node *targetnode = t->findnode_t(root,word);
        return targetnode;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return NULL;
}

node* Tree::findnode_t(node *root,char *word)
{
    try
    {
        if(root==NULL)
        {
            throw "The root does not exist";
            return NULL;
        }
        if(strcmp(word,"")==0)
            throw "Not valid for empty strings";
        return findnode(root,word);
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return NULL;
}

node* Tree::findnode(node *root,char *word)
{
    if(root==NULL)
    {
        return NULL;
    }
    node *temp, *tempright, *templeft;
    temp = root;
    if(strcmp(temp->word,word)==0)
    {
        return temp;
    }
    templeft = findnode(temp->left,word);
    tempright = findnode(temp->right,word);
    if(templeft)
        return templeft;
    else
        return tempright;
}

int Tree::getNodeLabel(Tree *t,char* word)
{
    try
    {
        if(!t)
            throw "Null tree";
        if(strcmp(word,"")==0)
            throw "Not applicable for null strings";
        node *root= t->getRoot(t);
        if(!root)
        {
            throw "Root does not exist";
            return -1;
        }
        node *targetnode = t->findnode_t(root,word);
        return targetnode->score;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return -1;
}

bool Tree::hasChildren(node* targetnode)
{
    try
    {
        if(targetnode==NULL)
            throw "Not a valid node";
        cout<<"Node:"<<targetnode->score<<" "<<targetnode->word<<endl;
        if (targetnode->left !=NULL)
        {
            cout<<"Has left child"<<endl;
            return true;
        }
        if (targetnode->right !=NULL)
        {
            cout<<"Has right child"<<endl;
            return true;
        }
        return false;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return false;
}

bool Tree::isComma(node* targetnode)
{
    try
    {
        if(targetnode==NULL)
            throw "Target node does not exist";
        if(strcmp(targetnode->word,",")==0)
            return true;
        return false;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return false;
}

bool Tree::isPeriod(node* targetnode)
{
    try
    {
        if(targetnode==NULL)
            throw "Target node does not exist";
        if(strcmp(targetnode->word,".")==0)
            return true;
        return false;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return false;
}

bool Tree::isEmpty(node* rootnode)
{
    try
    {
        // Root is a dummy node
        // So it is unlikely that root will be null
        if(rootnode==NULL)
        {
            throw "Root node is null";
            return true;
        }
        if((rootnode->left==NULL)&&(rootnode->right==NULL))
            return true;
        return false;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return false;
}

bool Tree::isTerminal(node* targetnode)
{
    try
    {
        if(targetnode==NULL)
        {
            throw "The node does not exist";
            return false;
        }
        if((targetnode->left==NULL)&&(targetnode->right==NULL))
        {
            //cout<<"Terminal node"<<endl;
            return true;
        }
        return false;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return false;
}

node* Tree::getNodes(Tree *t,char* word)
{
    try
    {
        if(!t)
            throw "The tree does not exist";
        node *head = NULL, *n=NULL;
        node *root = t->getRoot(t);
        if (root == NULL)
           return head;
        stack<node *> nodeStack;
        nodeStack.push(root);
        while (nodeStack.empty() == false)
        {
            // Pop the top item from stack and print it
            node *temp = nodeStack.top();
            nodeStack.pop();
            if(strcmp(temp->word,word)==0)
            {
                //cout<<"Inside comp"<<endl;
                if(head)
                {
                    n = head;
                    while(n->right!=NULL)
                    {
                        n = n->right;
                    }
                    n->right = temp;
                }
                else
                {
                    //cout<<"Head does not exist"<<endl;
                    head = temp;
                    head->right = NULL;
                }
            }
            // Push right and left children of the popped node to stack
            if (temp->right)
                nodeStack.push(temp->right);
            if (temp->left)
                nodeStack.push(temp->left);
        }
        n = head;

        if(!n)
            throw "Head is null";
        while(n)
        {
            cout<<n->score<<" "<<n->word<<endl;
            n=n->right;
        }
        return head;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return NULL;
}

bool Tree::ifEqualNodes(node *n1, node *n2)
{
    if(n1==NULL && n2==NULL)
        return true;
    if(n1 && !n2)
        return false;
    if(!n1 && n2)
        return false;
    if(n1->left!= n2->left)
        return false;
    if(n1->right!= n2->right)
        return false;
    if(n1->score!= n2->score)
        return false;
    if(n1->parent!= n2->parent)
        return false;
    if(strcmp(n1->word,n2->word)!=0)
        return false;
    return true;
}

Tree* Tree::changeNodeWordByTarget(Tree *t, node *targetnode, const char *word)
{
    try
    {
        if(t==NULL)
            throw "Tree does not exist";
        if(targetnode==NULL)
            throw "Target node does not exist";
        t->setWord(targetnode,word);
        return t;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return NULL;
}

Tree* Tree::changeNodeWord(Tree *t, const char *oldword, const char *newword)
{
    try
    {
        if(t==NULL)
            throw "Tree does not exist";
        node *root = t->getRoot(t);
        stack<node *> nodeStack;
        nodeStack.push(root);
        while (nodeStack.empty() == false)
        {
            // Pop the top item from stack and print it
            node *temp = nodeStack.top();
            nodeStack.pop();
            if(strcmp(temp->word,oldword)==0)
            {
                t->setWord(temp,newword);
            }
            // Push right and left children of the popped node to stack
            if (temp->right)
                nodeStack.push(temp->right);
            if (temp->left)
                nodeStack.push(temp->left);
        }
        return t;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return t;
}

Tree* Tree::changeNodeScoreByTarget(Tree *t, node *targetnode, int score)
{
    try
    {
        if(t==NULL)
            throw "Tree does not exist";
        if(targetnode==NULL)
            throw "Target node does not exist";
        t->setScore(targetnode,score);
        return t;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return t;
}

Tree* Tree::changeNodeScore(Tree *t, int oldscore, int newscore)
{
    try
    {
        if(t==NULL)
            throw "Tree does not exist";
        node *root = t->getRoot(t);
        stack<node *> nodeStack;
        nodeStack.push(root);
        while (nodeStack.empty() == false)
        {
            // Pop the top item from stack and print it
            node *temp = nodeStack.top();
            nodeStack.pop();
            if(temp->score==oldscore)
            {
                t->setScore(temp,newscore);
            }
            // Push right and left children of the popped node to stack
            if (temp->right)
                nodeStack.push(temp->right);
            if (temp->left)
                nodeStack.push(temp->left);
        }
        return t;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return t;
}

// APPENDED FROM IMPLEMENTATION POINT OF VIEW

void Tree::appendCharacterToWord(char* s, char c)
{
    try
    {
        //Appends a character to the end of a character array
        int len = strlen(s); // finds the length of the string
        s[len] = c; // adds the character at the end
        s[len + 1] = '\0'; // adds terminal symbol
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
}

Tree* Tree::buildTreeFromFile(char *fname)
{
    //Tokenizing the text from file
    //Creating the tree object to store the words and the labels
    Tree *t;
    node *currentNode;
    node *parentNode = NULL;
    node *temp = NULL;
    char c;
    int score;
    string line;
    int parencount = 0;
    try
    {
        if (strcmp(fname,"")==0)
            throw "File name cannot be blank";
        char* currentWord = new char[100];
        //Open the file
        ifstream fin;
        string filename = fname;
        // FOR USER INPUT
        //cout << "Please enter a file name to read(The full path without quotes): ";
        //getline( cin, filename );
        //fin.open(filename.c_str()); //"C:\\Users\\532650.ITRI\\Documents\\samplePTB_eng.txt"
        fin.open(filename.c_str());
        strcpy(currentWord,"");
        t = t->createTree();
        node *root = t->getRoot(t);
        currentNode = root;

        //Checking for errors while opening files
        if(!fin.is_open())
        {
            //The file could not be opened
            throw "Unable to open file";
        }
        else
        {
            while(!fin.eof())
            {
                fin.get(c);
                if(c=='(')
                {
                    parencount++;
                    //cout<<"PC:"<<parencount<<endl;
                    strcpy(currentWord,"");
                    if(!fin.eof())
                    {
                        fin.get(c);
                    }
                    score = (int)c - 48;
                    //cout<<"Score:"<<score<<endl;
                    temp = t->createNewNode(score,"");
                    //cout<<"temp score:"<<temp->score<<endl;
                    if(currentNode!=NULL)
                    {
                        //cout<<currentNode->score<<endl;
                        parentNode = currentNode;
                        currentNode = t->addChild(currentNode,temp);//adds child and returns pointer to child node
                        //cout<<"back from iot"<<endl;
                    }
                    else
                    {
                        currentNode = temp;
                    }
                }
                else if (c==')')
                {
                    parencount--;
                    //cout<<"PC:"<<parencount<<endl;
                    if(strcmp(currentWord,"")!=0)
                    {
                        //cout<<"Current Word:"<<currentWord<<endl;
                        t->setWord(currentNode,currentWord);
                        strcpy(currentWord ,"");
                    }

                    if(parencount==0)
                    {
                        //t->inOrderTreeTraversal(root);
                        t->preOrderTreeTraversal(root);
                        //t->postOrderTreeTraversal(root);


                        //cout<<t->destroyTree(root,0);
                        //t->inOrderTraversal(root);
                        //Closing the file after operation
                        fin.close();
                        return t;
                    }
                    if(!t->isRoot(t,currentNode))
                        currentNode = t->getNodeParent(currentNode);
                }
                else if ((c==' ')||(c=='\t'))
                {
                    continue;
                }
                else
                {
                    appendCharacterToWord(currentWord, c);
                }
            }
        }
        //t->Print(root, 0);
        //Closing the file after operation
        fin.close();
        return t;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return t;
}

void Tree::writeTreeToFile(Tree *t)
{
    try
    {
        if(t==NULL)
            throw "The tree is null";
        node *root,*p;
        // writing back the tree to parenthesized format
        ofstream myfile ("C:\\Users\\532650.ITRI\\Desktop\\Testpit\\PTB_op.txt");

        if (!myfile.is_open())
            throw "Unable to open file";
        else
        {
            root = t->getOriginalRoot(t);
            if(!root) return;
             // Create an empty stack and push root to it
            stack<node *> nodeStack;
            nodeStack.push(root);
            while (nodeStack.empty() == false)
            {
                // Pop the top item from stack and print it
                struct node *n = nodeStack.top();
                if(t->getScore(n)!=999)
                {
                    myfile << "(";
                    myfile << t->getScore(n);
                }

                nodeStack.pop();
                //cout<<"Node:"<<n->score<<" "<<n->word<<endl;
                if(t->getScore(n)==999)
                {
                    // to mark every step that involves a move to parent
                    myfile << ")";
                }
                else if(t->isTerminal(n))
                {
                    myfile << " " << t->getWord(n);
                    myfile << ")";
                }
                else
                {
                    p = t->createNewNode(999,")");
                    nodeStack.push(p);
                    // Push right and left children of the popped node to stack
                    if (n->right)
                        nodeStack.push(n->right);
                    if (n->left)
                        nodeStack.push(n->left);
                }
            }
            myfile.close();
        }
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
}

int Tree::getNodeParentLabel(node* targetnode)
{
    try
    {
        if(!targetnode)
        {
            throw "The specified node does not exist";
        }
        node *parentnode = targetnode->parent;
        return parentnode->score;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return -1;
}

node* Tree::getLeftChild(node* targetnode)
{
    try
    {
        if(!targetnode)
        {
            throw "The specified node does not exist";
            return NULL;
        }
        return targetnode->left;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return NULL;
}

node* Tree::getRightChild(node* targetnode)
{
    try
    {
        if(!targetnode)
        {
            throw "The specified node does not exist";
            return NULL;
        }
        return targetnode->right;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return NULL;
}

node* Tree::getNodeSiblings(Tree *t, node* targetnode)
{
    try
    {
        if(t==NULL)
        {
            throw "The tree does not exist";
            return NULL;
        }
        node *head = NULL, *n=NULL;
        if (targetnode == NULL)
        {
            throw "The specified node does not exist";
            return head;
        }
        node *parent = t->getNodeParent(targetnode);
        if (parent==NULL)
        {
            throw "The specified node does not have any parent";
            return NULL;
        }
        if(t->ifEqualNodes(parent->left,targetnode))
            return parent->right;
        if(t->ifEqualNodes(parent->right,targetnode))
            return parent->left;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return NULL;
}

int Tree::getNodeSiblingLabels(Tree *t,node* targetnode)
{
    try
    {
        if(t==NULL)
        {
            throw "The tree cannot be null";
            return -1;
        }
        if(targetnode==NULL)
        {
            throw "The target node cannot be null";
            return -1;
        }
        node *head = t->getNodeSiblings(t,targetnode);
        // returns a pointer to the head of list of nodes
        cout<<"The sibling labels are as follows:"<<endl;
        if(head)
        {
            cout<<head->score<<endl;
            return head->score;
        }
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return -1;
}

node* Tree::getNodeChildren(Tree *t, node* targetnode)
{
    try
    {
        if(t==NULL)
        {
            throw "Tree cannot be NULL";
            return NULL;
        }
        node *head = NULL, *n=NULL, *temp1,*temp2;
        node *root = t->getRoot(t);
        if (targetnode == NULL)
        {
            throw "The specified node does not exist";
            return head;
        }
        if(targetnode->left)
        {
            temp1 = targetnode->left;
            head = temp1;
        }
        if(targetnode->right)
        {
            temp2 = targetnode->right;
            if (head)
            {
                head->right = temp2;
            }
            else
            {
                head = temp2;
            }
        }
        //Checking the output
        n = head;
        while(n)
        {
            cout<<n->score<<" "<<n->word<<endl;
            n=n->right;
        }
        return head;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return NULL;
}


// Given a binary tree, print its nodes in level order
// using array for implementing queue
void Tree::levelOrderTraversal(node* root)
{
    try
    {
        if(root==NULL)
            throw "The root does not exist";
        int rear,frnt;
        Tree *t;
        node **queue_t = t->createQueue(&frnt, &rear);
        node *temp = root;
        while(temp)
        {
            cout<<temp->score<<" "<<temp->word<<endl;
            //Enqueue left child
            if(temp->left)
                t->enqueue(queue_t,&rear,temp->left);
            //Enqueue right child
            if(temp->right)
                t->enqueue(queue_t,&rear,temp->right);
            //Dequeue node and make it temp
            temp = t->dequeue(queue_t,&frnt,&rear);
        }
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
}

node** Tree::createQueue(int *frnt, int *rear)
{
    node **queue_t;
    queue_t = new node*[MAXQSIZE];
    *frnt = *rear = 0;
    return queue_t;
}

void Tree::enqueue(node **queue_t, int *rear, node *newnode)
{
    queue_t[*rear] = newnode;
    (*rear)++;
}

node* Tree::dequeue(node **queue_t, int *frnt, int *rear)
{
    if(*frnt>=*rear)
    {
        return NULL;
    }
    (*frnt)++;
    return queue_t[*frnt - 1];
}


// An iterative process to print preorder traversal of Binary tree
void Tree::iterativePreorder(node *root)
{
    try
    {
        // Base Case
        if (root == NULL)
        {
            throw "Root does not exist";
            return;
        }
        // Create an empty stack and push root to it
        stack<node *> nodeStack;
        nodeStack.push(root);
        while (nodeStack.empty() == false)
        {
            // Pop the top item from stack and print it
            node *tos = nodeStack.top();
            cout<<tos->score<<" "<<tos->word<<endl;
            nodeStack.pop();
            // Push right and left children of the popped node to stack
            if (tos->right)
                nodeStack.push(tos->right);
            if (tos->left)
                nodeStack.push(tos->left);
        }
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
}


// Given two trees, return true if they are structurally identical
bool Tree::ifIdenticalTrees(node* a, node* b)
{
    // Both are empty trees
    if (a==NULL && b==NULL)
        return true;
    //Both trees are non-empty
    if (a!=NULL && b!=NULL)
    {
        if(a->score == b->score && (strcmp(a->word,b->word)==0) && ifIdenticalTrees(a->left, b->left) && ifIdenticalTrees(a->right, b->right))
            return true;
    }
    // one empty tree, the other non-empty
    return false;
}

// Count the number of leaf nodes in the binary tree
int Tree::numOfLeafNodes(node* root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right==NULL)
    {
        cout<<root->score<<root->word<<endl;
        return 1;
    }
    else
        return numOfLeafNodes(root->left)+ numOfLeafNodes(root->right);
}

// Computes the number of nodes in a tree
int Tree::sizeOfTree(node* root)
{
  if (root==NULL)
    return 0;
  else
    return(sizeOfTree(root->left) + 1 + sizeOfTree(root->right));
}
