/////////////////////////////////////////////////////////////////////////////
//
//	File: LeftLeaningRedBlack.h
//
//	$Header: $
//
//
//	This version of red-black trees is based on Robert Sedgewick's new
//	algorithm, "Left Leaning Red Black Trees", based on papers published in
//	2008 and 2009.
//
//	A Left Leaning Red-Black Tree ("LLRB" for short) is a variation of the
//	standard red-black tree.  It requires that if a node has one red child,
//	that child must be the left child (hence the tree "leans to the left").
//
//	It also allows a black node to have two red children, effectively making
//	the node a 4-node.
//
//	Depending on how values are inserted into the tree, the tree may emulate
//	either a 2-3 tree or a 2-3-4 tree.  The USE_234_TREE symbol controls
//	which rule is applied.  Empirically, 2-3 trees are slightly faster for
//	insertions and look-ups, since fewer special cases are triggered due to
//	how the nodes in the tree are arranged.  Test it if it matters, but in
//	general, leave the USE_234_TREE symbol undefined for better overall
//	performance.
//
//	By enforcing the left-leaning rule, fewer special cases need to be tested
//	when performing insertions and deletions, meaning that less code needs to
//	be written to implement an LLRB.
//
//	In theory, this also makes the code faster.  However, in practice the
//	LLRB is slower than a normal red-black tree.  Due to the need to touch
//	and rearrange more child nodes to test and enforce the left-leaning
//	rule, the LLRB has to access more memory, which makes the code perform
//	slower on modern computers -- main memory is much slower than the CPU,
//	so all of those extra memory accesses cause more pipeline stalls, which
//	inhibits performance.  When running on a system where main memory runs
//	at the same speed as the CPU, LLRBs do demonstrate better performance.
//
//	However, due to limits on specific embedded processors used for this
//	testing, any performance generalization is not reliable.  If you need to
//	use balanced trees on an embedded processor (or any other processor that
//	has the CPU and memory running at similar clock speeds), the different
//	algorithms should be tested on that hardware to determine which one
//	yields the best performance.
//
/////////////////////////////////////////////////////////////////////////////


#pragma once


#include "VoidRef.h"
#include <stdint.h>
#include <iostream>

struct LLTB_t
{
	VoidRef_t Ref;

	bool IsRed;

	LLTB_t *pLeft;
	LLTB_t *pRight;
};


class LeftLeaningRedBlack
{
private:
	LLTB_t* m_pRoot;

public:
	LeftLeaningRedBlack(void);
	~LeftLeaningRedBlack(void);

	bool IsEmpty(void) { return NULL == m_pRoot; }

	void FreeAll(void);
	void Free(LLTB_t *pNode);

	LLTB_t* NewNode(void);

	void* LookUp(const uint32_t value);

	bool Insert(VoidRef_t ref);
	LLTB_t* InsertRec(LLTB_t *pNode, VoidRef_t ref);

	void Delete(const uint32_t value);
	LLTB_t* DeleteRec(LLTB_t *pNode, const uint32_t value);
	LLTB_t* DeleteMin(LLTB_t *pNode);

	void SanityCheck(void);
	void SanityCheckRec(LLTB_t *pNode, bool isParentRed, uint32_t blackDepth, uint32_t &minBlack, uint32_t &maxBlack);

	uint32_t  KeyCount(void);
	uint32_t  KeyCountRec(LLTB_t *pNode);

	void LeafDepth(void);
	uint32_t  LeafDepthRec(LLTB_t *pNode, uint32_t depth, uint32_t ary[], uint32_t depthLimit, uint32_t blackDepth, uint32_t &minBlack, uint32_t &maxBlack);

	void Traverse(void);
	void TraverseRec(LLTB_t *pNode, uint32_t &prev);

	uint32_t Min(uint32_t a, uint32_t b);
	uint32_t Max(uint32_t a, uint32_t b);
	int ArraySize(uint32_t array[]);
	void SafeDelete(LLTB_t *pNode);

	LLTB_t *findParent(uint32_t key);
	LLTB_t *findInsert(uint32_t key);
};



