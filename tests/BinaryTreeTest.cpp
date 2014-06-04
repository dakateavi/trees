#include <gtest/gtest.h>
#include "trees/BinaryTree.h"


using trees::BinaryTree;

class BinaryTreeTest : public testing::Test {
public:
    BinaryTree<int> tree;
};

TEST_F(BinaryTreeTest, addRemoveSingleton)
{
    tree.insert(42);
    EXPECT_EQ(42, tree.remove(42));
}

// TEST_F(BinaryTreeTest, addRemoveTwoElements)
// {
//     tree.insert(42);
//     tree.insert(1812);
//     EXPECT_EQ(42, tree.remove(42));
//     EXPECT_EQ(1812, tree.remove(1812));
// }