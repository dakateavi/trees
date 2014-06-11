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
    tree.insert(8);
    tree.insert(20);
    tree.insert(9);
    tree.insert(6);
    tree.insert(5);
    tree.insert(42);
    tree.insert(19);
    auto aux = tree.rootForTest();
    EXPECT_EQ(10, aux->element);
    EXPECT_EQ(8, aux->left->element);
    EXPECT_EQ(20, aux->right->element);;
    EXPECT_EQ(6, aux->left->left->element);
    EXPECT_EQ(5, aux->left->left->left->element);
    EXPECT_EQ(9, aux->left->right->element);
    EXPECT_EQ(19, aux->right->left->element);
    EXPECT_EQ(42, aux->right->right->element);
}

TEST_F(BinarySearchTreeTest, removeNodeWithoutSons)
{
    tree.insert(10);
    tree.insert(8);
    tree.insert(20);
    tree.insert(9);
    tree.insert(6);
    tree.insert(5);
    tree.insert(42);
    tree.insert(19);
    tree.remove(5);
    auto aux = tree.rootForTest();
    EXPECT_EQ(10, aux->element);
    EXPECT_EQ(8, aux->left->element);
    EXPECT_EQ(20, aux->right->element);
    EXPECT_EQ(6, aux->left->left->element);
    EXPECT_EQ(9, aux->left->right->element);
    EXPECT_EQ(19, aux->right->left->element);
    EXPECT_EQ(42, aux->right->right->element);
    EXPECT_FALSE(tree.has(5));
}
TEST_F(BinarySearchTreeTest, removeNodeWithOneSon)
{
    tree.insert(10);
    tree.insert(8);
    tree.insert(20);
    tree.insert(9);
    tree.insert(6);
    tree.insert(5);
    tree.insert(42);
    tree.insert(19);
    tree.remove(6);
    auto aux = tree.rootForTest();
    EXPECT_EQ(10, aux->element);
    EXPECT_EQ(8, aux->left->element);
    EXPECT_EQ(20, aux->right->element);
    EXPECT_EQ(5, aux->left->left->element);
    EXPECT_EQ(9, aux->left->right->element);
    EXPECT_EQ(19, aux->right->left->element);
    EXPECT_EQ(42, aux->right->right->element);
    EXPECT_FALSE(tree.has(6));
}

TEST_F(BinarySearchTreeTest, removeNodeWithTwoSons)
{
    tree.insert(10);
    tree.insert(8);
    tree.insert(20);
    tree.insert(9);
    tree.insert(6);
    tree.insert(5);
    tree.insert(42);
    tree.insert(19);
    tree.remove(8);
    auto aux = tree.rootForTest();
    EXPECT_EQ(10, aux->element);
    EXPECT_EQ(9, aux->left->element);
    EXPECT_EQ(20, aux->right->element);
    EXPECT_EQ(6, aux->left->left->element);
    EXPECT_EQ(5, aux->left->left->left->element);
    EXPECT_EQ(19, aux->right->left->element);
    EXPECT_EQ(42, aux->right->right->element);
    EXPECT_FALSE(tree.has(8));
}
TEST_F(BinarySearchTreeTest, removeNodeWithTwoSonsExtrmeModeAkaRemoveRoot)
{
    tree.insert(10);
    tree.insert(8);
    tree.insert(20);
    tree.insert(9);
    tree.insert(6);
    tree.insert(5);
    tree.insert(42);
    tree.insert(19);
    tree.insert(18);
    tree.remove(10);
    auto aux = tree.rootForTest();
    EXPECT_EQ(18, aux->element);
    EXPECT_EQ(8, aux->left->element);
    EXPECT_EQ(20, aux->right->element);
    EXPECT_EQ(6, aux->left->left->element);
    EXPECT_EQ(5, aux->left->left->left->element);
    EXPECT_EQ(9, aux->left->right->element);
    EXPECT_EQ(19, aux->right->left->element);
    EXPECT_EQ(42, aux->right->right->element);
    EXPECT_FALSE(tree.has(10));
}