// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PawnBase.h"
#include "Enemy.generated.h"

class AFlappyBirdPawn;

UCLASS()
class FLAPPYBIRDWAR_API AEnemy : public APawnBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
		float FireRate = 2.0f;

	FTimerHandle FireRateTimerHandle;
	AFlappyBirdPawn* PlayerPawn;
	FVector CurrentLocation = FVector(0.0, 0.0, 0.0);

	void TryFire();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, Category = "Stats")
		int speed = 1;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void HandleDestruction() override;

};
