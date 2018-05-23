// Copright Jared Selling 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenableDoorWithColorPads.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenableDoorWithColorPads : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenableDoorWithColorPads();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	TArray<AActor*> TriggerPads;
	
};
