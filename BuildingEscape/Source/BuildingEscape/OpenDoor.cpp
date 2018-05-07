// Copright Jared Selling 2018

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"


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

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}



// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Poll the Trigger Volume
	if (PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens)) {
		//If the ActorThatOpens is in the volume
		OpenDoor();
	}

}


void UOpenDoor::OpenDoor()
{

	AActor* Owner = GetOwner();

	FRotator Rotation = Owner->GetActorRotation();

	FRotator NewRotation;

	if (Rotation.Yaw < 0) {
		NewRotation = FRotator(0.f, -15.f, 0.f);
	}
	else {
		NewRotation = FRotator(0.f, 60.f, 0.f);
	}
	Owner->SetActorRotation(NewRotation);
}