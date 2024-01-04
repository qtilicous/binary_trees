#include "binary_trees.h"

/**
 * check_tree_height - Measure the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 * Return: The height of the tree, or 0 if tree is NULL.
 */
size_t check_tree_height(const binary_tree_t *tree);

/**
 * check_tree_is_bst - Check if a binary tree is a valid BST.
 * @tree: A pointer to the root node of the tree to check.
 * @prev: A pointer to the previously visited node.
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int check_tree_is_bst(const binary_tree_t *tree, const binary_tree_t *prev);

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!check_tree_is_bst(tree, NULL))
		return (0);

	if (abs((int)check_tree_height(tree->left) -
		(int)check_tree_height(tree->right)) > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) &&
		binary_tree_is_avl(tree->right));
}

/**
 * check_tree_height - Measure the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 * Return: The height of the tree, or 0 if tree is NULL.
 */
size_t check_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = check_tree_height(tree->left);
	right_height = check_tree_height(tree->right);

	return ((left_height > right_height) ? left_height + 1 :
		right_height + 1);
}

/**
 * check_tree_is_bst - Check if a binary tree is a valid BST.
 * @tree: A pointer to the root node of the tree to check.
 * @prev: A pointer to the previously visited node.
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int check_tree_is_bst(const binary_tree_t *tree, const binary_tree_t *prev)
{
	if (tree == NULL)
		return (1);

	if (!check_tree_is_bst(tree->left, prev))
		return (0);

	if (prev != NULL && tree->n <= prev->n)
		return (0);

	prev = tree;

	return (check_tree_is_bst(tree->right, prev));
}
