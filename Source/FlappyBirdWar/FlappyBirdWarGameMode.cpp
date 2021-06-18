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
		HandleGameOver(Score);
		//UE_LOG(LogTemp, Warning, TEXT("Player died!"));
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

void AFlappyBirdWarGameMode::HandleGameOver(float PlayerScore)
{
	//UE_LOG(LogTemp, Warning, TEXT("Game over"));
	ScoreTimerHandle.Invalidate();
	GameOver(PlayerScore);
}

void AFlappyBirdWarGameMode::IncreaseScore()
{
	++Score;
}

void AFlappyBirdWarGameMode::HandleGameStart()
{
	PlayerBird = Cast<AFlappyBirdPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
	GetWorld()->GetTimerManager().SetTimer(ScoreTimerHandle, this, &AFlappyBirdWarGameMode::IncreaseScore, 1.f, true);

}





