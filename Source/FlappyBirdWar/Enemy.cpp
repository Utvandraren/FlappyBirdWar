// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FlappyBirdPawn.h"



// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerPawn = Cast<AFlappyBirdPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
	FireRate += FMath::RandRange(-1.f, 1.f);
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &AEnemy::TryFire, FireRate, true);

}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemy::TryFire()
{
	if (!PlayerPawn)
	{
		return;
	}

	Fire();
}


void AEnemy::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}



