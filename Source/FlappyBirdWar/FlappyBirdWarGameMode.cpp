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
	UE_LOG(LogTemp, Warning, TEXT("GameOVerhandle!"));
	//GameOver(); //dint work because of bug
	AActor::DisableInput(GetWorld()->GetFirstPlayerController());
}


void AFlappyBirdWarGameMode::HandleGameStart()
{
	UE_LOG(LogTemp, Warning, TEXT("Game started!"));

	PlayerBird = Cast<AFlappyBirdPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
	//PlayerBird->RestoreHealth();
	//PlayerController = Cast < APlayerController, AController(GetController());
	//DisableInput(PlayerController);
	GetWorld()->GetTimerManager().SetTimer(ScoreTimerHandle, this, &AFlappyBirdWarGameMode::IncreaseScore, 1.f, true);

}

void AFlappyBirdWarGameMode::IncreaseScore()
{
	++Score;
}





