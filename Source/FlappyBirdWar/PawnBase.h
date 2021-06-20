// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class USphereComponent;
class AProjectileBase;
class UHealthComponent;
class UPaperSpriteComponent;
class UNiagaraComponent;

UCLASS()
class FLAPPYBIRDWAR_API APawnBase : public APawn
{
	GENERATED_BODY()

private:
	//Components
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UPaperSpriteComponent* Sprite;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UHealthComponent* HealthComponent;

	//Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Type", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AProjectileBase> ProjectileClass;
	UPROPERTY(EditAnywhere, Category = "Effects")
		UNiagaraComponent* DeathParticle;
	UPROPERTY(EditAnywhere, Category = "Effects")
		USoundBase* DeathSound;
	UPROPERTY(EditAnywhere, Category = "Effects")
		TSubclassOf<UCameraShake> DeathShake;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USphereComponent* SphereComponent;

	// Sets default values for this pawn's properties
	APawnBase();
	virtual void HandleDestruction();
	void RestoreHealth();

protected:


	void Fire();


};
