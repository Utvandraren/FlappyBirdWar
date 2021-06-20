// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.h"
#include "FlappyBirdPawn.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UPhysicsThrusterComponent;

UCLASS()
class FLAPPYBIRDWAR_API AFlappyBirdPawn : public APawnBase
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UCameraComponent* Camera;
	FTimerHandle ScoreTimerHandle;
	UInputComponent* PlayerInput;

	void IncreaseScore();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FVector CurrentLocation = FVector(0.0, 0.0, 0.0);
public:
	// Sets default values for this pawn's properties
	AFlappyBirdPawn();


	//Variables
	UPROPERTY(EditAnywhere, Category = "Stats")
		FVector ForceVector = FVector(1000.0, 0.0, 0.0);
	UPROPERTY(EditAnywhere, Category = "Stats")
		int speed = 1;
	UPROPERTY(EditAnywhere, Category = "Stats")
		FVector ConstantForceVector = FVector(100.0, 0.0, 0.0);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float Score;

	UFUNCTION(BlueprintImplementableEvent)
		void GameOver();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void Jump();
	virtual void HandleDestruction() override;


};
