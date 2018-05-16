// Copright Jared Selling 2018

#include "Activator.h"
#include "GameFramework/Actor.h"


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
	//Determine matching Trigger
	
}


// Called every frame
void UActivator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//poll the appropriate trigger volume
		//if overlapping, activate

}

//ATriggerVolume UActivator::GetMatchingTrigger()
//{
//	return ATriggerVolume();
//}
//
//ATriggerVolume UActivator::GetOverlappingTrigger()
//{
//	return ATriggerVolume();
//}
//
//
//
//void UActivator::Activate()
//{
//
//}

