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
			PuzzleStates = LoadGameInstance->SavedPuzzleStates;
	}
	else
		InitializeDefaultPuzzleStates(PuzzleStates);
}

void UIts_GameInstance::InitializeDefaultPuzzleStates(const TMap<FString, bool>& InitialStates)
{
	PuzzleStates = InitialStates;
	UE_LOG(LogTemp, Warning, TEXT("Puzzle States initialized"));
}

void UIts_GameInstance::SetPuzzleState(const FText& PuzzleName, bool bIsCompleted)
{
	PuzzleStates.Add(PuzzleName.ToString(), bIsCompleted);

	UIts_SaveGame* SaveGameInstance = Cast<UIts_SaveGame>(
		UGameplayStatics::CreateSaveGameObject(UIts_SaveGame::StaticClass()));
	SaveGameInstance->SavedPuzzleStates = PuzzleStates;
	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("SaveSlot"), 0);
}

bool UIts_GameInstance::GetPuzzleState(const FText& PuzzleName) const
{
	if (const bool* bIsCompleted = PuzzleStates.Find(PuzzleName.ToString()))
	{
		return *bIsCompleted;
	}
	return false;
}
