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

// TEST_F(BinarySearchTreeTest, addRightLeft)
// {
//     tree.insert(42);
//     tree.insert(1812);
//     tree.insert(7);
//     EXPECT_EQ(42, tree.remove(42));
//     EXPECT_EQ(1812, tree.remove(1812));
//     EXPECT_EQ(7, tree.remove(7));
// }