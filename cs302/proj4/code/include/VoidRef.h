/////////////////////////////////////////////////////////////////////////////
//
//	File: VoidRef.h
//
//	$Header: $
//
//
//	This defines the key-value pair structure used by all of the balanced
//	tree algorithms tested.
//
/////////////////////////////////////////////////////////////////////////////


#pragma once
#include <stdint.h>

struct VoidRef_t
{
	uint32_t   Key;
	void* pContext;
};
