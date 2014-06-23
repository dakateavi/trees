#include <gtest/gtest.h>
#include "trees/AvlTree.h"


using trees::AvlTree;

class AvlTreeTest : public testing::Test {
public:
    AvlTree<int> tree;
};

TEST_F(AvlTreeTest, hasSingleton)
{
    tree.insert(42);
    EXPECT_FALSE(tree.has(-17));
    EXPECT_TRUE(tree.has(42));
}

TEST_F(AvlTreeTest, hasTwoElements)
{
    tree.insert(42);
    tree.insert(1812);
    EXPECT_FALSE(tree.has(7));
    EXPECT_TRUE(tree.has(1812));
    EXPECT_TRUE(tree.has(42));
}

TEST_F(AvlTreeTest, root)
{
    tree.insert(42);
    EXPECT_EQ(42, tree.rootForTest()->element);

}

TEST_F(AvlTreeTest, leftRotation)
{
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    auto aux = tree.rootForTest();
    EXPECT_EQ(2, aux->element);
    EXPECT_EQ(1, aux->left->element);
    EXPECT_EQ(3, aux->right->element);;
}

TEST_F(AvlTreeTest, rightRotation)
{
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    auto aux = tree.rootForTest();
    EXPECT_EQ(2, aux->element);
    EXPECT_EQ(1, aux->left->element);
    EXPECT_EQ(3, aux->right->element);;
}
TEST_F(AvlTreeTest, subTreeRotation)
{
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    auto aux = tree.rootForTest();
    EXPECT_EQ(2, aux->element);
    EXPECT_EQ(1, aux->left->element);
    EXPECT_EQ(4, aux->right->element);
    EXPECT_EQ(5, aux->right->right->element);
    EXPECT_EQ(3, aux->right->left->element);


}

TEST_F(AvlTreeTest, rootRotationLeft)
{
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    auto aux = tree.rootForTest();
    EXPECT_EQ(4, aux->element);
    EXPECT_EQ(2, aux->left->element);
    EXPECT_EQ(5, aux->right->element);
    EXPECT_EQ(1, aux->left->left->element);
    EXPECT_EQ(3, aux->left->right->element);
    EXPECT_EQ(6, aux->right->right->element);
}
TEST_F(AvlTreeTest, justOneMoreForTheFolks1to7)
{
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    auto aux = tree.rootForTest();
    EXPECT_EQ(4, aux->element);
    EXPECT_EQ(2, aux->left->element);
    EXPECT_EQ(6, aux->right->element);
    EXPECT_EQ(1, aux->left->left->element);
    EXPECT_EQ(3, aux->left->right->element);
    EXPECT_EQ(5, aux->right->left->element);
    EXPECT_EQ(7, aux->right->right->element);
}
TEST_F(AvlTreeTest, doubleRotationForTheFolks)
{
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(15);
    tree.insert(14);
    auto aux = tree.rootForTest();
    EXPECT_EQ(4, aux->element);
    EXPECT_EQ(2, aux->left->element);
    EXPECT_EQ(6, aux->right->element);
    EXPECT_EQ(1, aux->left->left->element);
    EXPECT_EQ(3, aux->left->right->element);
    EXPECT_EQ(5, aux->right->left->element);
    EXPECT_EQ(14, aux->right->right->element);
    EXPECT_EQ(7, aux->right->right->left->element);
    EXPECT_EQ(15, aux->right->right->right->element);
}
TEST_F(AvlTreeTest, remove) 
{
	tree.insert(42);
	tree.remove(42);
	EXPECT_FALSE(tree.has(42));
}

TEST_F(AvlTreeTest, nodeWithLeftChildRemoval) {
	tree.insert(42);
	tree.insert(13);
	tree.insert(1963);
	tree.insert(7);
	tree.remove(13);
	auto aux = tree.rootForTest();
	EXPECT_EQ(42, aux->element);
    EXPECT_EQ(7, aux->left->element);
    EXPECT_EQ(1963, aux->right->element);
}

TEST_F(AvlTreeTest, nodeWithRightChildRemoval) {
	tree.insert(42);
	tree.insert(7);
	tree.insert(1963);
	tree.insert(13);
	tree.remove(7);
	auto aux = tree.rootForTest();
	EXPECT_EQ(42, aux->element);
    EXPECT_EQ(13, aux->left->element);
    EXPECT_EQ(1963, aux->right->element);



}

TEST_F(AvlTreeTest, nodeWithBothChildRemoval) {
	tree.insert(42);
	tree.insert(13);
	tree.insert(1963);
	//tree.remove(42);
	auto aux = tree.rootForTest();
	//EXPECT_EQ(13, aux->element);
    //EXPECT_EQ(1963, aux->right->element);


}

TEST_F(AvlTreeTest, valueNotPresentRemovalThrows) {
	EXPECT_THROW(tree.remove(42), std::exception);
	
}

