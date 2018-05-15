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

	//Setup input component
	//
	
}


// Called every frame
void UActivator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//poll the appropriate trigger volume
		//if overlapping, activate

}

ATriggerVolume UActivator::GetOverlappingTrigger()
{
	return ATriggerVolume();
}

void UActivator::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		InputComponent->BindAction("Activate", IE_Pressed, this, UActivator::Activate);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s is missing input component"), *GetOwner()->GetName())
	}
}

void UActivator::Activate()
{

}

