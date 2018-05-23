// Copright Jared Selling 2018

#include "OpenDoorWithColorPads.h"
#include "GameFramework/Actor.h"
#include "ColorPadActivator.h"


// Sets default values for this component's properties
UOpenDoorWithColorPads::UOpenDoorWithColorPads()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoorWithColorPads::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOpenDoorWithColorPads::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//loop through trigger pads
	for (AActor* Trigger : TriggerPads)
	{
		//if all are active, open door
		bool ActivationStatus = Trigger->FindComponentByClass<UColorPadActivator>()->GetActivationStatus();
		if (ActivationStatus)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s ACTIVATED"), *Trigger->GetName())
		}
		//otherwise, close door
	}
}

TArray<AActor*> UOpenDoorWithColorPads::GetTriggerPads()
{
	return TriggerPads;
}

