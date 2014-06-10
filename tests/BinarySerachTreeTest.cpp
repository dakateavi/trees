#include <gtest/gtest.h>
#include "trees/BinarySearchTree.h"


using trees::BinarySearchTree;

class BinarySearchTreeTest : public testing::Test {
public:
    BinarySearchTree<int> tree;
};

TEST_F(BinarySearchTreeTest, hasSingleton)
{
    tree.insert(42);
    EXPECT_FALSE(tree.has(-17));
    EXPECT_TRUE(tree.has(42));
}

TEST_F(BinarySearchTreeTest, hasTwoElements)
{
    tree.insert(42);
    tree.insert(1812);
    EXPECT_FALSE(tree.has(7));
    EXPECT_TRUE(tree.has(1812));
    EXPECT_TRUE(tree.has(42));
}

TEST_F(BinarySearchTreeTest, root)
{
    tree.insert(42);
    EXPECT_EQ(42, tree.rootForTest()->element);

}

TEST_F(BinarySearchTreeTest, addRightLeft)
{
    tree.insert(10);
    tree.recursiveInsert(8, tree.rootForTest());
    tree.recursiveInsert(20, tree.rootForTest());
    tree.recursiveInsert(9, tree.rootForTest());
    tree.recursiveInsert(6, tree.rootForTest());
    tree.recursiveInsert(5, tree.rootForTest());
    tree.recursiveInsert(42, tree.rootForTest());
    tree.recursiveInsert(19, tree.rootForTest());
    auto aux = tree.rootForTest();
    EXPECT_EQ(10, aux->element);
    EXPECT_EQ(8, aux->left->element);
    EXPECT_EQ(20, aux->right->element);
    auto aux2 = aux->right;
    aux = aux->left;
    EXPECT_EQ(6, aux->left->element);
    EXPECT_EQ(9, aux->right->element);
    EXPECT_EQ(19, aux2->left->element);
    EXPECT_EQ(42, aux2->right->element);
}