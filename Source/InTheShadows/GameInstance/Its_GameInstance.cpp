// Fill out your copyright notice in the Description page of Project Settings.


#include "Its_GameInstance.h"
#include "Its_SaveGame.h"
#include "Kismet/GameplayStatics.h"


void UIts_GameInstance::Init()
{
	Super::Init();

	if (UGameplayStatics::DoesSaveGameExist(TEXT("SaveSlot"), 0))
	{
		UIts_SaveGame* LoadGameInstance = Cast<UIts_SaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("SaveSlot"), 0));
		if (LoadGameInstance != nullptr)
		{
			bIsSaveDeleted = false;
			PuzzleStates = LoadGameInstance->SavedPuzzleStates;
			PuzzleTransforms = LoadGameInstance->SavedPuzzleTransforms;
		}
		UE_LOG(LogTemp, Warning, TEXT("Save loaded from game instance"));
	}
	else
	{
		// InitializeDefaultPuzzleStates(PuzzleStates);
		bIsSaveDeleted = true;
		UE_LOG(LogTemp, Warning, TEXT("Save not found, puzzle states initialized from game instance"));
	}
}

// void UIts_GameInstance::InitializeDefaultPuzzleStates(const TMap<FString, bool>& InitialStates)
// {
// 	PuzzleStates = InitialStates;
// 	UE_LOG(LogTemp, Warning, TEXT("Puzzle States initialized from game instance : InitializeDefaultPuzzleStates"));
// }

void UIts_GameInstance::ResetPuzzleStates()
{
	PuzzleStates.Empty();
	UGameplayStatics::DeleteGameInSlot(TEXT("SaveSlot"), 0);
	bIsSaveDeleted = true;
	UE_LOG(LogTemp, Warning, TEXT("Save deleted from game instance"));
}

void UIts_GameInstance::SetPuzzleState(const FText& PuzzleName, const FPuzzleState& State,
                                       const FTransform& PuzzleTransform)
{
	PuzzleStates.Add(PuzzleName.ToString(), State);
	PuzzleTransforms.Add(PuzzleName.ToString(), PuzzleTransform);

	if (UIts_SaveGame* SaveGameInstance = Cast<UIts_SaveGame>(
		UGameplayStatics::CreateSaveGameObject(UIts_SaveGame::StaticClass())))
	{
		bIsSaveDeleted = false;
		SaveGameInstance->SavedPuzzleStates = PuzzleStates;
		SaveGameInstance->SavedPuzzleTransforms = PuzzleTransforms;

		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("SaveSlot"), 0);

		UE_LOG(LogTemp, Warning, TEXT("Puzzle state set with name %s and transform %s from game instance"),
		       *PuzzleName.ToString(),
		       *PuzzleTransform.ToString());
	}
}

FPuzzleState UIts_GameInstance::GetPuzzleState(const FText& PuzzleName, FTransform& PuzzleTransform) const
{
	const FPuzzleState* FoundState = PuzzleStates.Find(PuzzleName.ToString());
	const FTransform* SavedTransform = PuzzleTransforms.Find(PuzzleName.ToString());

	FPuzzleState ResultState;
	if (FoundState)
	{
		UE_LOG(LogTemp, Warning, TEXT("Puzzle %s state found."), *PuzzleName.ToString());
		ResultState = *FoundState;

		if (SavedTransform)
		{
			PuzzleTransform = *SavedTransform;
			UE_LOG(LogTemp, Warning, TEXT("Puzzle %s transform loaded: %s"), *PuzzleName.ToString(),
			       *PuzzleTransform.ToString());
		}
		else
			UE_LOG(LogTemp, Warning, TEXT("No saved transform for Puzzle %s. Using default."), *PuzzleName.ToString());
	}
	else
	{
		ResultState.bIsPuzzleSolved = false;
		ResultState.HasPlayedSound = false;
		UE_LOG(LogTemp, Warning, TEXT("Puzzle state found and loaded from game instance"));
	}
	
	return ResultState;
}
