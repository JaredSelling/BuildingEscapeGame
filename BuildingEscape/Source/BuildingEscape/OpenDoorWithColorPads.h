// Copright Jared Selling 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoorWithColorPads.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorTriggerWithColorPads);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoorWithColorPads : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoorWithColorPads();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	TArray<AActor*> GetTriggerPads();

	UPROPERTY(BlueprintAssignable)
	FDoorTriggerWithColorPads OnOpen;

	UPROPERTY(BlueprintAssignable)
	FDoorTriggerWithColorPads OnClose;

private:
	UPROPERTY(EditAnywhere)
	TArray<AActor*> TriggerPads;

	bool AllTriggersActive;

	bool DetermineIfAllTriggersActive();

	

	
};
