// Copright Jared Selling 2018

#include "ColorPadActivator.h"


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

	//get overlapping pad

	//set current pad

	//if current pad has no previous pads and is a trigger pad
		//set active

	//if current pad has no previous pads and is NOT trigger pad
		//do nothing

	//if current pad's previous correct pad is active
		//activate current pad
	//otherwise deactivate all pads
}

