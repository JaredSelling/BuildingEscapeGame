// Copright Jared Selling 2018

#include "ColorPadActivator.h"
#include "GameFramework/DefaultPawn.h"
#include "Components/ActorComponent.h"
#include "OpenDoorWithColorPads.h"
#include "EngineUtils.h"
#include "UObjectIterator.h"

#define OUT

// Sets default values for this component's properties
UColorPadActivator::UColorPadActivator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UColorPadActivator::BeginPlay()
{
	Super::BeginPlay();

	//Initialize pad settings
	
}


// Called every frame
void UColorPadActivator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (DetermineIfPlayerOverlaps())
	{
		if (IsTrigger)
		{
			IsActive = true;
		}
		else
		{
			DeactivateAllColorPads();
		}
	}
}

bool UColorPadActivator::GetActivationStatus()
{
	return IsActive;
}

bool UColorPadActivator::GetIsTrigger()
{
	return IsTrigger;
}

void UColorPadActivator::DeactivateAllColorPads()
{
	for (TObjectIterator<UColorPadActivator> Itr; Itr; ++Itr)
	{
		UColorPadActivator *Trigger = *Itr;
		Itr->IsActive = false;
		if (Itr->GetOwner())
		{
			UE_LOG(LogTemp, Warning, TEXT("%s deactivated"), *Itr->GetOwner()->GetName());
		}
	}
	return;
}

bool UColorPadActivator::DetermineIfPlayerOverlaps()
{
	TArray<AActor*> OverlappingActors;

	GetOwner()->GetOverlappingActors(
		OUT OverlappingActors,
		ADefaultPawn::StaticClass()
	);
	
	if (OverlappingActors.IsValidIndex(0))
	{
		//player is overlapping
		return true;
	}
	else
	{
		//player is not overlapping
		return false;
	}
}

