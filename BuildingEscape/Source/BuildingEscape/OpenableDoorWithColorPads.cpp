// Copright Jared Selling 2018

#include "OpenableDoorWithColorPads.h"


// Sets default values for this component's properties
UOpenableDoorWithColorPads::UOpenableDoorWithColorPads()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenableDoorWithColorPads::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOpenableDoorWithColorPads::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	//loop through triggers
		//if all active, open door
		//otherwise close door
		
}

