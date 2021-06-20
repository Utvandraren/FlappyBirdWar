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

	AFlappyBirdPawn* PlayerBird;
	APlayerController* PlayerController;
	FTimerHandle ScoreTimerHandle;

	void IncreaseScore();


protected:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void GameOver();


public:
	void ActorDied(AActor* DeadActor);

	virtual void BeginPlay() override;
	//virtual void InitGame(const FString& MapName,const FString& Options,FString& ErrorMessage) override;

	//virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float Score;



	//AFlappyBirdWarGameMode();
};
