// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "InTheShadows/Pawns/PuzzlePawn.h"
#include "Its_SaveGame.generated.h"

UCLASS()
class INTHESHADOWS_API UIts_SaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	TMap<FString, FPuzzleState> SavedPuzzleStates;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	TMap<FString, FTransform> SavedPuzzleTransforms;
};
