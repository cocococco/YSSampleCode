// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

struct FYSInputKey
{
	EModifierKey::Type Modifier;
	FKey Key;

	FYSInputKey()
		: Modifier(0)
		, Key(EKeys::Invalid)
	{}

	FYSInputKey(const FKey& InKey)
		: Modifier(0)
		, Key(InKey)
	{}

	FYSInputKey(const EModifierKey::Type InModifier, const FKey& InKey)
		: Modifier(InModifier)
		, Key(InKey)
	{}

	void Clear()
	{
		Modifier = 0;
		Key = EKeys::Invalid;
	}

	bool IsCtrlDown() const { return (Modifier & EModifierKey::Control) != 0; }
	bool IsAltDown() const { return false; }
	bool IsShiftDown() const { return false; }
	
	bool CheckModifierState(const FModifierKeysState& InModifierState) const
	{
		return (InModifierState.IsControlDown() == IsCtrlDown());
		//
	}

	void SetCtrlDown() { Modifier |= EModifierKey::Control; }
	void SetAltDown() {}
	void SetShiftDown() {}

	void SetModifierFromKey(const FKey& InKey)
	{
		if (InKey.IsModifierKey())
		{
			if (InKey == EKeys::LeftControl)
			{
				SetCtrlDown();
			}
			//
		}
	}

	const FKey& GetModifierKey() const { return Key; }//

	FYSInputKey& operator=(const FYSInputKey& InOther)
	{
		return *this;
	}

	bool operator==(const FYSInputKey& InOther) const
	{
		return false;
	}

	bool operator!=(const FYSInputKey& InOther) const
	{
		return false;
	}
};

FORCEINLINE uint32 GetTypeHash(const FYSInputKey& InOther)
{
	return HashCombine(GetTypeHash(InOther.Modifier), GetTypeHash(InOther.Key));
}
