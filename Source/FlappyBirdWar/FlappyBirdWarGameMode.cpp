// Copyright Epic Games, Inc. All Rights Reserved.

#include "FlappyBirdWarGameMode.h"
#include "FlappyBirdPawn.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy.h"


void AFlappyBirdWarGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == PlayerBird)
	{
		PlayerBird->HandleDestruction();
		HandleGameOver(false);

		/*if (PlayerControllerRef)
		{
			PlayerControllerRef->SetPlayerEnabledState(false);
		}*/
	}
    else if (AEnemy* DestroyedEnemy = Cast<AEnemy>(DeadActor))
	{
		DestroyedEnemy->HandleDestruction();
		
	}
}


void AFlappyBirdWarGameMode::BeginPlay()
{
	Super::BeginPlay();
	HandleGameStart();
}

void AFlappyBirdWarGameMode::HandleGameOver(bool PlayerWon)
{
}

void AFlappyBirdWarGameMode::HandleGameStart()
{

}



