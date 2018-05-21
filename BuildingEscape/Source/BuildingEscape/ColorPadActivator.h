// Copright Jared Selling 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ColorPadActivator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UColorPadActivator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UColorPadActivator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	bool IsActive;

	UPROPERTY(EditAnywhere)
	AActor* NextCorrectPad = nullptr;

	UPROPERTY(EditAnywhere)
	AActor* PreviousCorrectPad = nullptr;

	UPROPERTY(EditAnywhere)
	TArray<AActor*> TriggerPads;
};
