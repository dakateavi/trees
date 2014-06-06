#include <gtest/gtest.h>
#include "trees/BinarySearchTree.h"


using trees::BinarySearchTree;

class BinarySearchTreeTest : public testing::Test {
public:
    BinarySearchTree<int> tree;
};

TEST_F(BinarySearchTreeTest, addRemoveSingleton)
{
    tree.insert(42);
    EXPECT_EQ(42, tree.remove(42));
}

TEST_F(BinarySearchTreeTest, addRemoveTwoElements)
{
    tree.insert(42);
    tree.insert(1812);
    EXPECT_EQ(1812, tree.remove(1812));
    EXPECT_EQ(42, tree.remove(42));
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