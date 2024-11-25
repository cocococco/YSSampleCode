// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define INVALID_ID 0

UENUM()
enum class EYSGrade : uint8
{
	Normal,
	Rare,
	Epic,
	Legend,
};

UENUM()
enum class EYSDamageType : uint8
{
	Radical,
	Linear,
	Point,
	Area,
};

UENUM()
enum class EYSElementType : uint8
{
	Fire,
	Ice,
	Poison,
	Earth,
	Electric,
};
