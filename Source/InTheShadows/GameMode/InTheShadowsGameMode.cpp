// Fill out your copyright notice in the Description page of Project Settings.


#include "InTheShadowsGameMode.h"
#include "GameFramework/DefaultPawn.h"
#include "InTheShadows/Pawns/PuzzlePawn.h"
#include "InTheShadows/Player/PlayerCharacter.h"
#include "IntheShadows/HUD/PlayerHUD.h"
#include "InTheShadows/GameInstance/ITS_GameInstance.h"
#include "Kismet/GameplayStatics.h"

AInTheShadowsGameMode::AInTheShadowsGameMode()
{
	// Set default pawn class to our Blueprinted character, HUD, etc.
	if (DefaultPawnClass == ADefaultPawn::StaticClass() || !DefaultPawnClass)
			DefaultPawnClass = APlayerCharacter::StaticClass();

	if (HUDClass == AHUD::StaticClass() || !HUDClass)
		HUDClass = APlayerHUD::StaticClass();
}

void AInTheShadowsGameMode::InitializeDefaultPuzzleStates()
{
	TArray<AActor*> FoundPuzzles;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APuzzlePawn::StaticClass(), FoundPuzzles);

	if (UITS_GameInstance* GI = Cast<UITS_GameInstance>(GetGameInstance()))
	{
		for (AActor* Actor : FoundPuzzles)
		{
			if (APuzzlePawn* Puzzle = Cast<APuzzlePawn>(Actor))
				GI->SetPuzzleState(Puzzle->InteractableData.Name, false);
		}
	}
}

void AInTheShadowsGameMode::BeginPlay()
{
	Super::BeginPlay();
	InitializeDefaultPuzzleStates();
}
