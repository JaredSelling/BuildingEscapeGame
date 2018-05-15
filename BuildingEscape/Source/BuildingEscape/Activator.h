// Copright Jared Selling 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Activator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UActivator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActivator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UInputComponent* InputComponent = nullptr;
	ATriggerVolume* MatchingTrigger = nullptr;
	ATriggerVolume* OverlappingTrigger = nullptr;
	
	bool IsActivated;

	ATriggerVolume GetOverlappingTrigger();
	void SetupInputComponent();
	void Activate();
	
};
