// Copright Jared Selling 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoorWithStatueTriggers.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorTrigger);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoorWithStatueTriggers : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoorWithStatueTriggers();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FDoorTrigger OnOpen;

	UPROPERTY(BlueprintAssignable)
	FDoorTrigger OnClose;

private:
	UPROPERTY(EditAnywhere)
	TArray<AActor*> DoorTriggers;

	bool CheckTriggers();
};
