#ifndef TREETEST_H
#define TREETEST_H


class TreeTest
{
    public:
        TreeTest();
        virtual ~TreeTest();
        void InitTreeFunctionTest();
        void CreateTreeFunctionTest();
        void CreateNewNodeFunctionTest();//
        void SetScoreFunctionTest();//
        void GetScoreFunctionTest();//
        void AddChildFunctionTest();//
        void AddLeftChildFunctionTest();//
        void AddRightChildFunctionTest();//
        void GetNodeParentFunctionTest();//
        void IsRootFunctionTest();//
        void SetWordFunctionTest();//
        void GetWordFunctionTest();//
        void GetRootLabelFunctionTest();//
        void GetNodeFunctionTest();//
        void GetNodeLabelFunctionTest();//
        void HasChildrenFunctionTest();//
        void IsCommaFunctionTest();//
        void IsPeriodFunctionTest();//
        void IsEmptyFunctionTest();//
        void IsTerminalFunctionTest();//
        void GetNodesFunctionTest();//
        void IfEqualNodesFunctionTest();
        void ChangeNodeWordFunctionTest();
        void ChangeNodeWordByTargetFunctionTest();
        void ChangeNodeScoreFunctionTest();
        void ChangeNodeScoreByTargetFunctionTest();
        void PostOrderTraversalFunctionTest();//
        void PreOrderTraversalFunctionTest();//
        void InOrderTraversalFunctionTest();//
        void LevelOrderTraversalFunctionTest();
        void IterativePreorderFunctionTest();
        void GetNodeParentLabelFunctionTest();//
        void GetLeftChildFunctionTest();//
        void GetRighttChildFunctionTest();//
        void GetNodeSiblingsFunctionTest();//
        void GetNodeSiblingLabelsFunctionTest();//
        void GetNodeChildrenFunctionTest();//
        void IfIdenticalTreesFunctionTest();
        void NumOfLeafNodesFunctionTest();
        void SizeOfTreeFunctionTest();
        void DestroyTreeFunctionTest();
        void GetOriginalRootFunctionTest();
        void ExceptionHandlingTests();


    protected:
    private:
};

#endif // TREETEST_H
