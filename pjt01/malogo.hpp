#ifndef __LCRS_TREE_H
#define __LCRS_TREE_H

#include <cstdio>
#include <cstdlib>

using ElementType = char;

typedef struct tagLCRSNode
{
	struct tagLCRSNode* leftNode;
	struct tagLCRSNode* rightNode;
} LCRSNode;

LCRSNode* LCRS_createNode(ElementType newData);
void	  LCRS_destroyNode(LCRSNode* node);
void	  LCRS_destroyTree(LCRSNode* node);

void 	  LCRS_addChildren(LCRSNode* parent, LCRSNode* children);
void	  LCRSNode_printTree(LCRSNode* node, int depth);


#endif
