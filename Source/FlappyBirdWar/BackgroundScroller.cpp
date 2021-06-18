// Fill out your copyright notice in the Description page of Project Settings.


#include "BackgroundScroller.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FlappyBirdPawn.h"
#include "Enemy.h"
#include "Engine/Engine.h"



// Sets default values
ABackgroundScroller::ABackgroundScroller()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	RootComponent = Sprite;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	BoxCollider->SetupAttachment(RootComponent);
	BoxCollider->SetCollisionProfileName("Trigger");

	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Tile Spawn Point"));
	SpawnPoint->SetupAttachment(RootComponent);
	FVector NewPos = SpawnPoint->GetComponentLocation();
	NewPos.X = 2400.f;
	SpawnPoint->AddRelativeLocation(NewPos);

	TopMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Top Mesh"));
	TopMesh->SetupAttachment(RootComponent);

	BottomMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bottom Mesh"));
	BottomMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ABackgroundScroller::BeginPlay()
{
	Super::BeginPlay();
	PlayerPawn = Cast<AFlappyBirdPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ABackgroundScroller::OnOverlapBegin);

	GetWorld()->GetTimerManager().SetTimer(DestroySelfTimerHandle, this, &ABackgroundScroller::DestroySelf, 360,false);
	//GetWorld()->GetTimerManager().SetTimer(EnemySpawnTimerHandle, this, &ABackgroundScroller::DestroySelf, 5, true);
	     
	

}

// Called every frame
void ABackgroundScroller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABackgroundScroller::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Error, TEXT("Background triggered"));
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, "Overlap Begin FUnction Called");
	//UE_LOG(LogTemp, Warning, TEXT("Taking dmamage"));


	//if the other actor "ISNT self Or owner AND exists
	if (OtherActor && OtherActor != this && OtherActor == PlayerPawn)
	{
		GenerateNewTile();

		/*if (EnemyToSpawn)
		{
			for (int i = 0; i < 5; ++i)
			{
				SpawnEnemy();
			}
		}*/

	}

}

void ABackgroundScroller::GenerateNewTile()
{
	UE_LOG(LogTemp, Warning, TEXT("Tile Created"));

	// Get transform + half of it
	//Create new backgorund on teranform and a half forward 
	//Set destroytimer for this object


	
	FRotator SpawnRotation = GetTransform().GetRotation().Rotator();
	ABackgroundScroller* NewBackground = GetWorld()->SpawnActor<ABackgroundScroller>(BackgroundScrollerClass, SpawnPoint->GetComponentLocation(), SpawnRotation);
	//NewBackground->SetOwner(this);
	
}

void ABackgroundScroller::DestroySelf()
{
	Destroy();
}

void ABackgroundScroller::SpawnEnemy()
{
	FVector spawnPos = SpawnPoint->GetComponentLocation();
	spawnPos.X += FMath::RandRange(-200.f, 200.f);
	spawnPos.Y += 100.f;
	spawnPos.Z += FMath::RandRange(-200.f, 200.f);

	FRotator SpawnRotation = GetTransform().GetRotation().Rotator();

	AEnemy* NewEnemy = GetWorld()->SpawnActor<AEnemy>(EnemyToSpawn, spawnPos, SpawnRotation);

}



