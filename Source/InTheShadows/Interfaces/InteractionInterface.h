// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

class APlayerCharacter;

UENUM()
enum class EInteractableType : uint8
{
	Instant UMETA(DisplayName = "Instant"),
	Puzzle UMETA(DisplayName = "Puzzle"),
	Progress UMETA(DisplayName = "Progress")
};

USTRUCT()
struct FInteractableData
{
	GENERATED_BODY()

	FInteractableData() : InteractableType(EInteractableType::Instant),
	                      Name(FText::GetEmpty()),
	                      Action(FText::GetEmpty()),
	                      InteractionDuration(0.0f)
	{
	};

	UPROPERTY(EditInstanceOnly)
	EInteractableType InteractableType;

	UPROPERTY(EditInstanceOnly)
	FText Name;

	UPROPERTY(EditInstanceOnly)
	FText Action;

	// used for objects that use interaction timer
	UPROPERTY(EditInstanceOnly)
	float InteractionDuration;
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

class INTHESHADOWS_API IInteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void BeginFocus();
	virtual void EndFocus();
	virtual void BeginInteract();
	virtual void EndInteract();
	virtual void Interact(APlayerCharacter* PC);

	bool IsInteracting;

	FInteractableData InteractableData;
};
