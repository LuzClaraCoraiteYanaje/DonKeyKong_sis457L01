// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h" 

// Sets default values
APlataforma::APlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube_Chamfer.1M_Cube_Chamfer'"));

	MeshPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshPlataforma->SetStaticMesh(MeshAsset.Object);
	RootComponent = MeshPlataforma;

	FVector NewScale(2.0f, 6.0f, 0.5f);
	SetActorScale3D(NewScale);

	Speed = 100.0f;
	bMovingRight = true;
	MovementDirection = FVector(0.0f, 0.0f,1.0f);
	MovementType = 0;
 
}
void APlataforma::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	EndLocation = StartLocation + MovementDirection * 400.0f;
	
}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//MovePlatform(DeltaTime);
	if (FMath::RandRange(0, 1) == 0)
    {
        MovementType = 1; // Movimiento Horizontal
    }
    else
    {
        MovementType = 2; // Movimiento Vertical
    }
}

void APlataforma::MovePlatform(float DeltaTime)
{
	if (MovementType == 1)  // Movimiento Horizontal
    {
        FVector CurrentLocation = GetActorLocation();
        FVector Direction = (bMovingRight ? EndLocation : StartLocation) - CurrentLocation;
        Direction.Normalize();
        CurrentLocation += Direction * Speed * DeltaTime;
        SetActorLocation(CurrentLocation);

        if (FVector::Dist(CurrentLocation, bMovingRight ? EndLocation : StartLocation) < 10.0f)
        {
            bMovingRight = !bMovingRight;
        }
    }
    else if (MovementType == 2)  // Movimiento Vertical
    {
        FVector CurrentLocation = GetActorLocation();
        if (bMovingRight)
        {
            CurrentLocation.Z += Speed * DeltaTime;
            if (CurrentLocation.Z >= EndLocation.Z)
            {
                bMovingRight = false; // Cambia la dirección
            }
        }
        else
        {
            CurrentLocation.Z -= Speed * DeltaTime;
            if (CurrentLocation.Z <= StartLocation.Z)
            {
                bMovingRight = true; // Cambia la dirección
            }
        }
        SetActorLocation(CurrentLocation);
    }

}

void APlataforma::SetMovementDirection(FVector NewDirection)
{
	MovementDirection = NewDirection;
	EndLocation = StartLocation + MovementDirection * 400.0f;
}

void APlataforma::SetMovementType(int32 NewMovementType)
{
	MovementType = NewMovementType;
}

