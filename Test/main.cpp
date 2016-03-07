#include <iostream>
#include <Tree.h>
#include <TreeTest.h>

using namespace std;

int main(int argc, char* argv[])
{
    Tree *t;
    char *fname, *outputfname;
    try
    {
        // argc should be 2 for correct execution
        if ( argc != 3 )
        {
            // We print argv[0] assuming it is the program name
            cout<<"usage: "<< argv[0] <<" <input file name> <output file name>\n"<<endl;
            cout<<"Using default files instead"<<endl;
            fname = "C:\\Users\\532650.ITRI\\Desktop\\Testpit\\samplePTB_eng.txt";
            outputfname = "C:\\Users\\532650.ITRI\\Desktop\\Testpit\\PTB_op.txt";
        }
        else
        {
            // IF THE ARGUMENTS ARE VALID, WE TRY TO CALL THE REQUIRED FUNCTIONS
            // We assume argv[1] is a filename to open
            //cout<<argv[0]<<endl; // To print argument 1
            //cout<<argv[1]<<endl; // To print argument 2
            fname = argv[1];
            outputfname = argv[2];
        }
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    catch (...)
    {
        cout<<"File error"<<endl;
    }


    // UNCOMMENT THIS BLOCK OF CODE IF YOU WANT TO VIEW TREE IMPLEMENTATION
    cout<<"BUILDING TREE FROM FILE:"<<endl;
    cout<<"------------------------\n"<<endl;
    t = t->buildTreeFromFile(fname);
    cout<<"WRITING BACK TREE TO FILE:"<<endl;
    cout<<"------------------------\n"<<endl;
    t->writeTreeToFile(t);

    //return 0;

    // THIS IS FOR UNIT TESTING THE FUNCTIONS
    // COMMENT OUT IF TESTING IS NOT NEEDED
    cout<<"RUNNING THE UNIT TEST MODULES:"<<endl;
    cout<<"------------------------------\n"<<endl;
    //return UnitTest::RunAllTests();
    TreeTest* tt;
    tt->InitTreeFunctionTest(); // 1
    tt->CreateTreeFunctionTest(); // 2
    tt->CreateNewNodeFunctionTest(); // 3
    tt->SetScoreFunctionTest(); // 4
    tt->GetScoreFunctionTest(); // 5
    tt->AddChildFunctionTest(); // 6
    tt->AddLeftChildFunctionTest(); // 7
    tt->AddRightChildFunctionTest(); // 8
    tt->GetNodeParentFunctionTest(); // 9
    tt->IsRootFunctionTest(); // 10
    tt->SetWordFunctionTest(); // 11
    tt->GetWordFunctionTest(); // 12
    tt->GetRootLabelFunctionTest(); // 13
    tt->GetNodeFunctionTest(); // 14
    tt->GetNodeLabelFunctionTest(); // 15
    tt->HasChildrenFunctionTest(); // 16
    tt->IsCommaFunctionTest(); // 17
    tt->IsPeriodFunctionTest(); // 18
    tt->IsEmptyFunctionTest(); // 19
    tt->IsTerminalFunctionTest(); // 20
    tt->GetNodesFunctionTest(); // 21
    tt->IfEqualNodesFunctionTest(); // 22
    tt->ChangeNodeWordFunctionTest(); // 23
    tt->ChangeNodeWordByTargetFunctionTest(); // 24
    tt->ChangeNodeScoreFunctionTest(); // 25
    tt->ChangeNodeScoreByTargetFunctionTest(); // 26
    tt->PostOrderTraversalFunctionTest(); // 27
    tt->PreOrderTraversalFunctionTest(); // 28
    tt->InOrderTraversalFunctionTest(); // 29
    tt->LevelOrderTraversalFunctionTest(); // 30
    tt->IterativePreorderFunctionTest();
    tt->GetNodeParentLabelFunctionTest(); // 31
    tt->GetLeftChildFunctionTest(); // 32
    tt->GetRighttChildFunctionTest(); // 33
    tt->GetNodeSiblingsFunctionTest(); // 34
    tt->GetNodeSiblingLabelsFunctionTest(); // 35
    tt->GetNodeChildrenFunctionTest(); // 36
    tt->IfIdenticalTreesFunctionTest(); // 37
    tt->NumOfLeafNodesFunctionTest(); // 38
    tt->SizeOfTreeFunctionTest(); // 39
    tt->DestroyTreeFunctionTest(); // 40
    tt->GetOriginalRootFunctionTest();
    tt->ExceptionHandlingTests(); // 41

}

