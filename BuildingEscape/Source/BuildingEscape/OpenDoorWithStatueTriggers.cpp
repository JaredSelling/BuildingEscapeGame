// Copright Jared Selling 2018

#include "OpenDoorWithStatueTriggers.h"
#include "Activator.h"

// Sets default values for this component's properties
UOpenDoorWithStatueTriggers::UOpenDoorWithStatueTriggers()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoorWithStatueTriggers::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UOpenDoorWithStatueTriggers::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//if all 3 triggers are activated, open door
	if (CheckTriggers())
	{
		OnOpen.Broadcast();
	}
	else
	{
		OnClose.Broadcast();
	}
	//close door otherwise
}

bool UOpenDoorWithStatueTriggers::CheckTriggers()
{
	if (!DoorTriggers[0]) { return false; }
	for (const auto Trigger : DoorTriggers)
	{
		if (!Trigger->FindComponentByClass<UActivator>()->GetActivationStatus())
		{
			return false;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("All Triggers set!"))
	return true;
}

