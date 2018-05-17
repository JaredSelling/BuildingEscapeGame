// Copright Jared Selling 2018

#include "Activator.h"
#include "GameFramework/Actor.h"

#define OUT


// Sets default values for this component's properties
UActivator::UActivator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActivator::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UActivator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//poll the appropriate trigger volume
	if (IsOverlappingMatchingTrigger())
	{
		IsActivated = true;
	}
	else
	{
		IsActivated = false;
	}
		//if overlapping, activate

}


bool UActivator::IsOverlappingMatchingTrigger()
{
	//find the actors overlapping with the matching trigger
	TArray<AActor*> OverlappingActors;
	if (!MatchingTrigger) { return false; }
	if (MatchingTrigger)
	{
		MatchingTrigger->GetOverlappingActors(
			OUT OverlappingActors
		);
		for (const auto* Actor : OverlappingActors)
		{
			if (Actor == GetOwner())
			{
				return true;
			}
		}
		
	}
	return false;
}

bool UActivator::GetActivationStatus()
{
	return IsActivated;
}

