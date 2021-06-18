// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

class AFlappyBirdWarGameMode;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FLAPPYBIRDWAR_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	float DefaultHealth = 100.0f;
	float Health = 0.0f;
	AFlappyBirdWarGameMode* GameModeRef;


public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION()
	void TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

		
};