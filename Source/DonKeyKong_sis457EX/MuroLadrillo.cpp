// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroLadrillo.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"

AMuroLadrillo::AMuroLadrillo()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroLadrilloAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	if (MuroLadrilloAsset.Succeeded())
	{
		MeshMuro->SetStaticMesh(MuroLadrilloAsset.Object);
	}

}

void AMuroLadrillo::BeginPlay()
{
	Super::BeginPlay();
}

void AMuroLadrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
