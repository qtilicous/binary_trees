#include "binary_trees.h"

/**
 * binary_tree_leaves - counts number of leaves in a tree
 * @tree: pointer to the root node of the tree to count the number of leave
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int count, left, right;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL || tree->right == NULL)
		return (1);
	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);
	count = left + right;

	return (count);
}
