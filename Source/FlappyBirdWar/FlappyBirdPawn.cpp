// Fill out your copyright notice in the Description page of Project Settings.


#include "FlappyBirdPawn.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "PhysicsEngine/PhysicsThrusterComponent.h"



// Sets default values
AFlappyBirdPawn::AFlappyBirdPawn()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void AFlappyBirdPawn::BeginPlay()
{
	Super::BeginPlay();
	CurrentLocation = this->GetActorLocation();

}

// Called every frame
void AFlappyBirdPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentLocation = this->GetActorLocation();
	CurrentLocation.X += speed * DeltaTime; 
	SetActorLocation(CurrentLocation);
}

// Called to bind functionality to input
void AFlappyBirdPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFlappyBirdPawn::Jump);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFlappyBirdPawn::Fire);
}

void AFlappyBirdPawn::Jump()
{
	SphereComponent->AddImpulse(ForceVector, NAME_None, true);
	//UE_LOG(LogTemp, Warning, TEXT("Jump presses"));
}





