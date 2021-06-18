// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FlappyBirdWarGameMode.generated.h"

class AFlappyBirdPawn;

UCLASS()
class AFlappyBirdWarGameMode : public AGameModeBase
{
	GENERATED_BODY()
private:
	void HandleGameStart();
	void HandleGameOver(float PlayerScore);
	void IncreaseScore();

	AFlappyBirdPawn* PlayerBird;
	//APlayerControllerBase* PlayerControllerRef;
	float Score;
	FTimerHandle ScoreTimerHandle;

public:
	void ActorDied(AActor* DeadActor);

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
		void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
		void GameOver(float PlayerScore);

	//AFlappyBirdWarGameMode();
};
