// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Its_GameInstance.generated.h"

UCLASS()
class INTHESHADOWS_API UIts_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	void SetPuzzleState(const FText& PuzzleName, bool bIsCompleted, const FTransform& PuzzleTransform);
	void InitializeDefaultPuzzleStates(const TMap<FString, bool>& InitialStates);

	UFUNCTION(BlueprintCallable)
	bool GetPuzzleState(const FText& PuzzleName, FTransform& PuzzleTransform) const;

	UFUNCTION(BlueprintCallable)
	void ResetPuzzleStates();

	// Use this in the menu widget
	UFUNCTION(BlueprintCallable)
	bool GetIsSaveDeleted() const { return bIsSaveDeleted; };

private:
	TMap<FString, bool> PuzzleStates;
	TMap<FString, FTransform> PuzzleTransforms;
	bool bIsSaveDeleted = false;
};
