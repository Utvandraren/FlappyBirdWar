// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BackgroundScroller.generated.h"

class UBoxComponent;
class UPaperSpriteComponent;
class AFlappyBirdPawn;
class AEnemy;

UCLASS()
class FLAPPYBIRDWAR_API ABackgroundScroller : public AActor
{
	GENERATED_BODY()

private:
	//Components
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UPaperSpriteComponent* Sprite;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UBoxComponent* BoxCollider;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USceneComponent* SpawnPoint;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* TopMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* BottomMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Type", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<ABackgroundScroller> BackgroundScrollerClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Type", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AEnemy> EnemyToSpawn;


	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	AFlappyBirdPawn* PlayerPawn;
	FTimerHandle DestroySelfTimerHandle;
	//FTimerHandle EnemySpawnTimerHandle;


public:	
	// Sets default values for this actor's properties
	ABackgroundScroller();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void GenerateNewTile();
	void DestroySelf();
	void SpawnEnemy();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
