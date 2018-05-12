// Copright Jared Selling 2018

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

#define OUT


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	if(!PressurePlate) { UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName()); }
	if(!Owner) {UE_LOG(LogTemp, Error, TEXT("No owning door found")) }
}



// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Poll the Trigger Volume
	if (GetTotalMassOfActorsOnPlate() > TriggerMass) //TODO make into a parameter
	{
		//If the ActorThatOpens is in the volume
		OnOpen.Broadcast();
	}
	else
	{
		OnClose.Broadcast();
	}
}

float UOpenDoor::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.f;
	//find all overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!PressurePlate) { return TotalMass; }
	if (PressurePlate)
	{
		PressurePlate->GetOverlappingActors(
			OUT OverlappingActors
		);

		for (const auto* Actor : OverlappingActors)
		{
			TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
			UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName());
		}
	}		
	return TotalMass;
}