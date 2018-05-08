// Copright Jared Selling 2018

#include "Grabber.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"
#include "Engine/EngineTypes.h"
#include "Engine/World.h"

#define OUT


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"));
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	///Get player viewpoint this tick
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	//UE_LOG(LogTemp, Warning, TEXT("Location: %s, Position: %s"), 
	//	*PlayerViewPointLocation.ToString(), 
	//	*PlayerViewPointRotation.ToString()
	//);

	///draw a red trace in the world to visualize
	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		10.f
	);

	///setup query parameters
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	///Line-trace aka ray-cast out to reach distance
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);

	//see what we hit
	AActor* ActorHit = Hit.GetActor();
	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Line trace hit hit:  %s"), *(ActorHit->GetName()))
	}
	
}

