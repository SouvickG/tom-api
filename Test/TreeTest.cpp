#include "TreeTest.h"
#include "Tree.h"
#include <cstring>
#include <iostream>

using namespace std;

char *filename = "C:\\Users\\532650.ITRI\\Desktop\\Test\\samplePTB_eng.txt";
int count = 0;

TreeTest::TreeTest()
{
    //ctor
}

TreeTest::~TreeTest()
{
    //dtor
}

// Unit test for function InitTree
void TreeTest::InitTreeFunctionTest()
{
    Tree *t;
    bool result = false;
    Tree* tr = t->initTree(); // the function should return a null
    node *tn = tr->getRoot(tr);
    if(tn == NULL)
    {
        result = true;
    }
    if (result==true)
    {
        cout<< "1) InitTreeFunction passed successfully\n"<<endl;
        count++;
    }
}

// Unit test for function CreateTree
void TreeTest::CreateTreeFunctionTest()
{
    Tree *t;
    bool result = false;
    t = t->createTree();
    node* tn = t->getRoot(t);
    if(tn)
    {
        if ((tn->score == 0) && (strcmp(tn->word,"Root")==0))
            result = true;
    }
    if (result==true)
    {
        cout<< "2) CreateTreeFunction passed successfully\n"<<endl;
        count++;
    }
}

// Unit Test for function CreateNewNode
void TreeTest::CreateNewNodeFunctionTest()
{
    Tree *t;
    bool result = true;
    node *newnode = t->createNewNode(100,"Test");
    if (newnode->score != 100)
        result = false;
    if (strcmp(newnode->word,"Test")!=0)
        result = false;
    if (newnode->left != NULL)
        result = false;
    if (newnode->right != NULL)
        result = false;
    if (newnode->parent != NULL)
        result = false;
    if (result==true)
    {
        cout<< "3) CreateNewNodeFunction passed successfully\n"<<endl;
        count++;
    }
}

//Unit test for the function SetScore
void TreeTest::SetScoreFunctionTest()
{
    Tree *t;
    bool result = false;
    node *tn;
    t->setScore(tn,500);
    if (tn->score == 500)
        result = true;
    if (result==true)
    {
        cout<< "4) SetScoreFunction passed successfully\n"<<endl;
        count++;
    }
}

//Unit test for the function GetScore
void TreeTest::GetScoreFunctionTest()
{
    Tree *t;
    bool result = false;
    node *tn;
    t->setScore(tn,500);
    if (t->getScore(tn) == 500)
        result = true;
    if (result==true)
    {
        cout<< "5) GetScoreFunction passed successfully\n"<<endl;
        count++;
    }
}

//Unit test for the function AddChild
void TreeTest::AddChildFunctionTest()
{
    Tree *t;
    bool result = false;
    node *tn = t->createNewNode(100,"Parent");
    node *nodetoadd = t->createNewNode(100,"Child");
    nodetoadd = t->addChild(tn,nodetoadd);
    // addchild function returns a pointer to the child node
    if(nodetoadd->parent == tn)
        result = true;
    if (result==true)
    {
        cout<< "6) AddChildFunction passed successfully\n"<<endl;
        count++;
    }
}

//Unit test for the function AddLeftChild
void TreeTest::AddLeftChildFunctionTest()
{
    Tree *t;
    bool result = false;
    node *tn = t->createNewNode(100,"Parent");
    node *nodetoadd = t->createNewNode(100,"Child");
    nodetoadd = t->addLeftChild(tn,nodetoadd);
    // addleftchild function returns a pointer to the child node
    if((nodetoadd->parent == tn) && (tn->left==nodetoadd))
        result = true;
    if (result==true)
    {
        cout<< "7) AddLeftChildFunction passed successfully\n"<<endl;
        count++;
    }
}

//Unit test for the function AddLeftChild
void TreeTest::AddRightChildFunctionTest()
{
    Tree *t;
    bool result = false;
    node *tn = t->createNewNode(100,"Parent");
    node *nodetoadd = t->createNewNode(100,"Child");
    nodetoadd = t->addRightChild(tn,nodetoadd);
    // addleftchild function returns a pointer to the child node
    if((nodetoadd->parent == tn) && (tn->right==nodetoadd))
        result = true;
    if (result==true)
    {
        cout<< "8) AddRightChildFunction passed successfully\n"<<endl;
        count++;
    }
}

//Unit test for the function AddLeftChild
void TreeTest::GetNodeParentFunctionTest()
{
    Tree *t;
    bool result = false;
    node *tn = t->createNewNode(100,"Parent");
    node *child = t->createNewNode(100,"Child");
    child = t->addChild(tn,child);
    // addchild function returns a pointer to the child node
    node *parent = t->getNodeParent(child);
    if(parent == tn)
        result = true;
    if (result==true)
    {
        cout<< "9) GetNodeParentFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::IsRootFunctionTest()
{
    //cout<<"Testing function ifRoot-->"<<endl;
    Tree *t = t->initTree();
    bool result = false;
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    node *node1 = t->createNewNode(100,"node1");
    node *node2 = t->createNewNode(100,"node2");
    node1 = t->addChild(treeroot,node1);
    node2 = t->addChild(treeroot,node2);
    //addchild function returns a pointer to the child node
    bool ifnode1isroot = t->isRoot(t,node1);
    bool ifnode2isroot = t->isRoot(t,node2);
    bool ifrootisroot = t->isRoot(t,treeroot);
    if(!ifnode1isroot && !ifnode2isroot && ifrootisroot)
        result = true;
    if (result==true)
    {
        count++;
        cout<< "10) IsRootFunction passed successfully\n"<<endl;
    }
}

void TreeTest::SetWordFunctionTest()
{
    bool result = false;
    Tree *t = t->initTree();
    t = t->createTree();
    node *node1 = t->createNewNode(100,"");
    t->setWord(node1,"node1");
    if (strcmp(node1->word,"node1")==0)
        result = true;
    if (result==true)
    {
        cout<< "11) SetWordFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::GetWordFunctionTest()
{
    bool result = false;
    Tree *t = t->initTree();
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    node *node1 = t->createNewNode(100,"node1");
    node1 = t->addChild(treeroot,node1);
    //addchild function returns a pointer to the child node
    char *word1 = t->getWord(node1);
    char *rootword = t->getWord(treeroot);
    if(strcmp(word1,t->getWord(node1))==0 && strcmp(rootword,t->getWord(treeroot))==0)
        result = true;
    if (result==true)
    {
        cout<< "12) GetWordFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::GetRootLabelFunctionTest()
{
    bool result = false;
    Tree *t = t->initTree();
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    int obtainedscore = t->getRootLabel(t);
    if(obtainedscore == treeroot->score)
    {
        result = true;
    }
    if (result==true)
    {
        cout<< "13) GetRootLabelFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::GetNodeFunctionTest()
{
    bool result = false;
    Tree *t;
    t = t->buildTreeFromFile(filename);
    node *temp = t->getNode(t,"ZA");
    if((temp->score==2) && (strcmp(temp->word,"ZA")==0))
    {
        result = true;
    }
    if (result==true)
    {
        cout<< "14) GetNodeFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::GetNodeLabelFunctionTest()
{
    bool result = false;
    Tree *t;
    t = t->buildTreeFromFile(filename);
    int temp = t->getNodeLabel(t,"ZA");
    if(temp==2)
    {
        result = true;
    }
    if (result==true)
    {
        cout<< "15) GetNodeLabelFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::HasChildrenFunctionTest()
{
    Tree *t;
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    bool result = false;
    node *tn = t->createNewNode(100,"Parent");
    tn = t->addChild(treeroot,tn);
    node *child = t->createNewNode(100,"Child");
    child = t->addChild(tn,child);
    bool parenthaschild = t->hasChildren(tn);
    bool childhaschild = t->hasChildren(child);
    if (parenthaschild && !childhaschild)
        result = true;
    if (result==true)
    {
        cout<< "16) HasChildrenFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::IsCommaFunctionTest()
{
    Tree *t;
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    bool result = false;
    node *node1 = t->createNewNode(100,"Node1");
    node1 = t->addChild(treeroot,node1);
    node *node2 = t->createNewNode(200,"Node2");
    node2 = t->addChild(treeroot,node2);
    node *node3 = t->createNewNode(300,",");
    node3 = t->addChild(node1,node3);
    if(t->isComma(node3))
        result = true;
    if (result==true)
    {
        cout<< "17) IsCommaFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::IsPeriodFunctionTest()
{
    Tree *t;
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    bool result = false;
    node *node1 = t->createNewNode(100,"Node1");
    node1 = t->addChild(treeroot,node1);
    node *node2 = t->createNewNode(200,"Node2");
    node2 = t->addChild(treeroot,node2);
    node *node3 = t->createNewNode(300,".");
    node3 = t->addChild(node1,node3);
    if(t->isPeriod(node3))
        result = true;
    if (result==true)
    {
        cout<< "18) IsPeriodFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::IsEmptyFunctionTest()
{
    Tree *t;
    bool result = false;
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    cout<<treeroot->score<<" "<<treeroot->word<<endl;
    if(t->isEmpty(treeroot))
        result = true;
    if (result==true)
    {
        cout<< "19) IsEmptyFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::IsTerminalFunctionTest()
{
    Tree *t;
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    bool result = false;
    node *tn = t->createNewNode(100,"Parent");
    tn = t->addChild(treeroot,tn);
    node *child = t->createNewNode(100,"Child");
    child = t->addChild(tn,child);
    bool isparentterminal = t->isTerminal(tn);
    bool ischildterminal = t->isTerminal(child);
    if (!isparentterminal && ischildterminal)
        result = true;
    if (result==true)
    {
        cout<< "20) IsTerminalFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::GetNodesFunctionTest()
{
    bool result = false;
    Tree *t;
    t = t->buildTreeFromFile(filename);
    node *head = t->getNodes(t,"EF");
    while(head!=NULL)
    {
        if(strcmp(head->word,"EF")==0)
        {
            //cout<<"Here"<<endl;
            head = head->right;
            result = true;
        }
        else
        {
            result = false;
            break;
        }
    }
    if (result==true)
    {
        cout<< "21) GetNodesFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::IfEqualNodesFunctionTest()
{
    Tree *t = t->initTree();
    bool result = false;
    t = t->createTree();
    node *node1 = t->createNewNode(100,"node1");
    node *node2 = t->createNewNode(100,"node1");
    node *node3 = t->createNewNode(300,"node3");
    if(t->ifEqualNodes(node1,node2))
    {
        result = true;
    }
    if(t->ifEqualNodes(NULL,NULL)==false)
    {
        result = false;
    }
    if(t->ifEqualNodes(NULL,node2))
    {
        result = false;
    }
    if(t->ifEqualNodes(node1,NULL))
    {
        result = false;
    }
    if (result==true)
    {
        cout<< "22) IfEqualNodesFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::ChangeNodeWordFunctionTest()
{
    Tree *t;
    t = t->buildTreeFromFile(filename);//"C:\\Users\\Souvick\\Desktop\\Testpit\\samplePTB_eng.txt"
    t = t->changeNodeWord(t,"EF","SG");
    cout<<"The new tree:"<<endl;
    cout<<"--------------------"<<endl;
    t->preOrderTreeTraversal(t->getRoot(t));
    cout<< "23) ChangeNodeWordFunction tested\n"<<endl;
    count++;
}

void TreeTest::ChangeNodeWordByTargetFunctionTest()
{
    Tree *t = t->initTree();
    bool result = false;
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    node *node1 = t->createNewNode(100,"node1");
    node *node2 = t->createNewNode(100,"node2");
    node1 = t->addChild(treeroot,node1);
    node2 = t->addChild(treeroot,node2);
    t = t->changeNodeWordByTarget(t,node2,"node3");
    t->inOrderTreeTraversal(treeroot);
    if(strcmp(t->getWord(node2),"node3")==0)
    {
        result = true;
    }
    if (result==true)
    {
        cout<< "24) ChangeNodeWordByTargetFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::ChangeNodeScoreFunctionTest()
{
    Tree *t;
    t = t->buildTreeFromFile(filename);//"C:\\Users\\Souvick\\Desktop\\Testpit\\samplePTB_eng.txt"
    t = t->changeNodeScore(t,2,4);
    cout<<"The new tree:"<<endl;
    cout<<"--------------------"<<endl;
    t->preOrderTreeTraversal(t->getRoot(t));
    cout<< "25) ChangeNodeScoreFunction tested\n"<<endl;
    count++;
}

void TreeTest::ChangeNodeScoreByTargetFunctionTest()
{
    Tree *t = t->initTree();
    bool result = false;
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    node *node1 = t->createNewNode(100,"node1");
    node *node2 = t->createNewNode(200,"node2");
    node1 = t->addChild(treeroot,node1);
    node2 = t->addChild(treeroot,node2);
    t = t->changeNodeScoreByTarget(t,node2,500);
    t->inOrderTreeTraversal(treeroot);
    if(t->getScore(node2)==500)
    {
        result = true;
    }
    if (result==true)
    {
        cout<< "26) ChangeNodeScoreByTargetFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::PostOrderTraversalFunctionTest()
{
    Tree *t;
    t = t->buildTreeFromFile(filename);
    node *root = t->getRoot(t);
    if(root)
        t->postOrderTraversal(root);
    cout<< "27)Post-orderTraversal function tested\n"<<endl;
    count++;
}

void TreeTest::PreOrderTraversalFunctionTest()
{
    Tree *t;
    t = t->buildTreeFromFile(filename);
    node *root = t->getRoot(t);
    if(root)
        t->preOrderTraversal(root);
    cout<< "28)Pre-order Traversal function tested\n"<<endl;
    count++;
}

void TreeTest::InOrderTraversalFunctionTest()
{
    Tree *t;
    t = t->buildTreeFromFile(filename);
    node *root = t->getRoot(t);
    if(root)
        t->inOrderTraversal(root);
    cout<< "29)In-order Traversal function tested\n"<<endl;
    count++;
}

void TreeTest::LevelOrderTraversalFunctionTest()
{
    Tree *t;
    t = t->buildTreeFromFile(filename);
    cout<<"Arranged in Level order:"<<endl;
    node *root = t->getRoot(t);
    if(root)
        t->levelOrderTraversal(root);
    cout<< "30)Level-order Traversal function tested\n"<<endl;
    count++;
}

void TreeTest::IterativePreorderFunctionTest()
{
    Tree *t;
    t = t->buildTreeFromFile(filename);
    cout<<"Arranged in preorder order:"<<endl;
    node *root = t->getRoot(t);
    if(root)
        t->iterativePreorder(root);
    cout<< "31)Iterative pre-order function tested\n"<<endl;
    count++;
}


// Works only when the labels are unique
// Otherwise it is difficult to determine the correctness of the label
void TreeTest::GetNodeParentLabelFunctionTest()
{
    bool result = false;
    Tree *t;
    t = t->buildTreeFromFile(filename);
    node* targetnode = t->getNode(t,"ZA");
    int temp = t->getNodeParentLabel(targetnode);
    if(temp==2)
    {
        result = true;
    }
    if (result==true)
    {
        cout<< "32) GetNodeParentLabelFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::GetLeftChildFunctionTest()
{
    Tree *t = t->initTree();
    bool result = false;
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    node *node1 = t->createNewNode(100,"node1");
    node *node2 = t->createNewNode(200,"node2");
    node1 = t->addChild(treeroot,node1);
    node2 = t->addChild(treeroot,node2);
    //addchild function returns a pointer to the child node
    node *testnode = t->getLeftChild(treeroot);
    if((testnode->score == 100) && (strcmp(testnode->word,"node1")==0))
        result = true;
    if (result==true)
    {
        cout<< "33) GetLeftChildFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::GetRighttChildFunctionTest()
{
    Tree *t = t->initTree();
    bool result = false;
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    node *node1 = t->createNewNode(100,"node1");
    node *node2 = t->createNewNode(200,"node2");
    node1 = t->addChild(treeroot,node1);
    node2 = t->addChild(treeroot,node2);
    //addchild function returns a pointer to the child node
    node *testnode = t->getRightChild(treeroot);
    if((testnode->score == 200) && (strcmp(testnode->word,"node2")==0))
        result = true;
    if (result==true)
    {
        cout<< "34) GetRighttChildFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::GetNodeSiblingsFunctionTest()
{
    Tree *t = t->initTree();
    bool result = false;
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    node *node1 = t->createNewNode(100,"node1");
    node *node2 = t->createNewNode(200,"node2");
    node1 = t->addChild(treeroot,node1);
    node2 = t->addChild(treeroot,node2);
    //addchild function returns a pointer to the child node
    node *testnode = t->getNodeSiblings(t,node1);
    if(t->ifEqualNodes(testnode,node2))
    {
        result = true;
    }
    if (result==true)
    {
        cout<< "35) GetNodeSiblingsFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::GetNodeSiblingLabelsFunctionTest()
{
    Tree *t3 = t3->initTree();
    bool result = false;
    t3 = t3->createTree();
    node *treeroot = t3->getRoot(t3);
    node *node1 = t3->createNewNode(100,"node1");
    node *node2 = t3->createNewNode(200,"node2");
    node1 = t3->addChild(treeroot,node1);
    node2 = t3->addChild(treeroot,node2);
    //addchild function returns a pointer to the child node
    int testlabel = t3->getNodeSiblingLabels(t3,node1);
    //cout<<"Testlabel:"<<testlabel<<endl;
    if(testlabel == 200)
    {
        result = true;
    }
    if (result==true)
    {
        cout<< "36) GetNodeSiblingLabelsFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::GetNodeChildrenFunctionTest()
{
    Tree *t = t->initTree();
    bool result = false;
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    node *node1 = t->createNewNode(100,"node1");
    node *node2 = t->createNewNode(200,"node2");
    node1 = t->addChild(treeroot,node1);
    node2 = t->addChild(treeroot,node2);
    node *head = t->getNodeChildren(t,treeroot);
    if((head=node1) && (head->right==node2))
    {
        result = true;
    }
    if (result==true)
    {
        cout<< "37) GetNodeChildrenFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::IfIdenticalTreesFunctionTest()
{
    char *file2 = "C:\\Users\\532650.ITRI\\Desktop\\Test\\samplePTB_eng2.txt";
    bool result = false;
    Tree *t1, *t2, *t3;
    node *r1, *r2, *r3;
    cout<<"TREE 1"<<endl;
    t1 = t1->buildTreeFromFile(filename);
    cout<< "\nTREE 2" <<endl;
    r1 = t1->getRoot(t1);
    t2 = t2->buildTreeFromFile(filename);
    cout<< "\nTREE 3" <<endl;
    r2 = t2->getRoot(t2);
    t3 = t3->buildTreeFromFile(file2);
    cout<<endl;
    r3 = t3->getRoot(t3);
    //cout<<"T1:"<<t1->ifIdenticalTrees(r1,r2)<<endl;
    //cout<<"T2:"<<t1->ifIdenticalTrees(r1,r3)<<endl;
    if(t1->ifIdenticalTrees(r1,r2) && !(t1->ifIdenticalTrees(r1,r3)))
    {
        result = true;
    }
    if (result==true)
    {
        cout<< "38) IdenticalTreesFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::NumOfLeafNodesFunctionTest()
{
    Tree *t;
    node *root;
    int num;
    bool result = false;
    t = t->buildTreeFromFile(filename);
    root = t->getRoot(t);
    cout<<"\nLeaf Nodes:"<<endl;
    num = t->numOfLeafNodes(root);
    cout<<"\nNumber of leaf nodes:"<<num<<endl;
    if(num==23)
        result = true;
    if(result == true)
    {
        cout<< "39) NumOfLeafNodesFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::SizeOfTreeFunctionTest()
{
    Tree *t;
    node *root;
    int sizeoftree;
    bool result = false;
    t = t->buildTreeFromFile(filename);
    root = t->getRoot(t);
    sizeoftree = t->sizeOfTree(root);
    cout<<"\nSize of tree:"<<sizeoftree<<endl;
    if(sizeoftree==46)
        result = true;
    if(result == true)
    {
        cout<< "40) SizeOfTreeFunction passed successfully\n"<<endl;
        count++;
    }
}

void TreeTest::DestroyTreeFunctionTest()
{
    Tree *t;
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    bool result = false;
    node *node1 = t->createNewNode(100,"Node1");
    node1 = t->addChild(treeroot,node1);
    node *node2 = t->createNewNode(200,"Node2");
    node2 = t->addChild(treeroot,node2);
    node *node3 = t->createNewNode(300,".");
    node3 = t->addChild(node1,node3);
    t->destroyTree(treeroot);
    if(treeroot)
        t->inOrderTraversal(treeroot);
    cout<< "41) DestroyTreeFunction tested\n"<<endl;
    count++;
}

void TreeTest::GetOriginalRootFunctionTest()
{
    Tree *t;
    bool result = false;
    t = t->buildTreeFromFile(filename);
    node *root = t->getOriginalRoot(t);
    //cout<<root->score<<":"<<root->word<<endl;
    if(root)
        if(root->score==1 && strcmp(root->word,"")==0)
            result = true;
    if(result == true)
    {
        cout<< "42) GetOriginalRootFunction passed successfully\n"<<endl;
        count++;
    }
}


void TreeTest::ExceptionHandlingTests()
{
    cout<<"TESTING EXCEPTION HANDLING OF VARIOUS FUNCTIONS"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    Tree *t1, *t;
    node *root;
    // Checking SetRoot
    cout<<"\nChecking SetRoot:"<<endl;
    t1->setRoot(NULL,root);
    t1->setRoot(t,NULL);
    // Checking CreateNode
    cout<<"\nChecking CreateNode:"<<endl;
    t1->createNewNode(-1,"impossible");
    // Checking SetScore
    cout<<"\nChecking SetScore:"<<endl;
    t1->setScore(root,-1);
    // Checking SetWord
    cout<<"\nChecking SetWord:"<<endl;
    t1->setWord(NULL,"root");
    // Checking AddChild
    cout<<"\nChecking AddChild:"<<endl;
    t = t->createTree();
    node *treeroot = t->getRoot(t);
    node *node1 = t->createNewNode(1,"Node1");
    t->addChild(NULL,node1);
    node *node2 = t->createNewNode(2,"Node2");
    node *node3 = t->createNewNode(3,"Node3");
    t->addChild(treeroot,node1);
    t->addChild(treeroot,node2);
    t->addChild(treeroot,node3);
    t->addChild(treeroot,NULL);
    // Checking AddLeftChild
    cout<<"\nChecking AddLeftChild:"<<endl;
    t->addLeftChild(node1,NULL);
    t->addLeftChild(NULL,node2);
    t->addLeftChild(root,node3);
    // Checking AddRightChild
    cout<<"\nChecking AddRightChild:"<<endl;
    t->addRightChild(node1,NULL);
    t->addRightChild(NULL,node2);
    t->addRightChild(root,node3);
    // Checking GetNodeParent
    cout<<"\nChecking GetNodeParent:"<<endl;
    t->getNodeParent(NULL);
    t->getNodeParent(treeroot);
    //Traversals
    cout<<"\nChecking Traversals:"<<endl;
    t->inOrderTreeTraversal(NULL);
    t->preOrderTreeTraversal(NULL);
    t->postOrderTreeTraversal(NULL);
    // Checking GetScore
    cout<<"\nChecking GetScore:"<<endl;
    t->getScore(NULL);
    // Checking GetWord
    cout<<"\nChecking GetWord:"<<endl;
    t->getWord(NULL);
    // Checking IsRoot
    cout<<"\nChecking IsRoot:"<<endl;
    t->isRoot(NULL,node1);
    t->isRoot(t,NULL);
    // Checking GetRootLabel
    cout<<"\nChecking GetRootLabel:"<<endl;
    t->getRootLabel(NULL);
    // Checking GetNode
    cout<<"\nChecking GetNode:"<<endl;
    t->getNode(NULL,"AB");
    t->getNode(t,"");
    // Checking FindNode
    cout<<"\nChecking FindNode:"<<endl;
    t->findnode_t(treeroot,"");
    t->findnode_t(NULL,"AB");
    // Checking GetNodeLabel
    cout<<"\nChecking GetNodeLabel:"<<endl;
    t->getNodeLabel(NULL,"AB");
    t->getNodeLabel(t,"");
    // Checking HasChildren
    cout<<"\nChecking HasChildren:"<<endl;
    t->hasChildren(NULL);
    // Checking IsComma
    cout<<"\nChecking IsComma:"<<endl;
    t->isComma(NULL);
    // Checking IsPeriod
    cout<<"\nChecking IsPeriod:"<<endl;
    t->isPeriod(NULL);
    // Checking IsEmpty
    cout<<"\nChecking IsEmpty:"<<endl;
    t->isEmpty(NULL);
    // Checking IsTerminal
    cout<<"\nChecking IsTerminal:"<<endl;
    t->isTerminal(NULL);
    // Checking GetNodes
    cout<<"\nChecking GetNodes:"<<endl;
    t->getNodes(NULL,"EF");
    // Checking GetNodeParentLabel
    cout<<"\nChecking GetNodeParentLabel:"<<endl;
    t->getNodeParentLabel(NULL);
    // Checking GetLeftChild
    cout<<"\nChecking GetLeftChild:"<<endl;
    t->getLeftChild(NULL);
    // Checking GetRightChild
    cout<<"\nChecking GetRightChild:"<<endl;
    t->getRightChild(NULL);
    // Checking GetNodeSiblings
    cout<<"\nChecking GetNodeSiblings:"<<endl;
    Tree *t2;
    t2 = t2->createTree();
    node *treeroot1 = t2->getRoot(t2);
    node *node4 = t2->createNewNode(4,"Node4");
    t2->addChild(treeroot1,node4);
    node *node5 = t2->createNewNode(5,"Node5");
    t2->addChild(treeroot1,node4);
    t2->getNodeSiblings(NULL,node5);
    t2->getNodeSiblings(t2,NULL);
    // Checking GetNodeSiblings
    cout<<"\nChecking GetNodeChildren:"<<endl;
    t2->getNodeChildren(t2,NULL);
    t2->getNodeChildren(NULL,treeroot1);
    // Checking GetNodeSiblingsLabels
    cout<<"\nChecking GetNodeSiblingsLabels:"<<endl;
    t2->getNodeSiblingLabels(t2,NULL);
    t2->getNodeSiblingLabels(NULL,treeroot1);
    // Checking the implementation functions
    cout<<"\nChecking LevelOrderTraversal:"<<endl;
    t->levelOrderTraversal(NULL);
    cout<<"\nChecking IterativePreOrder:"<<endl;
    t->iterativePreorder(NULL);
    cout<<"\nChecking GetRoot:"<<endl;
    t->getRoot(NULL);
    cout<<"\nChecking GetOriginalRoot:"<<endl;
    t->getOriginalRoot(NULL);
    cout<<"\nChecking ChangeNodeWordByTarget:"<<endl;
    t->changeNodeWordByTarget(NULL,node1,"n1");
    t->changeNodeWordByTarget(t,NULL,"n1");
    cout<<"\nChecking ChangeNodeScoreByTarget:"<<endl;
    t->changeNodeScoreByTarget(NULL,node1,10);
    t->changeNodeScoreByTarget(t,NULL,10);
    cout<<"\nChecking ChangeNodeWord:"<<endl;
    t->changeNodeWord(NULL,"AB","ZA");
    cout<<"\nChecking ChangeNodeScore:"<<endl;
    t->changeNodeScore(NULL,100,200);
    cout<<"\nChecking BuildTreeFromFile:"<<endl;
    t->buildTreeFromFile("");
    cout<<"\nChecking WriteTreeToFile:"<<endl;
    t->writeTreeToFile(NULL);
    cout<<"\n\nFunctions tested: "<< count << endl;
}





